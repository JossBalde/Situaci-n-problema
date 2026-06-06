#include "video.h"
#include "episodio.h"
#include "pelicula.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(){

    int opcion;
    do{
    cout << "Menu:\n"
         << "1. Cargar archivo de datos\n"
         << "2. Mostrar los datos\n"
         << "3. Mostrar los videos en general con una cierta calificacion o de un cierto género\n"
         << "4. Mostrar los episodios de una dterminada serie con una calificacion determinada\n"
         << "5. Mostrar las peliculas con cierta calificacion\n"
         << "6. Calificar un video\n"
         << "0. Salir\n"
         << "Eige una opcion: ";
        cin >> opcion;
    
    }while()
    return 0;
}