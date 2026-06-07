#include "video.h"
#pragma once
#define PELICULA_ATRIBUTE_SIZE 4

class Pelicula : public Video{
public:
    Pelicula() {}
    void mostrarDatos() override;
};
bool loadPeliculaFromCSV(std::string fileName, Pelicula* partArray, unsigned int arraySize);
