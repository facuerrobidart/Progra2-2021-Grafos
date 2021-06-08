#include <stdlib.h>
#include <stdio.h>
#define max 20

typedef struct nodo{
    int etiqueta;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;
typedef struct{
    int etiqueta;
    TLista adyacentes;
}cabeceras;
int main(){

    return 0;
}

/* Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
c) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia.

e) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.*/

void generaArreglo(int matriz[][max],int grados[],int i,int j,int orden){ //i,j entran con orden-1
    if (i>0){
        if (j>0){
            if (matriz[i][j])
                grados[i]++;
            generaArreglo(matriz,grados,i,j-1,orden);
        }else{
            if (matriz[i][j])
                grados[i];
            generaArreglo(matriz,grados,i-1,orden-1,orden);
        }
    }
}

int gradoEntradaLista(cabeceras listaAdy[max],int vertice,int i, TLista aux){ //i entra con orden-1, aux en null
    if (i>=0){
        if (aux=NULL){
            return gradoEntradaLista(listaAdy,vertice,i-1,listaAdy[i-1].adyacentes);
        }else{
            
        }
    }
}

int gradoEntrada(int matriz[][max],int vertice,int i){//i entra con orden-1
    if (i>=0)
        if (matriz[i][vertice-1])
            return 1+gradoEntrada(matriz,vertice,i-1);
        else
            return gradoEntrada(matriz,vertice,i-1);
    else
        return 0;
}
/*d) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).*/
int todosMarcados(int vector[],int orden){
    int i=0;

    while (i<orden && vector[i]!=0)
        i++;
    
    return i==orden;
}
int todosTienenCosto(int matriz[][max],int costo,int i,int j,int orden,int marcados[]){ //i, j entran con orden-1
    if (i>=0 && j>=0 && !todosMarcados(marcados,orden)){
        if (matriz[i][j]>=costo){
            marcados[i]=1;
            marcados[j]=1;
        }
        return (todosTienenCosto(matriz,costo,i-1,j-1,orden,marcados)||todosTienenCosto(matriz,costo,i-1,j,orden,marcados));
    }else
        return todosMarcados(marcados,orden);
}