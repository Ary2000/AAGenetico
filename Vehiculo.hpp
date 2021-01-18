#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "Pliege.hpp"
#include "Torque.hpp"

//#define ENERGIA_TOTAL 7000

class Vehiculo{
    private:
        int cromosoma;
        Torque* torque;
        Pliege* pliege;
        double energia;// = ENERGIA_TOTAL;

        double energiaPorKm;

    public:
        //Constructor
        Vehiculo(int cromosoma, Torque* torque, Pliege* pliege, double energia);

        //get
        int getCromosoma() { return cromosoma; }
        double getEnergiaPorKm() { return energiaPorKm; }
        double getEnergiaTotal() { return energia; }
        int getIDTorque() { return torque->getID(); }
        int getIDPliege() { return pliege->getID(); }
        
        int probarFirmezaTorque(int firmeza);
        int probarHumedadTorque(int humedad);
        int probarAgarreTorque(int agarre);

        int probarFirmezaPliege(int firmeza);
        int probarHumedadPliege(int humedad);
        int probarAgarrePliege(int agarre);
};

#endif