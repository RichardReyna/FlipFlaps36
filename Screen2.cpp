#include "GUI.h"
#include "Graph.h"
#include "Screen2.h"

#include "Pancake.h"
#include "Pancake_stack.h"
#include "Player.h"

Pancake_stack pp;
Player player;

int num_of_games = 0;

// Constructs window and screen elements.
Screen2::Screen2(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
        to_instructions(Point(x_max() - 380, 0), 140, 20, "TO INSTRUCTIONS", cb_to_instructions),
	splash(Point(0, 20), "SPLASH_REAL.jpg"),
	instructions(Point(0, 20), "DIRECTIONS_REAL.jpg"),
	get_name(Point(120, 0), 50, 20, "Enter name here: "),
	flip(Point(x_max() - 320, 340), 70, 20, "FLIP", cb_flip),
	to_game_state(Point(x_max() - 120, 0), 70, 20, "TO GAME", cb_to_game_state),
	to_end_state(Point(x_max() - 120, 0), 70, 20, "TO END", cb_to_end_state),
	to_quit(Point(x_max() - 120, 20), 70, 20, "QUIT", cb_quit),
	difficulty(Point(320, 0), 50, 20, "Enter diff here: "),
	pick_place(Point(x_max() - 320, 400), 70, 20, "Enter place here: "),
	score_table(Point(x_max() - 240, 60), "Scores: \t\t\tPlayers: ")
{
	attach(splash);
	color(Color::white);
	attach(flip);
	attach(to_instructions);
	attach(to_game_state);
	attach(to_end_state);
	attach(to_quit);
	attach(pick_place);
	attach(score_table);

	detach(flip);
	to_game_state.hide();
	to_end_state.hide();
	to_quit.hide();
	pick_place.hide();
	detach(score_table);
}

void Screen2::instructions_pressed()
{
	detach(splash);
	detach(to_instructions);
	attach(instructions);
	attach(get_name);
	attach(difficulty);
	attach(to_game_state);
}

// Creates random stack of pancakes and draws them
// allowing game loop to start.
void Screen2::game_state_pressed()
{
	num_of_tries = 0;
	pp.make_stack(difficulty.get_int());
	draw_pancakes();
	pick_place.show();
	attach(flip);

	player.set_name(get_name.get_string());

	detach(instructions);
	get_name.hide();
	to_game_state.hide();
	to_quit.hide();
	difficulty.hide();
	detach(score_table);
        erase_high_scores();

	Fl::redraw();
}

// Sets score from last game played and writes
// score/name pair to file which is then sorted.
void Screen2::end_state_pressed()
{
//	int score = pp.calc_score();
//	if(score < 100){score = 100;}
//	player.set_score(score);
//	player.store_high_score();

	erase_pancakes();
	pick_place.hide();
	detach(flip);

	to_end_state.hide();

	to_quit.show();
	to_game_state.show();
	difficulty.show();
	get_name.show();

	++num_of_games;
	Fl::redraw();

	//sort high scores and clear high score container
	player.sort_high_scores();
	ppp = Vector_ref<Text>();

	draw_high_scores();

        Fl::redraw();
}

// Ends game by destroying window
void Screen2::quit()
{
        hide();
}

void Screen2::flip_p()
{
	++num_of_tries;
	erase_pancakes();
	pp.flip(pick_place.get_int());
	draw_pancakes();

	if(num_of_tries == 15)
	{
		erase_pancakes();
		detach(flip);
		pick_place.hide();
		attach(to_end_state);
	}

	if(pp.check_sorted())
	{
		int score = pp.calc_score();
		if(score < 100){score = 100;}
		player.set_score(score);
		player.store_high_score();
                erase_pancakes();
                detach(flip);
		pick_place.hide();
		attach(to_end_state);
	}
	Fl::redraw();
}

// Gets sorted score/name pairs from persistent file
// and uses them to create/draw the score table
void Screen2::draw_high_scores()
{
	// Show table title
	attach(score_table);

	for(int i = 0; i < 6; ++i)
	{
		string str = player.get_high_score(i);
                Text * t = new Text(Point(x_max() - 240, 80 + 20 * i), str);
		t->set_color(Color::black);
		ppp.push_back(*t);
		attach(ppp[i]);
	}
}

// Draws pancake objects
void Screen2::draw_pancakes()
{
        for(int i = 0; i < difficulty.get_int(); ++i)
        {
                attach(pp.pancakes[i]);
        }
}

// Erases pancake objects
void Screen2::erase_pancakes()
{
        for(int i = 0; i < difficulty.get_int(); ++i)
        {
                detach(pp.pancakes[i]);
        }
}

void Screen2::erase_high_scores()
{
        for(int i = 0; i < ppp.size(); ++i)
        {
                detach(ppp[i]);
        }
}

// Calls quit to destroy the window
void Screen2::cb_quit(Address, Address pw)
{
	reference_to<Screen2>(pw).quit();
}

void Screen2::cb_flip(Address, Address pw)
{
	reference_to<Screen2>(pw).flip_p();
}

void Screen2::cb_to_instructions(Address, Address pw)
{
	reference_to<Screen2>(pw).instructions_pressed();
}

// Switches game to game state
void Screen2::cb_to_game_state(Address, Address pw)
{
	reference_to<Screen2>(pw).game_state_pressed();
}

// Switches game to end state
void Screen2::cb_to_end_state(Address, Address pw)
{
	reference_to<Screen2>(pw).end_state_pressed();
}
