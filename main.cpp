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
//#include "JsonManager.hpp"
#include "Explorador.hpp"

#include "Torque.cpp"
#include "Pliege.cpp"
#include "Vehiculo.cpp"
#include "FabricaVehiculos.cpp"
#include "Tramo.cpp"
#include "Explorador.cpp"

#define PORCENTAJE_MUERTE 0.3 // 30%
#define CANTIDAD_VEHICULOS 10
#define CANTIDAD_CICLOS 5
/*
using namespace std;

std::vector<std::vector<double>>* v = new vector<std::vector<double>>();
std::vector<std::vector<double>> &vr = *v;

void printVector(std::vector<double> vector){
    for (int i = 0; i < vector.size(); i++)
    {
        cout<<vector[i];
    }
    
}

bool comparacion(const std::vector<double> elemento1, std::vector<double> elemento2)
{
    if(elemento1[1] > elemento2[1]) return true;
    if(elemento1[1] == elemento2[1]) return elemento1[2] < elemento2[2];
    return false;
}

std::vector<Vehiculo*> recorrerTramo(std::vector<Vehiculo*> poblacion, Tramo* tramo)
{
    std::vector<std::vector<double>> resultadosVehiculos;
    for(int posicionVehiculo = 0; posicionVehiculo < poblacion.size(); posicionVehiculo++)
    {
                                      //Vehiculo, km, energia
        resultadosVehiculos.push_back({(double)posicionVehiculo, 0, INT_MAX});
        if(poblacion[posicionVehiculo]->probarAgarre(tramo->getAgarre()) &&
           poblacion[posicionVehiculo]->probarFirmeza(tramo->getfirmeza()) &&
           poblacion[posicionVehiculo]->probarHumeadad(tramo->getHumedad()))
        {
            double distanciaTramo = tramo->getDistancia();
            double energiaPorKm = poblacion[posicionVehiculo]->getEnergiaPorKm();
            if((distanciaTramo * energiaPorKm) > poblacion[posicionVehiculo]->getEnergiaTotal())
                distanciaTramo = poblacion[posicionVehiculo]->getEnergiaTotal() / energiaPorKm;
            resultadosVehiculos[posicionVehiculo][1] = distanciaTramo;
            resultadosVehiculos[posicionVehiculo][2] = distanciaTramo * energiaPorKm;
        }
    }
    std::sort(resultadosVehiculos.begin(), resultadosVehiculos.end(), comparacion);
    std::vector<Vehiculo*> ranking;
    for(int posicionVehiculo = 0; posicionVehiculo < resultadosVehiculos.size(); posicionVehiculo++)
        ranking.push_back(poblacion[resultadosVehiculos[posicionVehiculo][0]]);
    return ranking;
}

void reproduccionMuerte(std::vector<Vehiculo*>& poblacion, FabricaVehiculos* fabrica)
{
   int cantidadMorir = poblacion.size() * PORCENTAJE_MUERTE;
   int cantidadVivir = CANTIDAD_VEHICULOS - cantidadMorir;
   while(poblacion.size() != cantidadVivir) poblacion.pop_back();
   while(poblacion.size() != CANTIDAD_VEHICULOS) poblacion.push_back(fabrica->crearHijo(poblacion[rand() % cantidadVivir], poblacion[rand() % cantidadVivir]));
}

void algortimoGenetico(Tramo* tramo, FabricaVehiculos* fabrica)
{
    std::vector<Vehiculo*> poblacion;
    for(int contadorVehiculos = 0; contadorVehiculos < CANTIDAD_VEHICULOS; contadorVehiculos++)
        poblacion.push_back(fabrica->crearVehiculo(rand() % 255));
    recorrerTramo(poblacion, tramo);
    reproduccionMuerte(poblacion, fabrica);
    cout << "El mejor carrito para el tramo con los datos: " << endl << "Firmeza: " << tramo->getfirmeza() << endl << "Humedad: " << tramo->getHumedad() << endl << "Agarre: " << tramo->getAgarre() << endl << "Seria el vehiculo con las siguientes configuraciones:" << endl << "Torque: " << poblacion[0]->getIDTorque() << endl << "Pliege: " << poblacion[0]->getIDPliege() << endl;
}
*/
int main(){

    srand(time(NULL));
    /*
    FabricaVehiculos* fabrica = new FabricaVehiculos();
    Tramo* tramo = new Tramo(0, 100, 10, 100, 5);
    
    int flag=0;
    std::thread first (JsonReader,"Mapa.json",v);
    while(flag<2){
        if (vr.size()!=0)
        {
            std::thread second (algortimoGenetico, tramo, fabrica);
            second.join();
            cout<<endl;
            vr.erase(vr.begin());
            flag++;
                
        }
    }

    first.join();
    
    cout<<endl<<"Finish";
    */

    Explorador explorador;
    explorador.realizarTrabajo();


    return 0;
}