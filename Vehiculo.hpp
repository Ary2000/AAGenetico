#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "Pliege.hpp"
#include "Torque.hpp"

#define ENERGIA_TOTAL 7000

class Vehiculo{
    private:
        int cromosoma;
        Torque* torque;
        Pliege* pliege;
        double energia = ENERGIA_TOTAL;

        double energiaPorKm;

    public:
        //Constructor
        Vehiculo(int cromosoma, Torque* torque, Pliege* pliege);

        //get
        int getCromosoma() { return cromosoma; }
        double getEnergiaPorKm() { return energiaPorKm; }
        double getEnergiaTotal() { return energia; }
        int getIDTorque() { return torque->getID(); }
        int getIDPliege() { return pliege->getID(); }
        
        bool probarFirmeza(int firmeza) { return (torque->probarFirmeza(firmeza) && pliege->probarFirmeza(firmeza)) ? true : false; }
        bool probarHumeadad(int humedad) {return (torque->probarHumedad(humedad) && pliege->probarHumedad(humedad)) ? true : false; }
        bool probarAgarre(int agarre) { return (torque->probarAgarre(agarre) && pliege->probarAgarre(agarre)) ? true : false; }
};

#endif