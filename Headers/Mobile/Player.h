#ifndef PROJET_PROGRAMMATION_S5_PLAYER_H
#define PROJET_PROGRAMMATION_S5_PLAYER_H

#include "Mobile.h"
#include <string>

class Player : public Mobile {
public:
    Player();
    int getLife() const;
    private:
        std::string d_name = "Player";
};


#endif //PROJET_PROGRAMMATION_S5_PLAYER_H
