#include "JsonManager.hpp"
#include <thread>  

using namespace std;
std::vector<std::vector<double>>* v = new vector<std::vector<double>>();
std::vector<std::vector<double>> &vr = *v;

void printVector(std::vector<double> vector){
    for (int i = 0; i < vector.size(); i++)
    {
        cout<<vector[i];
    }
    
}

int main()
{
    std::thread first (JsonReader,"Mapa.json",v);
    while(true){
        if (vr.size()!=0)
        {
            std::thread second (printVector,vr[0]);
            second.join();
            cout<<endl;
            if (vr[0][0]==9999.99)
        {
            break;
        }
            vr.erase(vr.begin()); 
        }
        
        
    }

    first.join();
    
    cout<<endl<<"Finish";
    return 0;
}

