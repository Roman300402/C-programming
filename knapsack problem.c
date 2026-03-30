
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>


int mochi(int i,int j);
int items,i,j,C,condi[20],valor[20],peso[20],t[20][20];//Tenemos una cantidad finita de elementos por lo tanto esta acotado el problema.
int max(int i,int j);


int main(int argc, char *argv[]){
	system("color 30");
	
    printf("\t\t\t*****PROBLEMA DE LA MOCHILA*****\n");
	printf("\nDigite el numero de los elementos:");
	scanf("%d",&items);//COLUMNAS DE LA MATRIZ
	printf("\nEscriba la capacidad de la mochila:");
	scanf("%d",&C);//FILAS


	for (i=1;i<=items;i++) {//Solicita la informacion de beneficio y peso de cada item
		system("cls");
		 printf("\t\t\t\t*****PROBLEMA DE LA MOCHILA*****\n");
		printf("Elemento numero %d\n",i);
		printf("Escriba el beneficio:");
		scanf("%d",&valor[i]);
		printf("Escriba el peso:");
		scanf("%d",&peso[i]);
	}
	system("cls");
	 printf("\t\t\t*****PROBLEMA DE LA MOCHILA*****\n");
	 items=items+1;
     C=C+1;
	int benefi,MKP[items][C];
 
 for(i=0;i<C;i++){
 	MKP[0][i]=0;
 	if(i<items){
 		MKP[i][0]=0;
	 }
 }		
 for(i=1;i<=items-1;++i){
    for(j=1;j<=C-1;++j){
    	if(j-peso[i]<0){
    			MKP[i][j]=MKP[i-1][j];
		}
		else{	
        MKP[i][j]= max(MKP[i-1][j], MKP[i-1][j-peso[i]] + valor[i]);
    	}
    }
 }
 
 //imprime matriz
 
 printf("Matriz solucion con n=Numero de Elementos+1 y m = Capacidad de la mochila +1");
printf("\n");
 int may=-1,V=0;
 for( i=0;i<items;++i){
    for(j=0;j<C;++j){
    	printf("%2d",MKP[i][j]);printf("  ");
    	if(MKP[i][j]>may){
    		may=MKP[i][j];
    		V=MKP[i][j];
		}
    	
    }
    printf("\n");
}

items=items-1;
C=C-1;
	for (i=0;i<=items;i++)
	
	  for (j=0;j<=C;j++)
	   if((i==0)||(j==0))
	    t[i][j]=0; else
	    t[i][j]=-1;
	benefi=mochi(items,C);
	i=items;
	j=C;
	while(j!=0&&i!=0) {
		if(t[i][j]!=t[i-1][j]) {
			condi[i]=1;
			j=j-peso[i];
			i--;
		} else
		   i--;
	}
	printf("\nLos elementos que maximizan el beneficio en la mochila son:\n");
	printf("\t\tPeso(W)\tBeneficio\n");
	for (i=1;i<=items;i++){
	
	  if(condi[i]){ //Este codicional nos permite mostrar solo los items que estaran dentro de la mochila
	   printf("\t\t%d\t%d\n",peso[i],valor[i]);
	   }
}
	   
	   
	printf("El beneficio total = %d\n",benefi);
return 0;
}


int max(int i,int j) {
	return ((i>j)?i:j);
}

int mochi(int i,int j) {
	int eval;
	if(t[i][j]<0) {
		if(j<peso[i])
		   eval=mochi(i-1,j); else
		   eval=max(mochi(i-1,j),valor[i]+mochi(i-1,j-peso[i]));
		t[i][j]=eval;
	}
	return(t[i][j]);
}




