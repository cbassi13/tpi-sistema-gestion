#pragma once
#include "docenteArchivo.h"

class DocenteManager {
public:
    DocenteManager();
    void guardarDocente();
    void listarDocentes();

private:
    Docente crearDocente();
    DocenteArchivo _docenteArchivo;
};
