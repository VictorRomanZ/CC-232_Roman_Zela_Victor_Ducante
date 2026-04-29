#include "bracket_walk.h"
#include <iostream>

int aprobados = 0;
int fallados  = 0;

void verificar(bool condicion, const std::string& nombre) {
    if (condicion) {
        std::cout << "  OK  - " << nombre << "\n";
        aprobados++;
    } else {
        std::cout << "  FAIL- " << nombre << "\n";
        fallados++;
    }
}

int main() {
    std::cout << "Tests CF 1838D - Bracket Walk\n";
    std::cout<<"========================================\n";

    std::cout << "\n=== Resultado: "
              << aprobados << " aprobados, "
              << fallados << " fallados ===\n";

    return (fallados == 0) ? 0 : 1;
}

void test_longitud_impar() {
    std::cout << "\n[Test 1] Longitud impar -> siempre NO\n";

    BracketWalk bw("(()");   // longitud 3, impar
    verificar(!bw.es_caminable(), "longitud 3: NO");

    bw.voltear(1);
    verificar(!bw.es_caminable(), "longitud 3 tras voltear: sigue NO");
}