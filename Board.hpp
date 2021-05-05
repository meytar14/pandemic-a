#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "City.hpp"
using namespace std;
namespace pandemic
{
class Board
{

private:
    unordered_map<City,string> city_color;//<city name , number of cubes>
    unordered_map<City,unordered_set<City>> cities_conection;
    unordered_map<City,int> cities_cubes;
    
public:
     Board()
     {
       

     }
    ~ Board()
    {

    }

    int& operator[](City city);
    friend std::ostream& operator<<(ostream& output,const Board& b);
    bool is_clean();
    void remove_cures();


    

};


}
