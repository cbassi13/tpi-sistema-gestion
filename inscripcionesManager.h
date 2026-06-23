#pragma once

#include "inscripcionesArchivo.h"

class InscripcionManager {
public:
    InscripcionManager();

    void guardarInscripcion();
    void listarInscripciones();

    void modificarInscripcion();
    void bajaInscripcion();

    void listarCantidadTotalInscriptos();


private:
    Inscripcion crearInscripcion();
    InscripcionArchivo _inscripcionArchivo;
};
