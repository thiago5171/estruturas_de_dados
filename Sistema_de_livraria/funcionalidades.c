#include "include/funcs.h"



int menu(){
  int escolha;
  printf("\n\n|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=|\n");
  printf("|1 - cadastrar livros.                                  |\n");
  printf("|2 - Excluir livro da prateleira                        |\n");
  printf("|3 - Realizar consulta de um livro                      |\n");
  printf("|4 - Efetuar uma compra                                 |\n");
  printf("|5 - exibir pedidos com demanda de estoque nao atendida |\n");
  printf("|6 - Exibir lista com todos                             |\n");
  printf("|7 - Finalizar                                          |\n");
  printf("|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=|\n");

  printf("\ndigite o valor correspondente a sua escolha : ");
  scanf("%i",&escolha);
  setbuf(stdin, NULL);
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
      printf("\nEstoque:              esgotado!!!");
      }else{
      printf("\nQuantidade em estoque: %i",l->estoque);
      }  
      l = l->prox;
    }
  }else{
      printf("\n\nNenhum livro foi cadastrado com este dado.\n\n");
  }
  printf("\n");
}

// exibir individual
void exibirUm(prateleira* l){
  if(l != NULL){
      printf("\nTitulo:                %s",l->titulo); 
      printf("\nAutor:                 %s",l->autor);
      printf("\nGenero:                %s",l->genero);
      printf("\nCodigo:                %i",l->codigo);
      printf("\nPreco:               R$%.2f",l->preco);
      printf("\nEditora:               %s",l->editora);
      if(l->estoque < 1){
      printf("\nEstoque:              esgotado!!!");
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
         
          return inicio;
      }else if(aux->codigo > (booklist->prox)->codigo){
        aux->prox = booklist->prox;
        booklist->prox = aux;
        booklist = inicio;
        
        return booklist;
      }
      booklist = booklist->prox; 
       
      exibir(booklist);
    }   
  } 
  return 0;
}

// exclui livro                                         
prateleira* excluir(prateleira *l, int c){
  prateleira *aux = l;
  if(l == NULL){
    printf("\n\nNenhum livro cadastrado\n");
    free(aux);
    return l;
  }else if (aux->codigo == c){
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
  return l;
  }
}

//buscar livro
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
//exibir  estoque que excede
void exibirEstoque(banco* db){
  banco* aux = db;
  while(aux != NULL){
    printf("\nCodigo:           %i",aux->codigo);
    printf("\nEstoque           %i",aux->estoque);
    aux = aux->prox;
  }
}

// realizar compra caso tenha estoque 
prateleira* comprar(prateleira *l, int q, int c){
  float price;
  prateleira* aux = l;
  
  
  while(aux != NULL){ 
    if(aux->codigo == c){
      exibirUm(aux);
      break;
    }
    aux = aux->prox;
  } 

  if(aux == NULL){
    printf("Livro nao encontrado");
    return l;
  }else{
    
    if(q <= aux->estoque){
      price = q * aux->preco;
      printf("\nO preço total da compra foi de R$%.2f",price);
      aux->estoque -= q;
    }
  
  return aux;
  }
}

//realizar armazenagem da diferença de estoque
banco* comprarEx(banco *db, prateleira *l, int q, int c){
  banco* aux2 = (banco*)malloc(sizeof(banco));
  prateleira *aux = l;

  aux2->codigo = aux->codigo;

  aux2->estoque =  q - aux->estoque;

  aux2->prox = db;

  aux2->ant = NULL;
  
  if(db != NULL){
    db->ant = aux2;
  }
 return aux2;
}
