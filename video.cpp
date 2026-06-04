#include "video.h"
#include <iostream>
Video::Video(std::string id,std::string nombre, std::string genero, int duracion){
    calificacion = 0;
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
    this->duracion = duracion;
}
void Video::setCalificacion(int calificacion){
        this->calificacion = calificacion;
        std::cout<<"Calificacion asignada\n";
}
float  getCalificacion(){
    return calificacion;
}
string getGenero(){
    return genero;
}

