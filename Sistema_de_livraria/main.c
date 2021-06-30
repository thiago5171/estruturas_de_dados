#include <stdio.h>
#include <stdlib.h>
#include "include/funcs.h"

int main(void) {
  int escolha;
  int n, c, q;
  
prateleira* inicio = NULL;
banco* inicioBD = NULL;

while(1){
  escolha = menu();
  if (escolha == 1){//cadastrar
    inicio = cadastro(inicio);
  
  }else if(escolha == 2){//excluir
    printf("\nDigite o codigo do livro que  deseja excluir: ");
    scanf("%i",&n);
    inicio = excluir(inicio, n);

  }else if(escolha ==3 ){//realizar consulta
    printf("\nDigite o codigo do livro que  deseja consultar: ");
    scanf("%i",&n);
    buscar(inicio, n);
    
  }else if(escolha == 4){//efetuar uma compra
    printf("\nDigite o codigo do produto que deseja comprar: ");
    scanf("%i",&c);
    printf("\nDigite a quantidade de unidades que deseja comprar:");
    scanf("%i",&q);
    prateleira* produto = NULL;
    produto = comprar(inicio, q, c);
    
    if(produto->estoque < q){
      inicioBD = comprarEx(inicioBD, produto, q, c);
    }
        
  }else if(escolha == 5){// verificar relção do falta do estoque
    exibirEstoque(inicioBD);

  }else if(escolha == 6){// exibir lista com todos os livros
    exibir(inicio);

  }else if(escolha == 7){ 
    printf("\n Atendimento finalizado\n Obrigado pela preferencia\n");
    break;
 }else {
    printf("\n\nescolha invalida!");
 
 }
 }
}
