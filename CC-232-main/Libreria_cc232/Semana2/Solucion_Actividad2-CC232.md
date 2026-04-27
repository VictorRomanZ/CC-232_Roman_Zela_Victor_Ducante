## Actividad 2-CC232

### Integrantes
Roman Zela Victor Ducante

#### Bloque 1 - Núcleo conceptual de la semana

**1. Expliquen con sus palabras qué significa que un arreglo use **memoria contigua.**

Significa que los elementos de una estructura se almacenan en direcciones de memoria física adyacentes, uno inmediatamente después del otro, sin huecos intermedios.

**2. Expliquen por qué acceder a `A[i]` es una operación de costo `O(1)`.**

Al usar memoria contigua, el programa no necesita buscar el elemento. Calcula su dirección exacta mediante aritmética de punteros usando una fórmula matemática simple: `dirección_base + (i * tamaño_del_tipo de dato)`. Esta operación matemática toma un tiempo constante.

**3. Expliquen la diferencia entre `size` y `capacity`.** 

`size` es la cantidad de elementos lógicos y válidos que el usuario ha insertado en la estructura. `length` es la cantidad total de espacio de memoria física que se ha reservado, incluyendo los espacios vacíos disponibles para futuras inserciones.

**4. Expliquen por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer `resize()`.** 

La memoria dinámica que provee el sistema operativo asigna bloques de tamaño fijo. Si el bloque actual está rodeado de datos de otros programas, no se puede "estirar" en el mismo lugar. Se debe reservar un bloque más grande en otra ubicación, copiar los datos viejos y liberar la memoria original.

**5. Expliquen por qué duplicar capacidad permite defender costo amortizado `O(1)` para inserciones al final.** 

Duplicar la capacidad significa que los redimensionamientos (que cuestan O(n)) ocurren cada vez con menor frecuencia (en potencias de 2). Si promediamos el costo de esa única operación pesada entre todas las inserciones individuales baratas que la precedieron, el costo "por inserción" se mantiene matemáticamente constante o O(1).

**6. Comparen `ArrayStack` y `DengVector`: ¿qué comparten y qué cambia en interfaz o intención didáctica?** 

Ambos implementan arreglos dinámicos que duplican su capacidad. Sin embargo, ArrayStack usa una clase intermediaria `ods::array` para simular arreglos de Java, enfocándose en la didáctica abstracta de interfaces tipo Lista (`get`, `set`, `add`). DengVector es más robusto a nivel de C++, usa punteros crudos, e implementa semántica de la STL.

**7. Expliquen qué mejora `FastArrayStack` respecto a `ArrayStack`.** 

Asintóticamente tienen la misma complejidad, pero FastArrayStack reemplaza los bucles `for` manuales de ArrayStack por funciones de la biblioteca estándar de C++ (`std::copy` y `std::copy_backward`). Esto permite que el compilador optimice los desplazamientos de memoria a nivel de hardware, haciendo la ejecución real mucho más rápida.

**8. Expliquen cuál es la idea espacial central de `RootishArrayStack`.** 

En lugar de reservar un solo arreglo gigante continuo que desperdicia mucha memoria, divide la estructura en una lista de bloques (arreglos) más pequeños, donde cada nuevo bloque es una unidad más grande que el anterior.

**9. Expliquen por qué `RootishArrayStack` usa bloques de tamaños `1, 2, 3, ...`.** 

Al usar el crecimiento aritmético (serie triangular), la estructura evita duplicar grandes cantidades de memoria de golpe. Esto garantiza que el espacio desperdiciado nunca exceda un costo proporcional a la raíz cuadrada de n, una mejora dramática frente al O(n) del arreglo tradicional.

**10. Expliquen qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.** 

Define el desperdicio espacial (mucho en ArrayStack, mínimo en RootishArrayStack) y afecta el costo temporal (cálculo directo en arreglos simples vs resolución de ecuaciones cuadráticas para mapear bloques en arreglos basados en raíces).

#### Bloque 2 - Demostración y trazado guiado

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo o espacio |
| :--- | :--- | :--- | :--- |
| `demo_array_basico.cpp` | `b.length = 5` tras `b = a` | El arreglo tiene tamaño fijo. La asignación transfiere el ownership de la memoria. | Modificar tamaño requiere una estructura superior. |
| `demo_arraystack_explicado.cpp` | `add(1, 15)` desplaza a la derecha, `remove(0)` a la izquierda | Mantenimiento del invariante: los elementos viven contiguos en el rango [0, n). | Inserción/eliminación cuestan O(n - i) por la copia de elementos. |
| `demo_fastarraystack.cpp` | Salida idéntica a ArrayStack | Uso de funciones de la STL para gestionar rangos en memoria. | Mismo costo asintótico, pero menor constante de tiempo por optimización. |
| `demo_rootisharraystack_explicado.cpp` | `índice lógico 5 -> bloque 3, offset 2` | Un índice lineal abstracto se descompone matemáticamente en coordenadas físicas (b, j). | El mapeo toma O(1) usando funciones matemáticas (sqrt). |
| `demo_deng_vector.cpp` | capacity se duplica (3 -> 6 -> 12) | Estrategia de expansión por duplicación de memoria subyacente. | Defiende el costo amortizado constante para inserciones al final. |
| `demo_stl_vector_contraste.cpp` | capacity de std::vector crece de forma controlada | Es el estándar de C++ que aplica el mismo diseño teórico visto en clase. | Valida que la estrategia de DengVector es estándar en la industria. |

**1. En `demo_array_basico.cpp`, ¿qué deja claro sobre arreglo, longitud y asignación?** 

Deja claro que el arreglo nativo tiene una longitud inmutable y que la asignación en la clase `ods::array` transfiere la propiedad del puntero (ownership).

**2. En `demo_arraystack_explicado.cpp`, ¿qué operación muestra mejor el costo por desplazamientos?** 

Las operaciones de `add` y `remove` en posiciones intermedias muestran claramente el costo de desplazamientos masivos de elementos.

**3. En `demo_fastarraystack.cpp`, ¿qué cambia en la implementación aunque no cambie la complejidad asintótica?** 

Cambia el uso de bucles explícitos por llamadas a `std::copy`, lo que mejora el rendimiento práctico mediante optimizaciones de bajo nivel del compilador.

**4. En `demo_rootisharraystack_explicado.cpp`, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?** 

El ejemplo del índice 5 mapeado al bloque 3 y offset 2 ilustra cómo la estructura "rompe" la secuencia lógica en bloques físicos de tamaño incremental.

**5. En `demo_deng_vector.cpp`, ¿qué observable permite defender el crecimiento de `capacity`?** 

El crecimiento de `capacity` (observando cómo salta de 3 a 6, luego a 12) permite defender el mecanismo de duplicación necesario para la amortización.

**6. En `demo_stl_vector_contraste.cpp`, ¿qué similitud conceptual observan con `DengVector`?** 

Se observa que `std::vector` sigue la misma lógica de redimensionamiento dinámico que el vector de Deng, validando la teoría.

**7. ¿Qué demo sirve mejor para defender amortización y cuál sirve mejor para defender uso de espacio?**

    - **Amortización:** `demo_deng_vector.cpp`
    - **Uso de espacio:** `demo_rootisharraystack_explicado.cpp`

#### Bloque 3 - Pruebas públicas, stress y correctitud

**1. ¿Qué operaciones mínimas valida la prueba pública para `ArrayStack`?** 

Valida `add(x)`, `add(i, x)`, `get(i)`, `remove(i)` y el mantenimiento de `size()`.

**2. ¿Qué operaciones mínimas valida la prueba pública para `FastArrayStack`?** 

Valida inserciones en distintos puntos, lectura y eliminación.

**3. ¿Qué operaciones mínimas valida la prueba pública para `RootishArrayStack`?** 

Valida el mapeo correcto mediante inserciones consecutivas, `get`, `set` y reubicación en `remove`.

**4. ¿Qué sí demuestra una prueba pública sobre una estructura?** 

Que el código compila y que para casos de uso estándar la lógica de índices y tamaños es correcta.

**5. ¿Qué no demuestra una prueba pública?**

No demuestra la ausencia de fugas de memoria, comportamiento bajo condiciones de memoria extrema o el cumplimiento estricto de la complejidad asintótica.

**6. En `resize_stress_week2.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?** 

Intenta estresar la estabilidad de los punteros internos y la correctitud de `resize/expand/shrink` sometiendo las estructuras a ráfagas de inserciones y eliminaciones masivas.

**7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?** 

Las pruebas son evidencia empírica limitada. La explicación de invariantes y complejidad es una prueba deductiva que garantiza el funcionamiento para cualquier entrada N.

#### Bloque 4 - Vector como puente entre teoría y código

**1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?** 

`_size` (límite lógico de elementos válidos), `_capacity` (límite físico reservado), `_elem` (puntero al arreglo crudo en el Heap).

**2. ¿Cuándo debe ejecutarse `expand()`?**

Cuando el arreglo está lleno (`_size == _capacity`) y se requiere insertar un nuevo elemento.

**3. ¿Por qué `insert(r, e)` necesita desplazar elementos?** 

Para mantener la contigüidad y el orden secuencial; de lo contrario, se sobreescribirían datos existentes.

**4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?** 

`remove(r)` mueve elementos uno por uno. `remove(lo, hi)` desplaza un bloque entero de una sola vez, siendo mucho más eficiente.

**5. ¿Qué evidencia de copia profunda aparece en la demo?** 

En la demo, modificar `asignado` no afecta a `copia`, lo que indica que cada uno tiene su propia reserva de memoria física.

**6. ¿Por qué `traverse()` es una buena interfaz didáctica?** 

Permite separar la estructura de datos de la lógica de procesamiento (patrón Visitor), facilitando el procesamiento uniforme.

**7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?** 

Permite entender la administración manual de memoria dinámica, la amortización y el comportamiento de los constructores en C++ antes de usar abstracciones de alto nivel.

#### Bloque 5 - RootishArrayStack: espacio y mapeo

**1. ¿Cómo se distribuyen los elementos entre bloques?** 

El bloque 0 tiene 1 elemento, el bloque 1 tiene 2, el bloque 2 tiene 3, y así sucesivamente (el bloque `b` tiene capacidad `b+1`).

**2. ¿Por qué con `r` bloques la capacidad total es `r(r+1)/2`?** 

Es la suma de una progresión aritmética de 1 hasta `r`.

**3. ¿Qué problema resuelve `i2b(i)`?** 

Permite encontrar en tiempo O(1) en qué bloque se encuentra un índice lógico sin tener que iterar por los bloques.

**4. ¿Qué información produce `locate(i)` en la versión explicada?** 

Proporciona el índice del bloque (`b`) y la posición relativa (`offset`) dentro de ese bloque.

**5. ¿Qué se gana en espacio frente a `ArrayStack`?** 

El desperdicio se limita a lo mucho al espacio vacío del último bloque, lo que resulta en un espacio extra de O(sqrt(n)) en lugar del O(n) de un arreglo tradicional.

**6. ¿Qué se conserva igual respecto a la interfaz?** 

Se mantiene la interfaz de Lista con acceso por índice, por lo que el usuario no percibe la complejidad de la fragmentación interna.

**7. ¿Qué parte les parece más difícil de defender oralmente: el mapeo, el análisis espacial o el costo amortizado de `grow/shrink`?** 

Generalmente, explicar la matemática del mapeo (la ecuación cuadrática para `i2b`) y cómo se logra el O(1) de acceso a pesar de la estructura de bloques.

#### Bloque 6 - Refuerzo de lectura

**1. ¿Qué aporta `operator[]` a la idea de vector?** 

Permite acceder a los elementos con la sintaxis natural de arreglos `v[i]`, mejorando la legibilidad.

**2. ¿Qué supone `find(e)` sobre igualdad entre elementos?** 

Supone que el tipo de dato `T` tiene definido el operador de igualdad `==`.

**3. ¿Qué muestra `traverse()` sobre procesamiento uniforme de toda la estructura?** 

Muestra cómo procesar todos los elementos de forma secuencial aplicando una función o functor de manera uniforme.

**4. ¿Por qué esta lectura sirve como refuerzo natural de `DengVector` aunque no sea el centro exclusivo de la semana?** 

Porque conecta la teoría de arreglos dinámicos con una implementación robusta en C++ que maneja plantillas y gestión de memoria cruda.

#### Bloque 7 - Cierre comparativo

**¿Qué cambia cuando pasamos de "usar un arreglo" a "diseñar una estructura dinámica basada en arreglo"?**

Al pasar de un arreglo estático a una estructura dinámica, **cambia la representación**: abandonamos el bloque inmutable por punteros dinámicos en el Heap que permiten el redimensionamiento. **Garantizar la correctitud** implica mantener el invariante entre el tamaño lógico (`size`) y la capacidad física (`capacity`). Para manejar la ineficiencia de las reservas de memoria, usamos el **costo amortizado**, permitiendo operaciones pesadas ocasionales para asegurar un promedio `O(1)`.

#### Autoevaluación breve

- **Qué podemos defender con seguridad:** La diferencia entre size/capacity y la lógica de duplicación para la amortización.
- **Qué todavía confundimos:** La implementación exacta de las funciones de la STL en FastArrayStack frente a los bucles manuales.
- **Qué evidencia usaríamos en una sustentación:** Las trazas de las demos explicadas y los resultados de los tests de estrés.
