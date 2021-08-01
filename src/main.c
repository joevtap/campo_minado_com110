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
  int isMine;     // E uma mina?
  int isOpen;     // Celula esta aberta?
  int neighbours; // Quantos vizinhos tem minas?
} Cell;

// Variaveis globais

int tam = 10, l, c; // Tamanho do campo, variaveis para iterar
Cell field[10][10]; // Matriz campo

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

void insert_mines()
{
  srand(time(NULL));
  for (int i = 0; i < 8; i++)
  {
    l = rand() % 10;
    c = rand() % 10;
    field[l][c].isMine = 1;
  }
}

void count_neighbours()
{
  int neighbours;
  for(l=0; l<10; l++){
    for(c=0; c<10; c++){
      if((field[l][c+1].isMine) == 1){
        field[l][c].neighbours += 1;
      }
      if ((field[l][c-1].isMine) == 1)
      {
        field[l][c].neighbours += 1;
      }
      if ((field[l+1][c].isMine) == 1)
      {
        field[l][c].neighbours += 1;
      }
      if ((field[l-1][c].isMine) == 1)
      {
        field[l][c].neighbours += 1;
      }
    }
  }
}

int main(void)
{

  // Menu (modulo)
  // open_menu();

  //Escolha da dificuldade
  //choice_dif();

  // Iniciar matriz do campo
  start_game();

  // Inserir N minas
  insert_mines();

  // Contar minas vizinhas da celula aberta
  count_neighbours();
  // Jogar
  // play();
  //   Mostrar campo
  //   print_field();

  //   Abrir celula
  //   open_cell();

  //   Verificar se ganhou
  //   have_won();

  //   Verificar se coordenada selecionada eh valida
  //   is_coor_valid();

  //   Incrementar score
  //   score_plus_one();

  // Salvar score em arquivo e encerrar o jogo (modulo)
  // end_game();

  //Teste
  // for(l=0; l<10; l++){
  //   for(c=0; c<10; c++){
  //     printf("%d ", field[l][c].neighbours);
  //   }
  //   printf("\n");
  // }
  return 0;
}