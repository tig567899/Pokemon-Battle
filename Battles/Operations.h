#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED
#include <bits/stdc++.h>
#include "Player.h"
#include "Battlefield.h"
#include "Pokemon.h"

vector<Move*> get_move_info();
vector<Pokemon*> get_party_info(int);
vector<int> get_stats();
Player* get_player_info();

void process_secondary_effects(Pokemon*, Move*, Pokemon*);
bool process_first_move(Pokemon*,Move*, Pokemon*, Move*);
void process_battle_turn(bool, Move*, Pokemon*, bool, Move*, Pokemon*);
bool process_accuracy_check(Pokemon*, Move*, Pokemon*);
int process_damage(Pokemon*, Move*, Pokemon*);
void clear_effects(Pokemon*);
bool process_confusion();

#endif // OPERATIONS_H_INCLUDED
