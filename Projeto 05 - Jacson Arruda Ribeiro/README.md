# Projeto 05 - SupTanques (Supervisório de Tanques)

**Disciplina:** Programação Avançada  
**Instituição:** Universidade Federal do Rio Grande do Norte (UFRN)  
**Autor:** Jacson Arruda Ribeiro  

---

## 📌 Sobre o Projeto

Este projeto tem como objetivo principal o desenvolvimento de um sistema supervisório baseado na arquitetura **Cliente-Servidor**. O sistema é responsável por simular e monitorar uma planta industrial composta por dois tanques de água interagentes, equipados com válvulas e uma bomba.

O sistema permite a conexão de múltiplos clientes a um servidor central, que calcula a física dos fluidos da planta em tempo real (através de equações diferenciais resolvidas pelo método de Runge-Kutta). Os clientes podem ser de dois tipos:
1. **Cliente de Terminal:** Interface baseada em linha de comando, ideal para testes rápidos e auditoria dos pacotes.
2. **Cliente Gráfico (Qt):** Interface rica (GUI) que provê controle visual dos atuadores (válvulas e bomba) e monitoramento gráfico do nível dos tanques e fluxo de água.

## 🛠️ Tecnologias e Conceitos Aplicados

O projeto foi desenvolvido inteiramente em **C++** moderno (padrões C++11 a C++17) e aplicou extensivamente os seguintes conceitos avançados de programação:

- **Programação Orientada a Objetos (POO):** Polimorfismo, Funções Virtuais Puras e Herança Múltipla (aplicada na interface gráfica associando `QMainWindow` à classe base do motor de rede).
- **Concorrência (Multithreading):** Uso de `std::thread` para instanciar rotinas de escuta de rede e atualização periódica (polling) de dados em paralelo com a thread principal de interface gráfica.
- **Sincronização e Exclusão Mútua:** Aplicação de `std::mutex` para proteger o envio e recebimento de pacotes nos sockets, impedindo condições de corrida (*race conditions*) e sobreposição de comandos.
- **Comunicação em Rede:** Programação de Sockets (TCP/IP) nativa sobre a API de rede (WinSock no ambiente Windows).
- **Interface Gráfica (GUI):** Integração com o framework **Qt (versão 5/6)**, isolamento de manipulação de *widgets* garantida através do sistema de *Signals e Slots*.

## 📂 Estrutura do Código-Fonte

- `supservidor.cpp / supservidor_main.cpp`: Lógica principal do servidor. Instanciação do simulador físico (`Tanks`) e gerenciamento de múltiplas conexões de rede em *threads* separadas.
- `supcliente.cpp`: Classe base e abstrata do Cliente. Gerencia toda a lógica de empacotamento, envio e sincronização de comandos via TCP (mantém estado da planta e permissões do usuário logado).
- `supcliente_term.cpp`: Especialização da classe `SupCliente` provendo a interface de linha de comando (*CLI*).
- `supcliente_qt.cpp`: Especialização da classe `SupCliente` operando como janela principal do *Qt* (Herança Múltipla). Realiza o parse das requisições virtuais para a atualização e bloqueio seguro dos botões e mostradores digitais.
- `mysocket.cpp`: Wrapper de comunicação TCP (Low-level).
- `tanques.cpp`: Simulador físico e matemático (motor das equações diferenciais da planta).

## ⚙️ Instruções de Compilação

Para compilar este projeto, é estritamente necessário possuir um compilador GCC (MinGW-w64 no Windows) moderno que proveja suporte completo a bibliotecas POSIX Threads (`std::thread`), como a distribuição UCRT. 

### 1. Servidor e Cliente de Terminal
O repositório disponibiliza um script *batch* automatizado que compila os dois módulos de terminal simultaneamente.
No terminal (ou prompt de comando) dentro da pasta raiz:
```bash
.\compilar.bat
```
Isto gerará os executáveis `servidor.exe` e `cliente_term.exe`.
*(Alternativamente, é possível abrir os arquivos `SupServidor.cbp` e `SupCliente.cbp` utilizando o Code::Blocks e realizar o Build diretamente pela IDE).*

### 2. Cliente Gráfico (Qt)
Para a compilação visual e linkagem dos componentes do framework (moc/uic):
1. Abra o arquivo **`SupCliente.pro`** utilizando o software **Qt Creator**.
2. Selecione um Kit base compatível (Desktop Qt MinGW 64-bit).
3. Execute o comando de compilação (*Build* ou *Play*). O Qt Creator resolverá as dependências da janela `.ui` gerando o cliente gráfico completo.

## 🔐 Simulação de Permissões
O sistema embarca um protocolo de controle de permissões durante a inicialização (handshake).
- **Usuários Administradores** (ex: `admin/admin`): Obtêm acesso de leitura e controle ativo de escrita na planta (abertura de válvulas e configuração da potência da bomba).
- **Usuários Visualizadores** (ex: `viewer/viewer`): Possuem suas interfaces bloqueadas, visualizando apenas a planta em modo *Read-Only*.
