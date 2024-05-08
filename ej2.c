// Ejercicio 2 - Valeria Jarquin Vargas, B83986
#include<stdio.h>

int factorial(int n){
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1; // La variable n estaba declarada doble, causando un loop infinito
    }
    return i;
}


int main (int argc , char *argv[]) {
    /*
    int fac4 = factorial(4);
    int fac5 = factorial(5) ;
    printf(" 4! = %d, 5! = %d\n" , fac4, fac5);
    */
    int fac, facn;
    printf("Ingrese el número al que desee calcular factorial: "); // Se le solicita al usuario que ingrese un número
    scanf("%d", &fac);
    facn = factorial(fac); //Llama la funcion factorial
    printf("El factorial de %d es %d\n" , fac, facn);
return 0;
}