#include "episodio.h"
#include <iostream>

void Episodio::mostrarDatos() {
    std::cout<<"Id: "<<id<<", Nombre: "<<nombre<<", Genero: "<<genero<<", Duracion: "
    <<duracion<<", Calif.prom: "<<calificacion<<", Titulo: "<<titulo<<", Temporada: "<<temporada<<"\n";
}