#include <cstring>
#include "alumno.h"

Alumno::Alumno():
   _legajo(0), _nombre(""), _estado(0),
   _fechaNacimiento(){}

Alumno::Alumno(int legajo, std::string nombre, int estado, Fecha nacimiento){

   setLegajo(legajo);
   setNombre(nombre);
   setEstado(estado);

   setFechaNacimiento(nacimiento);

}

Alumno::Alumno(int legajo, std::string nombre, int estado){
   Fecha nacimiento;
   nacimiento.cargarFecha();///agregar cargar Fecha

   setLegajo(legajo);
   setNombre(nombre);
   setEstado(estado);
   setFechaNacimiento(nacimiento);
}

int Alumno::getLegajo() const{
   return _legajo;
}

void Alumno::setLegajo(int id){
   _id = legajo;
}

std::string Alumno::getNombre() const{
   // return _nombre; /// convertirlo implicitamente
   return std::string(_nombre); /// conversion explicita
}

void Alumno::setNombre(std::string nombre){
   if(nombre.size() < 50){
      strcpy(_nombre, nombre.c_str());
   }
   else{
      strcpy(_nombre, "Nombre fuera de rango...");
   }

}

int Alumno::getEstado() const{
   return _estado;
}

void Alumno::setEstado(int estado){
   _estado = estado;
}

Fecha Alumno::getFechaCreacion() const{
   return _fechaCreacion;
}

void Tarea::setFechaCreacion(Fecha fechaCreacion){
   _fechaCreacion = fechaCreacion;
}

Fecha Tarea::getFechaInicio() const{
   return _fechaInicio;
}

void Tarea::setFechaInicio(Fecha fechaInicio){
   _fechaInicio = fechaInicio;
}

Fecha Tarea::getFechaCompletado() const{
   return _fechaCompletado;
}

void Tarea::setFechaCompletado(Fecha fechaCompletado){
   _fechaCompletado = fechaCompletado;
}
