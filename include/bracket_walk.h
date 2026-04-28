#ifndef BRACKET_WALK_H
#define BRACKET_WALK_H

#include <set>
#include <string>


class BracketWalk {
public:
    BracketWalk(const std::string& cadena);

    void voltear(int i);

    bool es_caminable() const;

private:
    std::string s;          
    int n;                  
    std::set<int> malas;   

    bool es_mala(int i) const;
};

#endif
