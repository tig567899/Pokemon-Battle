#include "Operations.h"

Player* get_player_info()
{
    int n;
    vector<Pokemon*> party;
    Player* play;
    bool g;
    string name;
    cin >> n;
    party = get_party_info(n);
    cin >> g;
    cin >> name;
    play = new Player(n, party, g, name);
    return play;
}

vector<Pokemon*> get_party_info(int k)
{
    vector<Pokemon*> party;
    string name, type1, type2, nature, status;
    int n,r,l;
    Pokemon* poke;
    for (int x = 0; x < k; x++)
    {
        cin >> name;
        cin >> n >> l >> r;
        cin >> type1 >> type2 >> nature>> status;
        poke = new Pokemon(name, n, l, r, type1,type2,nature, status);
        poke->set_stats(get_stats());
        poke->set_moves(get_move_info());
        poke->set_mods(vector<int>(8,0));
        party.push_back(poke);
    }
    return party;
}

vector<int> get_stats()
{
    vector<int> a;
    int input;
    for(int x = 0; x < 6; x++)
    {
        cin >> input;
        a.push_back(input);
    }
    return a;
}

vector<Move*> get_move_info()
{
    vector<Move*> a;
    Move* b;
    string name, att, type, secondary;
    int priority, pp, power, accuracy;
    for (int x = 0; x< 4; x++)
    {
        cin>> name >> att;
        cin >> priority >> pp >> power >> accuracy;
        cin >> type;
        getline(cin, secondary);
        b = new Move(name, att, priority, pp, power, accuracy, type, secondary);
        a.push_back(b);
    }
    b = new Move("confuse", "Physical", 0, 9999999, 40, 9999999, "none", "none");
    a.push_back(b);
    return a;
}

bool process_confusion()
{
    bool a = rand()%2;
    if (a == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void process_battle_turn(bool movement1, Move* p1move, Pokemon* p1, bool movement2, Move* p2move, Pokemon* p2)
{
    if (!movement1 && !movement2)
    {
        int t;
        if (!process_first_move(p1, p1move, p2, p2move))
        {
            clear_effects(p1);
            clear_effects(p2);
            if (p1->get_status() != "zzzz")
            {
                cout << "zzzz" << endl;
            }
            else if (!process_accuracy_check(p1,p1move,p2))
            {
                cout << "miss" << endl;
            }
            else if (p1->get_vol_stats()[2] == 1)
            {
                cout << "flin" << endl;
            }
            else if (p1->get_vol_stats()[0] == 1 && process_confusion())
            {
                t = process_damage(p1,p1->get_move()[4],p1);
                cout << "conf " << t <<  endl;

            }
            else
            {
                t = process_damage(p1,p1move,p2);
                cout << "damage " << t << endl;
                p2->drop_currenthp(t);
            }
        }
    }
}

bool process_accuracy_check(Pokemon* p1, Move* m, Pokemon* p2)
{
    int a = rand();
    double pmod;
    double evmod;
    if (p1->get_mod()[6] < 0)
    {
        pmod = 3.0/(3.0-p1->get_mod()[6]);
    }
    else
    {
        pmod = (3.0+p1->get_mod()[6])/3.0;
    }
    if (p2->get_mod()[7] < 0)
    {
        evmod = 3.0/(3.0-p2->get_mod()[7]);
    }
    else
    {
        evmod = (3.0+p2->get_mod()[7])/3.0;
    }
    if (a < m->return_accuracy()*pmod/evmod)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool process_first_move(Pokemon* p1, Move* m1, Pokemon* p2, Move* m2)
{
    if (m1->return_priority() > m2->return_priority())
    {
        return 0;
    }
    else if (m1->return_priority() < m2->return_priority())
    {
        return 1;
    }
    else if (p1->get_stat()[5] > p2->get_stat()[5])
    {
        return 0;
    }
    else if (p1->get_stat()[5] < p2->get_stat()[5])
    {
        return 1;
    }
    else
    {
        return rand()%2;
    }
}

int process_damage(Pokemon* p1, Move* m, Pokemon* p2)
{
    double pmod;
    double evmod;
    int random = rand() % 16;
    int crit = 1;
    if (m->return_secondary() == "crit")
    {
        if (random == 15 || random == 14)
        {
            crit = 2;
        }
    }
    else if (random == 15 || random == 14)
    {
        crit = 2;
    }
    if (m->return_att() == "Physical")
    {
        if (p1->get_mod()[1] < 0)
        {
            pmod = 2.0/(2.0-p1->get_mod()[1]);
        }
        else
        {
            pmod = (2.0+p1->get_mod()[1])/2.0;
        }
        if (p2->get_mod()[2] < 0)
        {
            evmod = 2.0/(2.0-p2->get_mod()[2]);
        }
        else
        {
            evmod = (2.0+p2->get_mod()[2])/2.0;
        }
        if (crit == 2)
        {
            cout << "crit" << endl;
        }
        return (m->return_power()* pmod/evmod * p1->get_stat()[1]/p2->get_stat()[2])*crit;
    }
    else if (m-> return_att() == "Special")
    {
        if (p1->get_mod()[3] < 0)
        {
            pmod = 2.0/(2.0-p1->get_mod()[3]);
        }
        else
        {
            pmod = (2.0+p1->get_mod()[3])/2.0;
        }
        if (p2->get_mod()[2] < 0)
        {
            evmod = 2.0/(2.0-p2->get_mod()[4]);
        }
        else
        {
            evmod = (2.0+p2->get_mod()[4])/2.0;
        }
        if (crit == 2)
        {
            cout << "crit" << endl;
        }
        return (m->return_power()* pmod/evmod * p1->get_stat()[3]/p2->get_stat()[4])*crit;
    }
    else
    {
        return 0;
    }
}

void clear_effects(Pokemon* p)
{
    int a;
    if (p->get_status() == "zzzz")
    {
        a = rand() %2;
        if (a)
        {
            p->change_status("none");
        }
    }
    for (int x = 0; x < 4; x++)
    {
        p->vol_stat_change(x,-1);
    }
}

void process_secondary_effects(Pokemon* user, Move* pmove, Pokemon* target)
{
    int percentage;
    int roll = rand() %100;
    if (pmove->return_secondary().substr(0,4) == "pois")
    {
        if (pmove->return_secondary().substr (5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            if (target->get_status() == "none")
            {
                target->change_status("pois");
            }
        }
    }
    else if (pmove->return_secondary().substr(0,4) == "burn")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            if (target->get_status() == "none")
            {
                target->change_status("burn");
                target->mod_change(1,-2);
            }
        }
    }
    else if (pmove->return_secondary().substr(0,4) == "para")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            if (target->get_status() == "none")
            {
                target->change_status("para");
                target->mod_change(5,-6);
            }
        }
    }
    else if (pmove->return_secondary().substr(0,4) == "zzzz")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            if (target->get_status() == "none")
            {
                target->change_status("zzzz");
            }
        }
    }
    /// ABOVE ARE THE NON-VOLATILE STATUSES
    else if (pmove->return_secondary().substr(0,5) == "matk1")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(1,-1);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "matk2")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(1,-2);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mdef1")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(2,-1);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mdef2")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(2,-2);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mspa1")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(3,-1);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mspa2")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(3,-2);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mspd1")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(4,-1);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mspd2")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(4,-2);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mspe1")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(5,-1);
        }
    }
    else if (pmove->return_secondary().substr(0,5) == "mspe2")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(5,-2);
        }
    }
    else if (pmove->return_secondary().substr(0,4) == "conf")
    {
        if (pmove->return_secondary().substr(5, 2) == "00")
        {
            percentage = 100;
        }
        else
        {
            percentage = atoi(pmove->return_secondary().substr(5, 2).c_str());
        }
        if (roll <= percentage)
        {
            target->mod_change(1,-1);
        }
    }
    //else if
}
