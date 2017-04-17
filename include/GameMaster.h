#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>
#include <iostream>

namespace GameMaster{
    extern std::vector<bool*> failSettings;
    extern int score;
    extern bool fail;
    void setFail(bool setting);
    void addScore();
}

#endif // GAMEMASTER_H
