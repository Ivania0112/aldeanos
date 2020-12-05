#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

string Civilizacion::getNombre()const
{
    return nombre;
}

void Civilizacion::setNombre(const string &value)
{
    nombre= value;
}

int Civilizacion::getUbicacion_x()const
{
    return ubicacion_x;
}

void Civilizacion::setUbicacion_x(int value)
{
    ubicacion_x= value;
}

int Civilizacion::getUbicacion_y()const
{
    return ubicacion_y;
}

void Civilizacion::setUbicacion_y(int value)
{
    ubicacion_y= value;
}

size_t Civilizacion::getPuntuacion()const
{
    return puntuacion;
}

void Civilizacion::setPuntuacion(const size_t &value)
{
    puntuacion= value;
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::EliminarNombre(const string &n)
{
    for (auto it=aldeanos.begin(); it !=aldeanos.end(); it++) {
        Aldeano &j=*it;
        if(n==j.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::EliminarSalud(int n)
{
    aldeanos.remove_if([n](const Aldeano &a){return a.getSalud()<n;});
}

void Civilizacion::EliminarEdad()
{
    aldeanos.remove_if([](const Aldeano &a){ return a.getEdad()<60;});
}

void Civilizacion::ClasificarNombre()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2 ){return
    a1.getNombre()<a2.getNombre();});
}

void Civilizacion::ClasificarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2 ){return
    a1.getEdad()>a2.getEdad();});
}

void Civilizacion::ClasificarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2 ){return
    a1.getSalud()>a2.getSalud();});
}

Aldeano *Civilizacion::BuscarAldeano(const Aldeano &a)
{
    auto it = find(aldeanos.begin(), aldeanos.end(), a);
    if (it == aldeanos.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}

void Civilizacion::MostrarAldeanos()
{
    cout<<left;
    cout<<setw(10)<<"Nombre";
    cout<<setw(10)<<"Edad";
    cout<<setw(10)<<"Genero";
    cout<<setw(10)<<"Salud";
    cout<<endl;
    for (auto it= aldeanos.begin(); it != aldeanos.end(); it++) {
        Aldeano &a= *it;
        cout<<a;
    }
}