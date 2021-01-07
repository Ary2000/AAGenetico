#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "rxcpp/rx.hpp"

using json = nlohmann::json;
using namespace std;

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
        NumTramo = "tramo"+to_string(indice);
        jsonfile["Tramos"][NumTramo]["Agarre"] = DatosTramos[indice][0];
        jsonfile["Tramos"][NumTramo]["Firmeza"] = DatosTramos[indice][1];
        jsonfile["Tramos"][NumTramo]["Humedad"] = DatosTramos[indice][2];
        jsonfile["Tramos"][NumTramo]["KmEnd"] = DatosTramos[indice][3];
        jsonfile["Tramos"][NumTramo]["KmStart"] = DatosTramos[indice][4];
    }
    
    

    std::ofstream file("MapaSensor.json");
    file << jsonfile.dump(1);
}

std::vector<std::vector<double>> JsonReader(std::string NombreJson, std::vector<std::vector<double>>* PointerVectorGlobal){

    json bufferJson;
    std::string bufferString;
    std::vector<std::vector<double>> &DatosTramos = *PointerVectorGlobal;
    std::vector<std::vector<double>> VectorRecorrido = {};
    std::vector<double> bufferDatos = {};

    std::ifstream file(NombreJson);
    json j = json::parse(file);

    for (auto it = j["Tramos"].begin(); it != j["Tramos"].end(); ++it){
    bufferJson = it.value();
    bufferString=bufferJson.dump();
    //cout << "Waiting..." << endl;
    auto values = rxcpp::observable<>::timer<>(std::chrono::seconds(10));
    values.subscribe([](int v) {});
    bufferDatos= parserDatos(bufferString);
    DatosTramos.push_back(bufferDatos);
    VectorRecorrido.push_back(bufferDatos);
    JsonWritter(VectorRecorrido);
    //cout << it.key() << " | " << it.value() << "\n";
    }
    /*
    //info de los tramos
    
    for (int i = 0; i < DatosTramos.size(); i++){
       cout<<"Tramo "<<i<<endl;
       for (int z = 0; z < DatosTramos[i].size(); z++){
        cout<< DatosTramos[i][z]<< " ";
        }
        cout<<endl;
    }
    */
   
    return DatosTramos;

}

