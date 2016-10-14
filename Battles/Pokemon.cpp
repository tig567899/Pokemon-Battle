#include "Pokemon.h"

Pokemon::Pokemon(string n, int t, int l, int c, string t1, string t2, string nat, string stat)
{
    name = n;
    totalpp = t;
    level = l;
    currenthp = c;
    type1 = t1;
    type2 = t2;
    status = stat;
}

void Pokemon::set_moves(vector<Move*> m)
{
    moves = m;
}

void Pokemon::set_stats(vector<int> a)
{
    stats = a;
}

void Pokemon::change_status(string t)
{
    status = t;
}

string Pokemon::get_status()
{
    return status;
}

vector<int> Pokemon::get_stat()
{
    return stats;
}

vector<int> Pokemon::get_mod()
{
    return modifiers;
}

vector<int> Pokemon::get_vol_stats()
{
    return min_statuses;
}

void Pokemon::set_min_statuses(vector<int> a)
{
    min_statuses = a;
}

bool Pokemon::drop_currenthp(int a)
{
    currenthp -= a;
    if (currenthp <= 0)
    {
        currenthp = 0;
        return 1;
    }
    else if (currenthp > stats[0])
    {
        currenthp = stats[0];
        return 0;
    }
    return 0;
}


void Pokemon::vol_stat_change(int index, int mod)
{
    min_statuses[index] += mod;
}

void Pokemon::mod_change(int index, int mod)
{
    modifiers[index] += mod;
}

void Pokemon::set_mods(vector<int> m)
{
    modifiers = m;
}

vector<Move*> Pokemon::get_move()
{
    return moves;
}
