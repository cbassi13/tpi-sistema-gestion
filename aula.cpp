#include "aula.h"

Aula::Aula()
    : _idAula(0), _capacidad(0), _proyector(false), _equipos(false), _eliminado(false)
{
}

Aula::Aula(int idAula, int capacidad, bool proyector, bool equipos)
    : _eliminado(false)
{
    setIdAula(idAula);
    setCapacidad(capacidad);
    setProyector(proyector);
    setEquipos(equipos);
}

void Aula::setIdAula(int idAula)
{
    _idAula = idAula;
}

int Aula::getIdAula() const
{
    return _idAula;
}

void Aula::setCapacidad(int capacidad)
{
    _capacidad = capacidad;
}

int Aula::getCapacidad() const
{
    return _capacidad;
}

void Aula::setProyector(bool proyector)
{
    _proyector = proyector;
}

bool Aula::getProyector() const
{
    return _proyector;
}

void Aula::setEquipos(bool equipos)
{
    _equipos = equipos;
}

bool Aula::getEquipos() const
{
    return _equipos;
}

void Aula::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

bool Aula::getEliminado() const
{
    return _eliminado;
}
