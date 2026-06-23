#include "inscripciones.h"

Inscripcion::Inscripcion() {
    _idInscripcion = 0;
    _legajoAlumno = 0;
    _nroMateria = 0;
    _importeMatricula = 0;
    _estado = true;
}

Inscripcion::Inscripcion(int idInscripcion,
                         int legajoAlumno,
                         int nroMateria,
                         Fecha fechaInscripcion,
                         float importeMatricula,
                         bool estado) {
    setIdInscripcion(idInscripcion);
    setLegajoAlumno(legajoAlumno);
    setNroMateria(nroMateria);
    setFechaInscripcion(fechaInscripcion);
    setImporteMatricula(importeMatricula);
    setEstado(estado);
}

void Inscripcion::setIdInscripcion(int idInscripcion) {
    _idInscripcion = idInscripcion;
}

int Inscripcion::getIdInscripcion() const {
    return _idInscripcion;
}

void Inscripcion::setLegajoAlumno(int legajoAlumno) {
    _legajoAlumno = legajoAlumno;
}

int Inscripcion::getLegajoAlumno() const {
    return _legajoAlumno;
}

void Inscripcion::setNroMateria(int nroMateria) {
    _nroMateria = nroMateria;
}

int Inscripcion::getNroMateria() const {
    return _nroMateria;
}

void Inscripcion::setFechaInscripcion(Fecha fechaInscripcion) {
    _fechaInscripcion = fechaInscripcion;
}

Fecha Inscripcion::getFechaInscripcion() const {
    return _fechaInscripcion;

}

void Inscripcion::setImporteMatricula(float importeMatricula) {
    _importeMatricula = importeMatricula;
}

float Inscripcion::getImporteMatricula() const {
    return _importeMatricula;
}

void Inscripcion::setEstado(bool estado) {
    _estado = estado;
}

bool Inscripcion::getEstado() const {
    return _estado;
}
