#include "Paciente.h"

Paciente::Paciente(){
    //ctor
}

Paciente::Paciente(Paciente &a_copiar){
    this->edad = a_copiar.edad;
    this->nombre = a_copiar.nombre;
    this->nss = a_copiar.nss;
    this->padecimiento = a_copiar.padecimiento;
}

Paciente::~Paciente(){
    //dtor
}

istream &operator>>(istream &in,Paciente &a_introducir){
    cout<<"nombre       : ";
    getline(in, a_introducir.nombre);
    cout<<"nss          : ";
    getline(in, a_introducir.nss);
    cout<<"padecimiento : ";
    getline(in, a_introducir.padecimiento);
    cout<<"edad         : ";
    in>>a_introducir.edad;in.ignore();
    return in;
}

ostream &operator<<(ostream &out,const Paciente &a_mostrar){
    out<<"nombre       : "<<a_mostrar.nombre<<"\t";
    out<<"nss          : "<<a_mostrar.nss<<"\t";
    out<<"padecimiento : "<<a_mostrar.padecimiento<<"\t";
    out<<"edad         : "<<a_mostrar.edad<<"\t";
    return out;
}

Paciente Paciente::operator=(const Paciente &a_copiar){
    this->edad = a_copiar.edad;
    this->nombre = a_copiar.nombre;
    this->nss = a_copiar.nss;
    this->padecimiento = a_copiar.padecimiento;
    return *this;
}

bool Paciente::operator==(const Paciente &a_comparar){
    if(this->nombre == a_comparar.nombre && this->nss == a_comparar.nss){
        return true;
    }
    return false;
}

bool Paciente::operator!=(const Paciente &a_comparar){
    if(this->nombre == a_comparar.nombre && this->nss == a_comparar.nss){
        return false;
    }
    return true;
}
