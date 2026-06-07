#include "video.h"
#include <iostream>
#include <fstream>
Video::Video(){
    calificacion = 0;
}
void Video::setId(std::string id){
        this->id = id;
}
void Video::setNombre(std::string nombre){
        this->nombre = nombre;
}
void Video::setGenero(std::string genero){
        this->genero = genero;
}
void Video::setDuracion(int duracion){
        this->duracion = duracion;
}
void Video::setCalificacion(float calificacion){
        this->calificacion = calificacion;
        std::cout<<"Calificacion asignada\n";
}
float Video::getCalificacion(){
    return calificacion;
}
std::string Video::getGenero(){
    return genero;
}
std::string Video::getId(){
    return id;
}
int countDataLinesInCSV(std::string fileName) {
    std::ifstream    file(fileName);
    int         lineCount = 0;
    std::string      line;

    // Contar la cantidad de líneas en el archivo csv
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fileName << '\n';
        return -1;
    }

    // skip header
    if(!getline(file, line)) {
        std::cerr << "El archivo no tiene header\n";
        file.close();
        return -1;
    }

    // Contar lineas 
    while(getline(file, line)) {
        lineCount++;    
    }

    file.close();
    return(lineCount);
}
