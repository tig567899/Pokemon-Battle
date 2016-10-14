#include "Battlefield.h"

Battlefield::Battlefield(int a, Player* play, Player* opo)
{
    pl = play;
    op = opo;
}

void Battlefield::set_active(bool pl, Pokemon* poke)
{
    if (!pl)
    {
        pl_active = poke;
    }
    else
    {
        op_active = poke;
    }
}

Pokemon* Battlefield::get_active(bool x)
{
    if (!x)
    {
        return pl_active;
    }
    else
    {
        return op_active;
    }
}

Player* Battlefield::get_player(bool a)
{
    if (a)
    {
        return pl;
    }
    else
    {
        return op;
    }
}
