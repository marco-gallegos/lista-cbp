#ifndef LISTA
#define LISTA
#include<iostream>

using namespace std;

template <class DATO> class Lista;

template<class DATO> class Nodo
{
public:
    //constructor sobrecargado no permite construir sin pasarle dat
    Nodo(DATO dat,Nodo<DATO> * ant=NULL, Nodo<DATO> * sig = NULL):valor(dat),anterior(ant),
        siguiente(sig) { }
    ~Nodo(){}

    DATO valor;
    Nodo<DATO> *anterior,*siguiente;

    friend class Lista<DATO>;


};

template<class DATO> ostream &operator <<(ostream &out,const Nodo<DATO> &a_mostrar)
{
    out<<a_mostrar.valor;
    return out;
}



template<class DATO> class Lista
{
public:
    Nodo<DATO> *head;
    //
    Nodo<DATO> *it;

    Lista():head(NULL),it(NULL){}
    ~Lista(){}

    void insertar(DATO a_insertar);
    //elimina el elemnto del tipo "class Dato" que le pases a la funcion
    bool eliminar(DATO a_borrar);
    //elimina el dato en la posicion pos 1 a N
    bool eliminar(unsigned int pos);
    //elimina el dato al final de la lista
    bool eliminar();
    //regresara el dato que busca
    DATO buscar(DATO &a_buscar);

    void mostrar();
    int tamano();
    void iterar();

};

template<class DATO> int Lista<DATO>::tamano()
{
    if(this->head == NULL)
    {
        return 0;
    }
    int contador = 1;
    Nodo<DATO> *it = this->head;
    while (it->siguiente != NULL)
    {
        contador ++;
        it = it->siguiente;
    }
    return contador;
}

template<class DATO> void Lista<DATO>::insertar(DATO a_insertar)
{
    if(this->head == NULL)
    {
        head = new Nodo<DATO>(a_insertar);
        return;
    }

    Nodo<DATO> *iterador= this->head;

    while(iterador->siguiente != NULL)
    {
        iterador = iterador->siguiente;
    }
    iterador->siguiente = new Nodo<DATO>(a_insertar,iterador);
    return;

}

template<class DATO> bool Lista<DATO>::eliminar(DATO a_borrar)
{
    if(this->head->valor == a_borrar)
    {
        delete this->head;
        this->head = NULL;
        return true;
    }
    Nodo<DATO> *iterador= this->head;
    Nodo<DATO> *anterior = NULL;
    if(a_borrar == this->head->valor)
    {
        this->head=this->head->siguiente;
        this->head->anterior = NULL;
        delete iterador;

        return true;
    }
    while(iterador->valor != a_borrar && iterador->siguiente != NULL)
    {
        anterior = iterador;
        iterador= iterador->siguiente;
    }
    if(iterador->valor != a_borrar)
    {
        return false;
    }
    if(iterador->siguiente == NULL)
    {
        anterior->siguiente = NULL;
        delete iterador;
        return true;
    }
    //el apuntador del nodo siguiente que lleva hacia iterador ahora apuntara hacia anterior
    iterador->siguiente->anterior = anterior;
    //el apuntador que lleva a iterador ahora apuntara a el nodo siguiente de iterador
    anterior->siguiente = iterador->siguiente;
    delete iterador;
    return true;
}

template<class DATO> bool Lista<DATO>::eliminar(unsigned int pos)
{
    unsigned int *tam = new unsigned int(this->tamano());
    //validar pos
    if(pos > *tam || *tam == 0 || pos < 1 )
    {
        return false;
    }
    if(pos == 1 && this->head->siguiente == NULL)
    {
        delete this->head;
        this->head = NULL;

        return true;
    }
    Nodo<DATO> *iterador= this->head;
    Nodo<DATO> *anterior = NULL;
    if(pos == 1 && this->head->siguiente != NULL)
    {
        this->head = this->head->siguiente;
        this->head->anterior = NULL;
        delete iterador;

        return true;
    }
    unsigned int contador = 1;
    //buscar posicion
    while(contador < pos && iterador->siguiente != NULL)
    {
        anterior = iterador;
        iterador = iterador->siguiente;
        contador ++;
    }
    if(iterador->siguiente == NULL)
    {
        anterior->siguiente = NULL;
        delete iterador;
        return true;
    }

    //el apuntador del nodo siguiente que lleva hacia iterador ahora apuntara hacia anterior
    iterador->siguiente->anterior = anterior;
    //el apuntador que lleva a iterador ahora apuntara a el nodo siguiente de iterador
    anterior->siguiente = iterador->siguiente;
    delete iterador;
    return true;

}

template<class DATO> bool Lista<DATO>::eliminar()
{
    if(this->head == NULL)
    {
        return false;
    }
    if(this->head->siguiente == NULL)
    {
        delete head;
        head= NULL;
        return true;
    }
    Nodo<DATO> *iterador= this->head;
    Nodo<DATO> *anterior = NULL;
    while(iterador->siguiente != NULL)
    {
        anterior = iterador;
        iterador = iterador->siguiente;
    }
    anterior->siguiente = NULL;
    delete iterador;
    return true;


}

template<class DATO> void Lista<DATO>::iterar()
{
    if(this->it == NULL)
    {
        this->it = this->head;
    }
    int opc = 0;
    while(opc != 6)
    {
        cout<<"1 izquieda  2 derecha 6 salir"<<endl;
        cout<<this->it->valor<<endl;
        cin>>opc;cin.ignore();
        switch (opc) {
        case 1:
            if(it->anterior == NULL)
            {
                cout<<"no hay"<<endl;
            }
            else
            {
                it=it->anterior;
            }
            break;
        case 2:
            if(it->siguiente == NULL)
            {
                cout<<"no hay"<<endl;
            }
            else
            {
                it=it->siguiente;
            }
            break;
        default:

            break;
        }
    }
}

template<class DATO> void Lista<DATO>::mostrar()
{
    if(this->head == NULL)
    {
        return;
    }
    Nodo<DATO> *iterador= this->head;
    do
    {
        cout<<iterador->valor<<" ";
        iterador=iterador->siguiente;
    }while(iterador!= NULL);
    cout<<endl;
}



#endif // LISTA
