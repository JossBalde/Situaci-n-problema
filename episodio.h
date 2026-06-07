#include "video.h"
#pragma once
#define EPISODIO_ATRIBUTE_SIZE 6

class Episodio : public Video{
private:
    int temporada;
    std::string titulo;
public:
    Episodio() {}
    void mostrarDatos() override;
    void setTemporada(int temporada);
    void setTitulo(std::string titulo);
    std::string getNombre();
};
bool loadSerieFromCSV(std::string fileName, Episodio* partArray, unsigned int arraySize);
