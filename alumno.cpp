#include <cstring>
#include "alumno.h"

Alumno::Alumno(): Persona(), _legajo(0) {}

Alumno::Alumno(int legajo, std::string nombre, Fecha nacimiento) {
    setLegajo(legajo);
    setNombre(nombre);
    setFechaNacimiento(nacimiento);
}

int Alumno::getLegajo() const {
    return _legajo;
}

void Alumno::setLegajo(int legajo) {
    _legajo = legajo;
}
