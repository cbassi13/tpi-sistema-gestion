#include <cstring>
#include "carrera.h"

Carrera::Carrera() {
    _idCarrera = 0;
    strcpy(_nombre, "");
    _eliminado = false;
}

void Carrera::setIdCarrera(int idCarrera) {
    _idCarrera = idCarrera;
}

int Carrera::getIdCarrera() const {
    return _idCarrera;
}

void Carrera::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}

std::string Carrera::getNombre() const {
    return _nombre;
}

void Carrera::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}

bool Carrera::getEliminado() const {
    return _eliminado;
}
