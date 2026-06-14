#pragma once
#include "persona.h"

class Alumno : public Persona {
public:
    Alumno();
    Alumno(int legajo, std::string nombre, Fecha nacimiento);

    int getLegajo() const;
    void setLegajo(int legajo);

private:
    int _legajo;
};
