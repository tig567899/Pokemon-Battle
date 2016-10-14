#include "Moves.h"

Move::Move(string n, string g,int pr, int f, int p, int a, string t, string e)
{
    name = n;
    att = g;
    priority = pr;
    pp = f;
    power = p;
    accuracy = a;
    type = t;
    secondary = e;
}

int Move::return_priority()
{
    return priority;
}

string Move::return_att()
{
    return att;
}

string Move::return_secondary()
{
    return secondary;
}

int Move::return_power()
{
    return power;
}

int Move::return_accuracy()
{
    return accuracy;
}

void Move::drop_pp()
{
    pp--;
}
