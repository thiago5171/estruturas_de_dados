#include "funcoes/func.h"

void imprimir(Pilha *p){
  if(p == NULL){
    printf("\nnenhum item cadastrado  na lista");
  }else{
    printf("\n");
    while(p != NULL){
    printf("%c",p->info);
    p = p->prox;
    }
  }
}

Pilha* push(Pilha *p , char valor){
  
    Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
    aux->info = valor;
    aux->prox = p;
    return aux;
}

Pilha* pop(Pilha *p){
  if(p == NULL){
    printf("\nnenhum item cadastrado  na lista");
    return p;
  }else{
    p = p->prox;
    return p;
  }
}
int pilhasIguais(Pilha* p1, Pilha* p2) {
	float verifiy = 1;

	if ((p1 == NULL) || (p2 == NULL)) {
		printf(" Um das Pilhas Está vazia ");
	} else {
		while ((p1 != NULL) && (p2 != NULL) && verifiy) {
			if (p1->info != p2->info) {
				verifiy = 0;
			} else {
				p1 = p1->prox;
				p2 = p2->prox;
			}
		}
	}
	if ((p1 == NULL) && (p2 == NULL) && verifiy) {
		return 1;
	}
  return 0; 
	
}

int verifcarPalindromo(){
  Pilha *p = NULL;
  int a;
  char word[100];
  printf("type a word for verify if is  the palindromo: ");
  gets(word);
  
  for(int i = 0; i < strlen(word); i++){
    p = push(p, word[i]);
  }
  Pilha* aux = NULL;
  Pilha* inicio= p;

  for(int i = 0; i < strlen(word); i++){
    aux = push(aux, p->info);
    p = p->prox;
  }
  p = inicio;
 
  a = pilhasIguais(aux, p);
  if(a == 1){
    printf("\né um palindromo");
    return 1;
  }
  printf("\nnão  é um palindromo");
  return 0;

}