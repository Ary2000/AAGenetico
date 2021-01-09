#include "Explorador.hpp"

Explorador::Explorador()
{
    fabrica = FabricaVehiculos();
    std::cout << "Se realizo" << std::endl;
}

void Explorador::algortimoGenetico(Tramo* tramo)
{
    std::vector<Vehiculo*> poblacion;
    bool seEncontroRespuesta = false;
    for(int contadorVehiculos = 0; contadorVehiculos < CANTIDAD_VEHICULOS - 1; contadorVehiculos++)
            poblacion.push_back(fabrica.crearVehiculo(rand() % 255, energiaActual));
    poblacion.push_back(fabrica.crearVehiculo(0, energiaActual));
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
            std::cout << "El mejor carrito para el tramo con los datos: " << std::endl << "Firmeza: " << tramo->getfirmeza() << std::endl << "Humedad: " << tramo->getHumedad() << std::endl << "Agarre: " << tramo->getAgarre() << std::endl << "Seria el vehiculo con las siguientes configuraciones:" << std::endl << "Torque: " << poblacion[0]->getIDTorque() << std::endl << "Pliege: " << poblacion[0]->getIDPliege() << std::endl;
            seEncontroRespuesta = true;
            energiaActual -= energiaAGastar;
            break;
        }
    }
    if(!seEncontroRespuesta)
        std::cout << "No se encontro ninguna configuracion que recorra todo el tramo sin gastar toda la energia" << std::endl;
}

void Explorador::realizarTrabajo()
{
    srand(time(NULL));
    
    std::vector<Tramo*> tramos;
    tramos.push_back(new Tramo(0, 100, 10, 100, 5));
    /*
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
    */
    
    for(int posicionTramo = 0; posicionTramo < tramos.size(); posicionTramo++)
        algortimoGenetico(tramos[posicionTramo]);

    cout<<endl<<"Finish";
}

bool comparacion(const std::vector<double> elemento1, std::vector<double> elemento2)
{
    if(elemento1[1] > elemento2[1]) return true;
    if(elemento1[1] == elemento2[1]) return elemento1[2] < elemento2[2];
    return false;
}

bool Explorador::compararPropiedadesVehiculoTramo(Vehiculo* vehiculo, Tramo* tramo)
{
    if(vehiculo->probarAgarre(tramo->getAgarre()) &&
       vehiculo->probarFirmeza(tramo->getfirmeza()) && 
       vehiculo->probarHumeadad(tramo->getHumedad()))
        return true;
    return false;
}

std::vector<Vehiculo*> Explorador::recorrerTramo(std::vector<Vehiculo*> poblacion, Tramo* tramo)
{
    std::vector<std::vector<double>> resultadosVehiculos;
    for(int posicionVehiculo = 0; posicionVehiculo < poblacion.size(); posicionVehiculo++)
    {
                                      //Vehiculo, km, energia
        resultadosVehiculos.push_back({(double)posicionVehiculo, 0, INT_MAX});
        if(compararPropiedadesVehiculoTramo(poblacion[posicionVehiculo], tramo))
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
   while(poblacion.size() != CANTIDAD_VEHICULOS) poblacion.push_back(fabrica.crearHijo(poblacion[rand() % cantidadVivir], poblacion[rand() % cantidadVivir], energiaActual));
}