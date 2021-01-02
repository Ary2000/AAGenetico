#include "Pliege.hpp"

Pliege::Pliege(int idPliege, int firmezaMax, int firmezaMin, int humedadMax, int humedadMin, int agarreMax, int agarreMin, int energia)
{
    this->idPliege = idPliege;
    this->firmezaMax = firmezaMax;
    this->firmezaMin = firmezaMin;
    this->humedadMax = humedadMax;
    this->humedadMin = humedadMin;
    this->agarreMax = agarreMax;
    this->agarreMin = agarreMin;
    this->energia = energia;
}