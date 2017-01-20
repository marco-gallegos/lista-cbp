
#include "lista.h"

int main()
{
    Lista<string> mi_lista;
    //hardcodenado como pro :v
    //mi_lista.insertar("hola");
    //mi_lista.insertar("hola2");
    //mi_lista.insertar("hola3");
    int opc = 1, pos_eliminar;
    string para_insertar;
    string para_eliminar;
    while(opc != 6)
    {
        cout<<"1 - insertar 2 - eliminar 3 - ver 4 - iterar 6 - salir "<<endl;
        cin>>opc;cin.ignore();
        switch (opc) {
        case 1:
            cout<<"dame un string : ";getline(cin,para_insertar);
            mi_lista.insertar(para_insertar);
            break;
        case 2:

                cout<<"1 - por un dato igual 2 - por posicion 3 - el ultimo en la lista "<<endl;
                cin>>opc;cin.ignore();
                switch (opc) {
                case 1 :
                    cout<<"dame un string : ";getline(cin,para_eliminar);
                    mi_lista.eliminar(para_eliminar);
                    break;
                case 2:
                    cout<<"posicion : ";cin>>pos_eliminar;cin.ignore();
                    mi_lista.eliminar(pos_eliminar);
                    break;
                case 3:
                    mi_lista.eliminar();
                    break;
                default:
                    break;
                }

            break;
        case 3:
            mi_lista.mostrar();
            break;
        default:
            cout<<"opcion invalida ";
            break;
        }
    }

    //return a.exec();
}

