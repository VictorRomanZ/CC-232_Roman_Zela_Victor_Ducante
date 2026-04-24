#### Bloque 1 - Núcleo conceptual de la semana

1. Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico.
    El almacenamiento contiguo guarda elementos en memoria adyacente, permitiendo acceso `O(1)` por índice pero con inserciones/eliminaciones costosas (`O(n)`). El almacenamiento enlazado usa nodos dispersos conectados por punteros. Esto abarata las inserciones/eliminaciones locales a `O(1)`, pero el acceso por índice se vuelve un recorrido secuencial de costo `O(i)`.

2. Expliquen la diferencia entre acceso por rango y acceso por posición o enlace.
    El acceso por rango es típico de los arreglos y se refiere a encontrar un elemento por su orden numérico. El acceso por posición o enlace es propio de listas enlazadas y se refiere a operar sobre un nodo del que ya se tiene una referencia.

3. Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice.
    Requiere reajustar los punteros `next`/`prev`, sin mover el resto de los datos. Empeora el acceso por índice porque al no tener memoria contigua no puede calcular la dirección de un elemento. Para llegar al índice `i`, debe recorrer secuencialmente `i` nodos desde el inicio, lo que tiene un costo lineal `O(i)`.

4. Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`.
    Para una `Stack`, las operaciones `push` y `pop` se implementan en `O(1)` agregando y quitando nodos en `head` de la lista. Para una `Queue`, `add` se hace en `O(1)` en `tail` y `remove` se hace en `O(1)` en `head`. `SLList` es eficiente para esto al mantener punteros a ambos extremos.

5. Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo.
    Un `Deque` requiere inserciones y eliminaciones eficientes en ambos extremos. `SLList` realiza `addFirst`, `removeFirst` y `addLast` en `O(1)` y `removeLast` cuesta `O(n)`, ya que para eliminar el último nodo se necesita una referencia al penúltimo. Al ser simplemente enlazada no se puede retroceder y debe recorrer toda la lista desde el inicio para encontrarlo.

6. Expliquen qué aporta el nodo centinela `dummy` en `DLList`.
    Conecta el final de la lista con el inicio, creando una estructura lógicamente circular. Su gran ventaja es que elimina los casos especiales de lista vacía, inserción/eliminación en los extremos porque toda modificación ocurre siempre entre dos nodos existentes, simplificando la implementación.

7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.
    Al ser doblemente enlazada, `DLList` puede recorrerse desde la cabeza hacia adelante o desde la cola hacia atrás. Para acceder al índice `i`, el algoritmo elige el camino más corto desde el inicio si `i` está en la primera mitad, o desde el final si está en la segunda. El recorrido es proporcional a `min(i, n-i)`.

8. Expliquen cuál es la idea espacial central de `SEList`.
    Reducir la sobrecarga de memoria de los punteros en una lista enlazada tradicional. En lugar de un nodo por elemento, agrupa múltiples elementos en bloques, logrando una mejor eficiencia espacial y mejorando la localidad de referencia.

9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.
    Cada nodo de la `SEList` es un bloque que necesita gestionar su propia colección de elementos de forma eficiente. Una `BDeque` implementada con `ArrayDeque` es ideal para esto. Proporciona acceso `O(1)` a los elementos dentro del bloque y permite agregar o quitar de sus extremos eficientemente, lo cual es fundamental para las operaciones de redistribución (`spread` y `gather`).

10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.
    DengList actúa como una capa de abstracción que provee una interfaz de lista con algoritmos de alto nivel porque no reemplaza a las estructuras de Morin, sino que las complementa. A través de `MorinDengBridge`, permite aplicar estos algoritmos genéricos sobre las listas de Morin sin tener que reimplementarlos para cada una.

#### Bloque 2 - Demostración y trazado guiado

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?
    La salida muestra que `push`/`pop` operan en la cabeza (LIFO) y `add`/`remove` operan en cola/cabeza (FIFO).

2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?
    La inserción con `add(i, x)` en medio de la lista y la posterior impresión muestran que la lista se mantiene conectada.

3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?
    Al imprimir la lista, los elementos aparecen en orden lógico, aunque internamente estén agrupados en bloques.

4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?
    La demo invoca operaciones como `sort`, `deduplicate`, `reverse` que no están en las listas base de Morin. 

5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?
    Se aplica `sort` a una `DLList` sin modificar su código, mostrando el resultado ordenado.

6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?
    La llamada a `min()` devuelve el mínimo actual en `O(1)` sin recorrer la estructura.

7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?
    Muestra cómo `LinkedStack` solo expone `push`/`pop`, adaptando la interfaz más general de `SLList`.

8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?
    Tiempos o conteos que muestran que el acceso por índice es rápido en arreglos, pero la inserción es rápida en listas.




