#include "lista.h"
#include "Paciente.h"

int main()
{
    Lista<Paciente> mi_lista;
    //hardcodenado como pro :v
    //mi_lista.insertar("hola");
    //mi_lista.insertar("hola2");
    //mi_lista.insertar("hola3");
    int opc = 1, pos_eliminar;
    Paciente para_insertar;
    Paciente para_eliminar;
    Paciente para_buscar,nuevo_val;
    while(opc != 6)
    {
        cout<<"1 - insertar 2 - eliminar 3 - ver 4 - iterar 5 - actualizar 7 - salir "<<endl;
        cin>>opc;cin.ignore();
        switch (opc) {
        case 1:
            //cout<<"dame un dato : ";getline(cin,para_insertar);
            cin>>para_insertar;
            mi_lista.insertar(para_insertar);
            break;
        case 2:

                cout<<"1 - por un dato igual 2 - por posicion 3 - el ultimo en la lista "<<endl;
                cin>>opc;cin.ignore();
                switch (opc) {
                case 1 :
                    cout<<"dame un dato : ";//getline(cin,para_eliminar);
                    cin>>para_eliminar;
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
        case 4:
            mi_lista.iterar();
            break;
        case 5:
            cout<<"valor a actualizar : ";
            //getline(cin,para_buscar);
            cin>>para_buscar;
            cout<<"valor nuevo        : ";
            //getline(cin,nuevo_str);
            cin>>nuevo_val;
            mi_lista.actualizar(para_buscar, nuevo_val);
            break;
        default:
            cout<<"opcion invalida ";
            break;
        }
    }

    //return a.exec();
}

