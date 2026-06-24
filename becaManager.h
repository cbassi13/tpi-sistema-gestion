#pragma once
#include "becaArchivo.h"

class BecaManager {
public:
    BecaManager();
    void guardarBeca();
    void listarBecas();
    void modificarBeca();
    void bajaBeca();
    void buscarPorLegajo();
    void buscarPorTipo();


private:
    Beca crearBeca();
    BecaArchivo _becaArchivo;
};
