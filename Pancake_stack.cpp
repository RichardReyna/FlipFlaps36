#include "Pancake_stack.h"
#include "Pancake.h"

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

//Random number generator
int myrandom (int i) { return rand()%i;}
//Put pancakes into random order
void Pancake_stack::randomize_stack(int difficulty)
{
	srand ( unsigned ( time(0) ) );
	vector<int> index;
	vector <Pancake*> p;
	
	for (int i=0; i<difficulty; ++i){
		index.push_back(i);}
		
	random_shuffle(index.begin(), index.end(), myrandom);
	
	for (int i=0;i<index.size();++i)
		p.push_back (new Pancake (Point (240 - 12 * index[i], 160 + 12 * i), 150 + 24 * index[i]));
		
	for(int i=0;i<p.size();++i)
		pancakes.push_back(p[i]);
		
	for(int i = 0; i < pancakes.size(); ++i){
		pancakes[i].set_fill_color(Color::yellow);}	
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
