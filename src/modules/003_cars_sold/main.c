//Se ingresan la cantidad de autos vendidos en los últimos 9 anos. 
//Calcular y mostrar:
//a) El ano que se vendieron la mayor cantidad de autos.
//b) La cantidad total de autos vendidos

#include <stdio.h>

int main() {
    int ventas[9];
    int anno = 0, max_anno = 0, total_ventas = 0, max_ventas = 0, i;
    
    for(i = 0; i < 9; i++) {
        printf("Ingrese el ano donde desea ingresar el numero de ventas: ");
        scanf("%d", &anno);
        printf("\nIngrese las ventas de autos para %d: ", anno);
        scanf("%d", &ventas[i]);
        total_ventas += ventas[i];
        if(ventas[i] > max_ventas) {
            max_ventas = ventas[i];
            max_anno = anno;
        }
    }
    
    printf("\n%d fue el ano con mas ventas de autos, con %d ventas.\n", max_anno, max_ventas);
    printf("El total de autos vendidos es de %d.", total_ventas);
    
    return 0;
}
