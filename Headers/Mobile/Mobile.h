#ifndef PROJET_PROGRAMMATION_S5_MOBILE_H
#define PROJET_PROGRAMMATION_S5_MOBILE_H

#include <vector>
using namespace std;

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

vector<int> convertDirectionToTab(Direction direction) {
    vector<int> tab;
    int result = static_cast<int>(direction);
    for (int i = 0; i < 2; i++) {
        tab.insert(tab.begin(), (result % 100) - 11);
        result = (result - (result % 100)) / 100;
    }
    // cout << "[ " << tab[0] << ", " << tab[1] << " ]" << '\n';
    return tab;
}

class Mobile {

};


#endif //PROJET_PROGRAMMATION_S5_MOBILE_H
