#ifndef PANCAKE_STACK_H
#define PANCAKE_STACK_H

#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Simple_window.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include "Pancake.h"
#include "find_solution.h"

class Pancake_stack
{
	public:
		void flip(int);
		int gen_rand(int);
		void randomize_stack(int);
		int calc_score();
		void init_stack();
		vector<Pancake> pp;
		Vector_ref<Pancake> pancakes;
	private:
		//...
	private:
		int difficulty;
		int num_flips;
		int score;
};

#endif
