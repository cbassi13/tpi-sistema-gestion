#pragma once
#include <string>
#include "fecha.h"

class Aula {
public:
    Aula();
    Aula(int idAula, int capacidad, bool proyector, bool equipos);

    void setIdAula(int idAula);
    int getIdAula() const;

    void setCapacidad(int capacidad);
    int getCapacidad() const;

    void setProyector(bool proyector);
    bool getProyector() const;

    void setEquipos(bool equipos);
    bool getEquipos() const;

    void setEliminado(bool eliminado);
    bool getEliminado() const;

private:
    int _idAula;
    int _capacidad;
    bool _proyector;
    bool _equipos;
    bool _eliminado;
};
