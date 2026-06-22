#include <iostream>
#include <cstring>
#include "beca.h"

using namespace std;

Beca::Beca()
:_idBeca(0), _legajo(0), _idCarrera(0), _tipo (""), _porcentaje(0), _fechaAsignacion(), _eliminado(false) {}

Beca::Beca(int idBeca, int legajo, int idCarrera, std::string tipo, float porcentaje, Fecha fechaAsignacion)
    :_eliminado(false)

{
    setIdBeca(idBeca);
    setLegajo(legajo);
    setIdCarrera(idCarrera);
    setTipo(tipo);
    setPorcentaje(porcentaje);
    setFechaAsignacion(fechaAsignacion);

}

void Beca::setIdBeca(int idBeca)
{///validacion de legajo con legajo existente
    _idBeca = idBeca;
}

int Beca::getIdBeca() const
{
    return _idBeca;
}

void Beca::setLegajo(int legajo)
{///validacion de legajo con legajo existente
    _legajo = legajo;
}

int Beca::getLegajo() const
{
    return _legajo;
}

void Beca::setIdCarrera(int idCarrera)
{///validacion de idCarrera con Carrera existente
    _idCarrera = idCarrera;
}

int Beca::getIdCarrera() const
{
    return _idCarrera;
}


void Beca::setTipo(std::string tipo)
{
    strcpy(_tipo, tipo.c_str());
}

std::string Beca::getTipo() const
{
    return std::string(_tipo);
}

void Beca::setPorcentaje(float porcentaje)
{///El porcentaje se vincula al tipo???
    _porcentaje = porcentaje;
}

float Beca::getPorcentaje() const
{
    return _porcentaje;
}

void Beca::setFechaAsignacion(Fecha fechaAsignacion)
{
    _fechaAsignacion = fechaAsignacion;
}

Fecha Beca::getFechaAsignacion() const
{
    return _fechaAsignacion;

}

void Beca::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

bool Beca::getEliminado() const
{
    return _eliminado;
}



