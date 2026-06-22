#pragma once
#include <string>

class Carrera {
public:
    Carrera();

    void setIdCarrera(int idCarrera);
    int getIdCarrera() const;

    void setNombre(std::string nombre);
    std::string getNombre() const;

    void setEliminado(bool eliminado);
    bool getEliminado() const;

    void setIdJefeCatedra(int idJefeCatedra);
    int getIdJefeCatedra() const;

private:
    int _idCarrera;
    char _nombre[50];
    bool _eliminado;
    int _idJefeCatedra;
};
