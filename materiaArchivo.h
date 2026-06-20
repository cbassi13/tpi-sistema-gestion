#pragma once
#include <string>
#include "materia.h"

class MateriaArchivo {
public:
    MateriaArchivo(std::string nombreArchivo = "materias.dat");
    bool guardar(Materia materia);
    bool modificar(Materia materia, int pos);
    Materia leer(int pos);
    int getCantidadRegistros();
    int getNuevoId();

private:
    std::string _nombreArchivo;
};
