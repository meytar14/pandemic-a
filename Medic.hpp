#pragma once
#include "Player.hpp"
#include "Board.hpp"
using namespace pandemic;
namespace pandemic
{
    class Medic : public Player
    {
        public:
        Medic(Board b,City city):Player(b,city,"Medic")
        {
           
        }
        ~ Medic()
        {
            
        }

    };
}