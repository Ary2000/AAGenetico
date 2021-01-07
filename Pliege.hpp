#ifndef PLIEGE_H
#define PLIEGE_H

class Pliege{

    private:
    //Propiedades
        int idPliege;

        int firmezaMin;
        int firmezaMax;

        int humedadMin;
        int humedadMax;

        int agarreMin;
        int agarreMax;

        int energia;

    public:
    //Constructor
        Pliege(int idTorque, int firmezaMin, int firmezaMax, int humedadMin, int humedadMax, int agarreMin, int agarreMax, int energia);

    //Gets
        int getFirmezaMin() { return firmezaMin; }
        int getFirmezaMax() { return firmezaMax; }

        int getHumedadMin() { return humedadMin; }
        int getHumedadMax() { return humedadMax; }

        int getAgarreMin() { return agarreMin; }
        int getAgarreMax() { return agarreMax; }

        int getEnergia() { return energia; }

    //Pruebas
        bool probarFirmeza(int firmeza){ return (firmeza >= firmezaMin && firmeza <= firmezaMax) ? true : false; }
        bool probarHumedad(int humedad){ return (humedad >= humedadMin && humedad <= humedadMax) ? true : false; }
        bool probarAgarre(int agarre){ return (agarre >= agarreMin && agarre <= agarreMax) ? true : false; }

};

#endif