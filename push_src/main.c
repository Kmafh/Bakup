#include "../include/libpush_swap.h"

#include <stdio.h>


/*
    FT_REPEAT; comprombromaos que los argumentos introducidos no este repetidos.
*/
static int ft_repeat(char *argv[])
{
    int i;
    char *temp;
    int j;
    i=1;
    while(argv[i])
    {
        temp=argv[i];
        j=i+1;
        while(argv[j])
            {
                if(ft_strncmp(temp,argv[j],3)==0)
                    return 1;
                j++;
            }
        
        i++;
    }
    return 0;
}

/*
    ordenStack. Comprobamos si la PIla esta ordenada.
*/

static int ordenStack(struct nodo** a)
{    int cont;
    int size;
    cont =0;
    size=sizeStack(a);
    struct nodo* nod=*a;
    
    while(cont<size)
        {            
            if((nod->num)>(nod->next->num))
                return 1;   
            *a=(*a)->next;
            nod=*a;
            cont++;
        }
    return 0;

}
/*
    push_swap. FUncion principal con el algoritmos de ordenación
*/

static struct nodo** push_swap(struct nodo** a, struct nodo** b)
{
    char *result=" ";
    char *re=" ";
    int cont;
    int conex;
    int size;
    conex=ordenStack(a); //Comprobamos si esta ordenado.
    cont =0;
    size=sizeStack(a);
    struct nodo* nod=*a;
    size--;
    while(conex!=0 && sizeStack(a)!=size)
        {
            if((nod->num)>(nod->next->num))//si el primer numero es mayor que el segundo
            {
                result=saStack(a);//Damos la vuelta a los dos primeros
                re=ft_strjoin(re," ");
                re=ft_strjoin(re,result);
            }
            if((nod->num)<(nod->next->num)) //sino, si el primer numero en menor que el segundo
            {
                result=pbStack(a,b); //pasamos el menor a la otra pila
                re=ft_strjoin(re," ");
                re=ft_strjoin(re,result);
            }
                printStack(a);
               // printStack(b);
                conex=ordenStack(a);//comprobamos si esta ordenado
                printf("Conex: %d. \n",conex);
                size=sizeStack(a);
                printf("Conex: %d. Size: %d\n",conex,size);
                if(size!=0)
                    size--;
        }
        printStack(a);
        //printStack(b);
        printf(" %s. \n",re);
        return a;
}


int main(int argc , char *argv[])
{
    struct nodo** a= createStack(argc,argv);
    struct nodo** b= createStackEmpty(1,' ');
    
    if(argc<=1)
        {
            ft_putstr_fd("Error. Enter at least two numbeers to play.\n",1);
        }
        else
        {
            if(ft_repeat(argv)==1)
                {
                    ft_putstr_fd("Introduce numeros sin quye se repitan\n",1);
                    exit(1);
                }
            a=push_swap(a,b);
            //printStack(a);
            //printStack(b);
        }
}
