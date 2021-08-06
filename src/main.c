/* JOGO CAMPO MINADO

# Checklist

- [*] Setup do projeto para a versao final
  - [*] Estrutura de pastas
  - [*] Estrutura do codigo
  - [*] Comentarios e passo a passo do desenvolvimento
  - [*] Checklist a respeito do desenvolvimento
- [*] Struct celula
- [*] Matriz campo
- [ ] Menu
- [*] Iniciar campo
- [*] Inserir minas
- [*] Contar minas vizinhas
- [ ] Jogar
  - [*] Mostrar campo
  - [*] Abrir celula
  - [*] Verificar se ganhou
  - [*] Verificar se coordenada e valida
  - [ ] Incrementar o score
- [ ] Salvar score e encerrar o jogo

*/

// ____________________ //

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "modules/save.h"
// #include "modules/menu.h"

// Struct celula

struct Cell
{
  int isMine;     // E uma mina?
  int isOpen;     // Celula esta aberta?
  int neighbours; // Quantos vizinhos tem minas?
};

// Struct jogador

struct Player
{
  char *name;
  int score;
};

// Variaveis globais

int tam = 10;
int l, c, score;
int n_players;
struct Cell field[10][10]; // Matriz campo

void start_game()
{
  for (l = 0; l < tam; l++)
    for (c = 0; c < tam; c++)
    {
      field[l][c].isMine = 0;
      field[l][c].isOpen = 0;
      field[l][c].neighbours = 0;
    }
}

void insert_mines(int number_of_bombs)
{
  srand(time(NULL));
  for (int i = 0; i < number_of_bombs; i++)
  {
    l = rand() % tam;
    c = rand() % tam;
    if (field[l][c].isMine == 0)
      field[l][c].isMine = 1;
    else
      i--;
  }
}

int is_coor_valid(int l, int c)
{
  if (l >= 0 && c >= 0 && l < tam && c < tam)
    return 1;
  return 0;
}

int mines_in_neighbourhood_of(int l, int c)
{
  int mines_in_neighbourhood = 0;

  // Celulas adjacentes
  if (is_coor_valid(l - 1, c) && (field[l - 1][c].isMine == 1))
    mines_in_neighbourhood++;
  if (is_coor_valid(l + 1, c) && (field[l + 1][c].isMine == 1))
    mines_in_neighbourhood++;
  if (is_coor_valid(l, c - 1) && (field[l][c - 1].isMine == 1))
    mines_in_neighbourhood++;
  if (is_coor_valid(l, c + 1) && (field[l][c + 1].isMine == 1))
    mines_in_neighbourhood++;

  // Celulas diagonais
  if (is_coor_valid(l + 1, c + 1) && (field[l + 1][c + 1].isMine == 1))
    mines_in_neighbourhood++;
  if (is_coor_valid(l - 1, c - 1) && (field[l - 1][c - 1].isMine == 1))
    mines_in_neighbourhood++;
  if (is_coor_valid(l + 1, c - 1) && (field[l + 1][c - 1].isMine == 1))
    mines_in_neighbourhood++;
  if (is_coor_valid(l - 1, c + 1) && (field[l - 1][c + 1].isMine == 1))
    mines_in_neighbourhood++;

  return mines_in_neighbourhood;
}

void count_neighbours()
{
  for (l = 0; l < tam; l++)
    for (c = 0; c < tam; c++)
      field[l][c].neighbours = mines_in_neighbourhood_of(l, c);
}

int have_won()
{
  int counter = 0;
  for (l = 0; l < tam; l++)
    for (c = 0; c < tam; c++)
    {
      if (field[l][c].isOpen == 0 && field[l][c].isMine == 0)
        counter++;
    }
  return counter; // se 0, n ganhou, se N, ganhou
}

void print_field(int print_mines)
{
  {
    printf("\n\n   ");
    for (l = 0; l < tam; l++)
    {
      printf("  %d ", l); // colunas
    }
    printf("\n   -----------------------------------------\n");
    for (int l = 0; l < tam; l++)
    {
      printf("%d  |", l);
      for (int c = 0; c < tam; c++)
      {
        if (field[l][c].isOpen || print_mines == 1)
        {
          if (field[l][c].isMine)
            printf(" * ");
          else
            printf(" %d ", field[l][c].neighbours);
        }
        else
        {
          printf("   ");
        }

        printf("|");
      }
      printf("\n   -----------------------------------------\n");
    }
  }
}

void open_cell(int l, int c)
{
  if (is_coor_valid(l, c) && field[l][c].isOpen == 0)
  {
    field[l][c].isOpen = 1;

    if (field[l][c].neighbours == 0)
    {
      open_cell(l - 1, c);
      open_cell(l + 1, c);
      open_cell(l, c - 1);
      open_cell(l, c + 1);

      open_cell(l + 1, c + 1);
      open_cell(l - 1, c - 1);
      open_cell(l + 1, c - 1);
      open_cell(l - 1, c + 1);
    }
  }
}

void play()
{
  int line, column;

  do
  {
    system("clear");
    print_field(0);
    do
    {
      printf("\nDigite as coodernadas (linha e coluna)\n");
      scanf("%d%d", &line, &column);

      if (is_coor_valid(line, column) == 0)
        printf("\nCoordenada invalida, digite novamente...\n");
      if (field[line][column].isOpen == 1)
        printf(" Você já escolheu esse campo! tente outro...");
    } while (is_coor_valid(line, column) == 0 || field[line][column].isOpen == 1);

    open_cell(line, column);
  } while (have_won() != 0 && field[line][column].isMine == 0);

  if (field[line][column].isMine == 1)
    printf("\n\nVoce perdeu :(\n");
  else
    printf("\nVoce ganhou!\n");

  print_field(1);
}

int open_menu()
{
  int menu_choice;

  do
  {
    system("clear");
    printf(" ==========CAMPO MINADO==========\n");
    printf(" 1 - Jogar\n 2 - Ranking\n 3 - Créditos\n 4 - Sair\n");
    printf(" ================================\n");
    printf(" Digite uma opção: ");
    scanf("\n%d", &menu_choice);
  } while (!(menu_choice > 0 && menu_choice <= 4));
  return (menu_choice);
}

int main(void)
{
  struct Player players[n_players];
  int goback;

  do {
    // Menu (modulo);
    int menu_choice = open_menu();

    switch (menu_choice)
    {
    case 1:
      // Iniciar matriz do campo
      start_game();

      // Inserir N minas
      insert_mines(10);

      // Contar minas vizinhas da celula aberta
      count_neighbours();
      // Jogar
      play();

      //   Incrementar score
      // score_plus_one(l, c);

      // Salvar score em arquivo e encerrar o jogo (modulo)
      // end_game();
      break;

    case 2:
      system("clear");
      //Adicionar ranking
      printf("\nVoltar? (1: Sim | 2: Nao)\n");
      scanf("%d", &goback);
      break;

    case 3:
      system("clear");
      printf("\n Joel Vitor Torres\n Samuel Canellas Ferreira\n Ryan Augusto Ribeiro Silva\n");
      printf("\nVoltar? (1: Sim | 2: Nao)\n");
      scanf("%d", &goback);

    case 4:
      ("\nVocê escolheu sair! Até mais!");
      break;

    default:
      printf(" Erro: opção inválida! ");
      break;
    }
  } while (goback == 1);

  return 0;
}