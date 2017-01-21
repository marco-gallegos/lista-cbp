#ifndef PACIENTE_H
#define PACIENTE_H
#include<iostream>
#include<string>
using namespace std;
class Paciente
{
    public:
        Paciente();
        Paciente(Paciente &a_copiar);
        virtual ~Paciente();
        string nss,nombre,padecimiento;
        int edad;

        Paciente operator=(const Paciente &a_copiar);
        bool operator==(const Paciente &a_comparar);
        bool operator!=(const Paciente &a_comparar);
        friend ostream& operator<<(ostream &out,const Paciente &a_mostrar);
        friend istream& operator>>(istream &in, Paciente &a_introducir);
    protected:

    private:
};


#endif // PACIENTE_H
