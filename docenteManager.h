#pragma once
#include "docenteArchivo.h"
#include "materiaArchivo.h"

class DocenteManager {
public:
    DocenteManager();
    void guardarDocente();
    void listarDocentes();
    void modificarDocente();
    void bajaDocente();
    void buscarDocentePorLegajo();
    void mostrarAgendaDocente();

private:
    Docente crearDocente();
    DocenteArchivo _docenteArchivo;
    MateriaArchivo _materiaArchivo;
};
