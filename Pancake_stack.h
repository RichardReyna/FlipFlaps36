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

class Pancake;

class Pancake_stack
{
        Vector_ref<Pancake> pancakes;
        public:
//              void push_back(Pancake& p);
                void flip(int);
                int myrandom(int);
                vector <int> random_pancake(int);
                int calc_score();
                int find_solution();
        private:
                // Functions
        private:
                int difficulty;
                int num_flips;

};

#endif
