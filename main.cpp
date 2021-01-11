#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <thread>  

#include "Torque.hpp"
#include "Pliege.hpp"
#include "Vehiculo.hpp"
#include "FabricaVehiculos.hpp"
#include "Tramo.hpp"
#include "JsonManager.hpp"
#include "Explorador.hpp"

#include "Torque.cpp"
#include "Pliege.cpp"
#include "Vehiculo.cpp"
#include "FabricaVehiculos.cpp"
#include "Tramo.cpp"
#include "Explorador.cpp"


int main(){
    Explorador explorador;
    explorador.realizarTrabajo();

    return 0;
}