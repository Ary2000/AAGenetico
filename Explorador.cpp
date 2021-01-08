#include "Explorador.hpp"

Explorador::Explorador()
{
    fabrica = FabricaVehiculos();
    std::cout << "Se realizo" << std::endl;
}

void Explorador::algortimoGenetico(Tramo* tramo)
{
    std::vector<Vehiculo*> poblacion;
    for(int contadorVehiculos = 0; contadorVehiculos < CANTIDAD_VEHICULOS; contadorVehiculos++)
        poblacion.push_back(fabrica.crearVehiculo(rand() % 255));
    recorrerTramo(poblacion, tramo);
    reproduccionMuerte(poblacion);
    std::cout << "El mejor carrito para el tramo con los datos: " << std::endl << "Firmeza: " << tramo->getfirmeza() << std::endl << "Humedad: " << tramo->getHumedad() << std::endl << "Agarre: " << tramo->getAgarre() << std::endl << "Seria el vehiculo con las siguientes configuraciones:" << std::endl << "Torque: " << poblacion[0]->getIDTorque() << std::endl << "Pliege: " << poblacion[0]->getIDPliege() << std::endl;
}

void Explorador::realizarTrabajo()
{
    srand(time(NULL));
    
    Tramo* tramo = new Tramo(0, 100, 10, 100, 5);
    
    int flag=0;
    std::thread first (JsonReader,"C://Users//Ary/Documents//GitHub//AAGenetico//Mapa.json",v);
    while(flag<2){
        if (vr.size()!=0)
        {
            std::thread second (&Explorador::algortimoGenetico, this, tramo);
            second.join();
            cout<<endl;
            vr.erase(vr.begin());
            flag++;
                
        }
    }

    first.join();
    
    cout<<endl<<"Finish";
}

bool comparacion(const std::vector<double> elemento1, std::vector<double> elemento2)
{
    if(elemento1[1] > elemento2[1]) return true;
    if(elemento1[1] == elemento2[1]) return elemento1[2] < elemento2[2];
    return false;
}

std::vector<Vehiculo*> Explorador::recorrerTramo(std::vector<Vehiculo*> poblacion, Tramo* tramo)
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

void Explorador::reproduccionMuerte(std::vector<Vehiculo*>& poblacion)
{
   int cantidadMorir = poblacion.size() * PORCENTAJE_MUERTE;
   int cantidadVivir = CANTIDAD_VEHICULOS - cantidadMorir;
   while(poblacion.size() != cantidadVivir) poblacion.pop_back();
   while(poblacion.size() != CANTIDAD_VEHICULOS) poblacion.push_back(fabrica.crearHijo(poblacion[rand() % cantidadVivir], poblacion[rand() % cantidadVivir]));
}