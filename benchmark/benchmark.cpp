#include "bracket_walk.h"
#include <iostream>
#include <chrono>
#include <string>
#include <random>


int main() {
    std::cout << "=== Benchmark CF 1838D ===\n\n";

    int n = 200000;
    int q = 200000;

    std::mt19937 rng(42); 
    std::uniform_int_distribution<int> moneda(0, 1);
    std::uniform_int_distribution<int> posicion(1, n);

    std::string cadena(n, '(');
    for (int i = 0; i < n; i++) {
        cadena[i] = (moneda(rng) == 0) ? '(' : ')';
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    BracketWalk bw(cadena);
    auto t2 = std::chrono::high_resolution_clock::now();

    double ms_construccion = std::chrono::duration<double, std::milli>(t2 - t1).count();

    auto t3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < q; i++) {
        int pos = posicion(rng);
        bw.voltear(pos);
        bw.es_caminable(); 
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    double ms_queries = std::chrono::duration<double, std::milli>(t4 - t3).count();

    std::cout << "n = " << n << ", q = " << q << "\n";
    std::cout << "Tiempo construccion : " << ms_construccion << " ms\n";
    std::cout << "Tiempo " << q << " queries : " << ms_queries << " ms\n";
    std::cout << "Tiempo total        : " << (ms_construccion + ms_queries) << " ms\n";
    std::cout << "\n(El limite tipico de Codeforces es 2000 ms)\n";

    return 0;
}
