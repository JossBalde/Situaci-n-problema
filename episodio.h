#include "video.h"
#pragma once

class Episodio : public Video{
private:
    int temporada;
    std::string titulo;
public:
    void mostrarDatos() override;
};