//Calcular el índice de masa corporal ingresando el peso de una persona en kilos y suestatura en metros.
// Este índice se obtiene realizando el cociente entre el peso y elcuadrado de la estatura.

#include <stdio.h>
#include <stdlib.h>

float cargar_peso(){

    float peso;

    printf("Ingrese un peso en kgs.:\n");
    scanf("%f", &peso);

    while(peso<1 || peso>500){

        printf("El peso no puede se menor a 1kg ni mayor a 500kg. Intentelo nuevamente\n");
        scanf("%f", &peso);

    }

    return peso;
}


float cargar_altura(){

    float altura;

    printf("Ingrese una altura en metros (dos decimales):\n");
    scanf("%f", &altura);

    while(altura<1 || altura>3){

        printf("La altura ingresada es incorrecta. No puede ser menor a 1 o mayor a 3 metros\n");
        scanf("%f", &altura);

    }

    return altura;
}

float calculo(float peso, float altura){

    float imc = peso/(altura*altura);

    return imc;
}


int main(){

    float peso = cargar_peso(peso);
    float altura = cargar_altura(altura);
    float imc = calculo(peso, altura);

    printf("El Indice de Masa Corporal es de %.2f\n", imc);

    return 0;
}