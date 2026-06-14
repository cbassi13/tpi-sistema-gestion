#pragma once
#include "fecha.h"

class Persona
{
public:
    Persona();
    Persona(int dni, const char* nombre, const char* apellido, const char* email,
        const char* telefono, const char* direccion, Fecha fechaNacimiento);

    void setDni(int dni);
    int getDni();

    void setEmail(const char* email);
    const char* getEmail();

    void setNombre(const char* nombre);
    const char* getNombre();

    void setApellido(const char* apellido);
    const char* getApellido();

    void setTelefono(const char* telefono);
    const char* getTelefono();

    void setDireccion(const char* direccion);
    const char* getDireccion();

    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();

    void setEliminado(bool eliminado);
    bool getEliminado();

private:
    int _dni;
    char _email[50], _nombre[50], _apellido[50], _telefono[20], _direccion[100];
    Fecha _fechaNacimiento;
    bool _eliminado;
};
