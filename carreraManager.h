#pragma once
#include "carreraArchivo.h"

class CarreraManager {
  public:
    CarreraManager();

    void guardarCarrera();
    void listarCarreras();

    void modificarCarrera();
    void bajaCarrera();

private:
    Carrera crearCarrera();
    CarreraArchivo _carreraArchivo;
};


