#include "Pancake_stack.h"
#include "Pancake.h"
#include "find_solution.h"

// reorder stack according to flip pos
void Pancake_stack::flip(int pos)
{
	int temp;
	int begin = 0;

	while(begin < pos)
	{
		temp = index[begin];
		index[begin] = index[pos];
		index[pos] = temp;

		begin++;
		pos--;
	}

	pancakes = Vector_ref<Pancake>();
	for(int i = 0; i < index.size(); ++i)
	{
		pancakes.push_back(new Pancake(Point(240 - 12 * index[i], 160 + 12 * i), 150 + 24 * index[i]));
	}

	for(int i = 0; i < pancakes.size(); ++i)
	{
		pancakes[i].set_fill_color(Color::yellow);
	}
}

bool Pancake_stack::check_sorted()
{
	int n = 0;
	for(int i = 0; i < index.size() - 1; ++i)
	{
		if(index[i] < index[i + 1])
		{
			++n;
		}
	}

	if(n == index.size() - 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int gen_rand(int i)
{
	return rand()%i;
}

// Makes random stack of pancakes by generating a
// vector of random ints and generating a vector_ref
// of pancakes whose order uses the random ints as
// indices thus randomizing the stack
void Pancake_stack::make_stack(int diff)
{
	// Clear containers so that stack orders do not
	// consistently repeat for a given diff val
	pp = vector<Pancake>();
	p = vector<Pancake*>();
	index = vector<int>();
	pancakes = Vector_ref<Pancake>();

	srand ( unsigned ( time(0) ) );

	for (int i = 0; i < diff; ++i)
	{
		index.push_back(i + 1);
	}

	random_shuffle(index.begin(), index.end(), gen_rand);

	for (int i = 0; i < index.size(); ++i)
		p.push_back (new Pancake (Point (240 - 12 * index[i], 160 + 12 * i), 150 + 24 * index[i]));

	for(int i = 0; i < p.size(); ++i)
	{
		pancakes.push_back(p[i]);
	}

	for(int i = 0; i < pancakes.size(); ++i)
	{
		pancakes[i].set_fill_color(Color::yellow);
	}
}

void Pancake_stack::set_num_flips(int n)
{
	num_flips = n;
}

//Calculates user's score
int Pancake_stack::calc_score()
{
	int diff = index.size();
	cout << find_solution(index)->size();
//	int min_flips = find_solution(index);
	int min_flips = 1;
	int score = (100 - (num_flips - (min_flips - 1))) * diff;

	return score;
}
