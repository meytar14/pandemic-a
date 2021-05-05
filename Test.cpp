#include "doctest.h"
#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "Scientist.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "FieldDoctor.hpp"
#include "Researcher.hpp"
#include "Virologist.hpp"
using namespace pandemic;
using namespace std;


TEST_CASE("cities cubes") {
    Board board;
    board[City::Kinshasa] = 3;      
	board[City::HoChiMinhCity] = 1;
	board[City::MexicoCity] = 1;
    CHECK(board[City::Kinshasa] == 3);
    CHECK(board[City::HoChiMinhCity] == 1);
    CHECK(board[City::MexicoCity] == 1);
    board[City::MexicoCity] = 5;
    CHECK(board[City::MexicoCity] == 5);
    board[City::MexicoCity] = 10;
    CHECK(board[City::MexicoCity] == 10);
}


TEST_CASE("treat") {
Board board;
board[City::Johannesburg] = 3;
board[City::Atlanta] = 5;
OperationsExpert player {board, City::Atlanta};  
	player.take_card(City::Johannesburg)
    .take_card(City::Baghdad)
    .take_card(City::Cairo)
    .take_card(City::Chicago)
    .take_card(City::Delhi)
    .take_card(City::Mumbai)
	 .take_card(City::Algiers);
player.fly_direct(City::Johannesburg);
player.treat(City::Johannesburg);
CHECK(board[City::Johannesburg] == 2);
player.treat(City::Atlanta);
CHECK(board[City::Atlanta] == 4);
player.build();
player.discover_cure(Color::Black);
player.treat(City::Atlanta);
CHECK(board[City::Atlanta] == 0);
CHECK(board[City::Johannesburg] == 2);
CHECK_THROWS(player.fly_direct(City::Essen));
CHECK_THROWS(player.fly_direct(City::HoChiMinhCity));
CHECK_THROWS(player.fly_shuttle(City::HoChiMinhCity));
player.fly_direct(City::Mumbai);
CHECK_THROWS(player.fly_shuttle(City::Atlanta));
CHECK_THROWS(player.build());
}

TEST_CASE("role") {
Board board;
OperationsExpert player1 {board, City::Atlanta}; 
FieldDoctor player2 {board, City::Atlanta}; 
Scientist player3 {board, City::Atlanta,4}; 
Medic player4 {board, City::Atlanta}; 
Researcher player5 {board, City::Atlanta}; 
Virologist player6 {board, City::Atlanta}; 

CHECK(player1.role()=="OperationsExpert");
CHECK(player2.role()=="FieldDoctor");
CHECK(player3.role()=="Scientist");
CHECK(player4.role()=="Medic");
CHECK(player5.role()=="Researcher");
CHECK(player6.role()=="Virologist");
}