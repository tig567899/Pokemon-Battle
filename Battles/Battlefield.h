#ifndef BATTLEFIELD_H_INCLUDED
#define BATTLEFIELD_H_INCLUDED

#include "Pokemon.h"
#include "Player.h"

class Battlefield
{
    private:
        Player* pl;
        Player* op;
        Pokemon* op_active;
        Pokemon* pl_active;
    public:
        Battlefield(int, Player*, Player*);
        void set_active(bool, Pokemon*);
        Player* get_player(bool);
        Pokemon* get_active(bool);
};

#endif // BATTLEFIELD_H_INCLUDED
