#include "Pancake.h"

Pancake::Pancake(int difficulty_level)
{
	difficulty = difficulty_level;
}

// Accessor for difficulty field
int Pancake::get_difficulty()
{
	return difficulty;
}

// Mutator for difficulty field
void Pancake::set_difficulty(int diff)
{
	difficulty = diff;
}

// Creates pancakes w/ varying widths
void Pancake::init_stack(vector<Pancake> stack_init)
{/*
	switch(difficulty)
	{
		case 1:
			for (int i = 0; i < difficulty; ++i)
			{
				stack_init.push_back(new Pancake);
				stack_init[i].width = rand() % (difficulty + 1)
			}
		//...more cases...
	}*/
}

void Pancake::flip()
{

}

// Randomizes stack order
void Pancake::stack(vector<Pancake> stack_init, vector<Pancake> stack_rand)
{/*
	int size = stack_init.size();
	int n = size;
	while (n > 0)
	{
		int pos = rand() % (size + 1);
		if (stack_rand[pos] == NULL)
		{
			stack_rand[pos] = stack_init[n];
			--n;
		}

		else
		{
			continue();
		}
	}*/
}

void Pancake::find_solution()
{

}

