#pragma once

#include "inscripcionesArchivo.h"

class InscripcionManager {
public:
    InscripcionManager();

    void guardarInscripcion();
    void listarInscripciones();

private:
    Inscripcion crearInscripcion();
    InscripcionArchivo _inscripcionArchivo;
};
