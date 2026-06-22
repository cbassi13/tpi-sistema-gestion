#pragma once
#include <string>
#include "beca.h"

class BecaArchivo {
public:
    BecaArchivo(std::string nombreArchivo = "becas.dat");
    bool guardar(Beca beca);
    bool modificar(Beca beca, int pos);
    Beca leer(int pos);
    int getCantidadRegistros();
    int getPosByIdBeca(int idBeca);
    int getNuevoId();

private:
    std::string _nombreArchivo;
};
