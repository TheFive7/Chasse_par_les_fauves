#ifndef PROJET_PROGRAMMATION_S5_PLAYER_H
#define PROJET_PROGRAMMATION_S5_PLAYER_H

#include <string>
#include "Mobile.h"

class Player : public Mobile {
    public:
        Player();
        int getLife() const;
};


#endif //PROJET_PROGRAMMATION_S5_PLAYER_H
