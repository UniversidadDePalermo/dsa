#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*para usar strcpy*/

typedef struct lista{
    int dni; 
    char nombre[20]; 
    float saldo; 
  
  struct lista *sig;
 }nodo;


void crear (nodo *pt);
void mostrar(nodo *pt);
void saldos_negativos(nodo *registro, nodo *negativos); 
void saldos_negativos_recursi(nodo *registro, nodo *negativos);



int main()
{
    nodo *prin, *negativo;
    prin=(nodo*)malloc(sizeof(nodo));
    negativo = (nodo*)malloc(sizeof(nodo)); 

    crear(prin);
    mostrar (prin);

    printf("\nMostrar negativos\n"); 
    saldos_negativos(prin, negativo); 
    mostrar(negativo);  /*como tiene la misma struct que prin, puedo reutilizar la funcion mostrar*/

    return 0;
}


void saldos_negativos(nodo *lista, nodo *negativos){

    while(lista->sig!=NULL){
        if(lista->saldo<0){
            negativos->saldo=lista->saldo;
            negativos->dni=lista->dni; 
            strcpy(negativos->nombre,lista->nombre); /*la unica diferencia es que se usa la lib string.h y debemos copiar con strcpy xq es un char[20]*/

            negativos->sig=(nodo*)malloc(sizeof(nodo));
            negativos=negativos->sig;
        }
        lista=lista->sig;


    }
    negativos->sig=NULL; /*importante para poder recorrer la lista*/

}
void saldos_negativos_recursi(nodo *registro, nodo *negativos){

    if(registro->sig!=NULL){  

        if(registro->saldo<0){
            strcpy(negativos->nombre,registro->nombre);
            negativos->dni=registro->dni; 
            negativos->saldo = registro->saldo; 

            negativos->sig=(nodo*)malloc(sizeof(nodo)); /*reservo memoria para el siguiente nodo*/
            negativos = negativos->sig;  /*me muevo un lugar xq de lo contrario estaría posicionada en la primer pos*/
        }
        saldos_negativos(registro->sig, negativos); /*llamo a la funcion */

    }else{
        negativos->sig=NULL; 
    }
}

void crear (nodo *registro)
{
    printf("Ingrese dni");
    scanf("%d",&registro->dni);

    if (registro->dni==0){
        registro->sig=NULL;
    }else
  {
        printf("Ingrese nombre\n");
        scanf("%s", registro->nombre);  /*no se pide con & cuando es string xq recuerden q es un array de char*/
        printf("Ingrese saldo\n");
        scanf("%f", &registro->saldo); /*acá si pedimos con & y con %f xq es de tipo float*/
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

  }
  return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
  {
        printf("\n%s\t", registro->nombre); /*%s xq es una cadena de char, s de string*/
        printf ("%d\t",registro->dni);
        printf ("%f\n",registro->saldo);
        mostrar (registro->sig);
  }
  return;
}
