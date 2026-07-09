#include <iostream>     /* cerr */
#include <algorithm>
#include <cstdint>      /* uint16_t */
#include "supservidor.h"

using namespace std;

/* ========================================
   CLASSE SUPSERVIDOR
   ======================================== */

/// Construtor
SupServidor::SupServidor()
  : Tanks()
  , server_on(false)
  , LU()
  /*ACRESCENTAR*/
  , sock_conexao()
{
  // Inicializa a biblioteca de sockets
  /*ACRESCENTAR*/
  mysocket_status err = mysocket::init();
  // Em caso de erro, mensagem e encerra
  if (err != mysocket_status::SOCK_OK)
  {
    cerr <<  "Biblioteca mysocket nao pode ser inicializada";
    exit(-1);
  }
}

/// Destrutor
SupServidor::~SupServidor()
{
  // Deve parar a thread do servidor
  server_on = false;

  // Fecha todos os sockets dos clientes
  for (auto& U : LU) U.close();
  // Fecha o socket de conexoes
  /*ACRESCENTAR*/
  sock_conexao.close();

  // Espera o fim da thread do servidor
  /*ACRESCENTAR*/
  if (thr_server.joinable()) thr_server.join();

  // Encerra a biblioteca de sockets
  /*ACRESCENTAR*/
  mysocket::end();
}

/// Liga o servidor
bool SupServidor::setServerOn()
{
  // Se jah estah ligado, nao faz nada
  if (server_on) return true;

  // Liga os tanques
  setTanksOn();

  // Indica que o servidor estah ligado a partir de agora
  server_on = true;

  try
  {
    // Coloca o socket de conexoes em escuta
    /*ACRESCENTAR*/
    mysocket_status err = sock_conexao.listen(SUP_PORT, 5);
    // Em caso de erro, gera excecao
    if (err != mysocket_status::SOCK_OK) throw 1;

    // Lanca a thread do servidor que comunica com os clientes
    /*ACRESCENTAR*/
    thr_server = std::thread(&SupServidor::thr_server_main, this);
    // Em caso de erro, gera excecao
    if (!thr_server.joinable()) throw 2;
  }
  catch(int i)
  {
    cerr << "Erro " << i << " ao iniciar o servidor\n";

    // Deve parar a thread do servidor
    server_on = false;

    // Fecha o socket do servidor
    /*ACRESCENTAR*/
    sock_conexao.close();

    return false;
  }

  // Tudo OK
  return true;
}

/// Desliga o servidor
void SupServidor::setServerOff()
{
  // Se jah estah desligado, nao faz nada
  if (!server_on) return;

  // Deve parar a thread do servidor
  server_on = false;

  // Fecha todos os sockets dos clientes
  for (auto& U : LU) U.close();
  // Fecha o socket de conexoes
  /*ACRESCENTAR*/
  sock_conexao.close();

  // Espera pelo fim da thread do servidor
  /*ACRESCENTAR*/
  if (thr_server.joinable()) thr_server.join();
  // Faz o identificador da thread apontar para thread vazia
  /*ACRESCENTAR*/
  thr_server = std::thread();

  // Desliga os tanques
  setTanksOff();
}

/// Leitura do estado dos tanques
void SupServidor::readStateFromSensors(SupState& S) const
{
  // Estados das valvulas: OPEN, CLOSED
  S.V1 = v1isOpen();
  S.V2 = v2isOpen();
  // Niveis dos tanques: 0 a 65535
  S.H1 = hTank1();
  S.H2 = hTank2();
  // Entrada da bomba: 0 a 65535
  S.PumpInput = pumpInput();
  // Vazao da bomba: 0 a 65535
  S.PumpFlow = pumpFlow();
  // Estah transbordando (true) ou nao (false)
  S.ovfl = isOverflowing();
}

/// Leitura e impressao em console do estado da planta
void SupServidor::readPrintState() const
{
  if (tanksOn())
  {
    SupState S;
    readStateFromSensors(S);
    S.print();
  }
  else
  {
    cout << "Tanques estao desligados!\n";
  }
}

/// Impressao em console dos usuarios do servidor
void SupServidor::printUsers() const
{
  for (const auto& U : LU)
  {
    cout << U.login << '\t'
         << "Admin=" << (U.isAdmin ? "SIM" : "NAO") << '\t'
         << "Conect=" << (U.isConnected() ? "SIM" : "NAO") << '\n';
  }
}

/// Adicionar um novo usuario
bool SupServidor::addUser(const string& Login, const string& Senha,
                             bool Admin)
{
  // Nao pode ser chamada com servidor em funcionamento
  if (serverOn())
  {
    cerr << "Nao pode adicionar usuarios com servidor em funcionamento!\n";
    return false;
  }

  // Testa os dados do novo usuario
  if (Login.size()<6 || Login.size()>12) return false;
  if (Senha.size()<6 || Senha.size()>12) return false;

  // Testa se jah existe usuario com mesmo login
  auto itr = find(LU.begin(), LU.end(), Login);
  if (itr != LU.end()) return false;

  // Insere
  LU.push_back( User(Login,Senha,Admin) );

  // Insercao OK
  return true;
}

/// Remover um usuario
bool SupServidor::removeUser(const string& Login)
{
  // Nao pode ser chamada com servidor em funcionamento
  if (serverOn())
  {
    cerr << "Nao pode remover usuarios com servidor em funcionamento!\n";
    return false;
  }

  // Testa se existe usuario com esse login
  auto itr = find(LU.begin(), LU.end(), Login);
  if (itr == LU.end()) return false;

  // Remove
  LU.erase(itr);

  // Remocao OK
  return true;
}

/// A thread que implementa o servidor.
/// Comunicacao com os clientes atraves dos sockets.
void SupServidor::thr_server_main(void)
{
  // Fila de sockets para aguardar chegada de dados
  mysocket_queue fila;

  while (server_on)
  {
    // Erros mais graves que encerram o servidor
    // Parametro do throw e do catch eh uma const char* = "texto"
    try
    {
      // Encerra se o socket de conexoes estiver fechado
      if (!sock_conexao.connected())
      {
        throw "socket de conexoes fechado";
      }

      // Limpa a fila de sockets
      fila.clear();
      // Inclui na fila o socket de conexoes
      fila.include(sock_conexao);
      // Inclui na fila todos os sockets dos clientes conectados
      for (auto& U : LU) {
        if (U.isConnected()) fila.include(U.sock);
      }

      // Espera ateh que chegue dado em algum socket (com timeout)
      mysocket_status status = fila.wait_read(SUP_TIMEOUT * 1000);

      if (status == mysocket_status::SOCK_ERROR) {
        throw "Erro fatal no select() dos sockets";
      }

      if (status == mysocket_status::SOCK_OK) {
        // Houve atividade em algum socket da fila:

        // 1. Testa se houve atividade nos sockets dos clientes. Se sim:
        for (auto itr = LU.begin(); itr != LU.end(); ++itr) {
            if (itr->isConnected() && fila.had_activity(itr->sock)) {
                uint16_t cmd;
                if (itr->sock.read_uint16(cmd) == mysocket_status::SOCK_OK) {
                    if (cmd == SupCommands::CMD_GET_DATA) {
                        SupState S;
                        readStateFromSensors(S);
                        itr->sock.write_uint16(SupCommands::CMD_DATA);
                        itr->sock.write_bytes((const mybyte*)&S, sizeof(SupState)); // Envia a struct completa (7 uint16_t = 14 bytes)
                    }
                    else if (cmd == SupCommands::CMD_SET_V1) {
                        uint16_t state;
                        itr->sock.read_uint16(state);
                        if (itr->isAdmin) {
                            setV1Open(state != 0);
                            itr->sock.write_uint16(SupCommands::CMD_OK);
                            cout << "CMD_SET_V1 " << state << " DE " << itr->login << " (OK)\n";
                        } else {
                            itr->sock.write_uint16(SupCommands::CMD_ERROR);
                        }
                    }
                    else if (cmd == SupCommands::CMD_SET_V2) {
                        uint16_t state;
                        itr->sock.read_uint16(state);
                        if (itr->isAdmin) {
                            setV2Open(state != 0);
                            itr->sock.write_uint16(SupCommands::CMD_OK);
                            cout << "CMD_SET_V2 " << state << " DE " << itr->login << " (OK)\n";
                        } else {
                            itr->sock.write_uint16(SupCommands::CMD_ERROR);
                        }
                    }
                    else if (cmd == SupCommands::CMD_SET_PUMP) {
                        uint16_t input;
                        itr->sock.read_uint16(input);
                        if (itr->isAdmin) {
                            setPumpInput(input);
                            itr->sock.write_uint16(SupCommands::CMD_OK);
                            cout << "CMD_SET_PUMP " << input << " DE " << itr->login << " (OK)\n";
                        } else {
                            itr->sock.write_uint16(SupCommands::CMD_ERROR);
                        }
                    }
                    else if (cmd == SupCommands::CMD_LOGOUT) {
                        itr->sock.close();
                        cout << "CMD_LOGOUT " << itr->login << "\n";
                    }
                } else {
                    // Se o read falhar (Ex: cliente fechou abruptamente o terminal)
                    itr->sock.close();
                    cout << "CMD_LOGOUT " << itr->login << " (Conexao perdida)\n";
                }
            }
        }

        // 2. Depois, testa se houve atividade no socket de conexao (Novo Login).
        if (fila.had_activity(sock_conexao)) {
            tcp_mysocket sock_temp;
            if (sock_conexao.accept(sock_temp) == mysocket_status::SOCK_OK) {
                uint16_t cmd;
                if (sock_temp.read_uint16(cmd) == mysocket_status::SOCK_OK && cmd == SupCommands::CMD_LOGIN) {
                    string login, senha;
                    sock_temp.read_string(login);
                    sock_temp.read_string(senha);

                    auto itr = std::find(LU.begin(), LU.end(), login);
                    if (itr != LU.end() && itr->password == senha) {
                        // Se usuário válido e senha bater
                        if (itr->isConnected()) itr->sock.close(); // Derruba conexao antiga, se houver
                        itr->sock = std::move(sock_temp); // Move o socket temporário para o usuário
                        itr->sock.write_uint16(itr->isAdmin ? SupCommands::CMD_ADMIN_OK : SupCommands::CMD_OK);
                        cout << "CMD_LOGIN " << login << " (OK)\n";
                    } else {
                        // Se não encontrar usuário ou senha errada
                        sock_temp.write_uint16(SupCommands::CMD_ERROR);
                        sock_temp.close();
                        cout << "CMD_LOGIN inexistente (ERROR)\n";
                    }
                } else {
                    sock_temp.close(); // Fecha se o comando não for LOGIN
                }
            }
        }
      }

    } // fim try - Erros mais graves que encerram o servidor
    catch(const char* err)  // Erros mais graves que encerram o servidor
    {
      cerr << "Erro no servidor: " << err << endl;

      // Sai do while e encerra a thread
      server_on = false;

      // Fecha todos os sockets dos clientes
      for (auto& U : LU) U.close();
      // Fecha o socket de conexoes
      sock_conexao.close();

      // Os tanques continuam funcionando
    } // fim catch - Erros mais graves que encerram o servidor
  } // fim while (server_on)
}
