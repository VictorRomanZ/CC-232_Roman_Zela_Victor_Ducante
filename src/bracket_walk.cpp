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

void BracketWalk::voltear(int i) {

    if (s[i - 1] == '(') {
        s[i - 1] = ')';
    } else {
        s[i - 1] = '(';
    }

    if (malas.count(i)) {
        malas.erase(i);
    } else {
        malas.insert(i);
    }
}

bool BracketWalk::es_caminable() const {

    if (n % 2 != 0) {
        return false;
    }

    if (malas.empty()) {
        return true;
    }

    int primera = *malas.begin();  
    int ultima  = *malas.rbegin();  

    if (primera % 2 == 0) {
        return false;
    }

    if (ultima % 2 != 0) {
        return false;
    }

    return true;
}

bool BracketWalk::es_mala(int i) const {

    if (i % 2 == 1) {
        return s[i - 1] != '(';
    } else {
        return s[i - 1] != ')';
    }
}











































