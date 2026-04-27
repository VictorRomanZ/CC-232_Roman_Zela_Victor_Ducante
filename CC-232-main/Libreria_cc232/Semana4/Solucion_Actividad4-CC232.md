# Actividad 4 - CC232

### Integrantes
- Roman Zela Victor Ducante

#### Bloque 1 - Núcleo conceptual de la semana

**1. Explica con tus palabras la diferencia entre acceso `LIFO` y acceso `FIFO`.**
LIFO significa que el último elemento en entrar es el primero en salir, operando solo sobre un extremo y FIFO significa que el primer elemento en entrar es el primero en salir, ingresando por el final y saliendo por el frente.

**2. Explica por qué `Stack` resuelve naturalmente problemas donde importa "lo último pendiente".**
La pila almacena contextos de ejecución o decisiones temporales. Cuando se necesita retroceder o evaluar una operación diferida, la información más reciente es siempre la primera accesible en el tope.

**3. Explica por qué `Queue` modela naturalmente procesos de espera y atención.**
Asegura que las entidades sean procesadas exactamente en el orden cronológico en el que llegaron.

**4. Explica qué significa reemplazar recursión implícita por una estructura explícita.**
Significa dejar de usar el call stack del sistema operativo y en su lugar instanciar un ADT Stack en el heap para almacenar manualmente las variables de estado.

**5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.**
Debe guardar el estado actual de la decisión tomada para saber desde dónde reanudar si ocurre un error o un backtracking.

**6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?**
Ambas se basan en el mismo algoritmo matemático para obtener residuos de divisiones sucesivas por la base. Ambas necesitan invertir el orden de los residuos, ya que el primero que se obtiene es el dígito menos significativo.
La versión recursiva usa la pila de llamadas implícita para almacenar los residuos y los concatena al volver. La versión iterativa usa una pila explícita para almacenar los residuos en un bucle y luego los extrae para construir la cadena.

**7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.**
Necesita una pila para recordar los paréntesis de apertura que aún no se han cerrado. Cuando aparece un símbolo de apertura, se apila. Cuando aparece uno de cierre, se verifica si coincide con el último de apertura apilado. La pila mantiene la "deuda" de cierres pendientes y garantiza que el orden de anidamiento sea correcto.

**8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.**
Usar una sola pila mezclaría datos y lógica de control, haciendo imposible manejar correctamente la precedencia de operaciones como en `3 + 5 * 2`.

**9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.**
Porque ambos problemas implican construir una solución paso a paso y retroceder cuando un camino no lleva a una solución válida.
En ambos casos, se explora una secuencia de decisiones y se deshacen cuando resultan ser incorrectas.

**10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.**
Este es un comportamiento FIFO, modelado por una `Cola`. Usar una `Pila` (LIFO) sería injusto porque el último cliente en llegar sería el primero en ser atendido, y los primeros podrían esperar indefinidamente.

**11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.**
La estructura auxiliar es el contenedor que almacena el estado parcial del algoritmo. La correctitud del algoritmo depende de que la estructura mantenga un invariante sobre ese estado. Por ejemplo, en N-Reinas, la pila siempre debe representar una colocación parcial de reinas sin conflictos. Si la estructura no gestiona bien el estado, el algoritmo fallará.

**12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".**
Resolver un problema busca encontrar una respuesta estática que cumple ciertas restricciones. El objetivo es la correctitud y eficiencia para llegar a esa solución.
Simular un proceso busca modelar la evolución de un sistema a lo largo del tiempo. El resultado es una traza del comportamiento dinámico del sistema. El objetivo es observar y analizar el comportamiento, a menudo con aleatoriedad, para entender el sistema.


#### Bloque 2 - Demostración y trazado guiado

| Archivo | Salida u observable importante | Estructura o técnica central | Qué concepto permite defender |
| :--- | :--- | :--- | :--- |
| `demo_stack_queue.cpp` | Orden inverso (Stack) vs Orden original (Queue) | Stack vs Queue | La naturaleza LIFO vs FIFO de los ADTs básicos. |
| `demo_base_conversion.cpp` | El mismo número (ej. "1010") para ambos métodos | Pila explícita vs Recursión | La equivalencia entre algoritmos iterativos y recursivos. |
| `demo_paren_rpn.cpp` | La cadena postfija (RPN) generada | Pilas y Precedencia | Cómo los operadores se ordenan según su prioridad jerárquica. |
| `demo_nqueens.cpp` | Diferencia entre soluciones halladas y checks realizados | Backtracking iterativo | El alto costo computacional de la búsqueda exhaustiva. |
| `demo_maze.cpp` | La lista de coordenadas del camino final | Pila de punteros a celdas | El uso de la pila para registrar una ruta exitosa. |
| `demo_bank.cpp` | Longitud de colas en cada segundo `t` | Vector de colas (`Queue<Customer>`) | La distribución de carga en un sistema multicanal. |
| `demo_capitulo4_panorama.cpp` | Resumen de ejecución de todas las utilidades | ADTs Lineales | La versatilidad de pilas y colas en diversas aplicaciones. |

**1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?**
La salida de desapilar (LIFO) muestra los elementos en orden inverso a su inserción, a diferencia de la cola.

**2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?**
El observable es que `toBaseRecursive` y `toBaseIterative` retornan la misma cadena para el mismo `n` y `base`.

**3. En `demo_paren_rpn.cpp`, ¿qué relación observas entre paréntesis balanceados, RPN y valor final?**
Se observa que las expresiones con paréntesis balanceados permiten generar una RPN que, al ser evaluada, da el valor matemático correcto.

**4. En `demo_nqueens.cpp`, ¿qué significan `solutions` y `checks`, y por qué no miden lo mismo?**
`solutions` cuenta configuraciones válidas; `checks` cuenta cada vez que se verifica si una reina ataca a otra. `checks` es mucho mayor debido a las pruebas fallidas.

**5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?**
Muestra la secuencia de pasos desde el inicio hasta el objetivo, omitiendo los caminos que resultaron en `BACKTRACKED`.

**6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante `t`?**
Cada lista impresa representa el tiempo de atención restante de los clientes que están esperando en esa ventanilla específica en el tiempo `t`.

**7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?**
La salida que muestra el éxito de tareas tan distintas usando las mismas bases estructurales.

#### Bloque 3 - Pruebas públicas, pruebas internas y correctitud

**1. ¿Qué operaciones mínimas valida la prueba pública para `Stack`?**
`push`, `pop`, `top`, `empty` y `size`

**2. ¿Qué operaciones mínimas valida la prueba pública para `Queue`?**
`enqueue`, `dequeue`, `front`, `empty` y `size` 

**3. ¿Qué valida la prueba pública sobre conversión de base?**
Valida bases entre 2 y 16, manejo de caracteres 'A'-'F' y el caso especial del número 0.

**4. ¿Qué valida la prueba pública sobre paréntesis balanceados?**
Valida balanceo simple, anidamiento múltiple y detección de tipos de cierre incorrectos.

**5. ¿Qué valida la prueba pública sobre evaluación de expresiones y RPN?**
Valida precedencia, asociatividad, paréntesis y manejo de errores (división por cero).

**6. ¿Qué valida la prueba pública sobre `NQueens`?**
Valida que el número de soluciones para un `n` dado coincida con los resultados matemáticos conocidos.

**7. ¿Qué valida la prueba pública sobre `Maze`?**
Valida que encuentre un camino en laberintos simples y que reporte error si no hay salida.

**8. ¿Qué valida la prueba pública sobre `bestWindow` en la simulación bancaria?**
Valida que se elija la cola con el menor número de clientes (`size()`) en el momento del arribo

**9. ¿Qué casos adicionales cubre la prueba interna y no aparecen de forma explícita en la pública?**
Suelen cubrir casos de borde como estructuras vacías, valores máximos, o laberintos sin ningún espacio disponible.

**10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, estado y complejidad?**
Las pruebas confirman que funciona para casos específicos; la explicación de invariantes asegura que el diseño es robusto para cualquier entrada válida.

**11. Da un ejemplo de un error conceptual que podría sobrevivir si solo se ejecutaran los casos mínimos.**
Por ejemplo, que el evaluador funcione para sumas y restas pero falle en potencias por no considerar la asociatividad a la derecha, algo que una prueba mínima podría no detectar.


#### Bloque 4 - Comparación recursivo vs iterativo

**1. En conversión de base, ¿qué papel juegan el cociente, el residuo y la pila?**
El cociente reduce el número para la siguiente iteración; el residuo es el dígito de la nueva base; la pila invierte el orden de los residuos para formar el número correcto 

**2. ¿Por qué los residuos se apilan antes de formar la cadena final?**
Porque el primer residuo calculado es el dígito menos significativo, pero al escribir el número empezamos por el más significativo.

**3. ¿Qué cambia entre dejar que el call stack haga el trabajo y manejar una pila explícita?**
La pila explícita reside en el heap y su tamaño solo está limitado por la RAM total, mientras que el call stack es pequeño y limitado por el sistema operativo.

**4. En `parenRecursive`, ¿qué idea intenta capturar `divideParentheses`?**
Busca el punto donde se cierra el primer bloque de paréntesis abierto en `lo`, permitiendo dividir la cadena en sub-problemas independientes.

**5. ¿Qué limitación conceptual tiene la versión recursiva mostrada frente a la iterativa cuando aparecen `[]` y `{}`?**
La versión `parenRecursive` mostrada suele estar diseñada solo para un tipo de paréntesis `()`. La versión iterativa maneja fácilmente `[]` y `{}` usando la pila para recordar cuál fue el último abierto

**6. En `parenIterative`, ¿por qué un cierre incorrecto puede detectarse apenas aparece?**
Porque en el momento que aparece un cierre, este debe coincidir con el tope de la pila. Si no coincide, la cadena es inválida en ese mismo instante.

**7. Compara ambas parejas de funciones: ¿en cuál caso la versión iterativa te parece más natural y en cuál la recursiva resulta más expresiva?**
La iterativa es más natural para procesos lineales; la recursiva es más expresiva para estructuras jerárquicas como árboles o divisiones lógicas.

##### Experimento 1

| Número | Base | Salida recursiva | Salida iterativa | ¿Coinciden? | Comentario |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 10 | 2 | `1010` | `1010` | Sí | Conversión binaria estándar. |
| 255 | 16 | `FF` | `FF` | Sí | Prueba de dígitos hexadecimales A-F. |
| 64 | 8 | `100` | `100` | Sí | Caso de potencia exacta de la base. |
| 123 | 10 | `123` | `123` | Sí | Identidad en base decimal. |
| 42 | 3 | `1120` | `1120` | Sí | Prueba en base impar con múltiples dígitos. |

##### Experimento 2

| Caso | Expresión | Res. Recursivo | Res. Iterativo | ¿Coinciden? | Qué explica el caso |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Vacía | `""` | `true` | `true` | Sí | Caso base trivial. |
| Sin paréntesis | `"abc"` | `true` | `true` | Sí | No hay símbolos que procesar. |
| Anidada | `"(())"` | `true` | `true` | Sí | Estructura balanceada simple. |
| Desbalance | `"(()"` | `false` | `false` | Sí | Falta un cierre al final. |
| Cruce incorrecto | `"([)]"` | `false` | `false` | Sí | El cierre no corresponde a la última apertura. |
| Múltiples tipos | `"{[()]}"` | `false` | `true` | No | La recursiva solo busca `()`; la iterativa es polivalente. |
| Larga | `"((((()))))"` | `true` | `true` | Sí | Profundidad de anidamiento manejada correctamente. |
| Inventada | `"()(())"` | `true` | `true` | Sí | Dos bloques independientes válidos. |


