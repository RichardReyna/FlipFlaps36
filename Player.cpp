#include "Player.h"

int Player::get_score()
{
	return score;
}

void Player::set_name(string s)
{
	name = s + '\n';
}

void Player::set_score(int n)
{
	score = n;
}

// Make score/name pair, write to persistent file
void Player::store_high_score()
{
	os.open("names.txt", ios_base::app);
	os << to_string(score) << "\t\t\t\t\t\t\t" << name;
	os.close();
}

// Get a certain high score from the file
string Player::get_high_score(int n)
{
        ifs.open("names.txt");
        string str1, str2;

	for(int i = 0; getline(ifs, str1) && i < n + 1; ++i)
	{
		if(i == n)
		{
			str2 = str1;
		}
	}
        ifs.close();

	return str2;
}

// Extract scores from string containing
// score/name pairs and test if they're in
// decsending order
bool Player::check_sorted(vector<string> v)
{
	int n = 0;
	for(int i = 0; i < v.size() - 1; ++i)
	{
                int score_a = stoi(lines[i].substr(0, 3));
                int score_b = stoi(lines[i + 1].substr(0, 3));

		if(score_a >= score_b)
		{
			++n;
		}
	}

	if(n == v.size() - 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Extract scores and do iterate sorting algo
// until high scores are in descending order
void Player::sort_high_scores()
{
	string str, temp_str;
	bool sorted;

	ifs.open("names.txt");

	lines = vector<string>();
	while(getline(ifs, str))
	{
		lines.push_back(str);
	}
	ifs.close();

	while(!sorted)
	{
		for(int i = 0; i < lines.size() - 1; ++i)
		{
			int a = stoi(lines[i].substr(0, 3));
			int b = stoi(lines[i + 1].substr(0, 3));
			if(a < b)
			{
				temp_str = lines[i];
				lines[i] = lines[i + 1];
				lines[i + 1] = temp_str;
			}
		}
		sorted = check_sorted(lines);
	}
	rewrite_file();
}

// Clear file and write sorted high scores to it
void Player::rewrite_file()
{
	os.open("names.txt", ios_base::trunc);
	os.close();

	os.open("names.txt", ios_base::out | ios_base::app);
	for(int i = 0; i < lines.size(); ++i)
	{
		os << lines[i] << '\n';
	}
	os.close();
}
