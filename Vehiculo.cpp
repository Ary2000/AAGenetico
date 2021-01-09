#include "Vehiculo.hpp"

Vehiculo::Vehiculo(int cromosoma, Torque* torque, Pliege* pliege, double energia)
{
    this->cromosoma = cromosoma;
    this->torque = torque;
    this->pliege = pliege;
    this->energia = energia;
    this->energiaPorKm = torque->getEnergia() + pliege->getEnergia();
}