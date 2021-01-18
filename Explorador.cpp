#include "Explorador.hpp"

Explorador::Explorador()
{
    fabrica = FabricaVehiculos();
    std::cout << "Se realizo" << std::endl;
}

void metodoThread(std::vector<Tramo*> &tramos)
{
    JsonReader(tramos);
}

void Explorador::algortimoGenetico(Tramo* tramo)
{
    std::vector<Vehiculo*> poblacion;
    bool seEncontroRespuesta = false;
    for(int contadorVehiculos = 0; contadorVehiculos < CANTIDAD_VEHICULOS; contadorVehiculos++)
            poblacion.push_back(fabrica.crearVehiculo(rand() % 255, energiaActual));
    for(int ciclosAlgoritmo = 0; ciclosAlgoritmo < CICLOS_FALLIDOS_MAXIMO; ciclosAlgoritmo++)
    {
        for(int ciclosVida = 0; ciclosVida < CICLOS; ciclosVida++)
        {
            poblacion = recorrerTramo(poblacion, tramo);
            reproduccionMuerte(poblacion);
        }
        double energiaAGastar = poblacion[0]->getEnergiaPorKm() * tramo->getDistancia();
        if(compararPropiedadesVehiculoTramo(poblacion[0], tramo) && poblacion[0]->getEnergiaPorKm() * tramo->getDistancia() <= poblacion[0]->getEnergiaTotal())
        {
            std::cout << "Tramo:" << std::endl << "Firmeza: " << tramo->getFirmeza() << std::endl << "Humedad: " << tramo->getHumedad() << std::endl << "Agarre: " << tramo->getAgarre() << std::endl << "Mejor configuracion:" << std::endl << "Torque: " << poblacion[0]->getIDTorque() << std::endl << "Pliege: " << poblacion[0]->getIDPliege() << std::endl;
            seEncontroRespuesta = true;
            energiaActual -= energiaAGastar;
            break;
        }
    }
    if(!seEncontroRespuesta)
        std::cout << "Tramo:" << std::endl << "Firmeza: " << tramo->getFirmeza() << std::endl << "Humedad: " << tramo->getHumedad() << std::endl << "Agarre: " << tramo->getAgarre() << std::endl;
        std::cout << "Mejor configuracion" << std::endl << "No se encontro ninguna configuracion que pueda recorrer todo el tramo o tenga suficiente energia para recorrelo todo" << std::endl;
}

void Explorador::realizarTrabajo()
{
    std::thread first (metodoThread, std::ref(tramos));
    srand(time(NULL));
    
    
    //tramos.push_back(new Tramo(0, 100, 10, 100, 5));
    
    //Codigo que le el mapa
   while (true)
   {
       if (tramos.size()!=0)
       {
           if (tramos[0]==nullptr)
           {
               break;
           }
           algortimoGenetico(tramos[0]);
           tramos.erase(tramos.begin());
       }
       
   }
   
   // while(int posicionTramo = 0; posicionTramo < tramos.size(); posicionTramo++)
        //algortimoGenetico(tramos[posicionTramo]);

    first.join();
    std::cout << std::endl <<"Finish";
}

bool comparacion(std::vector<double> elemento1, std::vector<double> elemento2)
{
    if(elemento1[1] < elemento2[1]) return true;
    if(elemento1[1] == elemento2[1]) return elemento1[2] < elemento2[2];
    return false;
}

int Explorador::compararPropiedadesVehiculoTramo(Vehiculo* vehiculo, Tramo* tramo)
{
    return vehiculo->probarAgarreTorque(tramo->getAgarre()) + vehiculo->probarHumedadTorque(tramo->getHumedad()) + vehiculo->probarFirmezaTorque(tramo->getFirmeza()) +
           vehiculo->probarAgarrePliege(tramo->getAgarre()) + vehiculo->probarHumedadPliege(tramo->getHumedad()) + vehiculo->probarFirmezaPliege(tramo->getFirmeza());
}

std::vector<Vehiculo*> Explorador::recorrerTramo(std::vector<Vehiculo*> poblacion, Tramo* tramo)
{
    std::vector<std::vector<double>> resultadosVehiculos;
    for(int posicionVehiculo = 0; posicionVehiculo < poblacion.size(); posicionVehiculo++)
    {
                                      //Vehiculo, peso, energia
        resultadosVehiculos.push_back({(double)posicionVehiculo, 0, INT_MAX});
        resultadosVehiculos[posicionVehiculo][1] = compararPropiedadesVehiculoTramo(poblacion[posicionVehiculo], tramo);
        resultadosVehiculos[posicionVehiculo][2] = poblacion[posicionVehiculo]->getEnergiaPorKm();
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
   while(poblacion.size() != CANTIDAD_VEHICULOS) poblacion.push_back(fabrica.crearHijo(poblacion[rand() % cantidadVivir], poblacion[rand() % cantidadVivir], energiaActual));
}