/*#ifndef PLAYER_H
#define PLAYER_H

#include "std_lib_facilities_4.h"
#include <map>
#include <fstream>
#include <iostream>
#include <string>

//fstream fs;

class Player
{
	public:
//		multimap<string, int>& get_high_scores();
		void add_name(string);
		void add_score(int);
		vector<string> get_names();
		vector<int> get_scores();
		multimap<string, int> get_high_scores();
		void write_high_score(int);
		void sort_file();
		fstream fs;
	private:
		//...
	private:
		multimap<string, int> high_scores;
		//fstream fs;
		vector<string> names;
		vector<int> scores;
};

#endif
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "std_lib_facilities_4.h"

class Player
{
	public:
//		string get_name();
		int get_score();

		void set_name(string);
		void set_score(int);
		void store_high_score();
		string get_high_score(int);
		void sort_high_scores();
	private:
		bool check_sorted(vector<string>);
		void rewrite_file();
//		void store_name();
//		void store_score();
	private:
		ofstream os;
		ifstream ifs;
		string name;
		int score;
		vector<string> lines;
};

#endif
