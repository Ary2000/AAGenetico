#include "Vehiculo.hpp"

Vehiculo::Vehiculo(int cromosoma, Torque* torque, Pliege* pliege)
{
    this->cromosoma = cromosoma;
    this->torque = torque;
    this->pliege = pliege;
}