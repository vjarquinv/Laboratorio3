// Ejercicio1 Laboratorio 3 - Valeria Jarquin Vargas
#include <stdio.h>

int main(){

    int trg, n = 1, i = 1;
    printf("Los primeros 100 numeros triangulares son:\n");
    while(i<=100){
        trg = ((n + 1)*n)/2;
        printf("%d ", trg);
        n++;
        i++;
    }
    printf("\n");
return 0;
}

