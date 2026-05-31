# Projeto 02: Planejador de Rotas (Algoritmo A*)

Este projeto consiste no desenvolvimento de um sistema de planejamento de rotas geográficas terrestres. O aplicativo é capaz de ler mapas a partir de arquivos de texto, validar rigorosamente essas informações e aplicar inteligência artificial (Busca Heurística) para encontrar o trajeto mais curto entre dois locais.

## 🎯 Objetivos e Foco Acadêmico

Desenvolvido para a disciplina de Programação Avançada na UFRN, este projeto representou uma evolução em relação ao Projeto 01. Enquanto o primeiro focava em restrições de gerenciamento manual de memória, este introduziu o uso extensivo de recursos avançados do C++ moderno:

- **Uso Intensivo da STL (Standard Template Library):** Substituição de arrays dinâmicos e ponteiros crus por contêineres seguros como `std::vector`, `std::list` e `std::stack`, além da utilização de algoritmos prontos como `std::find` e `std::upper_bound`.
- **Tratamento Robusto de Exceções:** Implementação de uma malha rigorosa de `try-catch` para validar arquivos de entrada linha a linha, emitindo exceções específicas (`std::ios_base::failure`, `std::invalid_argument`) com códigos de erro exatos caso o arquivo contenha formatações inválidas ou dados inconsistentes.
- **Algoritmos em Grafos:** Implementação prática do algoritmo de busca **A* (A-Estrela)**, gerenciando conjuntos de nós Abertos e Fechados para encontrar o menor caminho com eficiência.

## 🚀 Funcionalidades Principais

- **Leitura e Validação de Mapas:** O sistema importa pontos e rotas de arquivos formatados (`pontos.txt` e `rotas.txt`), descartando espaços em branco e validando inconsistências lógicas (ex: rotas que ligam pontos inexistentes).
- **Fórmula de Haversine:** A distância real (em linha reta) entre duas coordenadas geográficas de Latitude e Longitude é calculada matematicamente considerando a curvatura do planeta Terra (Raio = 6371 km). Essa distância atua como a heurística (`h`) do Algoritmo A*.
- **Cálculo de Rota (A*):** A partir de um ID de origem e um ID de destino, o sistema explora o grafo e calcula:
  - O comprimento total do caminho (em km).
  - O tempo de execução da busca (em milissegundos).
  - A quantidade de nós explorados (Fechados) e na fronteira (Abertos).
  - O trajeto passo a passo (ex: *De X, Por Y, Até Z*).

## 🗂 Estrutura do Projeto

- `planejador.h` / `planejador.cpp`: Contém as definições de classes como `Ponto`, `Rota`, o controlador `Planejador` e a estrutura auxiliar `Noh` utilizada pelo algoritmo A*.
- `planejador-main.cpp`: Interface interativa via console que permite ao usuário carregar os arquivos base, visualizar o mapa e solicitar cálculos de rotas.
- `teste.cpp`: Bateria de testes automatizados projetada especificamente para bombardear a função de leitura (`ler()`) com 48 arquivos defeituosos, garantindo que o programa não sofra *crash* e identifique os erros adequadamente.
- `Prova_Planejador_Questionario.txt`: Registro das execuções e validações exigidas durante a avaliação da disciplina.

## 🛠️ Como Compilar e Executar

**Requisitos:** Compilador compatível com C++17 (ex: `g++`).

### Opção 1: Executar o Planejador (Modo Interativo)

Abra o terminal na pasta do projeto e compile os arquivos principais:

```cmd
g++ -Wall -Wextra -std=c++17 planejador.cpp planejador-main.cpp -o planejador.exe
```
Em seguida, execute a aplicação (certifique-se de que os arquivos `pontos.txt` e `rotas.txt` estão no mesmo diretório):
```cmd
planejador.exe
```
*Você poderá escolher opções numéricas no menu para listar o mapa ou calcular um caminho informando IDs (ex: `#1` para `#3`).*

### Opção 2: Executar a Bateria de Testes de Arquivos

Para verificar a resiliência do parser de arquivos contra formatações corrompidas (presentes na pasta `arq_teste`), compile e execute o teste de validação:

```cmd
g++ -Wall -Wextra -std=c++17 planejador.cpp teste.cpp -o teste.exe
```
```cmd
teste.exe
```
*O terminal deverá listar o diagnóstico de leitura de cada um dos arquivos `.txt` propositalmente errados, validando se a exceção correta foi disparada sem alterar o estado do sistema.*

---

*Desenvolvido como projeto acadêmico focado em estruturas de dados, algoritmos de busca e uso moderno de C++.*