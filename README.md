# PC2 - CC232

### Estudiante
- Nombre: Roman Zela Victor Ducante
- Código: 20220050A
- Problema asignado: CF 1838D — Bracket Walk
- Enlace: https://codeforces.com/problemset/problem/1838/D

---

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

---

### Tema principal
- Semana: Semana 3 y Semana 4
- Estructura principal: `std::set<int>` — conjunto ordenado que mantiene las posiciones problemáticas de la cadena

---

### Resumen de la solución

El problema pide determinar, tras cada flip de un carácter, si la cadena de paréntesis es "caminable": es decir, si existe alguna forma de recorrer la cadena, se puede mover libremente izquierda y derecha, tal que los caracteres escritos formen una secuencia de paréntesis válida.
La idea clave es que, como el movimiento es libre, se puede escribir cualquier par de caracteres extra en cualquier punto. Esto lleva a la condición simple de que la cadena es caminable si y solo si su longitud es par, y el conjunto de posiciones malas, donde el carácter no coincide con lo esperado según su paridad, cumple que la primera posición mala es impar y la última es par.

---

### Complejidad

- Tiempo: O(n + q·log n) — construcción O(n), cada flip O(log n), cada consulta O(1)
- Espacio: O(n) 

---

### Invariante o idea clave

En todo momento, el set `malas` contiene exactamente las posiciones i donde el carácter actual de la cadena no coincide con el esperado:
- Posiciones impares deben tener `(`
- Posiciones pares deben tener `)`
Este invariante se establece en el constructor recorriendo toda la cadena y se mantiene en cada llamada a `voltear(i)`. Si la posición estaba en `malas` se elimina y si no estaba se inserta porque voltear un carácter siempre cambia si esa posición es mala o no.

---

### Archivos relevantes
- include/
- src/
- tests/
- demos/

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución
```bash
# Solución
./build/bracket_walk

# Tests
./build/tests

# Demo
./build/demo

# Benchmark
./build/benchmark
```

### Casos de prueba

1. **Longitud impar**
   Resultado esperado: `NO` siempre, porque una secuencia válida tiene longitud par y no es posible escribir una de longitud impar.

2. **Cadena perfecta `"()()"`**
   Demuestra el caso base donde la secuencia sigue el patrón alternado exacto. El set malas permanece vacío y el algoritmo responde YES automáticamente.

3. **Secuencia de queries**
    Cadena base ()()()(). Inicia como caminable YES. Tras aplicar un flip en la posición 1, la cadena se rompe y el algoritmo actualiza el set respondiendo NO. Otro flip posterior en la posición 8 mantiene la cadena inválida.

### Historial de commits
El historial de commits se puede ver directamente en el repositorio de GitHub y se muestra durante el video de sustentación. Los commits fueron realizados en días distintos.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.