# Jogo da Velha

Este projeto foi desenvolvido por Gabriel de Jesus Santos em 2016. É uma implementação simples de um jogo da velha em C++ que pode ser jogado entre um jogador e a IA do jogo. 

## Descrição

O jogo da velha é um jogo clássico onde dois jogadores, "X" e "O", se alternam marcando os espaços em uma grade 3x3. O objetivo é fazer uma linha de três marcas horizontais, verticais ou diagonais antes do adversário.

## Funcionalidades

- **Jogador vs IA:** Um jogador humano joga contra a IA do jogo.
- **Múltiplas partidas:** O jogo suporta jogar várias partidas consecutivas.
- **Histórico de vitórias:** O jogo mantém um registro de quantas partidas cada jogador ganhou.
- **Tutorial:** Instruções sobre como jogar o jogo estão disponíveis no menu.

## Estrutura do Código

- **Variáveis principais:**
  - `jogo[9]`: Array para representar o tabuleiro do jogo.
  - `p1_x`, `p2_o`: Símbolos dos jogadores (X para o jogador 1 e O para o jogador 2).
  - `x_ou_o`: Alterna entre X ou O conforme o jogador.
  - `numjog`: Número de jogadas feitas.
  - `partid_wins_p1`, `partid_wins_p2`: Contadores de vitórias dos jogadores.

- **Funções principais:**
  - `int gravar_banco_de_dados(void)`: Placeholder para gravação de dados.
  - `int posicoes_jogadas(void)`: Armazena as posições já jogadas.
  - `int zerar_pos_jogadas(void)`: Reseta as posições jogadas.
  - `int logva(void)`: Mostra valores das variáveis (para depuração).
  - `int tutorial(void)`: Exibe as instruções de como jogar.
  - `int cleararray(void)`: Limpa o tabuleiro para iniciar uma nova partida.
  - `int imprimir(void)`: Imprime o tabuleiro atualizado.
  - `int reset(void)`: Reseta os valores necessários para iniciar uma nova partida.
  - `int main()`: Função principal que controla o fluxo do jogo.

## Como Jogar

1. Compile o código utilizando um compilador de C++.
2. Execute o programa compilado.
3. Siga as instruções exibidas na tela para fazer suas jogadas.
4. Digite a posição onde deseja colocar seu símbolo (X ou O) conforme o esquema do tabuleiro:
   ```
   1 2 3
   4 5 6
   7 8 9
   ```
5. Continue jogando até que haja um vencedor ou o tabuleiro esteja cheio.
6. Acompanhe o placar para ver quem está ganhando mais partidas.

## Nota

Este código foi desenvolvido em 2016 e pode não seguir as melhores práticas de programação modernas. Está disponibilizado aqui para fins educativos e nostálgicos.

## Autor

Gabriel de Jesus Santos

---

Se você encontrar algum problema ou tiver sugestões de melhorias, sinta-se à vontade para contribuir ou entrar em contato.