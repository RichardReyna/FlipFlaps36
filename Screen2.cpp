#include "GUI.h"
#include "Graph.h"
#include "Screen2.h"

Game_State state = Game_State::Start;

Game_State Screen2::get_state()
{
        return state;
}

Screen2::Screen2(Point xy, int w, int h, const string& title)
        : Window(xy, w, h, title),
        to_game_state(Point(x_max() - 200, 0), 70, 20, "TO GAME", cb_to_game_state),
        to_end_state(Point(x_max() - 120, 0), 70, 20, "TO END", cb_to_end_state)

{
        attach(to_game_state);
        attach(to_end_state);
        to_end_state.hide();
//      Rectangle * r = new Rectangle(Point(10,10),10,10);
//      attach(*r);
}

void Screen2::change(Game_State s)
{
//      r_buffer.push_back(new Rectangle(Point(50, 60), 10, 10));
        //attach((Rectangle) r_buffer[0]);
//      attach( *(Rectangle*) (&r_buffer[0]));

///     Rectangle * r = new Rectangle(Point(20,20),20,20);
///     attach(*r);
//      cout << "try attach" << endl;
///     Fl::redraw();

        to_game_state.hide();
        to_end_state.show();
        state = s;
}

void Screen2::game_state_pressed()
{
        Rectangle * r = new Rectangle(Point(20, 20), 20, 20);
        attach(*r);

        Fl::redraw();

        change(Game_State::End);
}

void Screen2::cb_to_game_state(Address, Address pw)
{
        reference_to<Screen2>(pw).game_state_pressed();
}

void Screen2::cb_to_end_state(Address, Address pw)
{
        reference_to<Screen2>(pw).end_state_pressed();
}
