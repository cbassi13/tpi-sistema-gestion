#pragma once
#include <string>
#include "fecha.h"

class Alumno{
public:
	Alumno();
   Alumno(int legajo, std::string nombre, int estado);

   Alumno(int legajo, std::string nombre, int estado, Fecha nacimiento);



   int getLegajo() const;
   void setLegajo(int legajo);

   std::string getNombre() const;
   void setNombre(std::string nombre);

   int getEstado() const;
   void setEstado(int estado);

   Fecha getFechaNacimiento() const;
   void setFechaNacimiento(Fecha fechaNacimiento);


private:
   int _legajo;
   char _nombre[50];
   int _estado;

   Fecha _fechaNacimiento;

};
