#ifndef TRAMO_H
#define TRAMO_H

class Tramo{

    private:
        double kmStart;
        double kmEnd;
        double distancia;
        
        int firmeza;
        int humedad;
        int agarre;

    public:
        Tramo(int kmStart, int kmEnd, int firmeza, int humedad, int agarre);

        double getDistancia() { return distancia; }
        int getFirmeza() { return firmeza; }
        int getHumedad() { return humedad; }
        int getAgarre() { return agarre; }


};

#endif