#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include "Moves.h"
#include <vector>
#include "Ability.h"

class Pokemon
{
    private:
        vector <Move*> moves;
        vector <int> stats; ///MaxHp, Atk, Def, Sp.A, Sp.D, Spe
        vector <int> modifiers;
        vector <int> min_statuses; ///Confuse, Recharge, Flinch, Taunt
        int level;
        int currenthp;
        int totalpp;
        string name;
        string type1;
        string type2;
        string status; /// None, Burn, Pois, or Para
    public:
        Pokemon(string, int, int, int, string, string, string, string);
        void set_stats(vector<int>);
        void set_moves(vector<Move*>);
        void set_mods(vector<int>);
        void mod_stat(int,int);
        void vol_stat_change(int, int);
        void change_status(string);
        void set_min_statuses(vector<int>);
        vector<int> get_mod();
        vector<Move*> get_move();
        bool drop_currenthp(int);
        string get_status();
        vector<int> get_stat();
        vector<int> get_vol_stats();
        void mod_change(int,int);
};

#endif // POKEMON_H_INCLUDED
