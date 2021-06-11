#include <stdlib.h>
#include <stdio.h>
#define max 20

typedef struct nodo{
    int etiqueta;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

typedef struct{
    int grado;
    int vertice;
}TArray;
int main(){

    return 0;
}

/* Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.*/

void generaArreglo(int matriz[][max],int grados[],int i,int j,int orden){ //i,j entran con orden-1
    if (i>=0){
        if (j>0){
            if (matriz[i][j])
                grados[i]++;
            generaArreglo(matriz,grados,i,j-1,orden);
        }else{
            if (matriz[i][j])
                grados[i]++;
            generaArreglo(matriz,grados,i-1,orden-1,orden);
        }
    }
}

/*b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.*/

void mayorGradoMatriz(int matriz[][max],int i,int j,int orden,int gAct,int *vMax,int *gMax){
    if (j>=0)
        if (i==0){
            if (matriz[i][j] && gAct+1>*gMax){
                *gMax=gAct+1;
                *vMax=j+1;
            }
            mayorGradoMatriz(matriz,orden-1,j-1,orden,0,vMax,gMax); //comienzo a contar el grado de entrada de otro nodo
        }else
            if (matriz[i][j])
                mayorGradoMatriz(matriz,i-1,j,orden,gAct+1,vMax,gMax);
            else
                mayorGradoMatriz(matriz,i-1,j,orden,gAct,vMax,gMax);
}
/*c) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia.*/

void mayorEntradaLista(TLista lista[max],int grados[max],TLista aux,int i,int orden,int *gMax,int *vMax){//i entra como ORDEN
    if (i>=0){
        if (aux==NULL){ //este es el ultimo elemento de cada elemento del vector
            mayorEntradaLista(lista,grados,lista[i-1]->sig,i-1,orden,gMax,vMax);
            if (i==0){
                *gMax=grados[i];
                *vMax=i+1;
            }else
                if (i<orden && grados[i]>gMax){
                    *gMax=grados[i];
                    *vMax=i+1;
                }
        }else{
            grados[aux->etiqueta]++;
            mayorEntradaLista(lista,grados,aux->sig,i,orden,gMax,vMax);
        }
    }
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

/*e) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.*/

void generaVector(int matriz[][max],int grados[max],TArray arreglo[],int *n,int i,int j,int orden){
    if (i>=0){
        if (j>0){
            if (matriz[i][j])
                grados[i]++;
            generaVector(matriz,grados,arreglo,n,i,j-1,orden);
        }else{ //FINAL DE FILA
            if (matriz[i][j])
                grados[i]++;
            generaVector(matriz,grados,arreglo,n,i-1,orden-1,orden);
            if (grados[j]>3){
                (*n)++;
                arreglo[*n].vertice=j+1;
                arreglo[*n].grado=grados[j];
            }
        }
    }
}