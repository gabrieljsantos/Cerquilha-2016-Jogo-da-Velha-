# Jogo da Velha

Este projeto foi desenvolvido por mim em 2016 como uma implementação simples de um jogo da velha em C++. Ele permite que um jogador jogue contra a inteligência artificial do jogo. Embora funcional, o código apresenta alguns erros, redundâncias e práticas de programação não ideais. Na época, foi o programa mais complexo que consegui criar, e ainda hoje, **sinto um misto de orgulho nostálgico ao revisitar essa conquista**.
Se você decidir corrigir o código, sugiro usar como inspiração e começar a reescrevê-lo do zero.

---

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

Este código foi desenvolvido em 2016 quando o altor tinha um nivek muito baixo de programação, e pode não seguir as melhores práticas de programação. Está disponibilizado aqui para fins educativos e nostálgicos.

## Autor

Gabriel de Jesus Santos

---

Se você encontrar algum problema ou tiver sugestões de melhorias, sinta-se à vontade para contribuir ou entrar em contato. começe com:

### Pontos Negativos e Melhorias Necessárias

O código fornecido possui vários pontos negativos que precisam ser abordados para melhorar sua funcionalidade, legibilidade, e manutenção. Abaixo estão listados os principais problemas e sugestões de melhorias:

1. **Comentários Inconsistentes e Ortografia Incorreta**:
   - Comentários como "funcao que darar valo '-' a todo array" têm erros de ortografia e gramática.
   - **Melhoria**: Revise os comentários para corrigir os erros e torná-los mais claros.

2. **Nomes de Variáveis e Funções Pouco Descritivos**:
   - Variáveis como `v_to_all_jogo`, `controle`, `auter`, entre outras, não são descritivas.
   - **Melhoria**: Use nomes de variáveis e funções mais significativos e consistentes com as convenções de nomenclatura.

3. **Código Duplicado e Redundante**:
   - Muitas partes do código são duplicadas, especialmente na lógica de decisão e controle de jogadas.
   - **Melhoria**: Refatore o código para eliminar duplicações e usar funções auxiliares quando necessário.

4. **Uso Excessivo de Variáveis Globais**:
   - O código depende muito de variáveis globais, o que dificulta a manutenção e o entendimento do fluxo do programa.
   - **Melhoria**: Minimize o uso de variáveis globais e prefira passar parâmetros para funções.

5. **Falta de Verificação de Entrada do Usuário**:
   - Não há verificação adequada para garantir que a entrada do usuário seja válida.
   - **Melhoria**: Adicione verificações de entrada para evitar entradas inválidas e prevenir possíveis bugs.

6. **Formatação do Código**:
   - O código está mal formatado, com espaçamentos inconsistentes e linhas de código muito longas.
   - **Melhoria**: Aplique uma formatação consistente em todo o código, usando um padrão como o estilo K&R ou Allman.

7. **Lógica Complexa e Não Estruturada**:
   - A lógica para determinar as jogadas é complexa e difícil de seguir.
   - **Melhoria**: Simplifique a lógica usando estruturas de dados apropriadas e algoritmos mais claros.

8. **Falta de Modularização**:
   - O código principal está muito carregado e faz muitas coisas ao mesmo tempo.
   - **Melhoria**: Separe a lógica do jogo em diferentes módulos e funções para melhorar a organização.

