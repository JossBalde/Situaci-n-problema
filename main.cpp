#include "video.h"
#include <iostream>
using namespace std;

int main(){
    string nombre,id,genero;
    int duracion, califiacion; 
    cout<<"Agrega pelicula\n";
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Id: ";
    cin>>id;
    cout<<"Genero: ";
    cin>>genero;
    cout<<"Duracion en minutos: ";
    cin>>duracion;
    Video v(id, nombre, genero, duracion);
    v.print();
    cout<<"Asignar califiacion: ";
    cin>>califiacion;
    if (!v.setCalificacion(califiacion))
    return 1;
    v.print();

    return 0;
}