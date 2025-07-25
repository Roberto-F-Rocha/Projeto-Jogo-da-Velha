# Jogo da Velha em C

## Visão Geral

Este projeto implementa uma versão do clássico jogo da velha (Tic-Tac-Toe) em linguagem C. O jogo pode ser jogado contra um amigo (dois jogadores) ou contra o computador. Ele utiliza estruturas de dados simples para representar o tabuleiro e a lógica do jogo, incluindo a verificação de vitórias e empates.

## Funcionalidades

- **Modos de Jogo:**
  - **Jogador vs. Jogador:** Dois jogadores podem se revezar para fazer suas jogadas.
  - **Jogador vs. Computador:** Um jogador pode desafiar uma inteligência artificial simples.
- **Verificação de Vitória e Empate:** O jogo detecta automaticamente quando um jogador vence ou quando ocorre um empate.
- **Interface de Console:** Toda a interação com o usuário e a exibição do tabuleiro são feitas através do console.

## Estrutura do Código

O código é organizado em funções que gerenciam diferentes aspectos do jogo:

- `main()`: Função principal que controla o fluxo do jogo, apresenta o menu de opções e chama as funções dos modos de jogo.
- `cabeca()`: Exibe informações sobre a universidade, disciplina e desenvolvedores do projeto.
- `painel()`: Exibe o título do jogo no console.
- `menu()`: Apresenta as opções de modo de jogo ao usuário.
- `iniciar_tabuleiro()`: Inicializa o tabuleiro do jogo com espaços vazios.
- `mostrar_tabuleiro()`: Exibe o estado atual do tabuleiro no console.
- `verificar_vitoria()`: Verifica se um jogador venceu o jogo (linhas, colunas ou diagonais).
- `verificar_empate()`: Verifica se o tabuleiro está cheio e o jogo resultou em empate.
- `adicionar_movimento()`: Registra a jogada de um jogador no tabuleiro.
- `jogar_contra_amigo()`: Implementa a lógica para o modo de jogo entre dois jogadores.
- `jogar_contra_computador()`: Implementa a lógica para o modo de jogo contra o computador, incluindo uma IA básica para as jogadas do computador.

## Como Compilar e Executar

Para compilar o projeto, você precisará de um compilador C (como o GCC). No terminal, navegue até o diretório onde o arquivo `.c` está salvo e execute o seguinte comando:

```bash
gcc nome_do_arquivo.c -o jogo_da_velha
```

(Substitua `nome_do_arquivo.c` pelo nome do arquivo que contém o código-fonte, por exemplo, `pasted_content.c` se você salvou o conteúdo lá).

Após a compilação bem-sucedida, você pode executar o programa com:

```bash
./jogo_da_velha
```

## Desenvolvedores

- ROBERTO FERNANDES ROCHA
- HILDI DANTE OLIVEIRA DE QUEIROZ
- RENATO ALVES PESSOA DE MEDEIROS

## Professor

- KENNEDY REURISON LOPES

## Instituição

- Universidade Federal Rural do Semi-árido (UFERSA)
- Disciplina: LABORATÓRIO DE ALGORITMOS E ESTRUTURAS DE DADOS II


