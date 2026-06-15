#include <cstring>
#include "alumno.h"

Alumno::Alumno(): Persona(), _legajo(0) {}

Alumno::Alumno(int legajo, int dni, std::string nombre, std::string apellido, std::string email,
std::string telefono, std::string direccion, Fecha fechaNacimiento) {
    setLegajo(legajo);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setTelefono(telefono);
    setDireccion(direccion);
    setFechaNacimiento(fechaNacimiento);
}

int Alumno::getLegajo() const {
    return _legajo;
}

void Alumno::setLegajo(int legajo) {
    _legajo = legajo;
}
