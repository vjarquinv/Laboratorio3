// Ejercicio3 - Laboratorio 3 -- Valeria Jarquin Vargas, B83986
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min_SIZE 1
#define max_SIZE 10

// Funcion para verificar cual es el tamaño del cuadrado mas grande
int min(int a, int b, int c) {
    // Se inicializa min con a y despues va comprobando hasta encontrar el valor min
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Funcion para generar la matriz de 1 y 0 aleatoriamente
void generateMatrix(int size, int matrix[][size]) {
    srand(time(NULL)); // Inicializar la semilla con el tiempo actual para que cada que se ejecute de numeros aleotario distintos
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2; // Generar 0 o 1 aleatoriamente
        }
    }
}

// Funcion para encontrar el tamaño del cuadrado mas grande
int findLargestSquare(int size, int matrix[][size]) {
    int maxSize = 0; // Inicializamos el tamaño maximo del cuadrado a 0

    // Se crea una matriz auxiliar para almacenar los tamaños de los cuadrados
    int matrixAux[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrixAux[i][j] = 0;
        }
    }

    // Se llena la primera fila y la primera columna de la matriz auxiliar
    for (int i = 0; i < size; i++) {
        matrixAux[i][0] = matrix[i][0];
        matrixAux[0][i] = matrix[0][i];
        if (matrix[i][0] == 1 || matrix[0][i] == 1) {
            maxSize = 1; // Si hay al menos un 1 en la primera fila o columna, el tamaño maximo del cuadrado es 1
        }
    }

    // Recorremos el resto de la matriz para calcular los tamaños de los cuadrados
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (matrix[i][j] == 1) {
                matrixAux[i][j] = min(matrixAux[i-1][j], matrixAux[i][j-1], matrixAux[i-1][j-1]) + 1;
                if (matrixAux[i][j] > maxSize) {
                    maxSize = matrixAux[i][j]; // Se actualiza el tamaño maximo si encontramos uno mas grande
                }
            }
        }
    }

    return maxSize;
}

int main() {
    int n;
    printf("Ingrese el número de filas para la matriz nxn (en el rango %d - %d): ", min_SIZE, max_SIZE);
    scanf("%d", &n);

    // Se valida el tamaño ingresado
    if (n < min_SIZE || n > max_SIZE) {
        printf("Tamaño no válido. Se utilizará un tamaño por defecto de %dx%d.\n", max_SIZE, max_SIZE);
        n = max_SIZE; // Se establece el tamaño por defecto
    }

    int matrix[n][n];
    generateMatrix(n, matrix); // Se genera la matriz aleatoria
    printf("La matriz utilizada corresponde a:\n");

    // Para imprimir la matriz generada
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int largestSquareSize = findLargestSquare(n, matrix); // Se llama a la funcion para encontrar el tamaño del cuadrado mas grande
    printf("El tamaño del cuadrado mas grande de unos es: %dx%d\n", largestSquareSize, largestSquareSize);

    return 0;
}
