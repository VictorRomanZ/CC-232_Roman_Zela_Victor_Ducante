#include "bracket_walk.h"
#include <iostream>

int main() {

    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;
    BracketWalk bw(s);

    while (q--) {
        int pos;
        std::cin >> pos;
        bw.voltear(pos);
        if (bw.es_caminable()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
