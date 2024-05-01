// Ejercicio1 Laboratorio 3 - Valeria Jarquin Vargas
#include <stdio.h>

int main(){

    int trg, n = 1, i = 1;
    printf("Los primeros 100 números triangulares son:\n");
    while(i<=100){
        trg = ((n + 1)*n)/2; // formula para calcular los números triangulares
        printf("%d ", trg);
        n++; // se actualiza el n para calcular el siguiente número triangular
        i++; // se incrementa el contador
    }
    printf("\n");
return 0;
}

