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
                vector<Pancake> pp;
                void flip(int);
                int calc_score();
                void store_score();
                void init_stack();
                void randomize_stack(int);
                Vector_ref<Pancake> pancakes;
                vector<int> index;
        private:
                //...
        private:
                int difficulty;
                int num_flips;
                int score;
};

#endif
