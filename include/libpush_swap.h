#ifndef LIBPUSH_SWAP_H
#define LIBPUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

#include "../libft/libft.h"


struct nodo {
    int num;
    struct nodo *next;
};


struct nodo* createNodo(int data);
void pushNodo(int num,struct nodo** stack);
int popNodo(struct nodo** stack);
void printStack(struct nodo** a);
int sizeStack(struct nodo** stack);
struct nodo** createStack(int argc, char *argv[]);
struct nodo** createStackEmpty(int argc, int e);

char *saStack(struct nodo** stack);
char *raStack(struct nodo** stack);
char *pbStack(struct nodo** a,struct nodo** b);
#endif