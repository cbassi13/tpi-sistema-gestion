#pragma once
#include <string>
#include "aula.h"

class AulaArchivo {
public:
    AulaArchivo(std::string nombreArchivo = "aulas.dat");
    bool guardar(Aula aula);
    Aula leer(int pos);
    int getCantidadRegistros();
    int getNuevoId();

private:
    std::string _nombreArchivo;
};
