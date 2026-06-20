#pragma once
#include "materiaArchivo.h"

class MateriaManager {

public:

    MateriaManager();

    void guardarMateria();

    void listarMaterias();

    void modificarMateria();


private:

    Materia crearMateria();

    MateriaArchivo _materiaArchivo;
};
