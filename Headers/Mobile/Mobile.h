#ifndef PROJET_PROGRAMMATION_S5_MOBILE_H
#define PROJET_PROGRAMMATION_S5_MOBILE_H

#include <vector>
#include <string>
#include "../Empty.h"

enum class Direction {
    // -1 = 10; 0 = 11, 1 = 12
    NO = 1010,
    N = 1011,
    NE = 1012,
    O = 1110,
    E = 1112,
    SO = 1210,
    S = 1211,
    SE = 1212
};

class Mobile : public Empty {
    public:
        virtual ~Mobile() = default;
        void goTo(Direction direction);
        std::string getName();
        int getLife();
    protected:
        int d_life = 1;
        std::string d_name;
};


#endif //PROJET_PROGRAMMATION_S5_MOBILE_H
