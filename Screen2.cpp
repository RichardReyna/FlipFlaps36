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
        to_game_state(Point(x_max() - 120, 0), 70, 20, "TO GAME", cb_to_game_state),
        to_end_state(Point(x_max() - 120, 0), 70, 20, "TO END", cb_to_end_state),
        to_quit(Point(x_max() - 120, 20), 70, 20, "QUIT", cb_quit),
        difficulty(Point(120, 0), 50, 20, "Enter diff here: "),
        place_1(Point(x_max() - 120, 20), 70, 20, "Place 1", cb_place_1)
//        place_2(Point(x_max() - 120, 40), 70, 20, "Place 2", cb_place_2),
//        place_3(Point(x_max() - 120, 60), 70, 20, "Place 3", cb_place_3),
//        place_4(Point(x_max() - 120, 80), 70, 20, "Place 4", cb_place_4),
//        place_5(Point(x_max() - 120, 100), 70, 20, "Place 5", cb_place_5),
//        place_6(Point(x_max() - 120, 120), 70, 20, "Place 6", cb_place_6),
//        place_7(Point(x_max() - 120, 140), 70, 20, "Place 7", cb_place_7),
//        place_8(Point(x_max() - 120, 160), 70, 20, "Place 8", cb_place_8),
//        place_9(Point(x_max() - 120, 180), 70, 20, "Place 9", cb_place_9)
{
        attach(to_game_state);
        attach(to_end_state);
        attach(to_quit);
        attach(difficulty);
        attach(place_1);

        to_end_state.hide();
        to_quit.hide();
        place_1.hide();
//      place_2.hide();
//      place_3.hide();
//      place_4.hide();
//      place_5.hide();
//      place_6.hide();
//      place_7.hide();
//      place_8.hide();
//      place_9.hide();
}

void Screen2::change(Game_State s)
{
        state = s;
}

void Screen2::game_state_pressed()
{
        cout << difficulty.get_int() << endl;
        pp.init_stack();
//      randomize_stack(pp);

        for(int i = 0; i < difficulty.get_int(); ++i)
        {
                attach(pp.pancakes[i]);
        }

        to_game_state.hide();
        to_quit.hide();
        difficulty.hide();
        to_end_state.show();
        place_1.show();
//      place_2.show();
//      place_3.show();
//      place_4.show();
//      place_5.show();
//      place_6.show();
//      place_7.show();
//      place_8.show();
//      place_9.show();

        Fl::redraw();

        change(Game_State::Game);
}

int Screen2::get_diff()
{
        return difficulty.get_int();
}

void Screen2::end_state_pressed()
{
        for(int i = 0; i < difficulty.get_int(); ++i)
        {
                detach(pp.pancakes[i]);
        }

//      pp.pancakes.~Vector_ref();
//      Pancake_stack pp;

        to_end_state.hide();
        difficulty.hide();
        place_1.hide();
//      place_2.hide();
//      place_3.hide();
//      place_4.hide();
//      place_5.hide();
//      place_6.hide();
//      place_7.hide();
//      place_8.hide();
//      place_9.hide();
        to_quit.show();
        to_game_state.show();
        difficulty.show();

        Fl::redraw();

        change(Game_State::End);
}

void Screen2::quit()
{
        hide();
}

void Screen2::set_place(int p)
{
        place = p;
        cout << place << endl;
}

void Screen2::cb_get_diff(Address, Address pw)
{
        reference_to<Screen2>(pw).get_diff();
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

void Screen2::cb_place_1(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(1);
}

/*
void Screen2::cb_place_2(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(2);
}

void Screen2::cb_place_3(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(3);
}

void Screen2::cb_place_4(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(4);
}

void Screen2::cb_place_5(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(5);
}

void Screen2::cb_place_6(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(6);
}

void Screen2::cb_place_7(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(7);
}

void Screen2::cb_place_8(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(8);
}

void Screen2::cb_place_9(Address, Address pw)
{
        reference_to<Screen2>(pw).set_place(9);
}
*/
