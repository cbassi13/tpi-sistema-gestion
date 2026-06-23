#pragma once
#include <string>
#include "fecha.h"

class Cuota {
public:
    Cuota();
    Cuota(int nroCuota, int legajo, float monto, Fecha fechaPago, int mesCorrespondiente);

    void setNroCuota(int nroCuota);
    int getNroCuota() const;

    void setLegajo(int legajo);
    int getLegajo() const;

    void setMonto(float monto);
    float getMonto() const;

    void setFechaPago(Fecha fechaPago);
    Fecha getFechaPago() const;

    void setPagada(bool pagada);
    bool getPagada() const;

    void setEliminado(bool eliminado);
    bool getEliminado() const;

    void setMesCorrespondiente(int mes);
    int getMesCorrespondiente() const;

private:
    int _nroCuota, _legajo, _mesCorrespondiente;
    float _monto;
    Fecha _fechaPago;
    bool _pagada;
    bool _eliminado;
};

