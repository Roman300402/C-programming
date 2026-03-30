/*******************
Dominguez Solis Roman
ESFM - IPN
Symbolic Differentiator using Expression Trees
********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Estructura del Nodo del Arbol
typedef struct _nodo_ {
    char info;
    struct _nodo_ *izq, *der;
} NODO;

typedef NODO *ARBOL;

// Estructura de la Pila para construir el Arbol
typedef struct _elem_pila_ {
    NODO *info;
    struct _elem_pila_ *sig;
} ELPILA;

typedef ELPILA *PILA;

// --- Prototipos ---
int push(NODO *info, PILA *ppila);
NODO *pop(PILA *ppila);
NODO *creaNodo(char info);
ARBOL exprecionAlArbol(char *expresion);
ARBOL opderivar(ARBOL a);
void inorden(ARBOL a);

int main() {
    // Ejemplo: x^2 (en postfijo: x2^) -> Derivada: 2*x^(2-1)*1
    char cadena[] = "x2^"; 
    ARBOL a = NULL;
    
    printf("--- Symbolic Differentiation System ---\n");
    printf("Expresion original (Postfijo): %s\n", cadena);
    
    a = exprecionAlArbol(cadena);
    
    printf("Expresion en Inorden: ");
    inorden(a);
    
    printf("\nDerivada Simbolica: ");
    ARBOL derivada = opderivar(a);
    inorden(derivada);
    printf("\n---------------------------------------\n");
    
    return 0;
}

// Implementacion de Derivacion (Reglas de Calculo)
ARBOL opderivar(ARBOL a) {
    if (a == NULL) return NULL;
    NODO *aux = NULL, *sub1, *sub2;

    // Caso Variable 'x'
    if (a->info == 'x') return creaNodo('1');
    
    // Caso Constantes
    if ('a' <= a->info && a->info <= 'z' && a->info != 'x') return creaNodo('0');
    if ('0' <= a->info && a->info <= '9') return creaNodo('0');

    switch (a->info) {
        case '+':
        case '-':
            aux = creaNodo(a->info);
            aux->izq = opderivar(a->izq);
            aux->der = opderivar(a->der);
            break;
        case '*': // Regla del producto: (f*g)' = f'*g + f*g'
            aux = creaNodo('+');
            sub1 = creaNodo('*'); sub2 = creaNodo('*');
            aux->izq = sub1; aux->der = sub2;
            sub1->izq = opderivar(a->izq); sub1->der = a->der;
            sub2->izq = a->izq; sub2->der = opderivar(a->der);
            break;
        case '^': // Regla de la potencia: (x^n)' = n*x^(n-1) * x'
            aux = creaNodo('*');
            sub1 = creaNodo('*');
            aux->izq = sub1;
            aux->der = opderivar(a->izq); // Regla de la cadena
            sub1->izq = a->der; // n
            sub1->der = creaNodo('^');
            (sub1->der)->izq = a->izq; // x
            (sub1->der)->der = creaNodo('-');
            ((sub1->der)->der)->izq = a->der; // n
            ((sub1->der)->der)->der = creaNodo('1'); // 1
            break;
    }
    return aux;
}

// Construccion del Arbol a partir de Postfijo
ARBOL exprecionAlArbol(char *expresion) {
    char *pc;
    NODO *aux;
    PILA mipila = NULL;

    for (pc = expresion; *pc != '\0'; pc++) {
        if (('a' <= *pc && *pc <= 'z') || ('0' <= *pc && *pc <= '9')) {
            push(creaNodo(*pc), &mipila);
        } else {
            aux = creaNodo(*pc);
            aux->der = pop(&mipila);
            aux->izq = pop(&mipila);
            push(aux, &mipila);
        }
    }
    return pop(&mipila);
}

// (Funciones de Pila y Recorrido omitidas por brevedad, usar las mismas de tu archivo)