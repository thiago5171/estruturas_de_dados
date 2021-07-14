#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main(void){
  setlocale( LC_ALL, "" );
  Pilha *p = NULL;

  
   p = push(p, '7');
   p = push(p, '5');
   p = push(p, '4');
   p = push(p, '6');
   p = push(p, '3');
   p = push(p, '2');
   p = push(p, '1');

  imprimir(p);

  p = pop(p);
  p = pop(p);

  imprimir(p);
printf("\n\n");
  
verifcarPalindromo();
return 0;
}