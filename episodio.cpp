#include "episodio.h"
#include <iostream>
#include <fstream>
#include <sstream>


void Episodio::mostrarDatos() {
    std::cout<<"Id: "<<id<<", Nombre: "<<nombre<<", Genero: "<<genero<<", Duracion: "
    <<duracion<<", Calif.prom: "<<calificacion<<", Titulo: "<<titulo<<", Temporada: "<<temporada<<"\n";
}
void Episodio::setTemporada(int temporada){
    this->temporada = temporada;
}
void Episodio::setTitulo(std::string titulo){
    this->titulo = titulo;
}
bool loadSerieFromCSV(std::string fileName, Episodio* partArray, unsigned int arraySize) {
	std::ifstream		file(fileName);
	std::string			line;
	unsigned int	size = 0;

	if (!file.is_open()) {
		std::cerr << "Error al abrir el archivo: " << fileName << '\n';
		return false;
	}

	// Saltar el encabezado
	if(!getline(file, line)) {
		std::cerr << "El archivo no tiene header\n";
		file.close();
		return false;
	}

	std::cout << "Cargando archivo: " << fileName << '\n';

	while (getline(file, line)) {
		Episodio			newEpisodio;
		std::stringstream	ss(line);
		std::string			cell;
		int 			campo = 0, errores = 0;

		while (getline(ss, cell, ',')) {
			if(!cell.length())
				errores++;

			switch(campo) {
				case 0:
					newEpisodio.setId(cell);
					break;
				case 1:
					newEpisodio.setNombre(cell);
					break;
				case 2:
					newEpisodio.setDuracion(stoi(cell));
					break;
				case 3:
					newEpisodio.setGenero(cell);
					break;
                case 4:
                    newEpisodio.setTitulo(cell);
                    break;
                case 5:
                    newEpisodio.setTemporada(stoi(cell));
                    break;
				default:
					errores++;
					break;
			}
			campo++;
		}
    
		// Comparar si son el mismo numero de campos, aqui depende de cuantas 
		// entradas tiene cada clase, el número esta definido en el h
		// como PCPART_ATTRIB_SIZE
		if (errores || campo != EPISODIO_ATRIBUTE_SIZE) {
			std::cerr << "Error en la linea:\n" << line << '\n';
			file.close();
			return false;
		}

		if(size < arraySize) {
			partArray[size] = newEpisodio;
			size++;
		}
		else {
			std::cerr << "Error, el arreglo es muy pequeño\n";
			file.close();
			return false;
		}
	}

	file.close();
	return true;
}