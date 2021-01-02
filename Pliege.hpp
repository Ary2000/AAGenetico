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

};

#endif