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
- [ ] Inserir minas
- [ ] Contar minas vizinhas
- [ ] Jogar
  - [ ] Mostrar campo
  - [ ] Abrir celula
  - [ ] Verificar se ganhou
  - [ ] Verificar se coordenada e valida
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

typedef struct
{
  int isMine;       // E uma mina?
  int isOpen;       // Celula esta aberta?
  int neighbours;   // Quantos vizinhos tem minas?
} Cell;

// Variaveis globais

int tam = 10, l, c, score; // Tamanho do campo, variaveis para iterar
Cell field[10][10];        // Matriz campo

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

void have_won()
{
  if (score == 920)
  {
    printf(" Você obteve a pontuação máxima! Parabéns!!");
    //Falta anexar a pontuação ao nome do jogador
    return;
  }
}

// void score_plus_one()
// {
//   if (choosed[l][c] == (field[l][c].isMine == 0))
//   {
//     score += 10;
//   }
// }

int main(void)
{

  // Menu (modulo)
  // open_menu();

  // Iniciar matriz do campo
  start_game();

  // Inserir N minas
  insert_mines(8);

  // Contar minas vizinhas da celula aberta
  count_neighbours();
  // Jogar
  // play();
  //   Mostrar campo
  //   print_field();

  //   Abrir celula
  //   open_cell();

  //   Verificar se ganhou
  have_won();

  //   Verificar se coordenada selecionada eh valida
  //is_coor_invalid();

  //   Incrementar score
  //   score_plus_one();

  // Salvar score em arquivo e encerrar o jogo (modulo)
  // end_game();

  //Teste neighbours
  for (l = 0; l < 10; l++)
  {
    for (c = 0; c < 10; c++)
    {
      printf("%d  ", field[l][c].neighbours);
    }
    printf("\n");
  }

  printf("\n");

  //Teste bombas
  for (l = 0; l < 10; l++)
  {
    for (c = 0; c < 10; c++)
    {
      printf("%d  ", field[l][c].isMine);
    }
    printf("\n");
  }
  return 0;
}