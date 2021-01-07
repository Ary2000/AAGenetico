#include "Tramo.hpp"

Tramo::Tramo(int kmStart, int kmEnd, int firmeza, int humedad, int agarre)
{
    this->kmStart = kmStart;
    this->kmEnd = kmEnd;
    this->distancia = kmEnd - kmStart;
    this->firmeza = firmeza;
    this->humedad = humedad;
    this->agarre = agarre;

}