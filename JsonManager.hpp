#ifndef JSONMANAGER_HPP
#define JSONMANAGER_HPP

#include "json.hpp"
#include "Tramo.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include "rxcpp/rx.hpp"

using json = nlohmann::json;
//using namespace std;

std::vector<double> parserDatos(std::string Tramo){
    int indice = 10;
    std::string buffer = "";
    double bufferNumero = 0;
    std::vector<double> Datos={};
    while (Tramo.at(indice) != *",")
    {
        buffer += Tramo.at(indice);
        indice++;
    }
    indice+=11;
    bufferNumero += stod(buffer);
    Datos.push_back(bufferNumero);
    buffer="";
    bufferNumero=0;
    while (Tramo.at(indice) != *",")
    {
        buffer += Tramo.at(indice);
        indice++;
    }
    indice+=11;
    bufferNumero += stod(buffer);
    Datos.push_back(bufferNumero);
    buffer="";
    bufferNumero=0;
    while (Tramo.at(indice) != *",")
    {
        buffer += Tramo.at(indice);
        indice++;
    }
    indice+=9;
    bufferNumero += stod(buffer);
    Datos.push_back(bufferNumero);
    buffer="";
    bufferNumero=0;
    while (Tramo.at(indice) != *",")
    {
        buffer += Tramo.at(indice);
        indice++;
    }
    indice+=11;
    bufferNumero += stod(buffer);
    Datos.push_back(bufferNumero);
    buffer="";
    bufferNumero=0;
    while (Tramo.at(indice) != *"}")
    {
        buffer += Tramo.at(indice);
        indice++;
    }
    bufferNumero += stod(buffer);
    Datos.push_back(bufferNumero);

    return Datos;
}

void JsonWritter(std::vector<std::vector<double>> DatosTramos){
    json jsonfile;
    std::string NumTramo;
    for (int indice = 0; indice < DatosTramos.size(); indice++)
    {
        NumTramo = "tramo"+std::to_string(indice);
        jsonfile["Tramos"][NumTramo]["Agarre"] = DatosTramos[indice][0];
        jsonfile["Tramos"][NumTramo]["Firmeza"] = DatosTramos[indice][1];
        jsonfile["Tramos"][NumTramo]["Humedad"] = DatosTramos[indice][2];
        jsonfile["Tramos"][NumTramo]["KmEnd"] = DatosTramos[indice][3];
        jsonfile["Tramos"][NumTramo]["KmStart"] = DatosTramos[indice][4];
    }
    
    

    std::ofstream file("MapaSensor.json");
    file << jsonfile.dump(1);
}

void JsonReader(std::vector<Tramo*> &VectorPunteros, bool &sigue){

    json bufferJson;
    std::string bufferString;
    //std::vector<std::vector<double>> &DatosTramos = *PointerVectorGlobal;
    std::vector<std::vector<double>> VectorRecorrido = {};
    std::vector<double> bufferDatos = {};

    //std::ifstream file("C://Users//tian_//OneDrive//Desktop//Caso#6//AAGenetico//Mapa.json");
    std::ifstream file("C://Users//Ary//Documents//GitHub//AAGenetico//Mapa.json");
    json j = json::parse(file);

    for (auto it = j["Tramos"].begin(); (it != j["Tramos"].end()) && sigue == true; it++){
        bufferJson = it.value();
        bufferString=bufferJson.dump();
        auto values = rxcpp::observable<>::timer<>(std::chrono::seconds(10));
        values.subscribe([](int v) {});
        bufferDatos= parserDatos(bufferString);
        //DatosTramos.push_back(bufferDatos);
        VectorPunteros.push_back(new Tramo(bufferDatos[4],bufferDatos[3],bufferDatos[1], bufferDatos[2], bufferDatos[0]));
        VectorRecorrido.push_back(bufferDatos);
        JsonWritter(VectorRecorrido);
    }

    VectorPunteros.push_back(nullptr);
}

#endif