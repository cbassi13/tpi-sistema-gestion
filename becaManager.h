#pragma once
#include "becaArchivo.h"

class BecaManager {
public:
    BecaManager();
    void guardarBeca();
    void listarBecas();

private:
    Beca crearBeca();
    BecaArchivo _becaArchivo;
};
