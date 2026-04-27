# Actividad 1 - CC232

### Integrantes
- Roman Zela Victor Ducante

## Bloque 1 — Núcleo conceptual de Semana 1

**1. Expliquen con sus palabras la diferencia entre problema, algoritmo, ADT e implementación.**

Un problema es una especificación abstracta que define la entrada que se recibe y la salida que se espera. Un algoritmo es un procedimiento finito, determinista y correcto que resuelve ese problema para toda entrada válida.
Un ADT es una interfaz que describe qué operaciones están disponibles sobre una colección de datos y qué contrato cumple cada una (precondición, postcondición), sin comprometerse con ninguna representación concreta.
Una implementación es la realización concreta de un ADT o un algoritmo en un lenguaje y estructura de datos específicos.

**2. En `bubble_sort.cpp`, expliquen qué observable conecta correctitud y costo.**

El observable clave es el número de inversiones que quedan en el arreglo tras cada pasada. Una inversión es un par de posiciones `(i, j)` con `i < j` y `A[i] > A[j]`. Cada intercambio en `bubblePass` elimina exactamente una inversión. La función `inversionWitnesses` registra los índices donde aún existe desorden local (`A[i-1] > A[i]`), y `stats.swaps` cuenta cuántas inversiones se eliminaron en total.
Esto conecta correctitud y costo, el número de intercambios es exactamente el número de inversiones en la entrada; en el peor caso, un arreglo invertido tiene `n*(n-1)/2` inversiones, de ahí el costo Θ(n²).

**3. En `power.cpp`, expliquen por qué `power` mejora la idea de una versión ingenua.**

`powerBF` calcula `a^n` multiplicando `a` por sí mismo `n` veces: costo O(n) multiplicaciones.
`power` usa exponenciación por cuadrados sucesivos: en cada iteración revisa si el bit menos significativo de `n` está activo y luego cuadra la base y desplaza `n` a la derecha. Esto reduce el número de multiplicaciones a O(log n), porque `n` se divide a la mitad en cada paso. Para `n = 10`, `powerBF` haría 10 multiplicaciones; `power` hace al más 7 (≤ 2·⌊log₂ n⌋ + 1).

**4. En `fibonacci.cpp`, expliquen por qué una función puede ser correcta y aun así ser una mala elección práctica.**

La versión recursiva `fib(n)` en `fibonacci.cpp` es matemáticamente correcta: produce el valor correcto para toda entrada no negativa, con los casos base `fib(0)=0` y `fib(1)=1`. Sin embargo, tiene costo exponencial O(2^n) porque recalcula los mismos subproblemas repetidamente. Por ejemplo, `fib(5)` llama a `fib(4)` y `fib(3)`, y `fib(4)` vuelve a llamar a `fib(3)`, generando un árbol de llamadas con tamaño exponencial.
En contraste, `fibI(n)` resuelve el mismo problema en O(n) tiempo y O(1) espacio mediante un simple bucle que mantiene solo los dos valores anteriores. Para `n = 40`, la versión recursiva hace decenas de miles de millones de llamadas; la iterativa hace 40 sumas.
Correctitud y eficiencia son propiedades independientes. Un algoritmo puede ser correcto y demostrable, pero impracticable para entradas de tamaño realista.

**5. En `count_ones.cpp`, expliquen por qué el tamaño de entrada no siempre coincide con el valor numérico.**

El *tamaño* de una entrada es la cantidad de bits (o dígitos) necesarios para representarla, no su valor numérico. Para un entero sin signo `n`, el tamaño es `⌊log₂(n)⌋ + 1` bits.

`countOnes1` itera eliminando el bit menos significativo activo con `n &= (n-1)` en cada paso; su costo es proporcional al **número de unos** en la representación binaria, no al valor numérico. `countOnes2` trabaja agrupando bits en bloques mediante máscaras, completando el conteo en exactamente 5 rondas sin depender del valor numérico ni de cuántos unos haya.

Si el tamaño fuera el valor numérico, `countOnes1(0xFFFFFFFF)` (≈4 mil millones) sería impracticable; pero tiene exactamente 32 bits activos y termina en 32 iteraciones.


**6. En `demo_adt_secuencia.cpp`, expliquen por qué la misma interfaz puede convivir con representaciones distintas.**

`demo_adt_secuencia.cpp` define la clase abstracta `IntSequence` con operaciones `size`, `get`, `set`, `add` y `remove`. Luego implementa `FixedArraySequence` (arreglo estático de capacidad 16) y `VectorSequence` (respaldada por `std::vector<int>`).

La función `run_scenario` recibe un `IntSequence&` por referencia y ejecuta exactamente las mismas operaciones sobre ambas. El cliente no necesita saber cómo está representada internamente la secuencia. Esto ilustra el principio de **separación entre interfaz y representación**: la corrección del contrato (el ADT) no depende de los detalles de implementación. Se puede sustituir una representación por otra sin modificar el código cliente, siempre que se respete la misma interfaz.



