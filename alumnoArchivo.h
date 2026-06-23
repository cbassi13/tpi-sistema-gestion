#pragma once
#include <string>
#include "alumno.h"

class AlumnoArchivo {
public:
	AlumnoArchivo(std::string nombreArchivo = "alumnos.dat");
   bool guardar(const Alumno &reg);
   Alumno leer(int pos);
   int getCantidadRegistros();
   int getNuevoLegajo();

   int getPosByLegajo(int legajo);
   bool modificar(const Alumno &reg, int pos);

private:
   std::string _nombreArchivo;
};

