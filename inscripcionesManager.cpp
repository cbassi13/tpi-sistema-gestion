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
    float importeMatricula;
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

    cout << "Ingrese importe de la matricula: ";
    cin >> importeMatricula;

    Fecha fechaInscripcion(dia, mes, anio);

    return Inscripcion(
        idInscripcion,
        legajoAlumno,
        nroMateria,
        fechaInscripcion,
        importeMatricula,
        false
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

        if(!ins.getEliminado()) {

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

            cout << "Importe matricula: $" <<ins.getImporteMatricula() << endl;
        }
    }
}

void InscripcionManager::modificarInscripcion(){

    int id;

    cout << "Ingrese ID de la inscripcion: ";
    cin >> id;

    int pos = _inscripcionArchivo.getPosByIdInscripcion(id);

    if(pos == -1){
        cout << "No existe una inscripcion con ese ID." << endl;
        return;
    }

    Inscripcion reg = _inscripcionArchivo.leer(pos);

    int nroMateria;

    cout << "Nuevo numero de materia: ";
    cin >> nroMateria;

    reg.setNroMateria(nroMateria);

    float nuevoImporte;

    cout << "Nuevo importe de matricula: ";
    cin >> nuevoImporte;

    reg.setImporteMatricula(nuevoImporte);

    if(_inscripcionArchivo.modificar(reg, pos)){
        cout << "Inscripcion modificada correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar." << endl;
    }
}

void InscripcionManager::bajaInscripcion(){

    int id;

    cout << "Ingrese ID de la inscripcion: ";
    cin >> id;

    int pos = _inscripcionArchivo.getPosByIdInscripcion(id);

    if(pos == -1){
        cout << "No existe una inscripcion con ese ID." << endl;
        return;
    }

    Inscripcion reg = _inscripcionArchivo.leer(pos);

    reg.setEliminado(false);

    if(_inscripcionArchivo.modificar(reg, pos)){
        cout << "Inscripcion dada de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo realizar la baja." << endl;
    }
}

///-----------LISTAR CANTIDAD TOTAL INSCRIPTOS---------------

void InscripcionManager::listarCantidadTotalInscriptos(){

    int cantidad = _inscripcionArchivo.getCantidadRegistros();

    int totalAlumnos = 0;

    for(int i = 0; i < cantidad; i++){

        Inscripcion inscripcion = _inscripcionArchivo.leer(i);

        if(!inscripcion.getEliminado()){

            bool repetido = false;

            for(int j = 0; j < i; j++){

                Inscripcion anterior = _inscripcionArchivo.leer(j);

                if(!anterior.getEliminado() &&
                   anterior.getLegajoAlumno() == inscripcion.getLegajoAlumno()){

                    repetido = true;
                    break;
                }
            }

            if(!repetido){
                totalAlumnos++;
            }
        }
    }

    if(totalAlumnos > 0){
        cout << "------------------------" << endl;
        cout << "Cantidad total de alumnos inscriptos: "
             << totalAlumnos << endl;
    }
    else{
        cout << "No hay alumnos inscriptos." << endl;
    }
}

