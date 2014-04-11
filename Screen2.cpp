//struct Screen2;
#include "Screen2.h"

Game_State state = Game_State::Start;

// Construct window, attach/hide buttons
Screen2::Screen2(Point xy, int w, int h, const string& title)
        : Window(xy, w, h, title),
        to_game_state(Point(x_max() - 200, 0), 70, 20, "TO GAME", cb_to_game_state),
        to_end_state(Point(x_max() - 120, 0), 70, 20, "TO END", cb_to_end_state)

{
        attach(to_game_state);
        attach(to_end_state);
        to_end_state.hide();
}

// Change game state to arg val
void Screen2::change(Game_State s)
{
        state = s;
}

// Occurs on click of to_game_state button
// and changes game state to Game
void Screen2::game_state_pressed()
{
        change(Game_State::Game);
}

// Occurs on click of to_end_state button
// and changes game state to End
void Screen2::end_state_pressed()
{
        change(Game_State::End);
}

void Screen2::cb_to_game_state(Address, Address)
{
        reference_to<Screen2>(pw).game_state_pressed();
}

void Screen2::cb_to_end_state(Address, Address)
{
        reference_to<Screen2>(pw).end_state_pressed();
}
