#include "include/libpush_swap.h"
#include <stdio.h>
#include <limits.h>

/*
SA intercambia los dos primeros elementos encima del stack a. 
No hace nada si hay uno o menos elementos.
*/
char *saStack(struct nodo** stack)
{
    int numa;
    int numb;
    numa=popNodo(stack);
    numb=popNodo(stack);
    pushNodo(numa,stack);
    pushNodo(numb,stack);
    
    return "sa";
}
/*
desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
*/
char *raStack(struct nodo** stack)
{
    int *s;
    
    int size;
    int temp;
    int tempaux;
    int i;
    i=0;
    temp=popNodo(stack);
    size=sizeStack(stack);
    s=(int *)malloc(sizeof(int)*size);
    while(i<size)
        {
          tempaux=popNodo(stack);
          s[i]=tempaux;
          i++;
        }
        i++;
     s[i]='\0';
    pushNodo(temp,stack);
    while(size-->0)
       pushNodo(s[size],stack);
    return "ra";
}

/*
push b - toma el primer elemento del stack a y lo pone encima del stack b.
No hace nada si a está vacío.
*/

char *pbStack(struct nodo** a,struct nodo** b)
{
  printf("Dentro");
  int temp;
  temp=popNodo(a);
  printf("Dentro");
  pushNodo(temp,b);
  
  return "pb";
}