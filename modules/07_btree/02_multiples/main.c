// Ingresar números enteros y generar un árbol binario de búsqueda.
// Mostrarlo en Orden.
// Mostrar la cantidad de nodos hojas impares y la cantidad de nodos múltiplos de
// la raíz.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja, int* );
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int, int *,int*);

int main ()
{
    int raiz;
    int cont=0;
    int cont1=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,raiz,&cont,&cont1);
    printf("\nla cantidad de multiplos de la raiz es %d",cont);
    printf("\n la cantidad de nodos hojas impares es %d",cont1);

    return 0;
}
void crear (treenode **hoja,int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{




    if (numero>(*hoja)->dato)
    {

        insertar (&(*hoja)->der,elem);

    }
    else
    {

        insertar (&(*hoja)->izq,elem);
    }
    }
return;
}



void mostrar (treenode *hoja,int raiz,int *cont,int *cont1)
{
    if (hoja!=NULL)
    {


        mostrar(hoja->izq,raiz,cont,cont1);
        if (hoja->dato%raiz==0 && hoja->dato!=raiz)
               *cont=*cont+1;

        if (hoja->izq==NULL && hoja->der==NULL && hoja->dato%2!=0)
                *cont1=*cont1+1;

        printf("%d ",hoja->dato);
        mostrar(hoja->der,raiz,cont,cont1);

    }
    return;
}
