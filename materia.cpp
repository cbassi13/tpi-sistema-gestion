#include "materia.h"
#include <cstring>

Materia::Materia():_nroMateria(0), _cupo(0), _idAula(0), _idCarrera(0), _eliminado(false), _nombre(""), _docente("")
{
}

Materia::Materia(int nroMateria, std::string nombre, std::string docente, int cupo, int idAula, int idCarrera)
: _eliminado(false)
{
    setNroMateria(nroMateria);
    setNombre(nombre);
    setDocente(docente);
    setCupo(cupo);
    setIdAula(idAula);
    setIdCarrera(idCarrera);
}

void Materia::setNroMateria(int nroMateria) {
    _nroMateria = nroMateria;
}

int Materia::getNroMateria() const {
    return _nroMateria;
}

// ---------------- NOMBRE ----------------

void Materia::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

std::string Materia::getNombre() const
{
    return std::string(_nombre);
}

// ---------------- DOCENTE ----------------

void Materia::setDocente(std::string docente)
{
    strcpy(_docente, docente.c_str());
}

std::string Materia::getDocente() const
{
    return std::string(_docente);
}

// ---------------- CUPO ----------------

void Materia::setCupo(int cupo)
{
    _cupo = cupo;
}

int Materia::getCupo() const
{
    return _cupo;
}

// ---------------- ID AULA ----------------

void Materia::setIdAula(int idAula)
{
    _idAula = idAula;
}

int Materia::getIdAula() const
{
    return _idAula;
}

// ---------------- ID CARRERA ----------------

void Materia::setIdCarrera(int idCarrera)
{
    _idCarrera = idCarrera;
}

int Materia::getIdCarrera() const
{
    return _idCarrera;
}

// ---------------- ELIMINADO ----------------

void Materia::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

bool Materia::getEliminado() const
{
    return _eliminado;
}
