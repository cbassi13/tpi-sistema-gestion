#pragma once
#include "persona.h"

class Docente : public Persona {
public:
    Docente();
    Docente(int legajo, int dni, std::string nombre, std::string apellido,
            std::string email, std::string telefono,
            std::string direccion, Fecha fechaNacimiento);

    int getLegajo() const;
    void setLegajo(int legajo);

private:
    int _legajo;
};
