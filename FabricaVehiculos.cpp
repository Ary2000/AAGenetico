#include "FabricaVehiculos.hpp"

FabricaVehiculos::FabricaVehiculos()
{
    torques.push_back(new Torque(1, 10, 20, 70, INT_MAX, 5, 10 ,12));
    torques.push_back(new Torque(2, 10, 30, 70, INT_MAX, 5, 20, 10));
    torques.push_back(new Torque(3, 10, 40, 60, 70, 5, 30, 9));
    torques.push_back(new Torque(4, 40, 60, 55, 60, 30, 50, 8));
    torques.push_back(new Torque(5, 60, 65, 40, 55, 50, 70, 7));
    torques.push_back(new Torque(6, 65, 80, 20, 40, 70, 90, 6));
    torques.push_back(new Torque(7, 80, INT_MAX, 0, 20, 90, INT_MAX, 4));

    plieges.push_back(new Pliege(10, 1, 10, 90, INT_MAX, 1, 5, 15));
    plieges.push_back(new Pliege(9, 10, 15, 80, INT_MAX, 5, 10, 13));
    plieges.push_back(new Pliege(8, 10, 20, 70, 80, 10, 25, 11));
    plieges.push_back(new Pliege(7, 20, 25, 60, 75, 20, 30, 10));
    plieges.push_back(new Pliege(6, 25, 50, 45, 60, 30, 50, 8));
    plieges.push_back(new Pliege(5, 50, 75, 20, 45, 50, 80, 7));
    plieges.push_back(new Pliege(4, 75, INT_MAX, 0, 20, 80, INT_MAX, 6));

    canitdadCombinaciones = torques.size() * plieges.size();
}

Vehiculo* FabricaVehiculos::crearVehiculo(int numero, double energia)
{
    if(numero <= UINT8_MAX && numero >= 0){
        int torqueSeleccionado = numero / (UINT8_MAX / torques.size());
        if(torqueSeleccionado == torques.size())
            torqueSeleccionado = torques.size() - 1;
        int pliegeSeleccionado = (numero - (double)UINT8_MAX * ((double)torqueSeleccionado / (double)torques.size())) / (UINT8_MAX / canitdadCombinaciones);
        if(pliegeSeleccionado == plieges.size())
            pliegeSeleccionado = plieges.size() - 1;
        return new Vehiculo(numero, torques[torqueSeleccionado], plieges[pliegeSeleccionado], energia);
    }
	return new Vehiculo(0, NULL, NULL, 0);
}

Vehiculo* FabricaVehiculos::crearHijo(Vehiculo* padre, Vehiculo* madre, double energia)
{
    int cromosomaPadre = padre->getCromosoma();
    int cromosomaMadre = madre->getCromosoma();

    int tipoReproducion = rand() % 5;
    cromosomaPadre = cromosomaPadre & combinacionPadre[tipoReproducion];
    cromosomaMadre = cromosomaMadre & combinacionMadre[tipoReproducion];

    int cromosomaHijo = cromosomaPadre + cromosomaMadre;
    if((rand() % 100) < PORCENTAJE_MUTACION)
    {
        int posicionToggle = rand() % 8;
        cromosomaHijo ^= 1UL << posicionToggle;
    }
    
    return crearVehiculo(cromosomaHijo, energia);
}