#pragma once
#include <string>
#include "fecha.h"

class Beca {
public:
    Beca();
    Beca(int idBeca, int legajo, int idCarrera, std::string tipo, float porcentaje, Fecha fechaAsignacion);

    void setIdBeca(int idBeca);
    int getIdBeca() const;

    void setLegajo(int legajo);
    int getLegajo() const;

    void setTipo(std::string tipo);
    std::string getTipo() const;

    void setPorcentaje(float porcentaje);
    float getPorcentaje() const;

    void setFechaAsignacion(Fecha fechaAsignacion);
    Fecha getFechaAsignacion() const;

    void setEliminado(bool eliminado);
    bool getEliminado() const;

    void setIdCarrera(int idCarrera);
    int getIdCarrera() const;

private:
    int _idBeca;
    int _legajo;
    int _idCarrera;
    char _tipo[100];
    float _porcentaje;
    Fecha _fechaAsignacion;
    bool _eliminado;


};
