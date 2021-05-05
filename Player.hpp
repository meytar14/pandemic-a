#pragma once
#include "Board.hpp"
#include "Role.hpp"
#include "Color.hpp"
namespace pandemic
{

class Player
{
    protected:
    City current_city;
    Board board;
    unordered_set<City> cards;
    string role_;

    public:
    Player(Board b,City city,string r)
    {
        board=b;
        current_city=city;
        role_=r;
    }
    ~Player()
    {
        
    }
    Player& drive(City city);
    Player& fly_direct(City city);
    Player& fly_charter(City city);
    Player& fly_shuttle(City city);
    Player& build();
    Player& discover_cure(Color color);
    Player& treat(City city);
    string role();
    Player& take_card(City city);


};



}