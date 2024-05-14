#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

void colocarPrim(Node **p, string nom){
    push(p,nom);
}

void colocarUlt(Node **p, string nom){
    if((*(p))){
        string name = pop(p);
        colocarUlt(p,nom);
        push(p,name);
    }
    else
        push(p,nom);
}

void imprimir(Node *p){
    string name;
    if(!validate(p)){
        cout << p->nombre << endl;
        name = pop(&p);
        imprimir(p);
        push(&p,name);
    }
}

int main(){
    int op = 0, cont = 0;
    string nombre;
    Node *p = NULL;
    while (op != 4){
        int num = 0;
		system ("cls");
		cout<<"\tMENU COLAS \n"<<endl;
		cout<<"\t1. Agregar documento a imprimir \n";
        cout<<"\t2. Desapilar Documento\n";
        cout<<"\t3 Imprimir la Cola\n";
        cout<<"\t4. Salir\n";
        cout<<"\t";
		cin >> op;
		switch(op){
			case 1:
				system("cls");
                if(cont != 5){
                    cout << "Nombre del documento" << endl;
                    cin >> nombre;
                    while((num != 1) && (num !=2)){
                        cout << "\nPrioridad del documento"<< endl;
                        cout << "1. Prioritario" << endl;
                        cout << "2. No Prioritario"<< endl;
                        cout << "opcion: "; cin >> num;
                        if((num != 1) && (num != 2)){
                            cout << "ERROR Opcion invalida, intente nuevamente" << endl;
                        }
                    }
                    if(num == 1){
                        colocarPrim(&p,nombre);
                        cont ++;
                    }
                    else{
                        colocarUlt(&p,nombre);
                        cont++;
                    }
                }
                else{
                    cout << "LO SENTIMOS!! la cola de impresion esta llena intente en otro momento" << endl;
                }
                system("pause");
			break;
			case 2:
                system("cls");
                if(!validate(p)){
                    string aux = pop(&p);
                    cont --;
                }
                else{
                    cout<<"La pila esta vacia"<<endl;
                }
                system("pause");
			break;
			case 3:
				system("cls");
                if(!validate(p)){
                    imprimir(p);
                }
                else{
                    cout<<"LA pila ESTA VACIA"<<endl;
                }
                system("pause");
            break;
            case 4:
                system("cls");
                cout<<"SALIENDO...\n\n";
                system("pause");
            break;
            default:
                cout<<"ERROR OPCION NO VALIDA. Intente nuevamente"<<endl;
                system("pause");
            break;
		}
	}
    return 0;
}