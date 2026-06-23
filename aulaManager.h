#pragma once
#include "aulaArchivo.h"

class AulaManager {
public:
    AulaManager();

    void guardarAula();
    void listarAulas();
    void modificarAula();
    void bajaAula();
    void listarAulasConProyectorYEquipos();

private:
    Aula crearAula();
    AulaArchivo _aulaArchivo;
};
