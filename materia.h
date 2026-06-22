#pragma once
#include <string>

class Materia {
public:
    Materia();
    Materia(int nroMateria, std::string nombre, int idDocente, int cupo, int idAula, int idCarrera);

    void setNroMateria(int nroMateria);
    int getNroMateria() const;

    void setNombre(std::string nombre);
    std::string getNombre() const;

    void setIdDocente(int idDocente);
    int getIdDocente() const;

    void setCupo(int cupo);
    int getCupo() const;

    void setIdAula(int idAula);
    int getIdAula() const;

    void setIdCarrera(int idCarrera);
    int getIdCarrera() const;

    void setEliminado(bool eliminado);
    bool getEliminado() const;

private:
    int _nroMateria;
    char _nombre[50];
    int _idDocente;
    int _cupo;
    int _idAula;
    int _idCarrera;
    bool _eliminado;
};
