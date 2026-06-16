#include <cstring>
#include "alumno.h"

Alumno::Alumno(): Persona(), _legajo(0) {}

Alumno::Alumno(int legajo, int dni, std::string nombre, std::string apellido, std::string email, std::string telefono, std::string direccion, Fecha fechaNacimiento)
: Persona(dni, nombre, apellido, email, telefono, direccion, fechaNacimiento) {
    setLegajo(legajo);
}

int Alumno::getLegajo() const {
    return _legajo;
}

void Alumno::setLegajo(int legajo) {
    _legajo = legajo;
}
