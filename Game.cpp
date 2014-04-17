
#include "Simple_window.h"
#include "Screen2.h"
//#include "GUI.h"
//#include "Graph.h"

int main()
{
        bool running = true;

        try
        {
                Screen2 win(Point(100, 100), 640, 480, "wind");

                return gui_main();

        }

        catch(exception& e)
        {
                cerr << "" << e.what() << endl;
                return 1;
        }

        catch(...)
        {
                cerr << "" << endl;
                return 2;
        }
}
