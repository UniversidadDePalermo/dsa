//Ingresar números hasta que dicho número sea negativo. Calcular y mostrar:
//a) Cantidad de números mayores a 4 y menores a 25.
//b) Promedio de aquellos números múltiplos de 6.c) El menor número leído.

#include <stdio.h>

int main() {
    int mas_menos = 0;
    int prom = 0;
    int cant_mult = 0;
    int tot_mult = 0;
    int num = 0;
    int menor_num = 0;

    printf("Ingresar numeros hasta que dicho numero sea negativo. El programa entonces finalizara: ");
    scanf("%d", &num);

    menor_num = num;

    while (num >= 0) {
        if (num > 4 && num < 25) {
            mas_menos++;
        }

        if (num % 6 == 0 && num != 0) {
            // ATENCION: Sino cuenta al 0 como multiplo de 6
            cant_mult++;
            tot_mult += num;
        }

        if (num < menor_num) {
            menor_num = num;
        }

        printf("Ingrese otro numero hasta que dicho numero sea negativo. El programa entonces finalizara: ");
        scanf("%d", &num);
    }

    printf("\nLa cantidad de numeros mayores a 4 y menores a 25 es de %d", mas_menos);

    if (cant_mult > 0) {
        float prom = tot_mult/cant_mult;
        printf("\nEl promedio de los numeros multiplos de 6 es de %2.f", prom);
    } else {
        printf("\nNo se ingresaron numeros multiplos de 6");
    }

    if (menor_num < 0) {
        printf("\nNo se ingreso ningun numero mayor a 0.");
    }

    printf("\nEl menor numero leido es de %d", menor_num);

    return 0;
}
