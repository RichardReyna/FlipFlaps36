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
class Player;

struct Screen2 : Graph_lib::Window
{
	public:
		Screen2(Point, int, int, const string&);
	private:
		void instructions_pressed();
                void game_state_pressed();
                void end_state_pressed();
		void quit();
		void flip_p();
		void draw_high_scores();
		void draw_pancakes();
		void erase_pancakes();
		void erase_high_scores();

		static void cb_flip(Address, Address);
		static void cb_to_instructions(Address, Address);
                static void cb_to_game_state(Address, Address);
                static void cb_to_end_state(Address, Address);
		static void cb_get_diff(Address, Address);
		static void cb_quit(Address, Address);
	private:
		Button to_instructions;
		Image splash;
		Image instructions;
		In_box get_name;
		Button flip;
//		Button to_instructions;
	        Button to_game_state;
                Button to_end_state;
		Button to_quit;
		In_box difficulty;
		In_box pick_place;
		Text score_table;
//		Image splash;
		Vector_ref<Text> names;
		Vector_ref<Text> scores;
		Vector_ref<Text> ppp;
//		vector<Pancake> temp_pancakes;
		int place;
		int num_of_tries;
		bool sorted;
};

#endif
