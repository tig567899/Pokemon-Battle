#include <iostream>
#include "Battlefield.h"
#include <fstream>
#include "Player.h"
#include "Operations.h"

using namespace std;

bool choicep1; /// 0 = move, 1 = switch;
bool choicep2;
int selection1;
int selection2;

int main()
{
    freopen("player1.txt", "r", stdin);
    Player* p1;
    Player* p2;
    p1 = get_player_info();
    freopen("player2.txt", "r", stdin);
    p2 = get_player_info();
    Battlefield* battle = new Battlefield(1, p1, p2);
    battle->set_active(false, p1->search_poke()[0]);
    battle->set_active(true, p2->search_poke()[0]);

    cin >> choicep1;
    cin >> selection1;
    cin >> choicep2;
    cin >> selection2;
    while (p1->ret_npoke() >0 || p2 -> ret_npoke() > 0)
    {
        switch (choicep1)
        {
        case 0:
            cin >> choicep1;
            switch (choicep2)
            {
            case 0:
                process_battle_turn(true, NULL/**battle->get_active(0)->get_move(selection1)*/, battle->get_active(0),
                                    true, NULL/**battle->get_active(1)->get_move(selection2)*/, battle->get_active(1));
                break;
            case 1:
                process_battle_turn(true, NULL/**battle->get_active(0)->get_move[selection1]*/, battle->get_active(0),
                                    false,NULL, battle->get_active(1));
                break;
            }
            break;
        case 1:
            switch(choicep2)
            {
            case 0:
                process_battle_turn(false, NULL, battle->get_active(0),
                                    true, NULL /**battle->get_active(1)->get_move[selection2]*/, battle->get_active(1));
                break;
            case 1:
                process_battle_turn(false, NULL, battle->get_active(0),
                                    false, NULL, battle->get_active(1));
                break;
            }
            break;
        }
    }
    return 0;
}
