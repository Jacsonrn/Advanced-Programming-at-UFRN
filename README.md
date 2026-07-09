# Programação Avançada - UFRN

Olá! Este repositório guarda os projetos que venho desenvolvendo para a disciplina de Programação Avançada na Universidade Federal do Rio Grande do Norte (UFRN). 

O objetivo principal destes códigos é o aprendizado e a prática dos conceitos da linguagem C++. Sendo trabalhos acadêmicos, eles refletem o meu processo de evolução na programação, desde o gerenciamento manual de memória até o uso de recursos mais avançados da biblioteca padrão (STL) e algoritmos complexos.

Abaixo, explico brevemente do que se trata cada projeto.

---

## Projeto 01: BigInt - Inteiros de Tamanho Ilimitado

Neste projeto, o desafio foi implementar do zero uma classe `BigInt`, capaz de representar e manipular números inteiros positivos e negativos de qualquer tamanho, superando os limites dos tipos primitivos do C++ (como o `long long int`).

**Principais aprendizados e características:**
- **Gerenciamento Manual de Memória:** Para fins didáticos, foi proibido o uso de contêineres da STL (como `std::vector` ou `std::string`) para armazenar os dígitos. Todo o armazenamento foi feito utilizando ponteiros e alocação dinâmica (`new` e `delete`).
- **Regra dos Três/Cinco:** Implementação cuidadosa de construtores de cópia e movimento, além dos operadores de atribuição correspondentes, para evitar vazamentos de memória (memory leaks).
- **Sobrecarga de Operadores:** A classe suporta operações matemáticas naturais (`+`, `-`, `*`, `/`, `%`, `!`), operadores de fluxo (`<<`, `>>`), comparação e deslocamento de bits (`<<`, `>>`).

O projeto acompanha diversos arquivos de teste (`teste1.cpp`, `teste3.cpp`, etc.) e um script em lote (`run_tests.bat`) para facilitar a validação de todas as funcionalidades.

---

## Projeto 02: Planejador de Rotas (Algoritmo A*)

O segundo projeto consiste em um sistema de planejamento de rotas terrestres. O programa é capaz de ler um mapa (composto por pontos geográficos e rotas que os conectam) a partir de arquivos de texto, validar essas informações e calcular o caminho mais curto entre dois locais.

**Principais aprendizados e características:**
- **Algoritmo A* (A-Estrela):** Implementação do algoritmo de busca A* para encontrar a rota mais curta, utilizando heurísticas e cálculo de custo real.
- **Cálculo de Distâncias Geográficas:** Uso da fórmula de Haversine para calcular a distância em linha reta entre as coordenadas de latitude e longitude dos pontos.
- **Manipulação de Arquivos e Exceções:** Uso intensivo de leitura de arquivos (`std::ifstream`), validação de dados e um sistema robusto de lançamento e captura de exceções (`try-catch`, `std::ios_base::failure`, `std::invalid_argument`) para lidar com formatações incorretas nos arquivos de entrada.
- **Uso da STL:** Diferente do primeiro projeto, aqui foi incentivado o uso das estruturas de dados da biblioteca padrão do C++, como `std::vector`, `std::list` e `std::stack`.

---

## Projeto 03: Plotador de Funções

O terceiro projeto foca no desenvolvimento de uma aplicação com Interface Gráfica de Usuário (GUI) para a plotagem e visualização interativa de funções matemáticas em um plano cartesiano.

**Principais aprendizados e características:**
- **Uso do Framework Qt:** Introdução ao desenvolvimento de interfaces gráficas usando a biblioteca Qt (Widgets), explorando o paradigma de programação orientada a eventos com *Signals e Slots*.
- **Renderização Gráfica Customizada:** Utilização de herança em componentes visuais (`QLabel`) para criar uma classe de `Grafico` independente, responsável pela lógica de renderização (`QPainter`) e pela complexa tradução e mapeamento de coordenadas (Pixels da Tela vs. Plano Cartesiano Real).
- **Interatividade Dinâmica:** Construção de uma interface rica que se adapta automaticamente a redimensionamentos, lê limites através de SpinBoxes, lista as funções ativas com suas respectivas cores utilizando tabelas (`QTableWidget`) e identifica pontos no plano via eventos de clique com o mouse.

---

## Projeto 04: Conversor e Renderizador de Formas (SVG)

O quarto projeto consiste no desenvolvimento de um motor de plotagem vetorial orientado a objetos. Ele lê instruções de formas geométricas a partir de arquivos de texto e gera uma imagem correspondente no formato SVG (*Scalable Vector Graphics*).

**Principais aprendizados e características:**
- **Polimorfismo e Herança:** Uso de uma classe base genérica (`Shape`) com métodos virtuais para armazenar e manipular diversas formas (linhas, círculos, retângulos, estrelas, etc.) em uma coleção polimórfica (`std::vector<pShape>`).
- **Gerenciamento Seguro de Memória (Regra dos 5):** Implementação rigorosa de construtores de cópia/movimento, operadores de atribuição e destrutores na classe gerenciadora (`Designer`) para evitar vazamentos de memória na manipulação de ponteiros dinâmicos.
- **Tratamento de Exceções e Manipulação de Arquivos:** Leitura iterativa de arquivos `.txt`, extraindo parâmetros e delegando a renderização nativa de tags XML/SVG às respectivas instâncias, abortando de forma limpa em caso de erros e lidando de forma nativa com exceções de I/O.

---

## Projeto 05: SupTanques (Supervisório Cliente-Servidor)

O quinto projeto tem como objetivo o desenvolvimento de um sistema supervisório baseado na arquitetura Cliente-Servidor. O sistema simula e monitora, em tempo real, uma planta industrial composta por dois tanques de água interagentes (calculando a física dos fluidos com equações diferenciais).

**Principais aprendizados e características:**
- **Comunicação em Rede (Sockets):** Implementação de comunicação TCP/IP nativa para gerenciar múltiplas conexões simultâneas entre o servidor central e os clientes (gráficos ou de terminal).
- **Concorrência e Sincronização:** Uso de multithreading (`std::thread`) para escuta de rede e processamento em paralelo com a interface, além de controle de concorrência com exclusão mútua (`std::mutex`) para proteger o fluxo de pacotes.
- **Interface Gráfica e Herança Múltipla:** Integração da lógica de rede com o framework Qt, utilizando herança múltipla e manipulação segura da interface visual através do sistema de *Signals e Slots*.
- **Protocolos e Permissões:** Implementação de um protocolo de *handshake* e simulação de níveis de acesso (Administradores com controle ativo das válvulas e bombas vs. Visualizadores em modo *Read-Only*).

---

## Como executar

Os códigos foram escritos seguindo o padrão **C++17**. Para compilar os projetos, recomenda-se o uso do compilador `g++`.

No diretório do **Projeto 01**, você pode compilar e testar a classe `BigInt` rodando o script no terminal do Windows:
```cmd
run_tests.bat
```

---

*Agradeço pela visita ao repositório! Dicas, correções e sugestões construtivas sobre o código são sempre bem-vindas, pois o intuito final é sempre melhorar e aprender mais.*