#include <iostream>
#include <cstring>
#include "persona.h"

using namespace std;


Persona::Persona():_eliminado(false)(){}


void Persona::setDni(int dni)
{
    _dni=dni;
}

int Persona::getDni()
{
    return _dni;
}

void Persona::setEliminado(bool eliminado)
{
    _eliminado=eliminado;
}

bool Persona::getEliminado()
{
    return _eliminado;
}

void Persona::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}

void Persona::setApellido(const char* apellido)
{
    strcpy(_apellido, apellido);
}

Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}
