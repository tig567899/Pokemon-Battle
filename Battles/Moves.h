#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED

#include <string>

using namespace std;

class Move
{
    public:
        Move(string, string, int, int, int, int, string, string);
        void drop_pp();
        int return_priority();
        string return_secondary();
        int return_power();
        int return_accuracy();
        string return_att();
    private:
        string name;
        string att; /// special or physical
        int priority;
        int pp;
        int power;
        int accuracy;
        string type;
        string secondary;
};

#endif // MOVES_H_INCLUDED
