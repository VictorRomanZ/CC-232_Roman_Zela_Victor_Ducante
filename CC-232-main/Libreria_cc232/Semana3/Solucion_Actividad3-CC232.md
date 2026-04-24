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
    El nodo `dummy` es un nodo auxiliar que no almacena datos y actúa como ancla. Conecta el final de la lista con el inicio, creando una estructura lógicamente circular. Su gran ventaja es que elimina los casos especiales (lista vacía, inserción/eliminación en los extremos), ya que toda modificación ocurre siempre entre dos nodos existentes, simplificando la implementación.
    
7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.
8. Expliquen cuál es la idea espacial central de `SEList`.
9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.
10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.







