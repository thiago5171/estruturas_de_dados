#include <stdio.h>
#include <stdlib.h>

struct livro{
  char titulo[30];
  char autor[20];
  char genero[15];
  int codigo;
  float preco;
  int estoque;
  char editora[30];
  struct livro *prox;
};
typedef struct livro prateleira;

int menu(){
  int escolha;
  printf("\n\n|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=|\n");
  printf("|1 - cadastrar livros.                                |\n");
  printf("|2 - Excluir livro da prateleira                      |\n");
  printf("|3 - Realizar consulta de um livro                    |\n");
  printf("|4 - Efetuar uma compra                               |\n");
  printf("|5 - Verificar a falta de estoque                     |\n");
  printf("|6 - Exibir lista com todos                           |\n");
  printf("|7 - Finalizar                                        |\n");
  printf("|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=|\n");

  printf("\ndigite o valor correspondente a sua escolha : ");
  scanf("%i",&escolha);
 
 return escolha;
}

prateleira* inserir(){
  prateleira* livro = (prateleira*)malloc(sizeof(prateleira));
  printf("\nDigite o titulo: ");
  scanf("%s",livro->titulo);

  printf("\nDigite o nome do autor: ");
  scanf("%s",livro->autor);
  
  printf("\nDigite o genero:  ");
  scanf("%s",livro->genero);
  
  printf("\nDigite o  codigo (apenas numeros): ");
  scanf("%i",&livro->codigo);
  
  printf("\nDigite o preco : ");
  scanf("%f",&livro->preco);
  
  printf("\nDigite a quantidade do estoque : ");
  scanf("%i",&livro->estoque);
  
  printf("\nDigite o nome da editora: ");
  scanf("%s",livro->editora);
  return livro;
}


//título, autor, gênero, código, preço, quantidade em estoque e editora.
void exibir(prateleira* l){
    
  if(l != NULL){
    while(l != NULL){
      printf("\nTitulo:                %s",l->titulo);
      printf("\nAutor:                 %s",l->autor);
      printf("\nGenero:                %s",l->genero);
      printf("\nCodigo:                %i",l->codigo);
      printf("\nPreco:               R$%.2f",l->preco);
      printf("\nEditora:               %s",l->editora);
      if(l->estoque < 1){
      printf("\nEsgotado!!!");
      }else{
      printf("\nQuantidade em estoque: %i",l->estoque);
      }  
      l = l->prox;
    }
  }else{
      printf("\n\nNenhum livro foi cadastrado com este dado.\n\n");
  }
}

void exibirUm(prateleira* l){
    
  if(l != NULL){

      printf("\nTitulo:                %s",l->titulo);
      printf("\nAutor:                 %s",l->autor);
      printf("\nGenero:                %s",l->genero);
      printf("\nCodigo:                %i",l->codigo);
      printf("\nPreco:               R$%.2f",l->preco);
      printf("\nEditora:               %s",l->editora);
      if(l->estoque < 1){
      printf("\nEsgotado!!!");
      }else{
      printf("\nQuantidade em estoque: %i",l->estoque);
      }  
      l = l->prox;
  }else{
      printf("\n\nNenhum livro foi cadastrado com este dado.\n\n");
  }
}
// CADASTRO
prateleira* cadastro(prateleira* booklist){
  prateleira* aux = (prateleira*)malloc(sizeof(prateleira));

  aux = inserir();
  if(booklist == NULL){ 
    booklist = aux;
    free(aux);
    return booklist;
  
  }else if(aux->codigo > booklist->codigo){
    aux->prox = booklist;
    free(booklist);
    return aux;
  
  }else{     
    prateleira *inicio = booklist;
    while(booklist != NULL){
      if(booklist->prox == NULL){
          booklist->prox = aux;
          aux->prox = NULL;
          free(aux);
          return inicio;
      }else if(aux->codigo > (booklist->prox)->codigo){
        aux->prox = booklist->prox;
        booklist->prox = aux;
        booklist = inicio;
        free(aux);
        return booklist;
      }
      booklist = booklist->prox; 
       
      exibir(booklist);
    }   
  } 
  return 0;
}



int buscar(prateleira *l,int c){
  prateleira *aux = l;

  while(aux != NULL){ 
    if(aux->codigo == c){
      exibirUm(aux);
      return 1;
    }
    aux = aux->prox;
  } 
  printf("\nLivro nao encontrado.");
  return 0;
}

prateleira* excluir(prateleira *l, int c){
  prateleira *aux = l;

  if (aux->codigo == c){
    aux = aux->prox;
    return aux;
  }else{
    while(l != NULL){
      if((aux->prox)->codigo == c){
        aux->prox = (aux->prox)->prox;
        return l;
      }
      aux = aux->prox;
    }
  }
  return l;
}

int main(void) {
  int escolha;
  int n;
  
prateleira* inicio = NULL;

while(1){
  escolha = menu();
 if (escolha == 1){//cadastrar

  inicio = cadastro(inicio);
 }else if(escolha == 2){//excluir
    printf("\nDigite o codigo do livro que  deseja excluir: ");
    scanf("%i",&n);
    excluir(inicio, n);

 }else if(escolha ==3 ){//realizar consulta
    printf("\nDigite o codigo do livro que  deseja consultar: ");
     scanf("%i",&n);
     buscar(inicio, n);
     
    //consultar(inicio, n);
 }else if(escolha == 4){//efetuar uma compra
    printf("  ");
     scanf("%i",&n);
     //inicio = remover(inicio, n);
     
 }else if(escolha == 5){// verificar relção do falta do estoque
    printf(" ");
   
   //scanf("%s",&n);
  }else if(escolha == 6){// exibir lista com todos os livros
      exibir(inicio);

  }else if(escolha == 7){ 
    printf("Atendimento finalizado\nObrigado pela preferencia");
    break;
 }else {
   printf("escolha is invalid!");
 
 }


}
}