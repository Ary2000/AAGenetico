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

Vehiculo* FabricaVehiculos::crearVehiculo(int numero)
{
    int torqueSeleccionado = 0;
    for(int contadorRango = 1; contadorRango <= torques.size(); contadorRango ++)
    {
        if(numero < ((((double) contadorRango) / ((double) torques.size()) * UINT8_MAX) + 1))
        {
            contadorRango--;
            int pliegeSeleccionado = 0;
            for(int contarRangoPliege = 1; contarRangoPliege <= plieges.size(); contarRangoPliege++)
            {
                if(numero < ((double)contadorRango/(double)torques.size() * UINT8_MAX + (double)contarRangoPliege/(double)canitdadCombinaciones * UINT8_MAX + 1))
                    return new Vehiculo(numero, torques[torqueSeleccionado], plieges[pliegeSeleccionado]);
               
                else
                    pliegeSeleccionado++;
                
            }
        }
        else
            torqueSeleccionado++;
    }
    return new Vehiculo(0, NULL, NULL);
}

Vehiculo* FabricaVehiculos::crearHijo(Vehiculo* padre, Vehiculo* madre)
{
    int cromosomaPadre = padre->getCromosoma();
    int cromosomaMadre = madre->getCromosoma();

    int tipoReproducion = rand() % 3;
    switch(tipoReproducion)
    {
        case 1:
            cromosomaPadre = cromosomaPadre >> 2;
            cromosomaPadre = cromosomaPadre << 2;
            cromosomaMadre = cromosomaMadre << 6;
            cromosomaMadre = cromosomaMadre >> 6;
            break;
        case 2:
            cromosomaPadre = cromosomaPadre >> 4;
            cromosomaPadre = cromosomaPadre << 4;
            cromosomaMadre = cromosomaMadre << 4;
            cromosomaMadre = cromosomaMadre >> 4;
            break;
        case 3:
            cromosomaPadre = cromosomaPadre >> 6;
            cromosomaPadre = cromosomaPadre << 6;
            cromosomaMadre = cromosomaMadre << 2;
            cromosomaMadre = cromosomaMadre >> 2;
            break;
    }
    int cromosomaHijo = cromosomaPadre + cromosomaMadre;
    if((rand() % 100) > PORCENTAJE_MUTACION)
    {
        int posicionToggle = rand() % 8;
        cromosomaHijo ^= 1UL << posicionToggle;
    }
    
    return crearVehiculo(cromosomaHijo);
}