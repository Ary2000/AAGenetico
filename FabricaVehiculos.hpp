#ifndef FABRICAVEHICULOS_HPP
#define FABRICAVEHICULOS_HPP

#include <vector>

#include "Pliege.hpp"
#include "Torque.hpp"
#include "Vehiculo.hpp"

#define CANTIDAD_TORQUES 7
#define CANTIDAD_PLIEGUES 7

class FabricaVehiculos{

    private:
        int canitdadCombinaciones;

        std::vector<Pliege*> plieges;
        std::vector<Torque*> torques;

    public:
        FabricaVehiculos();
        Vehiculo* crearVehiculo(int numero);
        Vehiculo* crearHijo(Vehiculo* padre, Vehiculo* madre);
};

#endif