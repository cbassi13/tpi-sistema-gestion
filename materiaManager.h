#pragma once
#include "materiaArchivo.h"

class MateriaManager {

public:

    MateriaManager();

    void guardarMateria();

    void listarMaterias();

    void modificarMateria();

    void buscarMateriaPorNumero();

    void buscarMateriaPorNombre();

    void buscarPorDocente();

    void buscarPorCarrera();

    void bajaMateria();


private:

    Materia crearMateria();

    MateriaArchivo _materiaArchivo;
};
