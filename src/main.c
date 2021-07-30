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

// __________________________________________________________ //

#include <stdio.h>
#include <stdlib.h>
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

int tam = 10;       // Tamanho do campo
Cell field[10][10]; // Matriz campo

void start_game()
{
  for (int l = 0; l < tam; l++)
    for (int c = 0; c < tam; c++)
    {
      field[l][c].isMine = 0;
      field[l][c].isOpen = 0;
      field[l][c].neighbours = 0;
    }
}

int main(void)
{

  // Menu (modulo)
  // open_menu();

  // Iniciar matriz do campo
  start_game();

  // Inserir N minas
  // insert_mine();

  // Contar minas vizinhas da celula aberta
  // count_neighbours();

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

  return 0;
}