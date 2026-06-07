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
    Video();
    void setId(std::string id);
    void setNombre(std::string nombre);
    void setGenero(std::string genero);
    void setDuracion(int duracion);
    void setCalificacion(float calificacion);
    virtual void mostrarDatos() = 0;
    float getCalificacion();
    std::string getGenero();
    std::string getId();
    virtual ~Video() {
    }
};
int countDataLinesInCSV(std::string fileName);
