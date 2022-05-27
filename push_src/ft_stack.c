#include "include/libpush_swap.h"
#include <stdio.h>
#include <limits.h>

// Add element to stack

struct nodo* createNodo(int data)
{
    struct nodo *a= (struct nodo*)malloc(sizeof(struct nodo));
    a->num=data;
    a->next=NULL;
    return a;
}

// add Nodo
void pushNodo(int num,struct nodo** stack)
    {
        struct nodo *new = createNodo(num);

        new->next=*stack;
        *stack = new;        
    }

// Create Stack Initial

struct nodo** createStack(int argc, char *argv[])
{
    int i;
    int temp;
    i=argc-1;
    struct nodo** a= malloc(sizeof(struct nodo**));
    createNodo(ft_atoi(argv[i]));
    
    while(i!=0)
        {
            temp=ft_atoi(argv[i]);
            pushNodo(temp,a);
            i--;
        }  
    return a;
}

// Create Stack Empty
struct nodo** createStackEmpty(int argc, int e)
{
    int i;
    int temp;
    i=argc-1;
    struct nodo** a= malloc(sizeof(struct nodo**));
    if(!a)
        return NULL;
    createNodo(e);
    
    while(i!=0)
        {
            pushNodo(e,a);
            i--;
        }  
    return a;
}

// Dellete element to stack
int popNodo(struct nodo** stack)
{
    if(!(*stack))return INT_MIN;
    struct nodo* one =*stack;
    int data = one->num;
    *stack = (*stack)->next;
    free(one);
    return data;
}

// Print elements to stack
void printStack(struct nodo** a)
{
   struct nodo* atmp = *a;
   //struct nodo* btmp = *b;
   int conx;
   conx=0;
   
   ft_putchar_fd('\n',1);
   while(atmp)
   {
        ft_putchar_fd('\t',1);
        if(atmp->num==32)
        ft_putchar_fd(atmp->num,1);
        else
        ft_putnbr_fd(atmp->num,1);
        ft_putchar_fd('\t',1);
        /*if(btmp->num==32)
        ft_putchar_fd(btmp->num,1);
        else
        ft_putnbr_fd(btmp->num,1);*/
        ft_putchar_fd('\n',1);
        atmp=atmp->next;
       // btmp=btmp->next;
   }
   
}

// Size Stack

int sizeStack(struct nodo** stack)
{
    int cont;
    cont=0;
    struct nodo* tmp = *stack;
    while(tmp)
    {
       cont++;       
       tmp=tmp->next;
    }
    return cont;
}

