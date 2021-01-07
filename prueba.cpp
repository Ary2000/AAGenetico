#include "rxcpp/rx.hpp"
#include "JsonManager.hpp"
#include <thread>  

using namespace std;
std::vector<std::vector<double>> a;

int main()
{
    
    cout << "Waiting..." << endl;
    auto values = rxcpp::observable<>::timer<>(std::chrono::seconds(10));
    values.subscribe([](int v) {cout << "Called after 1s." << endl;});
    std::thread first (JsonReader,"Mapa.json");
    a = first;

    cout<<endl<<a[0][1];
    
    return 0;
}

