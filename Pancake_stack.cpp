#include "Pancake_stack.h"
//#include "Pancake.h"

void Pancake_stack::init_stack()
{
        for(int i = 0; i < 10; ++i)
        {
                Pancake * p = new Pancake(
                        Point(240 - 12 * i, 160 + 12 * i), 150 + 24 * i);

                pancakes.push_back(*p);
//              pancakes[i].set_fill_color(Color::yellow);
        }

        for(int i = 0; i < pancakes.size(); ++i)
        {
                pancakes[i].set_fill_color(Color::yellow);
        }
}


void Pancake_stack::flip(int n)
{
        // garbage to avoid compiler warnings
        ++n;
}

int Pancake_stack::gen_rand(int i)
{
        return rand()%i;
}

vector <int> Pancake_stack::random_pancake (int difficulty)
{
     srand ( unsigned (time(0) ) );
        vector <Pancake> *p;
        for (int x=0; x<difficulty; ++x)
          p.push_back(new Pancake (Point 240 - 12 * x , 160 + 12 * x ));
         random_shuffle ( p.begin(), p.end(), myrandom);
        vector_ref <Pancake> randomized; 
        randomized.push_back(p);
}

//Calculates user's score
int Pancake_stack::calc_score(){
        int score = 0;
//      if (num_flips-find_solution().size() >= 10)
//              score = 0;
//      else score = (100-10*(num_flips-find_solution().size()))*difficulty;

        return score;
}

void Pancake_stack::store_score()
{
        //...
}
