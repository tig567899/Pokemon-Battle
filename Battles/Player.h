#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <vector>
#include "Pokemon.h"


class Player
{
private:
    int n_of_pokemon;
    vector<Pokemon*> party;
    bool gender;
    string name;
public:
    Player(int, vector<Pokemon*>, bool, string);
    vector<Pokemon*> search_poke();
    int ret_npoke();
    string ret_name();
};

#endif // PLAYER_H_INCLUDED
