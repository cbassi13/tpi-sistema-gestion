#pragma once
#include <string>
#include "docente.h"

class DocenteArchivo {
public:
    DocenteArchivo(std::string nombreArchivo = "docentes.dat");

    bool guardar(const Docente &reg);
    Docente leer(int pos);

    int getCantidadRegistros();
    int getNuevoLegajo();


  int getPosByLegajo(int legajo);
  bool modificar(const Docente &reg, int pos);

private:
    std::string _nombreArchivo;
};
