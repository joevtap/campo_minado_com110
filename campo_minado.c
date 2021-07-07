#include <stdio.h>
#include <stdlib.h>

/*
  CAMPO MINADO {
    Regras {
      - Um campo 10 x 10 com 5 bombas escondidas
      - O jogador escolhe uma coordenada pra jogar
      - Se a coordenada corresponder a uma bomba ele perde
      - Senao ele pode jogar novamente
    }

    Logica {
      Serao duas matrizes, uma com as coordenadas das bombas e uma que sera apresentada para o jogador e que armazena as jogadas dele

      Onde for 0 eh onde nao tem bomba, onde for 1 eh onde tem bomba, onde for 2 eh onde o jogador ja passou
    }
  }

  TODO {

  }
*/

void renderizarCelula(int campo)
{
  switch (campo)
  {
  case 0:
    printf("   |");
    break;
  case 1:
    printf(" * |");
    break;
  case 2:
    printf(" @ |");
    break;
  default:
    printf("   |");
  }
}

void renderizarTabuleiro(int campo, int i, int j)
{
  printf("    0   1   2   3   4   5   6   7   8   9  ");
  printf("\n  -----------------------------------------\n");
  for (i = 0; i < 10; i++)
  {
    printf("%d |", i);

    for (j = 0; j < 10; j++)
      renderizarCelula(campo);

    printf("\n  -----------------------------------------\n");
  }
}

int main(void)
{

  int campo_jogador[10][10] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  },
      campo_bombas[10][10] = {
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      },
      i, j, linha, coluna, rodadas = 0;

  system("clear");
  printf("============= CAMPO MINADO =============\n\n");

  renderizarTabuleiro(campo_jogador, i, j);

  while (1)
  {
    if (rodadas > 0)
      printf("\nVoce ja sobreviveu por %d rodadas!\n\n", rodadas);

    printf("\nDigite a linha a jogar: \n");
    scanf("\n %d", &linha);
    printf("Digite a coluna a jogar: \n");
    scanf("\n %d", &coluna);
    system("clear");

    if (campo_jogador[linha][coluna] == 2)
    {
      // renderizarTabuleiro(campo_jogador, i, j);
      printf("    0   1   2   3   4   5   6   7   8   9  ");
      printf("\n  -----------------------------------------\n");

      for (i = 0; i < 10; i++)
      {
        printf("%d |", i);

        for (j = 0; j < 10; j++)
          renderizarCelula(campo_jogador[i][j]);

        printf("\n  -----------------------------------------\n");
      }

      printf("\nVoce nao pode jogar na mesma casa duas vezes!\n");
      continue;
    }

    if (campo_bombas[linha][coluna] == 1)
    {
      printf("    0   1   2   3   4   5   6   7   8   9  ");
      printf("\n  -----------------------------------------\n");

      for (i = 0; i < 10; i++)
      {
        printf("%d |", i);
        for (j = 0; j < 10; j++)
        {
          if (i == linha && j == coluna)
            printf(" * |");

          else
            renderizarCelula(campo_jogador[i][j]);
        }
        printf("\n  -----------------------------------------\n");
      }

      if (rodadas > 0 && rodadas != 1)
        printf("\nVoce perdeu depois de %d rodadas!\n", rodadas);

      else if (rodadas == 1)
        printf("\nVoce perdeu depois de 1 rodada!\n");

      else
        printf("\nOops...\nAzar, perdeu na primeira rodada...\n");

      break;
    }
    else
    {
      campo_jogador[linha][coluna] = 2;

      // renderizarTabuleiro(campo_jogador, i, j);

      printf("    0   1   2   3   4   5   6   7   8   9  ");
      printf("\n  -----------------------------------------\n");

      for (i = 0; i < 10; i++)
      {
        printf("%d |", i);

        for (j = 0; j < 10; j++)
          renderizarCelula(campo_jogador[i][j]);

        printf("\n  -----------------------------------------\n");
      }
      rodadas++;
      continue;
    }
  }

  return 0;
}
