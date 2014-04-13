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
        private:
                void change(Game_State s);

                void game_state_pressed();
                void end_state_pressed();
                void quit();

                static void cb_to_game_state(Address, Address);
                static void cb_to_end_state(Address, Address);
                static void cb_quit(Address, Address);
        private:
                Button to_game_state;
                Button to_end_state;
                Button to_quit;
                Vector_ref<Shape> r_buffer;
//               In_box difficulty;
};

#endif
