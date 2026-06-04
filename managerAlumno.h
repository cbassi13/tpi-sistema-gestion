#pragma once
#include "archivoAlumno.h"

class AlumnoManager {
public:
	AlumnoManager();

   void guardarAlumno();
   void listarAlumnos();

private:
   Alumno crearAlumno();
   AlumnoArchivo _alumnoArchivo;
};

