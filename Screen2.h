#ifndef SCREEN2_H
#define SCREEN2_H

#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Point.h"
#include "std_lib_facilities_4.h"

using namespace Graph_lib;
using namespace std;

class Pancake;
class Pancake_stack;

enum Game_State
{
        Start, Game, End
};

struct Screen2 : Graph_lib::Window
{
        public:
                Screen2(Point, int, int, const string&);
                Game_State get_state();
                int get_diff();
        private:
                void change(Game_State s);

                void game_state_pressed();
//              int get_diff();
                void end_state_pressed();
                void quit();
                void set_place(int);

                static void cb_to_game_state(Address, Address);
                static void cb_to_end_state(Address, Address);
                static void cb_get_diff(Address, Address);
                static void cb_quit(Address, Address);
                static void cb_place_1(Address, Address);
/*                static void cb_place_2(Address, Address);
                static void cb_place_3(Address, Address);
                static void cb_place_4(Address, Address);
                static void cb_place_5(Address, Address);
                static void cb_place_6(Address, Address);
                static void cb_place_7(Address, Address);
                static void cb_place_8(Address, Address);
                static void cb_place_9(Address, Address);*/
        private:
                Button to_game_state;
                Button to_end_state;
                Button to_quit;
                In_box difficulty;
                Button place_1;
/*                Button place_2;
                Button place_3;
                Button place_4;
                Button place_5;
                Button place_6;
                Button place_7;
                Button place_8;
                Button place_9;*/
                int diff;
                int place;
};

#endif
