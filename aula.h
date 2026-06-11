#pragma once

class Aula
{
public:
    Aula();
    Aula(int _idAula, int _capacidad, bool _tieneProyector, bool _tieneEquiposInformaticos, bool _eliminado);

    void setIdAula(int _idAula);
    int getIdAula();
    void setCapacidad(int _capacidad);
    int getCapacidad();
    void setTieneProyector(bool _tieneProyector);
    bool getTieneProyector();
    void setTieneEquiposInformaticos(bool _tieneEquiposInformaticos);
    bool getTieneEquiposInformaticos();
    void setEliminado(bool _eliminado);
    bool getEliminado();

private:
    int _idAula;
    int _capacidad;
    bool _tieneProyector;
    bool _tieneEquiposInformaticos;
    bool _eliminado;

};
