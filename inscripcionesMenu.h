#pragma once

#include "inscripcionesManager.h"
#include "menu.h"

class InscripcionMenu : public Menu {
public:
    InscripcionMenu();

    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

private:
    InscripcionManager _managerInscripcion;
};
