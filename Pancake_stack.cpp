#include "Pancake_stack.h"
//#include "Pancake.h"

void Pancake_stack::init_stack()
{
        for(int i = 0; i < 7; ++i)
        {
//              pancakes.push_back(new Pancake(Point(50, 50), (i + 1) * 12));
                Pancake * p = new Pancake(
                        Point(320 - 12 * i, 60 + 12 * i), 100 + 24 * i);

                pancakes.push_back(*p);
                pancakes[i].set_fill_color(Color::yellow);
        }
}

void Pancake_stack::flip(int n)
{
        //...
}

int Pancake_stack::myrandom (int i)
{
        return rand()%i;
}

int Pancake_stack::find_solution()
{
        //...
}

void Pancake_stack::random_pancake (Vector_ref <Pancake> p)
{
//      srand ( unsigned (time(0) ) );
//      random_shuffle ( p.begin(), p.end(), myrandom);
}


//Calculates user's score
int Pancake_stack::calc_score(){
//      int score;
//      if (num_flips-find_solution().size() >= 10)
//              score = 0;
//      else score = (100-10*(num_flips-find_solution().size()))*difficulty;
}
