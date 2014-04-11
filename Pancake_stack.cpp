#include "Pancake_stack.h"

void Pancake_stack::flip(int n)
{
        //...
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
