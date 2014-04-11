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
int myrandom (int i) { return rand()%i;}
vector <int> random_pancake (int difficulty) {
	srand ( unsigned (time(0) ) );
	vector<int> pancake;
	for (int i=0; i<difficulty; ++i) 
		pancake.push_back(i); 
	random_shuffle ( pancake.begin(), pancake.end(), myrandom);
	//cout << "pancake contains:";
	//for (vector<int>::iterator it=pancake.begin(); it!=pancake.end(); ++it)
	//	cout << ' ' << *it;
	//	cout << '\n';
}
//Calculates user's score
int calc_score(){
	int score;
	if (num_flips-find_solution().size() >= 10)
		score = 0;
	else score = (100-10*(flips-find_solution().size()))*difficulty;
}
void Pancake::find_solution()
{

}

