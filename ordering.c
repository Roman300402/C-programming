/***************
Dominguez Solis Roman
Grupo:4FM1
Programacion II
METODOS DE BUSQUEDA Y ORDENAMIENTO
****************/
//Bibliotecas 
#include <stdio.h>//
#include <stdlib.h>//
#include <assert.h>//proporciona la funcion macro llamada assert
#include <stdbool.h>//nos permite utilizar las variables de tipo booleanas
//Metodos de busqueda
int searchLineal(int list[], int m, int elemen);
int searchBinari(int list[], int low, int up, int elemen);
bool arregloHas[100][4];
bool searchHashing(int N);
//Metodos de ordenamiento 
int OrdInteDirec(int arre1[], int m);//met.intercambio directo
void OrdSeleDirec(int arre[], int tamano);//met.seleccion directa
void OrdInserDirec (int arreB[], int m);//met.insercion directa
void OrdQuick(int arre[], int movleft, int movright, int m);//met.quicksort
void OrdShell(int arreB[], int m);//met.shellsor
typedef int TipoDato;
typedef int(*Comparre)(const void *arre1, const void *arre2);
int Heap_comp_Asce(const void *arre1, const void *arre2);
int Heap_comp_Des(const void *arre1, const void *arre2);
void OrdHeap(TipoDato *arreglo, int dimen, Comparre cmp);//met.heapsort
void OrdMergesort(int arreglo[], int movleft,int movright, int m);//met.Mergesort
int printarreglo(int arreglo[], int m);
int samearreglo(int arreglo[], int aux[], int m);
int Parti(int arre[], int movleft, int movright, int m);
void Merge(int arreglo[], int movleft,int medio,int movright, int m);
void auxbin(int arreglo[], int movleft,int movright, int m);
void auxbin2(int arreglo[], int movleft,int medio,int movright, int m);
int printarreglo2(int arreglo[], int m);
void insertar(int arre1[], int m);

int main(){
    int  opc, salir=0,v[70], valaux[70], m, i, j, elemen, p;
    
    printf("\t\t\t\tMetodos de busqueda y Metodos de ordenamiento\n");
    printf("Digite el numero de elementos a ingresar:"); 
	scanf("%d", &m);
    for(i=0; i<m; i++){
    printf("Digite el elemento numero %d:", i+1); 
	scanf("%d", &v[i]);
    }
    samearreglo(v, valaux, m);

  do{
    	system("cls");
    	printf("\t\t\t\tMetodos de busqueda y Metodos de ordenamiento\n");
        printf("\nQue metodo desea realizarle al arreglo ya ingresado? \n\t\tMenu\n0-Salir del programa.\n\tMetodos de Busqueda.\n1-Lineal.\n2-Binaria.\n3-Hash.\n\tMetodos de Ordenamiento.\n4-Intercambio directo.\n5-Seleccion directa.\n6-Insercion directa.\n7-Shellsort.\n8-Heapsort.\n9-Quicksort.\n10-Mergesort\n11-Arreglo generado.\nDigite la opcion que quiera ejecutar:");
		scanf("%d", &opc);
        samearreglo(valaux, v, m);
        switch(opc){
        	case 0:
                printf("");
                salir=1;
                break;
            case 1:
            	system("cls");
                printf("****Busqueda lineal****\n");
				printf("Digite el elemento a buscar:");
				scanf("%d", &elemen);
				p = searchLineal(v, m, elemen);
				if(p>=0){
					printf("La posicion del elemento es %d.\nUbicado:\n", p);
					printarreglo(v, m);
					j=0;
					while(j<p){
						printf("\t");
						j++;
					}
					printf("^-<-<-<-<-\n\n");
				}else{
					printf("El elemento ingresado no esta en el arreglo.\n\n");
				}
                break;
            case 2:
            	system("cls");
                printf("\n****Busqueda binaria****\n");
                auxbin(v, 0,m-1, m);
                printf("\norden\n");
                sleep(2);
                printf("Digite el elemento a buscar:"); 
				scanf("%d", &elemen);
				p = searchBinari(v, 0, m, elemen);
				if(p>=0){
					printf("La posicion del elemento es %d.\nUbicado:\n", p);
					printarreglo(v, m);
					j=0;
					while(j<p){
						printf("\t");
						j++;
					}
					printf("^-<-<-<-<-\n\n");
				}else{
				printf("El elemento ingresado no esta en el arreglo.\n\n");
				}
                break;
            case 3:
            	system("cls");
            	insertar(v, m);
                printf("\n****Busqueda searchHashing****\n\n");
                printf("Digite el elemento:");
				scanf("%d", &elemen);
                if (searchHashing(elemen) == true)
					printf("El elemento esta contenido en el arreglo\n\n");
				else
					printf("El elemento no esta contenido en el arreglo\n\n");
                break;
            case 4:
            	system("cls");
                printf("\n****Ordenamiento por intercambio directo****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdInteDirec(v, m);
                break;
            case 5:
            	system("cls");
                printf("\n****Ordenamiento por seleccion directa****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdSeleDirec(v, m);
                break;
            case 6:
            	system("cls");
                printf("\n****Ordenamiento por insercion directa****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdInserDirec(v, m);
                break;
            case 7:
            	system("cls");
                printf("\n**** Ordenamiento shellsort****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdShell(v, m);
                break;
            case 8:
            	system("cls");
                printf("\n****Ordenamiento heapsort****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdHeap(v, m, Heap_comp_Des);
                break;
            case 9:
            	system("cls");
                printf("\n****Ordenamiento quicksort****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdQuick(v, 0, m-1, m);
                break;
            case 10:
            	system("cls");
                printf("\n****Ordenamiento mergesort****\n");
                sleep(2);
                printarreglo2(v, m);
                OrdMergesort(v, 0,m-1, m);
                break;
            case 11:
                system("cls");
                printf("El arreglo que ha generado es:\n");
    	        printarreglo(valaux, m);
    	        break;
            default:
                printf("La opcion ingresada es invalida");
                break;
        }
        system("pause");
    }while(salir==0);
    return 0;
}
/*Funciones auxuiliares*/
int samearreglo(int arreglo[], int valaux[], int m){
    int i;
    for(i=0; i<m; i++){
        valaux[i]=arreglo[i];
    }
    return 0;
}

int printarreglo(int arreglo[], int m){
    int i;
    for(i=0; i<m; i++){
        if(i==0){
            printf("|%d |\t", arreglo[i]);
        }else{
        if(i==m-1){
            printf("%d|", arreglo[i]);
        }else{
            printf("%d|\t", arreglo[i]);
        }}
    }
    printf("\n");
    return 0;
}
int printarreglo2(int arreglo[], int m){
    int i, j;
    system("cls");
    for(i=0; i<m; i++){
        for(j=0; j<arreglo[i]; j++){
        	printf("+");
		}
		printf("\n");
    }
    sleep(1);
    return 0;
}
void intercambiar(int *arre1, int *arre2){
  int temporal = *arre1;
  *arre1 = *arre2;
  *arre2 = temporal;
}
/***Metodos de ordenamiento******/
int OrdInteDirec (int arre1[], int m){
    int i, j;
    for (i = 0 ; i < m-1 ; i++){
        for (j = i+1 ; j < m ; j++){
            if (arre1[i] > arre1[j]){
                intercambiar(&arre1[i], &arre1[j]);
                printarreglo2(arre1, m);
            }
        }
    }
    return 0;
}

void OrdSeleDirec(int arre[], int tamano){
	int i, j;
  for(i = 0; i < tamano - 1; i++){
    for (j = i + 1; j < tamano; j++) {
     
      if (arre[i] > arre[j]) {
        intercambiar(&arre[i], &arre[j]);
        printarreglo2(arre, tamano);
      }
    }
  }
}
void OrdInserDirec (int arreB[], int m){
    int i, j, valaux;
    for (i = 1; i < m; i++){
        j = i;
        valaux = arreB[i];
        while (j > 0 && valaux < arreB[j-1]){
            arreB[j] = arreB[j-1];
            j--;
        }
        arreB[j] = valaux;
        printarreglo2(arreB, m);
    }
}

void OrdShell(int arreB[], int m){
    int i, j, k, salto = m/2;
    while (salto > 0){               //SALTO DE LISTA   
        for (i = salto; i < m; i++){ //ORDEN PARCIAL DE LOS ELEMENTOS

            j = i - salto;
            while(j >= 0){
                k = j + salto;
                if (arreB[j] <= arreB[k]) 
                    j = -1; 
                else{
                    intercambiar(&arreB[j], &arreB[k]);
                    j = j - salto;
                    printarreglo2(arreB, m);
                }
            }
        }   
        salto = salto / 2;
    }
}
//heapsort//
void HS_swap(TipoDato *arre1, TipoDato *arre2)
{
    TipoDato temp = *arre1;
    *arre1 = *arre2;
    *arre2 = temp;
}


int Heap_comp_Asce(const void *arre1, const void *arre2)
{
    return *(TipoDato*)arre1 - *(TipoDato*)arre2;
}


int Heap_comp_Des(const void *arre1, const void *arre2)
{
    return *(TipoDato*)arre2 - *(TipoDato*)arre1;
}

void HS_Adjust(TipoDato *arreglo, int dimen, int parent, Comparre cmp)
{
    int child = parent * 2 + 1;
    assert(arreglo);

    while (child < dimen)
    {
        if ((child + 1) < dimen && cmp(&arreglo[child], &arreglo[child + 1]) > 0)
        {
            child += 1;
        }
        if (arreglo[parent] < arreglo[child])
        {
            HS_swap(&arreglo[parent], &arreglo[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            return;
        }
    }
}


void OrdHeap(TipoDato *arreglo, int dimen, Comparre cmp){
    int end = dimen - 1;
    // CONSTRUCCION DEL MONTON
    int root = ((dimen - 1) - 1) >> 1;
    for (; root >= 0; --root)
    {
        HS_Adjust(arreglo, dimen, root, cmp);
    }
    //ORDEN 
    while (end)
    {
        HS_swap(&arreglo[0], &arreglo[end]);
        HS_Adjust(arreglo, end, 0, cmp);
        --end;
        printarreglo2(arreglo, dimen);
    }
}


int Parti(int arre[], int movleft, int movright, int m) {
  int pivote = arre[movleft];
  while (1) {
    while (arre[movleft] < pivote) {
      movleft++;
    }
    while (arre[movright] > pivote) {
      movright--;
    }
    if (movleft >= movright) {
      return movright;
    } else {
      intercambiar(&arre[movleft], &arre[movright]);
      movleft++;
      movright--;
      printarreglo2(arre, m);
    }
  }
}
void OrdQuick(int arre[], int movleft, int movright, int m){
  if (movleft < movright) {
    int indiceParticion = Parti(arre, movleft, movright, m);
    OrdQuick(arre, movleft, indiceParticion, m);
    OrdQuick(arre, indiceParticion + 1, movright, m);
  }
}

void OrdMergesort(int arreglo[], int movleft,int movright, int m){
    int medio;
    if(movleft<movright){
        medio=(movleft+movright)/2;
        OrdMergesort(arreglo, movleft,medio, m);
        OrdMergesort(arreglo, medio+1,movright, m);
        Merge(arreglo, movleft,medio,movright, m);
    }
}
void Merge(int arreglo[], int movleft,int medio,int movright, int m){
    int h,i,j,arre2[50],k;
    h=movleft;
    i=movleft;
    j=medio+1;
    
    while((h<=medio)&&(j<=movright)){
        if(arreglo[h]<=arreglo[j]){
            arre2[i]=arreglo[h];
            h++;
        }
        else
            {
                arre2[i]=arreglo[j];
                j++;
            }
        i++;
    }
    if(h>medio){
        for(k=j;k<=movright;k++){
            arre2[i]=arreglo[k];
            i++;
        }
    }
    else
        {
            for(k=h;k<=medio;k++){
                arre2[i]=arreglo[k];
                i++;
            }
        }
    for(k=movleft;k<=movright;k++){
        arreglo[k]=arre2[k];
        }
    printarreglo2(arreglo, m);
}

//***Metodos de busqueda******//
int searchLineal(int list [], int m, int elemen){
	int i;
	for(i = 0; i < m; i++)
		if(list[i] == elemen)
		return i;
	return -1;
}
int searchBinari(int list[], int low, int up, int elemen){
	int central, valorCentral;
	while(low <= up){
		central = (low + up)/2; // ELEMENTO CENTRAL
		valorCentral = list[central]; 
		if (elemen == valorCentral)
			return central; 
		else if (elemen < valorCentral)
			up = central -1; 
		else
			low = central + 1; 
	} 
	return -1;
}
bool searchHashing(int N)
{
	if (N >= 0) {
		if (arregloHas[N][0] == 1)
			return true;
		else
			return false;
	}
	N = abs(N);
	if (arregloHas[N][1] == 1)
		return true;

	return false;
}
void insertar(int arre1[], int m)
{
	int i=0;
	for (i = 0; i < m; i++) {
		if (arre1[i] >= 0)
			arregloHas[arre1[i]][0] = 1;
	else
			arregloHas[abs(arre1[i])][1] = 1;
	}
}
void auxbin(int arreglo[], int movleft,int movright, int m){
    int medio;
    if(movleft<movright){
        medio=(movleft+movright)/2;
        auxbin(arreglo, movleft,medio, m);
        auxbin(arreglo, medio+1,movright, m);
        auxbin2(arreglo, movleft,medio,movright, m);
    }
}
void auxbin2(int arreglo[], int movleft,int medio,int movright, int m){
    int h,i,j,arre2[50],k;
    h=movleft;
    i=movleft;
    j=medio+1;
    
    while((h<=medio)&&(j<=movright)){
        if(arreglo[h]<=arreglo[j]){
            arre2[i]=arreglo[h];
            h++;
        }
        else
            {
                arre2[i]=arreglo[j];
                j++;
            }
        i++;
    }
    if(h>medio){
        for(k=j;k<=movright;k++){
            arre2[i]=arreglo[k];
            i++;
        }
    }
    else
        {
            for(k=h;k<=medio;k++){
                arre2[i]=arreglo[k];
                i++;
            }
        }
    for(k=movleft;k<=movright;k++){
        arreglo[k]=arre2[k];
        }
}

