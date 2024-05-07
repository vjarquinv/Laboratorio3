// Ejercicio3 - Laboratorio 3 -- Valeria Jarquin Vargas, B83986
#include <stdio.h>
#define SIZE 5

// Funcion para verificar cual es el tamaño del cuadrado mas grande
int min(int a, int b, int c) {
    // Se inicializa min con a y despues va comprobando hasta encontrar el valor min
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int findLargestSquare(int matrix[][SIZE]) {
    int maxSize = 0; // Inicializamos el tamaño maximo del cuadrado a 0

    // Recorremos la matriz
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Si encontramos una celda ocupada
            if (matrix[i][j] == 1) {
                // Comprobar si es posible formar un cuadrado de tamaño mayor
                if (i > 0 && j > 0) {
                    int size = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
                    matrix[i][j] = size; // Se guarda el tamaño del cuadrado en esta celda
                    if (size > maxSize) {
                        maxSize = size; // Se actualiza el tamaño maximo si se encuentra otro mas grande
                    }
                } else {
                    if (maxSize == 0) {
                        maxSize = 1; // Si es la primera celda ocupada, el tamaño maximo sera 1
                    }
                }
            }
        }
    }

    return maxSize;
}

int main() {
    int matrix[SIZE][SIZE] = {
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1}
    };

    int largestSquareSize = findLargestSquare(matrix); // Se llama la funcion para encontrar el cuadrado masa grande
    printf("El tamaño más grande de unos es: %d\n", largestSquareSize);

    return 0;
}


