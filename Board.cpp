#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace pandemic;
using namespace std;
namespace pandemic
{
   
    int& Board::operator[](City city)
    {
        return cities_cubes[city];
    }
    ostream& operator<<(ostream& output,const Board& b)
    {
        return output;
    }
    bool Board::is_clean()
    {
        return true;
    }
    void Board::remove_cures()
    {

    }


}
