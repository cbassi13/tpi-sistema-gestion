#pragma once
#include <string>
#include "fecha.h"

class Persona
{
public:
    Persona();
    Persona(int dni, std::string nombre, std::string apellido, std::string email,
        std::string telefono, std::string direccion, Fecha fechaNacimiento);

    void setDni(int dni);
    int getDni() const;

    void setNombre(std::string nombre);
    std::string getNombre() const;

    void setApellido(std::string apellido);
    std::string getApellido() const;

    void setEmail(std::string email);
    std::string getEmail() const;

    void setTelefono(std::string telefono);
    std::string getTelefono() const;

    void setDireccion(std::string direccion);
    std::string getDireccion() const;

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento() const;

    void setEliminado(bool eliminado);
    bool getEliminado() const;

private:
    int _dni;
    char _email[50], _nombre[50], _apellido[50], _telefono[20], _direccion[100];
    Fecha _fechaNacimiento;
    bool _eliminado;
};
