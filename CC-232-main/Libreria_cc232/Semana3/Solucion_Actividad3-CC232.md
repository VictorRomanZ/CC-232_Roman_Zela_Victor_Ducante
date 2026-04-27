## Actividad 3-CC232

### Integrantes
- Roman Zela Victor Ducante

#### Bloque 1

1. **Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico**
    El almacenamiento contiguo guarda elementos en memoria adyacente, permitiendo acceso `O(1)` por índice pero con inserciones/eliminaciones costosas (`O(n)`). El almacenamiento enlazado usa nodos dispersos conectados por punteros. Esto abarata las inserciones/eliminaciones locales a `O(1)`, pero el acceso por índice se vuelve un recorrido secuencial de costo `O(i)`.

2. **Expliquen la diferencia entre acceso por rango y acceso por posición o enlace**
    El acceso por rango es típico de los arreglos y se refiere a encontrar un elemento por su orden numérico. El acceso por posición o enlace es propio de listas enlazadas y se refiere a operar sobre un nodo del que ya se tiene una referencia.

3. **Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice**
    Requiere reajustar los punteros `next`/`prev`, sin mover el resto de los datos. Empeora el acceso por índice porque al no tener memoria contigua no puede calcular la dirección de un elemento. Para llegar al índice `i`, debe recorrer secuencialmente `i` nodos desde el inicio, lo que tiene un costo lineal `O(i)`.

4. **Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`**
    Para una `Stack`, las operaciones `push` y `pop` se implementan en `O(1)` agregando y quitando nodos en `head` de la lista. Para una `Queue`, `add` se hace en `O(1)` en `tail` y `remove` se hace en `O(1)` en `head`. `SLList` es eficiente para esto al mantener punteros a ambos extremos.

5. **Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo**
    Un `Deque` requiere inserciones y eliminaciones eficientes en ambos extremos. `SLList` realiza `addFirst`, `removeFirst` y `addLast` en `O(1)` y `removeLast` cuesta `O(n)`, ya que para eliminar el último nodo se necesita una referencia al penúltimo. Al ser simplemente enlazada no se puede retroceder y debe recorrer toda la lista desde el inicio para encontrarlo.

6. **Expliquen qué aporta el nodo centinela `dummy` en `DLList`**
    Conecta el final de la lista con el inicio, creando una estructura lógicamente circular. Su gran ventaja es que elimina los casos especiales de lista vacía, inserción/eliminación en los extremos porque toda modificación ocurre siempre entre dos nodos existentes, simplificando la implementación.

7. **Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`**
    Al ser doblemente enlazada, `DLList` puede recorrerse desde la cabeza hacia adelante o desde la cola hacia atrás. Para acceder al índice `i`, el algoritmo elige el camino más corto desde el inicio si `i` está en la primera mitad, o desde el final si está en la segunda. El recorrido es proporcional a `min(i, n-i)`.

8. **Expliquen cuál es la idea espacial central de `SEList`**
    Reducir la sobrecarga de memoria de los punteros en una lista enlazada tradicional. En lugar de un nodo por elemento, agrupa múltiples elementos en bloques, logrando una mejor eficiencia espacial y mejorando la localidad de referencia.

9. **Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.**
    Cada nodo de la `SEList` es un bloque que necesita gestionar su propia colección de elementos de forma eficiente. Una `BDeque` implementada con `ArrayDeque` es ideal para esto. Proporciona acceso `O(1)` a los elementos dentro del bloque y permite agregar o quitar de sus extremos eficientemente, lo cual es fundamental para las operaciones de redistribución (`spread` y `gather`).

10. **Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.**
    DengList actúa como una capa de abstracción que provee una interfaz de lista con algoritmos de alto nivel porque no reemplaza a las estructuras de Morin, sino que las complementa. A través de `MorinDengBridge`, permite aplicar estos algoritmos genéricos sobre las listas de Morin sin tener que reimplementarlos para cada una.

#### Bloque 2 - Demostración y trazado guiado

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|---|---|---|---|
| `demo_sllist.cpp` | La salida muestra que `push`/`pop` operan en la cabeza (LIFO) y `add`/`remove` operan en cola/cabeza (FIFO). | Lista simplemente enlazada con punteros `head` y `tail`. | `push`, `pop`, `add`, `remove` son `O(1)`. El diseño con dos punteros permite implementar eficientemente interfaces de Pila y Cola. |
| `demo_dllist.cpp` | La inserción con `add(i, x)` en medio de la lista y la posterior impresión muestran que la lista se mantiene conectada. | Lista doblemente enlazada con nodo centinela `dummy`. | El acceso y modificación en `i` es `O(1 + min(i, n-i))` gracias al recorrido bidireccional. El centinela simplifica el código. |
| `demo_selist.cpp` | Al imprimir la lista, los elementos aparecen en orden lógico, aunque internamente estén agrupados en bloques. | Lista de bloques (nodos), donde cada bloque es un `BDeque` (deque acotado). | Reduce la sobrecarga de punteros, mejorando el uso de espacio. El costo de acceso `get(i)` es `O(b + n/b)`, un trade-off. |
| `demo_deng_list.cpp` | La demo invoca operaciones como `sort`, `deduplicate`, `reverse` que no están en las listas base de Morin. | Interfaz de lista (`DengList`) que ofrece una API rica con algoritmos de alto nivel. | Diseño enfocado en la completitud de la interfaz, reutilizando algoritmos genéricos sobre una estructura de datos subyacente. |
| `demo_morin_deng_bridge.cpp` | Se aplica `sort` a una `DLList` sin modificar su código, mostrando el resultado ordenado. | Un "puente" que convierte una lista de Morin a `DengList`, aplica una operación y convierte el resultado de vuelta. | Permite reutilizar algoritmos complejos a cambio de un costo de conversión de `O(n)` por operación. |
| `demo_min_structures.cpp` | La llamada a `min()` devuelve el mínimo actual en `O(1)` sin recorrer la estructura. | Estructuras aumentadas que guardan, junto al valor, información agregada (el mínimo hasta ese punto). | Es un trade-off clásico: se duplica el uso de espacio para ganar una consulta de `min()` en tiempo constante. |
| `demo_linked_adapters.cpp` | Muestra cómo `LinkedStack` solo expone `push`/`pop`, adaptando la interfaz más general de `SLList`. | Patrón Adaptador: una clase envuelve a otra para proveer una interfaz diferente y más específica. | El diseño promueve la reutilización de código y la claridad de la API. El costo de las operaciones es heredado de la estructura adaptada. |
| `demo_contiguous_vs_linked.cpp` | Tiempos o conteos que muestran que el acceso por índice es rápido en arreglos, pero la inserción es rápida en listas. | Comparación directa entre una implementación contigua (`ArrayDeque`) y una enlazada (`DLList`). | El almacenamiento contiguo tiene mejor localidad de caché y acceso `O(1)` por índice. El enlazado tiene inserciones/eliminaciones locales en `O(1)`. |

1.  **En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?**
    Una secuencia que intercala operaciones de ambos tipos, por ejemplo: `push(10)` y `push(20)`, seguido de `remove()` que saca `10`. Esto demuestra que `push` y `add` son distintos y que `pop` y `remove` son el mismo.

2.  **En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?**
     La operación `add(i, x)` cuando `i` es un índice que no es ni 0 ni el tamaño de la lista. La posterior impresión de la lista muestra cómo el nuevo elemento se intercala correctamente, reajustando los punteros `prev` y `next` de sus vecinos sin romper la secuencia.

3.  **En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?**
     El observable es la impresión completa de la lista. Esto prueba que los métodos de acceso y recorrido navegan correctamente entre bloques, ocultando la fragmentación interna al usuario.

4.  **En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?**
    La evidencia es la invocación de algoritmos de alto nivel como `sort()`, `deduplicate()` y `reverse()` directamente sobre el objeto lista. Estas operaciones, que son parte de un ADT de lista completo, no están en las interfaces de `SLList` o `DLList`.

5.  **En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?**
     La salida que muestra el estado de una `DLList` antes y después de llamar a una función como `stable_sort_with_deng`. Se observa que la lista, inicialmente desordenada, queda ordenada.

6.  **En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?**
    Almacenar solo valores obliga a recorrer la estructura (`O(n)`) para hallar el mínimo. Almacenar información adicional implica que cada nodo guarda el mínimo acumulado hasta ese punto. Esto permite que la consulta `min()` sea `O(1)`. La diferencia es un trade-off: se sacrifica espacio para ganar tiempo en una operación específica.


7.  **En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?**
    `LinkedStack` es el mejor ejemplo. Reutiliza la implementación de `SLList`, una lista de propósito general, pero expone una interfaz nueva y restringida de Pila (`push`, `pop`). Oculta las operaciones más complejas de la lista subyacente, como el acceso por índice. Esto ilustra perfectamente cómo una clase envuelve a otra para ofrecer una API diferente y más específica.

8.  **En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?**  
    Se observa un claro trade-off. La estructura contigua es superior en acceso por índice (`O(1)`) y tiene mejor localidad de memoria, beneficiando al caché. En contraste, la estructura enlazada es superior en inserciones/eliminaciones locales (costo `O(1)` una vez ubicado el nodo), ya que solo reajusta punteros en lugar de desplazar elementos masivamente.

#### Bloque 3 - Pruebas públicas, stress y correctitud

1. ¿Qué operaciones mínimas valida la prueba pública para `SLList`?
2. ¿Qué operaciones mínimas valida la prueba pública para `DLList`?
3. ¿Qué operaciones mínimas valida la prueba pública para `SEList`?
4. ¿Qué operaciones nuevas quedan cubiertas por `test_public_extras.cpp`?
5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?
6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?
7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?
8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?
9. ¿Qué no demuestra una prueba pública por sí sola?
10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?


