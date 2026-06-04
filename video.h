#include <string>
#pragma once
class Video{
protected:
    std::string id;
    std::string nombre;
    std::string genero;
    int duracion; 
    float calificacion;
public:
    Video(std::string id,std::string nombre, std::string genero, int duracion);
    virtual ~Video() = {}
    void setCalificacion(float calificacion);
    virtual void mostrarDatos() = 0;
    float getCalificacion();
    std::string getGenero();
};