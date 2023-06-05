// Ejercicio resuelto
//     Dado un árbol binario de busqueda, hallar:
//     a) El elemento maximo del arbol
//     b) Cantidad de nodos con dos hijos divisores de la raiz
//     c) Promedio de nodos con un valor par con un sólo hijo.

#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja,int *);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja, int *, int, int *, int *, int *);

int main ()
{
    int cont=0,raiz,maximo,cont1=0,acum=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");
    maximo=raiz;
    mostrar (arbol,&cont,raiz,&maximo,&acum,&cont1);
    printf("\n nodos divisores con dos hijos%d",cont);
    printf("\n maximo %d",maximo);
    if (cont1!=0)
        printf("\n promedio %d", acum/cont1);

    return 0;
}
void crear (treenode **hoja, int *raiz)
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



void mostrar (treenode *hoja, int *cont, int raiz, int *maximo, int *acum, int *cont1)
{
    if (hoja!=NULL)
    {

        mostrar(hoja->izq,cont,raiz, maximo,acum,cont1);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,cont, raiz,maximo,acum,cont1);
        if (hoja->dato > *maximo)
            *maximo=hoja->dato;
        
        if(raiz % hoja->dato==0 && hoja->der!=NULL && hoja->izq!=NULL )
                *cont=*cont+1;

        if (hoja->dato%2==0)
        {
            if ((hoja->der!=NULL && hoja->izq==NULL) || (hoja->der==NULL && hoja->izq!=NULL))
            {
                *acum=*acum+hoja->dato;
                *cont1=*cont1+1;
            }



        }
    }
    return;
}

