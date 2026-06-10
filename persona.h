#pragma once
#include "Fecha.h"

class Persona
{
public:
    Persona();
    void setDni(int _dni);
    int getDni();
    void setEmail(const char* _email);
    const char* getEmail();
    void setNombre(const char* _nombre);
    const char* getNombre();
    void setApellido(const char* _apellido);
    const char* getAapellido();
    void setTelefono(const char* _telefono);
    const char* getTelefono();
    void setDireccion(const char* _direccion);
    const char* getDireccion();
    Fecha getFechaNacimiento();
    void setEliminado(bool _eliminado);
    bool getEliminado();

protected:

    int _dni;
    char _email[50], _nombre[50], _apellido[50], _telefono[20], _direccion[100];
    Fecha _fechaNacimiento;
    bool _eliminado;
};
