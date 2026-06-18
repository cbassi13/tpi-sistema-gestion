#pragma once
#include "aulaArchivo.h"

class AulaManager {
public:
    AulaManager();
    void guardarAula();
    void listarAulas();

private:
    Aula crearAula();
    AulaArchivo _aulaArchivo;
};
