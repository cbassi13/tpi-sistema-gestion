#include <iostream>
#include <cstring>
#include "persona.h"

using namespace std;

Persona::Persona(): _eliminado(false) {}

Persona::Persona(int dni, const char* nombre, const char* apellido, const char* email,
                 const char* telefono, const char* direccion, Fecha fechaNacimiento)
{
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setTelefono(telefono);
    setDireccion(direccion);
    setFechaNacimiento(fechaNacimiento);
    _eliminado = false;
}

void Persona::setDni(int dni)
{
    _dni = dni;
}

int Persona::getDni()
{
    return _dni;
}

void Persona::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}

const char* Persona::getNombre()
{
    return _nombre;
}

void Persona::setApellido(const char* apellido)
{
    strcpy(_apellido, apellido);
}

const char* Persona::getApellido()
{
    return _apellido;
}

void Persona::setEmail(const char* email)
{
    strcpy(_email, email);
}

const char* Persona::getEmail()
{
    return _email;
}

void Persona::setTelefono(const char* telefono)
{
    strcpy(_telefono, telefono);
}

const char* Persona::getTelefono()
{
    return _telefono;
}

void Persona::setDireccion(const char* direccion)
{
    strcpy(_direccion, direccion);
}

const char* Persona::getDireccion()
{
    return _direccion;
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}

Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}

void Persona::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

bool Persona::getEliminado()
{
    return _eliminado;
}
