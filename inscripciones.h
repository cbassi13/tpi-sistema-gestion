#pragma once

#include "fecha.h"

class Inscripcion {
public:
    Inscripcion();

    Inscripcion(int idInscripcion,
                int legajoAlumno,
                int nroMateria,
                Fecha fechaInscripcion,
                float importeMatricula,
                bool estado);

    void setIdInscripcion(int idInscripcion);
    int getIdInscripcion() const;

    void setLegajoAlumno(int legajoAlumno);
    int getLegajoAlumno() const;

    void setNroMateria(int nroMateria);
    int getNroMateria() const;

    void setFechaInscripcion(Fecha fechaInscripcion);
    Fecha getFechaInscripcion() const;

    void setImporteMatricula(float importe);
    float getImporteMatricula() const;

    void setEstado(bool estado);
    bool getEstado() const;

private:
    int _idInscripcion;
    int _legajoAlumno;
    int _nroMateria;
    Fecha _fechaInscripcion;
    float _importeMatricula;
    bool _estado;
};
