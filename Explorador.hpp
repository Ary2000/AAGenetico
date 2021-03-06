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
#define CANTIDAD_VEHICULOS 100
#define CANTIDAD_CICLOS 10
#define ENERGIA_TOTAL 7000
#define CICLOS_FALLIDOS_MAXIMO 5
#define CICLOS 50

class Explorador{

    private:
        //Atributos
        std::vector<std::vector<double>>* v = new std::vector<std::vector<double>>();
        std::vector<std::vector<double>> &vr = *v;
        FabricaVehiculos fabrica;
        double energiaActual = ENERGIA_TOTAL;
        std::vector<Tramo*> tramos;

        //Metodos
        
        void reproduccionMuerte(std::vector<Vehiculo*>& poblacion);
        std::vector<Vehiculo*> recorrerTramo(std::vector<Vehiculo*> poblacion, Tramo* tramo);
        bool algortimoGenetico(Tramo* tramo);
        int compararPropiedadesVehiculoTramo(Vehiculo* vehiculo, Tramo* tramo);
        bool recorreConSuficienteEnergia(Vehiculo* vehiculo, Tramo* tramo);
        //void metodoThread();

    public:
        Explorador();
        void realizarTrabajo();
};

#endif