#include <cstring>
#include "docente.h"

Docente::Docente() : Persona(), _legajo(0) {}
Docente::Docente(int legajo, int dni, std::string nombre,
                 std::string apellido, std::string email,
                 std::string telefono, std::string direccion,
                 Fecha fechaNacimiento)
    : Persona(dni, nombre, apellido, email,
              telefono, direccion, fechaNacimiento) {
    setLegajo(legajo);
}

int Docente::getLegajo() const {
    return _legajo;
}

void Docente::setLegajo(int legajo) {
    _legajo = legajo;
}
