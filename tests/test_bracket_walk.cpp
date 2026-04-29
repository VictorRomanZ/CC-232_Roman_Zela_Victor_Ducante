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

    BracketWalk bw("(()");   // Longitud 3 impar
    verificar(!bw.es_caminable(), "longitud 3: NO");

    bw.voltear(1);
    verificar(!bw.es_caminable(), "longitud 3 tras voltear: sigue NO");
}

void test_cadena_perfecta() {
    std::cout << "\n[Test 2] Cadena perfecta\n";

    BracketWalk bw("()()");
    verificar(bw.es_caminable(), "()() es caminable");
}

void test_voltear() {
    std::cout << "\n[Test 3] Voltear actualiza correctamente\n";

    BracketWalk bw("()()");
    verificar(bw.es_caminable(), "inicio: ()() caminable");

    bw.voltear(1);
    verificar(!bw.es_caminable(), "tras voltear pos1: NO caminable");

    bw.voltear(1);
    verificar(bw.es_caminable(), "tras restaurar pos1: caminable de nuevo");
}

void test_caso_contraintuitivo() {
    std::cout << "\n[Test 5] Caso contraintuitivo: ')(' es caminable\n";
    BracketWalk bw(")(");
    verificar(bw.es_caminable(), ")( ES caminable");
}











