#pragma once
#include "archivoDocente.h"

class DocenteManager {
public:
    DocenteManager();
    void guardarDocente();
    void listarDocentes();

private:
    Docente crearDocente();
    DocenteArchivo _docenteArchivo;
};
