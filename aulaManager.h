#pragma once
#include "aulaArchivo.h"
#include "materiaArchivo.h"

class AulaManager {
public:
    AulaManager();

    void guardarAula();
    void listarAulas();
    void modificarAula();
    void bajaAula();
    void listarAulasConProyectorYEquipos();
    void listarAulasOcupadasYDesocupadas();

private:
    Aula crearAula();
    AulaArchivo _aulaArchivo;
    MateriaArchivo _materiaArchivo;
};
