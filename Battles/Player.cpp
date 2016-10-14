#include "Player.h"

Player::Player(int n, vector<Pokemon*> p, bool g, string na)
{
    n_of_pokemon = n;
    party = p;
    gender = g;
    name = na;
}

int Player::ret_npoke()
{
    return n_of_pokemon;
}

vector<Pokemon*> Player::search_poke()
{
    return party;
}

string Player::ret_name()
{
    return name;
}
