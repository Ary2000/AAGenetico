#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Torque.hpp"
#include "Pliege.hpp"
#include "Vehiculo.hpp"
#include "FabricaVehiculos.hpp"

#include "Torque.cpp"
#include "Pliege.cpp"
#include "Vehiculo.cpp"
#include "FabricaVehiculos.cpp"

#define CANTIDAD_VEHICULOS 10


int main(){

    srand(time(NULL));
    
    FabricaVehiculos fabrica;
    std::vector<Vehiculo*> poblacion;

    Vehiculo* padre = fabrica.crearVehiculo(255);
    Vehiculo* madre = fabrica.crearVehiculo(10);

    Vehiculo* hijo = fabrica.crearHijo(padre, madre);

    //for(int contador = 0; contador < CANTIDAD_VEHICULOS; contador++)
    //{
    //    int numeroRandom = rand() % UINT8_MAX;
    //    poblacion.push_back(fabrica.crearVehiculo(numeroRandom));
    //}

    return 0;
}