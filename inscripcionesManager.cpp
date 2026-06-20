#include <iostream>
#include "inscripcionesManager.h"

using namespace std;

InscripcionManager::InscripcionManager()
    : _inscripcionArchivo() {

}

Inscripcion InscripcionManager::crearInscripcion() {

    int idInscripcion = _inscripcionArchivo.getNuevoIdInscripcion();

    int legajoAlumno;
    int nroMateria;

    int dia, mes, anio;

    cout << "ID Inscripcion: #" << idInscripcion << endl;

    cout << "Ingrese legajo del alumno: ";
    cin >> legajoAlumno;

    cout << "Ingrese numero de materia: ";
    cin >> nroMateria;

    cout << "Ingrese dia de inscripcion: ";
    cin >> dia;

    cout << "Ingrese mes de inscripcion: ";
    cin >> mes;

    cout << "Ingrese anio de inscripcion: ";
    cin >> anio;

    Fecha fechaInscripcion(dia, mes, anio);

    return Inscripcion(
        idInscripcion,
        legajoAlumno,
        nroMateria,
        fechaInscripcion,
        true
    );
}

void InscripcionManager::guardarInscripcion() {

    Inscripcion reg = crearInscripcion();

    if(_inscripcionArchivo.guardar(reg)) {
        cout << "Se guardo exitosamente" << endl;
    }
    else {
        cout << "No se pudo guardar" << endl;
    }
}

void InscripcionManager::listarInscripciones() {

    int cantidad = _inscripcionArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidad; i++) {

        Inscripcion ins = _inscripcionArchivo.leer(i);

        cout << "------------------------" << endl;

        cout << "ID: " << ins.getIdInscripcion() << endl;

        cout << "Legajo Alumno: "
             << ins.getLegajoAlumno() << endl;

        cout << "Nro Materia: "
             << ins.getNroMateria() << endl;

        cout << "Fecha: "
             << ins.getFechaInscripcion().getDia() << "/"
             << ins.getFechaInscripcion().getMes() << "/"
             << ins.getFechaInscripcion().getAnio()
             << endl;

        cout << "Estado: "
             << ins.getEstado()
             << endl;
    }
}
