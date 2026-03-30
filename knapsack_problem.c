#include <stdio.h>
#include <stdlib.h>

// Función para obtener el máximo de dos enteros
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    
    printf("\t\t***** PROBLEMA DE LA MOCHILA *****\n");
    printf("Digite el numero de elementos: ");
    scanf("%d", &n);
    printf("Capacidad de la mochila: ");
    scanf("%d", &W);

    int valor[n + 1], peso[n + 1];
    int i, w;

    for (i = 1; i <= n; i++) {
        printf("\nElemento %d\n Beneficio: ", i);
        scanf("%d", &valor[i]);
        printf(" Peso: ");
        scanf("%d", &peso[i]);
    }

    // Matriz DP: filas (objetos), columnas (capacidad 0 a W)
    int K[n + 1][W + 1];

    // Construcción de la tabla
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (peso[i] <= w)
                K[i][w] = max(valor[i] + K[i - 1][w - peso[i]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("\nBeneficio total maximo: %d\n", K[n][W]);

    // Backtracking para encontrar qué elementos se incluyeron
    printf("Elementos incluidos (Peso, Beneficio):\n");
    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        // Si el resultado viene de la fila anterior, el item no se incluyó
        if (res == K[i - 1][w])
            continue;
        else {
            printf("- Item %d: (%d, %d)\n", i, peso[i], valor[i]);
            res -= valor[i];
            w -= peso[i];
        }
    }

    return 0;
}
