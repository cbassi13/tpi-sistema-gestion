#pragma once
#include <string>
#include "carrera.h"

class CarreraArchivo {
public:
    CarreraArchivo(std::string nombreArchivo = "carreras.dat");

    bool guardar(const Carrera &reg);
    Carrera leer(int pos);

    int getCantidadRegistros();
    int getNuevoIdCarrera();

    /// int getPosByIdCarrera(int idCarrera);

private:
    std::string _nombreArchivo;
};
