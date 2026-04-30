#include "bracket_walk.h"
#include <iostream>
#include <vector>


void mostrar_estado(BracketWalk& bw, int n, const std::string& etiqueta) {
    std::cout << "  " << etiqueta << "\n";
    std::cout << "  Caminable: " << (bw.es_caminable() ? "YES" : "NO") << "\n\n";
}

void correr_caso(const std::string& cadena_inicial, const std::vector<int>& queries) {
    std::cout << "Cadena inicial: \"" << cadena_inicial << "\"\n";
    std::cout << "Longitud: " << cadena_inicial.size() << "\n\n";

    BracketWalk bw(cadena_inicial);
    mostrar_estado(bw, cadena_inicial.size(), "Estado inicial (sin queries)");

    for (int i = 0; i < (int)queries.size(); i++) {
        int pos = queries[i];
        std::cout << "  Query " << (i + 1) << ": voltear posicion " << pos << "\n";
        bw.voltear(pos);
        mostrar_estado(bw, cadena_inicial.size(), "Estado tras query " + std::to_string(i + 1));
    }

    std::cout << "----------------------------------------\n\n";
}

int main() {
    std::cout << "=== DEMO: CF 1838D - Bracket Walk ===\n\n";

    std::cout << "--- Caso 1: empieza caminable, se rompe ---\n";
    correr_caso("()()", {1, 4});

    std::cout << "--- Caso 2: longitud impar ---\n";
    correr_caso("(()", {1, 2});

    std::cout << "--- Caso 3: ')(' parece invalido pero ES caminable ---\n";
    correr_caso(")(", {});

    std::cout << "--- Caso 4: secuencia de queries ---\n";
    correr_caso("()()()()", {1, 8, 1, 8});

    return 0;
}
