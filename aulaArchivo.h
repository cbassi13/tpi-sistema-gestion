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

    bool modificar(const Aula &reg, int pos);
    int getPosByIdAula(int idAula);

private:
    std::string _nombreArchivo;
};
