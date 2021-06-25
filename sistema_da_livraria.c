#include <stdio.h>
#include <stdlib.h>

struct livro{
  char titulo[20];
  char autor[20];
  char genero[20];
  int codigo;
  float preco;
  int estoque;
  struct livro *prox;
};
typedef struct livro prateleira;

int menu(){
  int escolha;
  printf("|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=|\n");
  printf("|1 - cadastrar livros.                                |\n");
  printf("|2 - Excluir livro da prateleira                      |\n");
  printf("|3 - Realizar consulta de dispoibilidade              |\n");
  printf("|4 - Efetuar uma compra                               |\n");
  printf("|5 -                                                  |\n");
  printf("|6 -                                                  |\n");
  printf("|7 -                                                  |\n");
  printf("|8 - Finalizar                                        |\n");
  printf("|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=|\n");

  printf("\ndigite o valor correspondente a sua escolha : ");
  scanf("%i",&escolha);
 
 return escolha;
}

prateleira* cadastro(prateleira* booklist){
  prateleira* aux = (prateleira*)malloc(sizeof(prateleira));
  
  if(booklist != NULL){ 
  
  
  }else(){ 
  return booklist;
  }
}


int main(void) {
  int choice, n;
//
prateleira* inicio = NULL;

  
while(1){
  choice = menu();
 if (choice == 1){

   inicio = cadastro(inicio)

     
     
 }else if(choice == 2){
     
 }else if(choice ==3 ){
     
 }else if(choice == 4){
    printf("what number you want search in the list: ");
    scanf("%d",&n);
     
 }else if(choice == 5){
    printf("what number you want to insert on the end of list: ");
    scanf("%d",&n);
   
 }else if(choice == 8){
    break;
 }else{
   printf("choice is invalid!");
 
 }

}
}
