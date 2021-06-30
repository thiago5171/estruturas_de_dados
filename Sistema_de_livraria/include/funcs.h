
#include <stdlib.h>
#include <stdio.h>
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

struct bd{
  int codigo;
  int estoque;
  struct bd *prox, *ant;
};

typedef struct bd banco;

int menu();
prateleira* inserir();
void exibir(prateleira* l);
void exibirUm(prateleira* l);
prateleira* cadastro(prateleira* booklist);
prateleira* excluir(prateleira *l, int c);
int buscar(prateleira *l,int c);
void exibirEstoque(banco* db);
prateleira* comprar(prateleira *l, int q, int c);
banco* comprarEx(banco *db, prateleira *l, int q, int c);