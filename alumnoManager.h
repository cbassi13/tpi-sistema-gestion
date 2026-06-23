#pragma once
#include "alumnoArchivo.h"

class AlumnoManager {
public:
	AlumnoManager();

   void guardarAlumno();
   void listarAlumnos();
   void modificarAlumno();
   void bajaAlumno();


private:
   Alumno crearAlumno();
   AlumnoArchivo _alumnoArchivo;
};

