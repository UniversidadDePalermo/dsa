//Ingresar la edad y sueldo de los empleados de una empresa hasta que ambas sean cero. Calcular y mostrar:
//a) El promedio de edad de los que ganan más de $10000
//b) El sueldo de aquellas personas mayores a 58 años, sabiendo que cobran un plus del 5% de su sueldo.
//c) El porcentaje de empleados cuyo sueldo es menor a 15000, que está entre 15000 y 20000, y mayor a 20000.

#include <stdio.h>

int main(){

    float sueldo, prom_mas_diez;
    int edad, cant_mas_diez = 0, suma_edad_mas_diez = 0, emp_tot = 0, emp_menor_quince = 0, emp_entre_quince_veinte = 0, emp_mayor_veinte = 0, porc_mayor_veinte = 0, porc_menor_quince = 0, porc_entre_quince_veinte = 0;

    printf("Ingresar edad y sueldo de los empleados. Cuando se coloca un 0 en ambos campos, el programa finalizara");
    printf("\nIngrese la edad: ");
    scanf("%d", &edad);

    while (edad<12 && edad!=0) {

        printf("Lo siento, pero no pueden haber trabajadores que tengan menos de 12 años de edad. Intentelo nuevamente");
        printf("\nIngrese la edad: ");
        scanf("%d", &edad);

    }

    printf("Ingrese el sueldo: ");
    scanf("%f", &sueldo);

    while (sueldo<0) {

        printf("Lo siento, pero el sueldo no puede ser negativo");
        printf("\nIngrese el sueldo: ");
        scanf("%f", &sueldo);

    }

    while (edad!=0 && sueldo!=0){

        if (sueldo>10000){

            cant_mas_diez++;
            suma_edad_mas_diez+=edad;

        }
        if (edad>58){

            float total_sueldo, tip;
            tip = (sueldo*5)/100;
            total_sueldo = sueldo+tip;
            printf("\nEl empleado con %d años cobra %2.f (con tip incluido), %2.f sin incluir el tip", edad, total_sueldo, sueldo);

        }
        if (sueldo<15000){

            emp_tot++;
            emp_menor_quince++;

        }
        else if (sueldo>=15000 && sueldo<=20000){

            emp_tot++;
            emp_entre_quince_veinte++;

        }
        else if (sueldo>20000){

            emp_tot++;
            emp_mayor_veinte++;

        }
        
        printf("\nSe ingresara la edad y sueldo del siguiente empleado.");
        printf("\nIngrese la edad: ");
        scanf("%d", &edad);

        while (edad<12 && edad!=0) {

            printf("Lo siento, pero no pueden haber trabajadores que tengan menos de 12 años de edad. Intentelo nuevamente");
            printf("\nIngrese la edad: ");
            scanf("%d", &edad);

        }
        
        printf("Ingrese el sueldo: ");
        scanf("%f", &sueldo);

        while (sueldo<0) {

            printf("Lo siento, pero el sueldo no puede ser negativo");
            printf("\nIngrese el sueldo: ");
            scanf("%f", &sueldo);

        }
        
    }

    if (emp_tot!=0){

        prom_mas_diez = suma_edad_mas_diez/cant_mas_diez;
        printf("El promedio de edad de los trabajadores que ganan mas de 10000 es de %2.f, de un numero de %d trabajadores.\n", prom_mas_diez, cant_mas_diez);

        porc_menor_quince = (emp_menor_quince*100)/emp_tot;
        printf("El porcentaje de empleados que ganan menos de 15000 es de %d %%.\n", porc_menor_quince);

        porc_entre_quince_veinte = (emp_entre_quince_veinte*100)/emp_tot;
        printf("El porcentaje de empleados que ganan entre 15000 y 20000 es de %d %%.\n", porc_entre_quince_veinte);

        porc_mayor_veinte = (emp_mayor_veinte*100)/emp_tot;
        printf("El porcentaje de empleados que ganan mas de 20000 es de %d %%.\n", porc_mayor_veinte);

    }
    else {

        printf("No se ingresaron trabajadores.");

    }



}