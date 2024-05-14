#include <iostream>
using namespace std;

struct nodo{
	string nombre;
	int estatus;
	struct nodo *prox;
};

typedef struct nodo *Tcola;
//Tcola cola=NULL;

Tcola crearCola(){
	Tcola aux = NULL;
	return aux;
}
 
void encolar(Tcola &cola, string nombre,int valor){
	Tcola nuevo=new(struct nodo);
	nuevo->nombre=nombre;
	nuevo->estatus=valor;
	nuevo->prox=NULL;
	if(cola==NULL){
		cola=nuevo;
	}
	else{
		Tcola aux=NULL;
		aux=cola;
		while(aux->prox!=NULL){
			aux=aux->prox;
    	}
    	aux->prox=nuevo;
	}
}


void desencolar(Tcola &cola){
	Tcola aux=NULL;
	aux=cola;
	cola=cola->prox;
	delete(aux);
}

string elemento(Tcola cola){
	return(cola->nombre);
}


bool esVacia(Tcola cola) {
	if (cola==NULL){ 
		return true;
	}
	else{
		return false;
	}
} 

