#include <iostream>

using namespace std;

int main(){
    int op = 0;

    do{
        system("cls");
        cout << "MENU OPCIONES\n" << endl;
        cout << "1. Agregar Inicio de la lista" << endl;
        cout << "2. Agregar al Final de la lista" << endl;
        cout << "3. Mostrar la lista" << endl;
        cout << "4. SALIR." << endl;
        cout << "\nOpcion: "; cin >> op;
        switch(op){
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 4:
                cout << "\nSALIENDO..." << endl;
                cout << "\n\n"; 
                system("pause");
                system("cls");
            break;
            default:
                cout << "\nOpcion no valida vuelva a intentar" << endl;
                cout << "\n\n";
                system("pause");
            break;
        }
    }while(op != 4);
}