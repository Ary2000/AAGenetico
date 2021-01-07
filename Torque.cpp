#include "Torque.hpp"

Torque::Torque(int idTorque, int firmezaMin, int firmezaMax, int humedadMin, int humedadMax, int agarreMin, int agarreMax, int energia)
{
    this->idTorque = idTorque;
    this->firmezaMax = firmezaMax;
    this->firmezaMin = firmezaMin;
    this->humedadMax = humedadMax;
    this->humedadMin = humedadMin;
    this->agarreMax = agarreMax;
    this->agarreMin = agarreMin;
    this->energia = energia;
}
