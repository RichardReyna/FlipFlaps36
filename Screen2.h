#ifndef SCREEN2_H
#define SCREEN2_H

#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Point.h"

using namespace Graph_lib;
using namespace std;

enum Game_State
{
        Start, Game, End
};

struct Screen2 : Graph_lib::Window
{
        public:
                Screen2(Point, int, int, const string&);
        private:
                void change(Game_State s);
                void game_state_pressed();
                void end_state_pressed();
                static void cb_to_game_state(Address, Address);
                static void cb_to_end_state(Address, Address);
        private:
               Button to_game_state;
               Button to_end_state;
//               In_box difficulty;
};

#endif
