#include <stdio.h>
#include <stdlib.h>

struct livro{
  char titulo[30];
  char autor[20];
  char genero[15];
  int codigo;
  float preco;
  int estoque;
  char editora[20];
  struct livro *prox;
};
typedef struct livro prateleira;

int menu(){
  int escolha;
  printf("\n\n|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=|\n");
  printf("|1 - cadastrar livros.                                |\n");
  printf("|2 - Excluir livro da prateleira                      |\n");
  printf("|3 - Realizar consulta de dispoibilidade              |\n");
  printf("|4 - Efetuar uma compra                               |\n");
  printf("|5 -                                                  |\n");
  printf("|6 -                                                  |\n");
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
      printf("\nPreco:                 %f",l->preco);
      printf("\nQuantidade de estoque: %i",l->estoque);
      printf("\nEditora:               %s",l->editora);
      l = l->prox;
    }
  }else{
      printf("\n\nNenhum livro foi cadastrado.\n\n");
  }
}
// CADASTRO
prateleira* cadastro(prateleira* booklist){
  prateleira* aux = (prateleira*)malloc(sizeof(prateleira));

  aux = inserir();
  if(booklist == NULL){ 
    booklist = aux;
    booklist->prox = NULL;
    return booklist;
  
  }else if(aux->codigo < booklist->codigo){
    aux->prox = booklist;
    return aux;
  
  }else{ 
    prateleira *inicio = (prateleira*)malloc(sizeof(prateleira));
    inicio = booklist;//salvar na memoria a posicao inicialda lista
  
    prateleira *codl = aux;
    aux = booklist;
    while(1){
      aux = booklist;
      booklist =booklist->prox;
      if(codl->codigo > aux->codigo ){
        aux->prox = codl;
        codl->prox = booklist; 
        break;
      }else if( booklist == NULL && codl->codigo < booklist->codigo ){
         aux->prox = codl;
         break;
      }
    aux = inicio;
   
    }
    return aux;
  }
  
}




int main(void) {
  int choice, n;
//
prateleira* inicio = NULL;

  
while(choice != 7){
  choice = menu();
 if (choice == 1){

  inicio = cadastro(inicio);

     
     
 }else if(choice == 2){
    exibir(inicio);
 }else if(choice ==3 ){
     
 }else if(choice == 4){
    printf("what number you want search in the list: ");
    scanf("%d",&n);
     
 }else if(choice == 5){
    printf("what number you want to insert on the end of list: ");
    scanf("%d",&n);
   
 }else{
   printf("choice is invalid!");
 
 }

}
}
