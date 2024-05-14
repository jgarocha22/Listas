#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

struct nodo{
    long int cedula;
    struct nodo *proximo;
};
//lista simplemente enlazada

typedef struct nodo *PointerCola;

PointerCola crearCola(){
	PointerCola aux = NULL;
	return aux;
}

bool esVacia(PointerCola cola) {
    bool log = false;   
    if (cola == NULL)
        log = true;
    return log;
}

PointerCola BuscarCola(PointerCola cola, long int cedula){
	PointerCola aux = cola;
	while((aux!=NULL)&&(cedula != aux->cedula)){
		aux=aux->proximo;
	}
	return (aux);
}

/*ENCOLAR PRIMERO DESENCOLAR ULTIMO*/

void EncolarPri(PointerCola &cola, long int elemento) {
    if (cola == NULL){
        cola->cedula = elemento;
        cola->proximo = NULL;
    }
    else {
        cola->cedula = elemento;
        cola->proximo = cola;        
    }   
}

void DesencolarUlt(PointerCola & cola){
    PointerCola aux = cola->proximo;
    if (cola->proximo ==NULL)
        cola = NULL;           
    else{
        PointerCola aux = cola;
        while(aux->proximo->proximo != NULL)
            aux = aux->proximo;
        PointerCola q = aux->proximo;
        aux->proximo = NULL;
            delete(q);
    }
}

PointerCola ElementoUlt(PointerCola cola) { //devuelve el próximo nodo a desencolar
    PointerCola aux = cola; 
    while(aux->proximo != NULL) 
        aux = aux->proximo;
    return aux;
}

/*ENCOLAR ULTIMO DESENCOLAR PRIMERO*/

void EncolarUlt(PointerCola & cola, long int elemento) {
    if (cola == NULL){
        cola->cedula = elemento;
        cola->proximo = NULL;
    }
    else {
        PointerCola aux = cola;
        PointerCola q = crearCola();
        while (aux->proximo != NULL) aux = aux->proximo;
        q->cedula = elemento;
        aux->proximo = q;
        q->proximo = NULL;
    }
}

void DesencolarPri(PointerCola & cola){
    PointerCola aux = cola;
    cola = cola->proximo;
    delete(aux);
}

PointerCola ElementoPri(PointerCola cola) { //devuelve el próximo nodo a desencolar
    return cola;
}

void GenerarCola(PointerCola &cola, int veces){
	int x;
    PointerCola aux = cola;
    srand(time(NULL));
    for (int i=0 ; i<veces ; i++){
        x = (rand() % 9) + 1 ;
        EncolarUlt(aux,x);
    }
}

void ImprimirCola(PointerCola cola){
	PointerCola aux;
	aux = cola;
    int i = 1;
    cout << "\tLISTA:\n\n";
    cout << left << setw(5) << "|Nro." << setw(20) << "|Cedula" <<endl;
    cout << "------------------------------------------------"<<endl;
    if (aux)
    {
        while (aux)
        {
            cout << left << setw(6) << i << setw(20) << aux->cedula <<endl;
            cout << endl;
            aux = aux->proximo;
            i++;
        }
    }
    else
    {
        cout << "La COLA se encuentra vacia." << endl;
    }
    cout << endl;
}

void MenuCola(PointerCola &cola){
    int op = 0;
    while (op != 8){
		system ("cls");
		cout<<"\tMENU COLAS \n"<<endl;
		cout<<"\t1. Generar Cola aleatoriamente \n";
		cout<<"\t2. Agregar Numero al final de la Cola \n";
		cout<<"\t3. Agregar Numero al inicio de la Cola \n";
        cout<<"\t4. Buscar elemento en la Cola \n";
        cout<<"\t5. Desencolar el primer elemento";
        cout<<"\t6. Desencolar el ultimo elemento";
        cout<<"\t7. Imprimir la Cola";
        cout<<"\t8. Salir";
        cout<<"\t";
		cin >> op;
		switch(op){
			case 1:
				system("cls");
                int veces;
                cout<<"Introduzca la longitud de la Cola"<<endl;
                cin >> veces; //= validarEntero();
				GenerarCola(cola,veces);
                system("pause");
				break;
			case 2:
				system("cls");
                long int n = 0;
                cout<<"Introduzca el numero a insertar al final de la cola"<<endl;
                cin >> n; //= validarEntero();
				EncolarUlt(cola,n);
                system("pause");
				break;
			case 3:
				system("cls");
				int n = 0;
                cout<<"Introduzca el numero a insertar al principio de la cola"<<endl;
                cin >> n; //= validarEntero();
				EncolarPri(cola,n);
                system("pause");
                break;
            case 4:
                system("cls");
                long int n = 0;
                if(!esVacia(cola)){
                    cout<<"Introduzca el Elemento a buscar"<<endl;
                    cin >> n; //= validarEntero();
                    BuscarCola(cola,n);
                }
                else{
                    cout<<"LA COLA ESTA VACIA"<<endl;
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if(!esVacia(cola)){
                    DesencolarPri(cola);
                }
                else{
                    cout<<"LA COLA ESTA VACIA"<<endl;
                }
                system("pause");
                break;
            case 6:
                system("cls");
                if(!esVacia(cola)){
                    DesencolarUlt(cola);
                }
                else{
                    cout<<"LA COLA ESTA VACIA"<<endl;
                }
                system("pause");
                break;
            case 7:
                system("cls");
                if(!esVacia(cola)){
                    ImprimirCola(cola);
                }
                else{
                    cout<<"LA COLA ESTA VACIA"<<endl;
                }
                system("pause");
            case 8:
                system("cls");
                cout<<"SALIENDO...";
                system("pause");
                break;
            default:
                cout<<"ERROR OPCION NO VALIDA. Intente nuevamente"<<endl;
                system("pause");
                break;
		}
	}
}