#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct pilha{
  char info;
  struct pilha *prox;
  
};
typedef struct pilha Pilha;


void imprimir(Pilha *p);
Pilha* push(Pilha *p , char valor);
Pilha* pop(Pilha *p);
int pilhasIguais(Pilha* p1, Pilha* p2);
int verifcarPalindromo();