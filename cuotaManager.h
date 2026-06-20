#pragma once
#include "cuotaArchivo.h"

class CuotaManager {
public:
    CuotaManager();
    void guardarCuota();
    void listarCuotas();
    void modificarCuota();

private:
    Cuota crearCuota();
    CuotaArchivo _cuotaArchivo;
};
