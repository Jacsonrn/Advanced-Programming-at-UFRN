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

## Como executar

Os códigos foram escritos seguindo o padrão **C++17**. Para compilar os projetos, recomenda-se o uso do compilador `g++`.

No diretório do **Projeto 01**, você pode compilar e testar a classe `BigInt` rodando o script no terminal do Windows:
```cmd
run_tests.bat
```

---

*Agradeço pela visita ao repositório! Dicas, correções e sugestões construtivas sobre o código são sempre bem-vindas, pois o intuito final é sempre melhorar e aprender mais.*