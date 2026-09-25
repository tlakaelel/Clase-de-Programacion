#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef unsigned char byte;

typedef struct comparte
{
	char nombre[50];
	char direccion[50];
	int  edad;
	struct comparte *next;
	struct comparte *prev;
}Registro; 

typedef struct l
{
	Registro *Inicial;
	Registro *Final;
	int len;
}Lista;


Registro *crear(){
	Registro *T;
	T = (Registro *)malloc(sizeof(Registro));
	T->next = NULL;
	T->prev = NULL;
	return T;
}

void crear_lista(Lista *lista){
	Registro *N_inicial;
	Registro *N_final;
	N_inicial = crear();
	N_final = crear();
	lista->Inicial = N_inicial;
	lista->Final = N_final;
	lista->len = 0;
	
	lista->Inicial->next=N_final;
	lista->Inicial->prev=NULL;
	
	lista->Final->prev=N_inicial;
	lista->Final->next=NULL;
}

int agregar(Lista *lista,char nombre[50],char direccion[50],int edad){
	Registro *N;
	
    N = crear();

    if(N==NULL)
		return 0;
	strcpy(N->nombre,nombre);
	strcpy(N->direccion,direccion);
	N->edad=edad;
	
	//T = N_inicial;

	N->prev = lista->Final->prev;
	N->next = lista->Final;

	lista->Final->prev->next = N;	
	lista->Final->prev = N;
	
	lista->len++;
	
	return 1;
}

void destruir_lista(Registro *N_inicial){
	Registro *Temp,*T;
	Temp = N_inicial->next;
	free(N_inicial);
	if(Temp == NULL)
		return;
	while(Temp->next != NULL){
		T = Temp->next;
		free(Temp);
		Temp = T;
	}
	free(Temp);
}

int size(Registro *N_inicial){
	Registro *p;
	int i=0;
	
	if(N_inicial->next==NULL)
		return 0;

	for(p=N_inicial;p->next!=NULL;p=p->next)
		i++;
	return i;
} 

int borrar(Lista *lista,char *nombre){
	Registro *iter;
	
	for(iter=lista->Inicial->next;iter!=lista->Final && strcmp(iter->nombre,nombre);iter=iter->next);
	if(!strcmp(iter->nombre,nombre)){
		iter->prev->next=iter->next;
		iter->next->prev=iter->prev;
		free(iter);
	}
}

void print_list(Lista *lista){
	Registro *iter;

	for(iter=lista->Inicial->next;iter!=lista->Final;iter=iter->next){
		printf("\n nombre %s \n",iter->nombre);
		printf("\n direccion %s \n",iter->direccion);
		printf("\n edad %d \n",iter->edad);
	}
}

void find_in_list(Lista *lista,char *nombre){
	Registro *iter;
	for(iter=lista->Inicial->next;iter!=lista->Final && strcmp(iter->nombre,nombre);iter=iter->next);
	printf("\n nombre %s \n",iter->nombre);
	printf("\n direccion %s \n",iter->direccion);
	printf("\n edad %d \n",iter->edad);
}

int main(){

Lista lista;

char nombre[50];
char direccion[50];
int edad;



//printf(" \n direccion_ini: %p \n",B);
crear_lista(&lista);

printf(" \n Tamaño Registro %ld\n", sizeof(Registro));
printf(" \n Direccion Inicial: %p \n",lista.Inicial);
printf(" \n Direccion Final: %p \n",lista.Final);
printf("Size: %d",lista.len);

strcpy(nombre,"Jose Ernesto");
strcpy(direccion,"Cuaupec Barrio Alto");

agregar(&lista,nombre,direccion,36);

printf(" \n Direccion Inicial.next: %p \n",lista.Inicial->next);
printf(" \n Direccion Inicial.prev: %p \n",lista.Inicial->prev);

printf(" \n Direccion Fin.next: %p \n",lista.Final->next);
printf(" \n Direccion Fin.prev: %p \n",lista.Final->prev);

printf("Size: %d \n",lista.len);

printf("\n nombre %s \n",lista.Inicial->next->nombre);
printf("\n direccion %s \n",lista.Inicial->next->direccion);
printf("\n edad %d \n",lista.Inicial->next->edad);


strcpy(nombre,"Alondra");
strcpy(direccion,"Ticoman");

agregar(&lista,nombre,direccion,22);
printf("Size: %d \n",lista.len);

strcpy(nombre,"Braulio");
strcpy(direccion,"Ticoman");

agregar(&lista,nombre,direccion,26);
printf("Size: %d \n",lista.len);

strcpy(nombre,"Francisco");
strcpy(direccion,"La Pastora");
agregar(&lista,nombre,direccion,26);
printf("Size: %d \n",lista.len);

/*
Registro *iter;
for(iter=lista.Inicial->next;iter!=lista.Final;iter=iter->next){
	printf("\n nombre %s \n",iter->nombre);
	printf("\n direccion %s \n",iter->direccion);
	printf("\n edad %d \n",iter->edad);
}

*/

print_list(&lista);
find_in_list(&lista,"Jose");

borrar(&lista,"Jose Ernesto");
printf("\n Borrando...\n");
print_list(&lista);




}
