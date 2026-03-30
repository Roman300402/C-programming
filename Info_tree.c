/*******************
Dominguez Solis Roman
Grupo: 4FM1
Programacion II
Project: Complex Binary Information Tree
********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct _info_ {
    char cadena1[128], cadena2[128];
    int entero1, entero2;
    float thisreal;
} INFO;

typedef struct _nodo_arbol_ {
    INFO info;
    struct _nodo_arbol_ *izq, *der;
} NODO;

typedef NODO *ARBOL;

// Prototipos
INFO Leeinf(void);
void preorden(ARBOL arbol);
void inorden(ARBOL arbol);
void posorden(ARBOL arbol);
void printinformacion(INFO info);
int ingresaNodos(INFO info, ARBOL *parbol);
int busnodo(INFO info, ARBOL arbol);
int cominformacion(INFO info, INFO elem);

int main(int argc, char *argv[]) {
    ARBOL arbol = NULL;
    INFO info;
    int i;

    printf("--- Creacion del Arbol (3 nodos iniciales) ---\n");
    for(i = 0; i < 3; i++) {
        info = Leeinf();
        ingresaNodos(info, &arbol);
    }

    printf("\n>>> Recorrido Preorden:"); preorden(arbol);
    printf("\n>>> Recorrido Inorden:"); inorden(arbol);
    printf("\n>>> Recorrido Posorden:"); posorden(arbol);

    printf("\n\n--- Busqueda de Informacion ---\n");
    info = Leeinf();

    if(busnodo(info, arbol)) 
        printf("\n[!] Resultado: Elemento localizado en el arbol.\n");
    else 
        printf("\n[!] Resultado: Elemento NO localizado.\n");

    return 0;
}

int cominformacion(INFO info, INFO elem) {
    if(strcmp(elem.cadena1, info.cadena1) == 0 &&
       strcmp(elem.cadena2, info.cadena2) == 0 &&
       elem.entero1 == info.entero1 &&
       elem.entero2 == info.entero2 &&
       elem.thisreal == info.thisreal) {
        return 1;
    }
    return 0;
}

// Recorridos (Cambiados a void para limpieza)
void preorden(ARBOL arbol) {
    if(arbol == NULL) return;
    printinformacion(arbol->info);
    preorden(arbol->izq);
    preorden(arbol->der);
}

void inorden(ARBOL arbol) {
    if(arbol == NULL) return;
    inorden(arbol->izq);
    printinformacion(arbol->info);
    inorden(arbol->der);
}

void posorden(ARBOL arbol) {
    if(arbol == NULL) return;
    posorden(arbol->izq);
    posorden(arbol->der);
    printinformacion(arbol->info);
}

INFO Leeinf(void) {
    INFO ret;
    // Limpieza de buffer profesional
    int c; while ((c = getchar()) != '\n' && c != EOF); 

    printf("\nPrimer cadena: "); scanf("%127[^\n]%*c", ret.cadena1);
    printf("Segunda cadena: "); scanf("%127[^\n]%*c", ret.cadena2);
    printf("Primer entero: "); scanf("%d", &ret.entero1);
    printf("Segundo entero: "); scanf("%d", &ret.entero2);
    printf("Numero punto flotante: "); scanf("%f", &ret.thisreal);

    return ret;
}

void printinformacion(INFO info) {
    printf("\n[ %d | %d | %.2f | %s | %s ]", 
            info.entero1, info.entero2, info.thisreal, info.cadena1, info.cadena2);
}

int ingresaNodos(INFO info, ARBOL *parbol) {
    if(*parbol == NULL) {
        NODO *nuevo = (NODO*)malloc(sizeof(NODO));
        if(nuevo == NULL) return -2;
        nuevo->info = info;
        nuevo->izq = nuevo->der = NULL;
        *parbol = nuevo;
        return 1;
    }

    ARBOL aux = *parbol;

    // Lógica BST: menor izquierda, mayor derecha
    if(info.entero1 < aux->info.entero1) {
        ingresaNodos(info, &(aux->izq));
    }
    else if(info.entero1 > aux->info.entero1) {
        ingresaNodos(info, &(aux->der));
    }
    else {
        // Criterio de desempate con entero2
        if(info.entero2 < aux->info.entero2) {
            ingresaNodos(info, &(aux->izq));
        }
        else if(info.entero2 > aux->info.entero2) {
            ingresaNodos(info, &(aux->der));
        }
        else {
            // Si coinciden ambos enteros, combinamos la informacion
            strncat(aux->info.cadena1, " ", 1);
            strncat(aux->info.cadena1, info.cadena1, 127);
            strncat(aux->info.cadena2, " ", 1);
            strncat(aux->info.cadena2, info.cadena2, 127);
            aux->info.thisreal += info.thisreal;
            return 1;
        }
    }
    return 1;
}

int busnodo(INFO info, ARBOL arbol) {
    while(arbol != NULL) {
        if(cominformacion(arbol->info, info)) return 1;

        if(info.entero1 < arbol->info.entero1) 
            arbol = arbol->izq;
        else if(info.entero1 > arbol->info.entero1) 
            arbol = arbol->der;
        else {
            if(info.entero2 < arbol->info.entero2) 
                arbol = arbol->izq;
            else 
                arbol = arbol->der;
        }
    }
    return 0;
}