#pragma once
#include <string>
#include "inscripciones.h"

class InscripcionArchivo {
public:
    InscripcionArchivo(std::string nombreArchivo = "inscripciones.dat");

    bool guardar(const Inscripcion &reg);
    Inscripcion leer(int pos);

    int getCantidadRegistros();
    int getNuevoIdInscripcion();

private:
    std::string _nombreArchivo;
};
