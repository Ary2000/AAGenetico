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
    int flag=0;
    std::thread first (JsonReader,"Mapa.json",v);
    while(flag<2){
        if (vr.size()!=0)
        {
            std::thread second (printVector,vr[0]);
            second.join();
            cout<<endl;
            vr.erase(vr.begin());
            flag++;
                
        }
    }

    first.join();
    
    cout<<endl<<"Finish";
    return 0;
}

