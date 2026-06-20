#pragma once
#include <string>
#include "beca.h"

class BecaArchivo {
public:
    BecaArchivo(std::string nombreArchivo = "becas.dat");
    bool guardar(Beca beca);
    Beca leer(int pos);
    int getCantidadRegistros();
    int getNuevoId();

private:
    std::string _nombreArchivo;
};
