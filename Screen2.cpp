#include "GUI.h"
#include "Graph.h"
#include "Screen2.h"

#include "Pancake.h"
#include "Pancake_stack.h"

Game_State state = Game_State::Start;
Pancake_stack pp;

Game_State Screen2::get_state()
{
        return state;
}

Screen2::Screen2(Point xy, int w, int h, const string& title)
        : Window(xy, w, h, title),
        to_game_state(Point(x_max() - 200, 0), 70, 20, "TO GAME", cb_to_game_state),
        to_end_state(Point(x_max() - 120, 0), 70, 20, "TO END", cb_to_end_state),
        to_quit(Point(x_max() - 120, 60), 70, 20, "QUIT", cb_quit)

{
        attach(to_game_state);
        attach(to_end_state);
        attach(to_quit);

        to_end_state.hide();
        to_quit.hide();
}

void Screen2::change(Game_State s)
{
//      to_game_state.hide();
//      to_end_state.show();
        state = s;
}

void Screen2::game_state_pressed()
{
//      Rectangle * r = new Rectangle(Point(20, 20), 20, 20);
//      attach(*r);

        pp.init_stack();

        for(int i = 0; i < pp.pancakes.size(); ++i)
        {
                attach(pp.pancakes[i]);

        }

        to_game_state.hide();
        to_quit.hide();
        to_end_state.show();

        Fl::redraw();

        change(Game_State::Game);
}

void Screen2::end_state_pressed()
{
        for(int i = 0; i < pp.pancakes.size(); ++i)
        {
                detach(pp.pancakes[i]);
        }

        to_end_state.hide();
        to_quit.show();
        to_game_state.show();

        Fl::redraw();

        change(Game_State::Game);
}

void Screen2::end_state_pressed()
{
        for(int i = 0; i < pp.pancakes.size(); ++i)
        {
                detach(pp.pancakes[i]);
        }

        to_end_state.hide();
        to_quit.show();
        to_game_state.show();

        Fl::redraw();

        change(Game_State::End);
}

void Screen2::quit()
{
        hide();
}

void Screen2::cb_quit(Address, Address pw)
{
        reference_to<Screen2>(pw).quit();
}

void Screen2::cb_to_game_state(Address, Address pw)
{
        reference_to<Screen2>(pw).game_state_pressed();
}

void Screen2::cb_to_end_state(Address, Address pw)
{
        reference_to<Screen2>(pw).end_state_pressed();
}
