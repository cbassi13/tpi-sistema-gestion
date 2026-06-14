#include <iostream>
#include <cstring>
#include "persona.h"

using namespace std;

Persona::Persona(): _eliminado(false) {}

Persona::Persona(int dni, std::string nombre, std::string apellido, std::string email,
    std::string telefono, std::string direccion, Fecha fechaNacimiento)
: _eliminado(false) {
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setTelefono(telefono);
    setDireccion(direccion);
    setFechaNacimiento(fechaNacimiento);
}

void Persona::setDni(int dni)
{
    _dni = dni;
}

int Persona::getDni() const
{
    return _dni;
}

void Persona::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

std::string Persona::getNombre() const
{
    return std::string(_nombre);
}

void Persona::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}

std::string Persona::getApellido() const
{
    return std::string(_apellido);
}

void Persona::setEmail(std::string email)
{
    strcpy(_email, email.c_str());
}

std::string Persona::getEmail() const
{
    return std::string(_email);
}

void Persona::setTelefono(std::string telefono)
{
    strcpy(_telefono, telefono.c_str());
}

std::string Persona::getTelefono() const
{
    return std::string(_telefono);
}

void Persona::setDireccion(std::string direccion)
{
    strcpy(_direccion, direccion.c_str());
}

std::string Persona::getDireccion() const
{
    return std::string(_direccion);
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}

Fecha Persona::getFechaNacimiento() const
{
    return _fechaNacimiento;
}

void Persona::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

bool Persona::getEliminado() const
{
    return _eliminado;
}
