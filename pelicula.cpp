#include "pelicula.h"
#include <iostream>

void Pelicula::mostrarDatos() {
    std::cout<<"Id: "<<id<<", Nombre: "<<nombre<<", Genero: "<<genero<<", Duracion: "
    <<duracion<<", Calif.prom: "<<calificacion<<"\n";
}
