#include "video.h"
#include "episodio.h"
#include "pelicula.h"
#include <iostream>
#include <fstream>
using namespace std;
#define SERIES_FILE "series.csv"
#define PELICULAS_FILE "movies.csv"


int main(){
    Pelicula *peliculas = nullptr;
    Episodio *series = nullptr;
    int seriesSize = 0;
    int peliculasSize = 0;
    int catalogoSize = 0;
    Video **catalogo = nullptr;

    seriesSize = countDataLinesInCSV(SERIES_FILE);
 	if(seriesSize == -1) {
		cerr << "No se pudo cargar el data set desde " << SERIES_FILE << "\n";
		return 0;
	}
	series = new(nothrow) Episodio[seriesSize];
	if(series == nullptr) {
		cerr << "No hubo memoria para el arreglo creado con datos de " << SERIES_FILE << "\n";
		return 0;
	}
    if(!loadSerieFromCSV(SERIES_FILE, series, seriesSize)) {
		cerr << "Error al cargar el data set de " << SERIES_FILE << "\n";
		delete [] series;
		return 0;
	}
    peliculasSize = countDataLinesInCSV(PELICULAS_FILE);
 	if(peliculasSize == -1) {
		cerr << "No se pudo cargar el data set desde " << PELICULAS_FILE << "\n";
		return 0;
	}
	peliculas = new(nothrow) Pelicula[peliculasSize];
	if(peliculas == nullptr) {
		cerr << "No hubo memoria para el arreglo creado con datos de " << PELICULAS_FILE << "\n";
		return 0;
	}
    if(!loadPeliculaFromCSV(PELICULAS_FILE, peliculas, peliculasSize)) {
		cerr << "Error al cargar el data set de " << PELICULAS_FILE << "\n";
		delete [] peliculas;
		return 0;
	}
    catalogoSize = peliculasSize + seriesSize;
    
    catalogo = new(nothrow) Video* [catalogoSize];
    if(catalogo == nullptr) {
		cerr << "No hubo memoria para el arreglo creado con datos de " << SERIES_FILE <<" y "<< PELICULAS_FILE<< "\n";
		return 0;
	}
    for(int i = 0; i < catalogoSize; i++)
        catalogo[i] = nullptr;
    for(int i = 0; i < catalogoSize; i++){
        if(i<peliculasSize)
            catalogo[i] = &peliculas[i];
        else
            catalogo[i] = &series[i-peliculasSize];
    }

    for(int i = 0; i<catalogoSize; i++)
        catalogo[i]->mostrarDatos();

/*  int opcion;
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
*/
    delete[] peliculas;
    delete[] series;
    delete[] catalogo;
    return 0;
}