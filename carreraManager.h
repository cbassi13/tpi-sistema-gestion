#pragma once
#include "carreraArchivo.h"

class CarreraManager {
  public:
    CarreraManager();

    void guardarCarrera();
    void listarCarreras();

private:
    Carrera crearCarrera();
    CarreraArchivo _carreraArchivo;
};


