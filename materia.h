#pragma once
#include <string>

class Materia {
public:
    Materia();
    Materia(int nroMateria, std::string nombre, std::string docente, int cupo, int idAula, int idCarrera);

    void setNroMateria(int nroMateria);
    int getNroMateria() const;

    void setNombre(std::string nombre);
    std::string getNombre() const;

    void setDocente(std::string docente);
    std::string getDocente() const;

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
    char _docente[50];
    int _cupo;
    int _idAula;
    int _idCarrera;
    bool _eliminado;
};
