#pragma once
#include "alumnoArchivo.h"

class AlumnoManager {
public:
	AlumnoManager();

   void guardarAlumno();
   void listarAlumnos();

private:
   Alumno crearAlumno();
   AlumnoArchivo _alumnoArchivo;
};

