#ifndef PLAYER_H
#define PLAYER_H

#include "std_lib_facilities_4.h"

class Player
{
        public:
                string get_name();
                int get_score();

                void set_name(string);
                void set_score(int);
        private:
                void store_name();
                void store_score();
        private:
                string name;
                int score;
};

#endif
