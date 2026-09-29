#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct n {
    int id;
    struct n *izq;
    struct n *der;
}nodo;

nodo *raiz;

nodo *crear_nodo(int x){
	nodo *nuevo;
	nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->id=x;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	return nuevo;
}

void insertar(int x){
	nodo *nuevo;
	nodo *anterior,*actual;
	nuevo = crear_nodo(x);
	if(raiz==NULL)
		raiz=nuevo;
	else
	{
		anterior=NULL;
		actual=raiz;
		while(actual!=NULL){
			anterior=actual;
			if(x<actual->id)
				actual=actual->izq;
			else
				actual=actual->der;	
		}
		if(x<anterior->id)
			anterior->izq = nuevo;
		else
			anterior->der = nuevo;	
	}
}

void imprimir_Preorden(nodo *actual){
	if(actual!=NULL){

		printf(" %d ",actual->id);
		imprimir_Preorden(actual->izq);
		imprimir_Preorden(actual->der);
	}
}

void imprimir_Postorden(nodo *actual){
	if(actual!=NULL){
		imprimir_Postorden(actual->izq);
		imprimir_Postorden(actual->der);
		printf(" %d ",actual->id);
	}
}

void imprimir_Inorder(nodo *actual){
	if(actual!=NULL){
		imprimir_Inorder(actual->izq);
		printf(" %d ",actual->id);
		imprimir_Inorder(actual->der);
	}
}

int buscar (int id){
	nodo *aux;
	if(raiz==NULL)
		return 0;
	aux=raiz;
	while(aux!=NULL){
		if(id<aux->id)
			aux = aux->izq;
		else if(id>aux->id)
			aux = aux->der;
		else
			return 1;
	}
	return 0;
}

int buscar_r (int id,nodo *actual){
	if(actual==NULL)
		return 0;
	if(id == actual->id)
		return 1;
	if(id<actual->id)
		return buscar_r(id,actual->izq);
	else
		return buscar_r(id,actual->der);
}

void borrar_arbol(nodo *actual){
	if(actual!=NULL){
		borrar_arbol(actual->izq);
		borrar_arbol(actual->der);
		free(actual);
	}
}

void borrar_nodo(int id,nodo *actual){
	if(actual==NULL)
		return 0;
	if(id == actual->id)
		return 1;
	if(id<actual->id)
		return borrar_nodo(id,actual->izq);
	else
		return borrar_nodo(id,actual->der);
}

int main(){

	insertar(10);
	insertar(4);
	insertar(6);
	insertar(2);
	insertar(34);
	insertar(1);
	insertar(0);
	printf("\n");
	imprimir_Preorden(raiz);
	printf("\n");
	imprimir_Postorden(raiz);
	printf("\n");
	imprimir_Inorder(raiz);
	
	printf("\n");
	printf(" %d %d\n",buscar(34),buscar(30));
	
	printf(" %d %d\n",buscar_r(34,raiz),buscar_r(0,raiz));
	
	//borrar_arbol(raiz);
	//printf(" %p \n",raiz);

	
}
