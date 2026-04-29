#include "bracket_walk.h"

BracketWalk::BracketWalk(const std::string& cadena) {
    s = cadena;
    n = s.size();

    for (int i = 1; i <= n; i++) {
        if (es_mala(i)) {
            malas.insert(i);
        }
    }
}


bool BracketWalk::es_mala(int i) const {

    if (i % 2 == 1) {
        return s[i - 1] != '(';
    } else {
        return s[i - 1] != ')';
    }
}











































