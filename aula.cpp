#include <iostream>
#include "aula.h"

using namespace std;

Aula::Aula() {
    _idAula = 0;
    _capacidad = 0;
    _tieneProyector = false;
    _tieneEquiposInformaticos = false;
    _eliminado = false;
}

Aula::Aula(int _idAula, int _capacidad, bool _tieneProyector, bool _tieneEquiposInformaticos, bool _eliminado){
///Crear aula???
}

///Getters

int Aula::getIdAula() {
  return _idAula;
}

int Aula::getCapacidad() {
  return _capacidad;
}

bool Aula::getTieneEquiposInformaticos() {
  return _tieneEquiposInformaticos;
}

bool Aula::getTieneProyector() {
  return _tieneProyector;
}

bool Aula::getEliminado()  {
  return _eliminado;
}

///Setters

void Aula::setIdAula(int idAula) {
  _idAula = idAula;
}

void Aula::setCapacidad(int capacidad) {
  _capacidad = capacidad;
}

void Aula::setTieneEquiposInformaticos(bool tieneEquiposInformaticos) {
  _tieneEquiposInformaticos = tieneEquiposInformaticos;
}

void Aula::setTieneProyector(bool tieneProyector) {
  _tieneProyector = tieneProyector;
}

void Aula::setEliminado(bool eliminado) {
  _eliminado = eliminado;
}
