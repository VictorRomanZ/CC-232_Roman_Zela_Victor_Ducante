# Actividad 1 - CC232

### Integrantes
- Roman Zela Victor Ducante

## Bloque 1 — Núcleo conceptual de Semana 1

**1. Expliquen con sus palabras la diferencia entre problema, algoritmo, ADT e implementación.**

Un problema es una especificación abstracta que define la entrada que se recibe y la salida que se espera. Un algoritmo es un procedimiento finito, determinista y correcto que resuelve ese problema para toda entrada válida.
Un ADT es una interfaz que describe qué operaciones están disponibles sobre una colección de datos y qué contrato cumple cada una (precondición, postcondición), sin comprometerse con ninguna representación concreta.
Una implementación es la realización concreta de un ADT o un algoritmo en un lenguaje y estructura de datos específicos.

**2. En `bubble_sort.cpp`, expliquen qué observable conecta correctitud y costo.**

El struct `BubbleStats` conecta la correctitud con el costo del número de comparaciones e intercambios.

**3. En `power.cpp`, expliquen por qué `power` mejora la idea de una versión ingenua.**

`power` utiliza exponenciación binaria que reduce drásticamente las multiplicaciones frente a la versión ingenua lineal `powerBF`.

**4. En `fibonacci.cpp`, expliquen por qué una función puede ser correcta y aun así ser una mala elección práctica.**

La versión recursiva pura es correcta pero ineficiente por recalcular valores; la iterativa `fibI` es lineal y preferible.

**5. En `count_ones.cpp`, expliquen por qué el tamaño de entrada no siempre coincide con el valor numérico.**

El costo depende de la cantidad de bits en '1' y no de la magnitud decimal del número.

**6. En `demo_adt_secuencia.cpp`, expliquen por qué la misma interfaz puede convivir con representaciones distintas.**

`IntSequence` permite que el cliente use `add` o `get` sin saber si los datos están en un arreglo fijo o en un vector dinámico.

## Bloque 2

### Tabla

| Archivo | Salida / observable importante | Idea algorítmica | Argumento de costo |
|---|---|---|---|
| `demo_bubblesort.cpp` | Índices con desorden local, `comparaciones`, `intercambios`, `lastSwapIndex`, verificación `isSortedNonDecreasing` | Eliminar inversiones locales de forma iterativa hasta que no queden desórdenes | Cada intercambio elimina una inversión; el total de intercambios mide el desorden inicial. En el peor caso O(n²) |
| `demo_power.cpp` | Resultados idénticos de `powerBF` y `power` para los mismos argumentos | Exponenciación por cuadrados sucesivos frente a multiplicación lineal | `powerBF` hace O(n) multiplicaciones; `power` hace O(log n) |
| `demo_fibonacci.cpp` | `fibI(10)`, `fib(10)` y `fib(10, prev)` dan el mismo resultado; `prev` captura `fib(9)` | Iteración (O(n), O(1) espacio) vs. recursión ingenua (O(2^n)) | Para `n` grandes, la recursión doble crece exponencialmente; la iterativa crece linealmente |
| `demo_countones.cpp` | `countOnes1(x) == countOnes2(x)` para el mismo `x`; representación binaria visible con `bitset` | `countOnes1` elimina bits activos uno a uno; `countOnes2` agrupa bits con máscaras en rondas fijas | `countOnes1` cuesta O(k) donde k = número de unos; `countOnes2` cuesta O(1) (exactamente 5 rondas) |


**1. En `demo_bubblesort.cpp`, ¿qué salida sirve para defender costo y no solo resultado?**

Las estadísticas impresas como `swaps` y `comparisons` cuantifican el esfuerzo algorítmico real.

**2. En `demo_power.cpp`, ¿qué comparación concreta muestra una mejora algorítmica?**

La comparación entre `powerBF` y `power` muestra que ambos llegan al mismo valor, pero con menos operaciones internas.

**3. En `demo_fibonacci.cpp`, ¿qué crecimiento se vuelve defendible?**

Se observa que la versión iterativa maneja valores de `n` grandes instantáneamente, mientras que la recursiva se bloquea.

**4. En `demo_countones.cpp`, ¿qué ejemplo ayuda más a distinguir valor numérico de tamaño en bits?**

El bitset muestra que un número grande puede tener pocos bits activos, lo que dicta el tiempo de ejecución.

## Bloque 3 — Pruebas públicas y preparación de sustentación

**1. ¿Qué funciones o ideas están verificando las pruebas públicas?**

Las pruebas validan casos base (arreglos vacíos), correctitud de sumas, potencias y secuencias de Fibonacci.

**2. ¿Qué sí demuestra una prueba pública?**

Que el código cumple con los requisitos mínimos y casos de prueba definidos.

**3. ¿Qué no demuestra una prueba pública?**

No garantiza la ausencia de errores en casos no probados o bajo condiciones de memoria extrema.

**4.Elijan una pregunta de `preguntas_semana1.md` y respóndanla bien.**

**¿Qué diferencia hay entre una prueba que verifica que un arreglo quedó ordenado y una demostración del invariante del Bubble Sort?**

La prueba solo mira el resultado; el invariante garantiza que tras cada paso, una parte del arreglo ya es correcta.

**5. Autoevaluación**

- **Comprensión conceptual**: Se distingue con claridad problema, algoritmo, ADT e implementación, y explicamos correctitud, finitud y recursión con ejemplos del código.
- **Sustentación de correctitud**: Se justifica la correctitud de `bubble_sort` mediante la reducción de inversiones, la de `power` mediante la propiedad de exponentes, y la de `fib` recursivo mediante los casos base.
- **Análisis de eficiencia**: Se identifica O(n²) para bubble sort, O(log n) para power, O(2^n) vs O(n) para fib, y O(1) vs O(k) para countOnes2 vs countOnes1.

## Bloque 4 — Puente corto con Proyecto0

**1. ¿Qué diferencia observable deja `demo_const_refs.cpp` entre lectura, modificación y copia?**

La lectura no altera datos, la modificación en sitio es eficiente y la copia duplica el uso de memoria.

**2. En `bench_vector_growth.cpp`, ¿qué cambia con `reserve`?**

Evita múltiples realocaciones y copias internas del vector al crecer, mejorando el tiempo de ejecución.

**3. En `bench_vector_ops.cpp`, ¿por qué `push_back`, `insert(begin())` e `insert(middle)` no cuestan lo mismo?**

`push_back` es $O(1)$ amortizado, pero `insert` en el inicio o medio es $O(n)$ porque debe desplazar los elementos existentes.

**4. En `bench_cache_effects.cpp`, ¿qué intuición deja sobre localidad de memoria?**

El acceso secuencial es mucho más rápido que el aleatorio debido a que aprovecha mejor la caché del procesador.

## Bloque 5 — Extensión breve con Ejercicios0

**1. Según `Ejercicios0.md`, ¿cuál es el orden correcto antes de optimizar?**

1. Elegir buen algoritmo
2. Verificar correctitud
3. Medir rendimiento
4. Optimización del compilador.

**2. ¿Qué muestra `stl_optimizacion_demostracion.cpp` con `reserve`, `nth_element`, `partial_sort` y `lower_bound`?**

Mostrar que algoritmos especializados de la STL (como `nth_element`) superan a microajustes del compilador.

**3. ¿Qué tipo de evidencia puede producir `resolver_ejercicios0_v4.2.sh`?**

Reportes de tiempo, tamaño de binario, logs de sanitizers y perfiles de ejecución.

**4. ¿Qué limitaciones de entorno menciona `INSTRUCCIONES_Ejercicios0_v4.2.md`?**

Problemas de compatibilidad con sanitizers o profiling en entornos Windows/MinGW puros

**5. ¿Por qué esta parte no reemplaza la discusión de correctitud de Semana 1?**

Porque optimizar un algoritmo incorrecto no tiene sentido; la lógica y la correctitud son prioritarias.

## Bloque 6 — Cierre comparativo

**¿Qué cambia cuando pasamos de defender correctitud básica en Semana 1 a comparar implementaciones con evidencia experimental?**

Cambiamos de asegurar que el programa funciona a entender "cómo" se comporta bajo estrés. La especificación define el contrato; la correctitud asegura que se cumple; el costo mide el uso de recursos; la representación influye en la velocidad por la caché; y la advertencia metodológica nos recuerda que los datos empíricos deben interpretarse con cuidado, pues un buen benchmark no salva a un mal algoritmo.

## Autoevaluación breve

- **Qué podemos defender con seguridad**:La diferencia entre ADT e implementación y la importancia del costo asintótico.

- **Qué todavía confundimos**: Los detalles técnicos de cómo el compilador aplica LTO o PGO.

- **Qué evidencia usaríamos en una sustentación**: Los resultados de los benchmarks de crecimiento de vectores y las estadísticas de Bubble Sort.



















