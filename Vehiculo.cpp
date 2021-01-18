#include "Vehiculo.hpp"

Vehiculo::Vehiculo(int cromosoma, Torque* torque, Pliege* pliege, double energia)
{
    this->cromosoma = cromosoma;
    this->torque = torque;
    this->pliege = pliege;
    this->energia = energia;
    this->energiaPorKm = torque->getEnergia() + pliege->getEnergia();
}

int Vehiculo::probarAgarreTorque(int agarre)
{
    int min = torque->getAgarreMin();
    int max = torque->getAgarreMax();
    if(min <= agarre && max >= agarre)
        return 0;
    if(min > agarre)
        return min - agarre;
    return agarre - max;
}

int Vehiculo::probarHumedadTorque(int agarre)
{
    int min = torque->getHumedadMin();
    int max = torque->getHumedadMax();
    if(min <= agarre && max >= agarre)
        return 0;
    if(min > agarre)
        return min - agarre;
    return agarre - max;
}

int Vehiculo::probarFirmezaTorque(int agarre)
{
    int min = torque->getFirmezaMin();
    int max = torque->getFirmezaMax();
    if(min <= agarre && max >= agarre)
        return 0;
    if(min > agarre)
        return min - agarre;
    return agarre - max;
}

int Vehiculo::probarAgarrePliege(int agarre)
{
    int min = pliege->getAgarreMin();
    int max = pliege->getAgarreMax();
    if(min <= agarre && max >= agarre)
        return 0;
    if(min > agarre)
        return min - agarre;
    return agarre - max;
}

int Vehiculo::probarHumedadPliege(int agarre)
{
    int min = pliege->getHumedadMin();
    int max = pliege->getHumedadMax();
    if(min <= agarre && max >= agarre)
        return 0;
    if(min > agarre)
        return min - agarre;
    return agarre - max;
}

int Vehiculo::probarFirmezaPliege(int agarre)
{
    int min = pliege->getFirmezaMin();
    int max = pliege->getFirmezaMax();
    if(min <= agarre && max >= agarre)
        return 0;
    if(min > agarre)
        return min - agarre;
    return agarre - max;
}