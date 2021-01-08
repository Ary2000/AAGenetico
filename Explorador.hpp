#ifndef EXPLORADOR_HPP
#define EXPLORADOR_HPP

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

#define PORCENTAJE_MUERTE 0.3 // 30%
#define CANTIDAD_VEHICULOS 10
#define CANTIDAD_CICLOS 5

class Explorador{

    private:
        //Atributos
        std::vector<std::vector<double>>* v = new std::vector<std::vector<double>>();
        std::vector<std::vector<double>> &vr = *v;
        FabricaVehiculos fabrica;

        //Metodos
        //bool comparacion(const std::vector<double> elemento1, std::vector<double> elemento2);
        
        void reproduccionMuerte(std::vector<Vehiculo*>& poblacion);
        std::vector<Vehiculo*> recorrerTramo(std::vector<Vehiculo*> poblacion, Tramo* tramo);
        void algortimoGenetico(Tramo* tramo);

    public:
        Explorador();
        void realizarTrabajo();
};

#endif