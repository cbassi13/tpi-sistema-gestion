#pragma once
#include "docenteArchivo.h"

class DocenteManager {
public:
    DocenteManager();
    void guardarDocente();
    void listarDocentes();
    void modificarDocente();
    void bajaDocente();

private:
    Docente crearDocente();
    DocenteArchivo _docenteArchivo;
};
