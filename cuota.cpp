#include "cuota.h"

Cuota::Cuota()
:_nroCuota(0), _legajo(0), _monto(0), _fechaPago(), _pagada(false) {}

Cuota::Cuota(int nroCuota, int legajo, float monto, Fecha fechaPago)
    : _pagada(false)

{
    setNroCuota(nroCuota);
    setLegajo(legajo);
    setMonto(monto);
    setFechaPago(fechaPago);
}

void Cuota::setNroCuota(int nroCuota)
{
    _nroCuota = nroCuota;
}

int Cuota::getNroCuota() const
{
    return _nroCuota;
}

void Cuota::setLegajo(int legajo)
{
    _legajo = legajo;
}

int Cuota::getLegajo() const
{
    return _legajo;
}

void Cuota::setMonto(float monto)
{
    _monto = monto;
}

float Cuota::getMonto() const
{
    return _monto;
}

void Cuota::setFechaPago(Fecha fechaPago)
{
    _fechaPago = fechaPago;
}

Fecha Cuota::getFechaPago() const
{
    return _fechaPago;
}

void Cuota::setPagada(bool pagada)
{
    _pagada = pagada;
}

bool Cuota::getPagada() const
{
    return _pagada;
}

void Cuota::setEliminado(bool eliminado)
{
    _pagada = eliminado;
}

bool Cuota::getEliminado() const
{
    return _eliminado;
}
