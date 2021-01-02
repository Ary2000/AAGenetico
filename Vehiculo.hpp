#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "Pliege.hpp"
#include "Torque.hpp"

class Vehiculo{
    private:
        int cromosoma;
        Torque* torque;
        Pliege* pliege;

    public:
        //Constructor
        Vehiculo(int cromosoma, Torque* torque, Pliege* pliege);

        //get
        int getCromosoma() { return cromosoma; }
};

#endif