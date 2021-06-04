#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int referencia; // este es el indice que tiene el nodo en el array
    int peso;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;
typedef struct {
    int etiqueta; //el nombre propiamente dicho del nodo
    TLista adyacentes; //puntero a la lista
}array;

int main(){

    return 0;
}
/*5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice
6. Resolver el ejercicio anterior suponiendo que el digrafo está almacenado en una lista de
adyacencia*/

int gradoSalida(array lista[],int vertice){
    TLista aux = lista[vertice-1].adyacentes; // me paro en la cabecera de la lista del vertice
    int cont=0;
    while (aux!=NULL){
        cont++; //cuento las aristas que salen del nodo
        aux=aux->sig;
    }
    
    return cont;
}

int gradoEntrada(array lista[],int vertice,int orden){
    TLista aux; int cont=0;
    for(int i=0;i<orden;i++){
        aux=lista[i].adyacentes;
        while (aux!=NULL){
            if (aux->referencia==vertice-1) //si me encuentro con la referencia de mi vertice, cuento
                cont++; //son las aristas que entran al vertice
            aux = aux->sig; //paso al siguiente elemento de la lista
        }
    }
    return cont;
}

int gradoTotal(array lista[],int vertice,int orden){
    TLista aux; int cont=0;
    for(int i=0;i<orden;i++){
        aux=lista[i].adyacentes;
        while (aux!=NULL){
            if (aux->referencia==vertice-1 || i==vertice-1) //flexibilizo el criterio de busqueda
                cont++; //cuento si aparece en la lista de otro nodo y los elementos de la lista del vertice
            aux=aux->sig;
        }
    }
    return cont;
}