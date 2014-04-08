#ifndef PANCAKE_H
#define PANCAKE_H

#include "std_lib_facilities_4.h"

class Pancake
{
	public:
		Pancake(int difficulty_level);
		int get_difficulty();
		void set_difficulty(int diff);
	private:
		// Functions
		void init_stack(vector<Pancake> stack_init);
		void flip();
		void stack(vector<Pancake> stack_init, vector<Pancake> stack_rand);
		void find_solution();
	private:
		// Vars
//		vector<Pancake> pancakes;
//		vector<Pancake> stack;

		int difficulty;
		int width;
};

#endif
