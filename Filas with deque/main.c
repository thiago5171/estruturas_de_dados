#include <stdio.h>
#include <stdlib.h>

struct lista{
  int info;
  struct lista *prox;
};
typedef struct lista Lista;

struct fila{
  Lista *inicio;
  Lista *fim;
};

typedef struct fila Fila;

Fila* criar(){
  Fila *f = (Fila*)malloc(sizeof (Fila));
  f->inicio = f->fim = NULL;
  return f;
}

void inserir(Fila *f, int valor){
  Lista *aux = (Lista*)malloc(sizeof(Lista));
  aux->info = valor;
  int c;

  
  if (f->inicio == NULL){
    aux->prox = NULL;
    f->inicio = f->fim = aux;
  }else{   
    printf("\n inserir no comeco digite [1], no fim [2]: ");
    scanf("%i",&c);
    if(c == 2){  
      aux->prox = NULL;
      f->fim->prox = aux;
      f->fim = aux;
    }else if(c==1){
      aux->prox = f->inicio;
      f->inicio =aux;
      
    }
  }
}


void consultar(Fila *f){
  Lista *aux = f->inicio;
  
  printf("\n Fila: ");
  while(aux!=NULL){
    printf("%d ", aux->info);
    aux=aux->prox;
  }
}

int remover(Fila *f){
  int valor = 0;
  Lista *aux = f->inicio;

  if(aux==NULL){
    printf("\n Fila vazia!");
  }else{
    int c;
    printf("\n remover no comeco digite [1], no fim [2]: ");
    scanf("%i",&c);

    if(c==1){
    valor = f->inicio->info;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL){
      f->fim = NULL;
    }
    free(aux);
    }else{
      while(aux!=NULL){
        if(aux->prox== NULL){
          aux= NULL; 
          f->inicio = f->fim = NULL;
        }else if((aux->prox)->prox == NULL){
          aux->prox =NULL;
          f->fim = aux;
        }
        aux=aux->prox;
      }
    }
 
  }
  return valor;
}

int contar(Fila *f){
  int cont = 0;
  Lista *aux = f->inicio;
  while (aux!=NULL){
    cont++;
    aux = aux->prox;
  }
  return cont;
}

int main(void) {
  
  Fila *f = criar();
  Fila *f2 = criar();
  remover(f);
  printf("\n Quantidade de elementos: %d", contar(f));
  inserir(f, 1);
  inserir(f, 2);
  inserir(f, 3);
  inserir(f, 4);
  inserir(f, 5);
  printf("\n Quantidade de elementos: %d", contar(f));

  consultar(f);

  remover(f);

  consultar(f);
  remover(f);
  consultar(f);
  return 0;
}
