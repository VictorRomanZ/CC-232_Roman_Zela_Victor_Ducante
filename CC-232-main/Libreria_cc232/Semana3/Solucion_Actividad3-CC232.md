## Actividad 3-CC232

### Integrantes
- Roman Zela Victor Ducante

#### Bloque 1

1. **Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico**

Se pasa de tener todos los elementos en un solo bloque de memoria contiguo que se accede mediante matemática de punteros, a tener elementos dispersos en la memoria (nodos), conectados explícitamente mediante punteros (`next`, `prev`).

2. **Expliquen la diferencia entre acceso por rango y acceso por posición o enlace**

En un arreglo, acceder al i-ésimo elemento toma O(1) calculando su dirección. En una lista enlazada, acceder al i-ésimo elemento requiere recorrer la estructura nodo por nodo desde el inicio o el fin, tomando tiempo O(i) u O(n-i).

3. **Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice**

Una vez que se tiene el puntero a la ubicación exacta, insertar o eliminar en una lista solo requiere reasignar 2 o 3 punteros (tiempo O(1)), sin desplazar arreglos masivos. Sin embargo, encontrar esa ubicación toma O(n).

4. **Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`**

`SLList` mantiene punteros al `head` y al `tail`. Para un Stack (LIFO), puede hacer `push` y `pop` en el `head` en O(1). Para un Queue (FIFO), puede hacer `add` en el `tail` en O(1) y `remove` en el `head` en O(1).

5. **Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo**

Un Deque requiere eliminar elementos tanto al inicio como al final en O(1). En una `SLList`, eliminar el último elemento `removeLast` toma O(n) porque, al no haber punteros hacia atrás `prev`, se debe iterar desde el inicio para encontrar el penúltimo nodo y actualizar el `tail`.

6. **Expliquen qué aporta el nodo centinela `dummy` en `DLList`**

Evita casos borde tediosos. En una lista sin centinela, insertar en una lista vacía o eliminar el último elemento requiere validaciones `if (head == nullptr)`. Con el `dummy`, la lista circular siempre tiene al menos un nodo, estandarizando la lógica de actualización de punteros.

7. **Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`**

El método `getNode(i)` decide inteligentemente si buscar desde el `head` (hacia adelante) o desde el `tail` (hacia atrás) comparando `i` con `n/2`. Como máximo, recorre la mitad de la lista. Tras hallar el nodo, la reasignación de punteros es O(1).

8. **Expliquen cuál es la idea espacial central de `SEList`**

Agrupar elementos en bloques organizados como una lista doblemente enlazada. Reduce el número de punteros necesarios y mejora la localidad de caché frente a una `DLList` normal.

9. **Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.**

`BDeque` hereda de `ArrayDeque` pero anula `resize()`. Es un bloque de capacidad fija ideal para desplazar elementos rápidamente de forma local durante las operaciones `spread` o `gather`.

10. **Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.**

Complementa a Morin. Mientras Morin ofrece implementaciones minimalistas para análisis asintótico, `DengList` proporciona operaciones más completas como sort, dedup, uniquify, reverse, típicas de un ADT robusto. No los reemplaza, sino que actúa como capa superior.

#### Bloque 2 - Demostración y trazado guiado

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
| :--- | :--- | :--- | :--- |
| `demo_sllist.cpp` | `peek=10`, `pop=5` | Lista simplemente enlazada con head/tail. | Operaciones en extremos (pila/cola) en O(1). |
| `demo_dllist.cpp` | Inserciones y lectura correcta. | Nodos doblemente enlazados con centinela. | Inserción en el medio O(1) una vez ubicado. |
| `demo_selist.cpp` | Impresión de secuencia lógica uniforme. | Bloques `BDeque` conectados. | Trade-off: Menos punteros, mejor localidad vs shifts locales. |
| `demo_deng_list.cpp` | `ordenada: ...` tras llamar `sort()` | ADT de lista enriquecido. | Reutilización de algoritmos complejos nativos. |
| `demo_morin_deng_bridge.cpp` | `Removido = 1` tras `dedup` | Puente de integración. | Rehúso de código: aplicar Deng a Morin sin reescribir. |
| `demo_capitulo3_panorama.cpp` | Carga e impresión de todas las TDA. | Diversidad de representaciones. | Comparativa directa de interfaces. |
| `demo_min_structures.cpp` | Mantenimiento de `min=1` en O(1). | Envoltorios con tracking interno (`Entry`). | Trade-off: Más memoria por nodo por tiempo O(1). |
| `demo_xor_list.cpp` | `front=5`, `back=20` | Puntero comprimido (XOR). | Ahorro de espacio (1 puntero por nodo en vez de 2). |
| `demo_linked_adapters.cpp` | Operaciones correctas de Stack/Queue. | Patrón Adapter / Envoltorio. | Reutilización de `SLList` y `DLList` limitando la interfaz. |
| `demo_contiguous_vs_linked.cpp` | Tiempo de `get(4)` vs acceso directo. | Contiguo vs Enlazado. | Arrays ganan en acceso aleatorio, listas en no-redimensionar. |


**1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?**

La llamada a `add` inserción al final y `push` inserción al inicio en el mismo objeto muestra cómo `SLList` maneja eficientemente operaciones de ambos paradigmas.

**2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?**

`d.add(1, 30)` y `d.add(1, 20)` muestran cómo los nodos se insertan re-enganchando punteros en el medio sin alterar la memoria de los nodos adyacentes.

**3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?**

La iteración secuencial con `get(i)` muestra una sucesión lineal perfecta, escondiendo completamente la fragmentación física interna en bloques.

**4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?**

 La ejecución directa de métodos como `.sort()` muestra que no es solo una estructura de almacenamiento, sino un contenedor de algoritmos.

**5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?**

Llamar a `cc232::stable_sort_with_deng(lista)` donde `lista` es una `DLList` pura de Morin prueba que la lógica de Deng es re-utilizable vía el puente.

**6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?**

Almacenar `Entry {value, current_min}` permite consultar el mínimo en tiempo constante absoluto sin recorrer toda la colección.

**7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?**

`LinkedQueue` envolviendo a `SLList` encapsula y restringe los métodos para forzar que el usuario solo use semántica FIFO (`add`, `remove`).

**8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?**  

El acceso `get(4)` en `ArrayDeque` utiliza matemática de punteros directa, mientras que `DLList` requiere un bucle para llegar al cuarto nodo.

#### Bloque 3 - Pruebas públicas, stress y correctitud

**1. ¿Qué operaciones mínimas valida la prueba pública para `SLList`?**

Valida la correcta actualización del tamaño, lecturas `peek`, extracciones `pop` y borrados en `remove`.

**2. ¿Qué operaciones mínimas valida la prueba pública para `DLList`?**

Valida inserción arbitraria `add(i, x)`, acceso `get(i)`, borrado intermedio `remove(i)` y lectura confiable de secuencias.

**3. ¿Qué operaciones mínimas valida la prueba pública para `SEList`?**

Valida inserción en extremos, lectura por índice, actualización `set(i, x)` y reajuste post-eliminación `remove(i)`.

**4. ¿Qué operaciones nuevas quedan cubiertas por `test_public_extras.cpp`?**

Cubre funciones extendidas: `secondLast`, `reverse`, rotación y validadores internos como `checkSize`y palíndromos; y listas avanzadas como `XorList`.

**5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?**

Valida que se mantenga la disciplina FIFO estricta para Queue, LIFO para Stack, y operaciones en ambos extremos para Deque.

**6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?**

Demuestra que las conversiones `to_vector`, `to_deng` y `assign_from_deng` son seguras e idempotentes, preservando el orden y los datos.

**7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?**

Estresa fuertemente `spread`, `gather` verificando que el `size` y la secuencia no se corrompan.

**8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?**

Que los enlaces principales no se rompen bajo flujos normales de uso.

**9. ¿Qué no demuestra una prueba pública por sí sola?**

No garantiza un tiempo O(1) constante o amortizado, y no prueba la ausencia total de "memory leaks".

**10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?**

Un test verifica datos específicos, una justificación estructural garantiza que para todo n el invariante matemáticamente se sostiene.

#### Bloque 4 - SLList, DLList y SEList: lectura cercana del código

**1. En `SLList`, ¿qué papel cumplen `head`, `tail` y `n`?**

`head` apunta al primer nodo, `tail` apunta al último nodo, y `n` lleva la cuenta de elementos para `size()` instantáneo.

**2. En `SLList::push`, `pop`, `add` y `remove`, ¿qué punteros cambian exactamente?**

En `push`, `nuevo->next` apunta al `head` actual y `head` asume el `nuevo`. En `pop`, `head` avanza a `head->next`. En `add`, `tail->next` asume `nuevo` y `tail` se actualiza.

**3. Expliquen cómo funciona `secondLast()` y por qué no puede resolverse directamente con solo mirar `tail`.**

Se debe iterar secuencialmente desde el `head` hasta que `u->next == tail`. No basta mirar el `tail` porque la lista es simplemente enlazada porque no hay puntero `prev`.

**4. Expliquen paso a paso cómo funciona `reverse()` y por qué no necesita estructura auxiliar.**

Itera usando tres punteros temporales como `prev`, `curr`, `next`. Invierte el enlace de `curr` para apuntar a `prev`, y avanza todos un paso. Toma O(n) y no gasta memoria extra.

**5. Expliquen qué verifica `checkSize()` y por qué esta función ayuda a defender correctitud.**

Cuenta manualmente cuántos nodos existen recorriendo desde el `head`. Valida que el conteo coincida con la variable de estado `n`. Defiende correctitud comprobando el sincronismo estado/memoria.

**6. En `DLList`, expliquen por qué `getNode(i)` puede empezar desde el inicio o desde el final.**

Evalúa `i < n/2`. Si es cierto, arranca desde `dummy.next` hacia adelante. Si es falso, arranca desde `dummy.prev` hacia atrás.

**7. En `DLList::addBefore`, ¿qué enlaces se actualizan y por qué el nodo centinela elimina casos borde?**

Re-engancha 4 punteros: `u->prev` que apunta atrás de `w`, `u->next` que apunta a `w`, y los punteros inversos de esos vecinos hacia `u`. El `dummy` evita chequear si `w` era nulo.

**8. Expliquen cómo funciona `rotate(r)` sin mover los datos elemento por elemento.**

Corta la lista circular en la posición lógica correspondiente sin mover los datos internamente, solo re-linkeando el `dummy` a los nuevos extremos en O(r).

**9. Expliquen cómo `isPalindrome()` aprovecha la naturaleza doblemente enlazada de la estructura.**

Utiliza dos iteradores simultáneos, uno avanzando de izquierda a derecha (`dummy.next`) y otro retrocediendo desde el final (`dummy.prev`).

**10. En `SEList`, expliquen qué representa `Location`.**

Contiene `Node* u` que es el puntero al bloque que aloja el dato e `int j` que es el offset exacto dentro de la estructura `BDeque` interna de ese bloque.

**11. Expliquen qué hacen `spread()` y `gather()` y en qué situaciones aparecen.**

`spread` se lanza si un bloque se satura; distribuye un elemento hacia adelante hasta crear un bloque nuevo. `gather` se activa tras borrados para fusionar y compactar bloques casi vacíos.

**12. Expliquen cómo el tamaño de bloque `b` afecta el trade-off entre acceso, actualización y uso de espacio.**

Un `b` grande mejora memoria, pero encarece inserciones/eliminaciones porque desplazar el arreglo interno cuesta O(b).

#### Bloque 5 - Adaptadores y estructuras derivadas

**1. ¿Cómo reutiliza `LinkedStack` a `SLList`?**

Oculta los métodos irrelevantes, asociando semántica `push(x)` a `list.push(x)` y `pop()` a `list.pop()`, asegurando operaciones de pila O(1).

**2. ¿Cómo reutiliza `LinkedQueue` a `SLList`?**

Asocia semántica `add(x)` a la cola de la `SLList` y `remove()` a la cabecera `list.remove()`.

**3. ¿Por qué `LinkedDeque` se construye naturalmente sobre `DLList` y no sobre `SLList`?**

Un Deque exige `removeLast` en O(1). Como vimos, `SLList` lo hace en O(n), pero `DLList` accede a su penúltimo elemento directamente vía `dummy.prev->prev`.

**4. En `MinStack`, ¿por qué cada entrada guarda el valor y el mínimo acumulado?**

Guarda el valor y el mínimo en el momento en que este nodo fue el tope. Esto evita buscar el mínimo cada vez; solo devolvemos `current_min` en O(1).

**5. En `MinQueue`, ¿por qué usar dos pilas permite mantener semántica FIFO y consulta de mínimo?**

Emula una cola insertando en `in_` y extrayendo de `out_`. Como son implementaciones `MinStack`, se puede calcular el mínimo de la cola chequeando el mínimo de ambas en O(1).

**6. En `MinDeque`, ¿qué problema resuelve el rebalanceo entre `front_` y `back_`?**

Si `front_` o `back_` se quedan vacíos, no podemos simular el doble acceso eficientemente. `rebalance()` copia todo a un arreglo plano y reparte mitad y mitad de nuevo en ambas pilas.

**7. Comparen "implementar una estructura" y "adaptar una estructura existente" usando ejemplos de este bloque.**

Implementar es manejar punteros crudos `Node* prev, next` en `DLList`. Adaptar es envolver otra clase madura `LinkedDeque` que tiene un `DLList<T> list` privado.

**8. ¿Qué operaciones pueden defender como constantes y cuáles deben defender como amortizadas?**

`MinStack.min()` es constante O(1). `MinDeque.removeFirst()` es amortizado O(1) debido al método `rebalance()` que, aunque es O(n), ocurre muy espaciadamente.

#### Bloque 6 - Deng como refuerzo algorítmico y puente de integración


**1. ¿Qué operaciones del ADT de lista aparecen reforzadas en `DengList`?**

`sort`, `dedup`, `uniquify` y `reverse`.

**2. ¿Qué ventaja tiene encapsular una lista más rica sin cambiar el resto de estructuras de Semana 3?**

Permite que las listas de Morin sigan siendo solo para manejo básico de la memoria y análisis teórico, mientras se delega la algoritmia compleja.

**3. Expliquen qué hacen `to_deng` y `assign_from_deng`.**

`to_deng` copia los datos de una `DLList` o `SEList` hacia una nueva `DengList`. `assign_from_deng` purga la lista original y la re-puebla a partir de la lista Deng temporal.

**4. Expliquen por qué `stable_sort_with_deng` no obliga a reimplementar ordenamiento dentro de `DLList` o `SEList`.**

Extrae a DengList, usa el método maduro `tmp.sort()`, y devuelve los valores reordenados, cumpliendo el principio de no re-inventar la rueda.

**5. Expliquen qué hace `dedup_with_deng` y qué relación guarda con `deduplicate()` o `uniquify()` de la teoría.**

Aprovecha el método de `DengList` para eliminar repetidos con costo O(n^2) generalmente para desordenados e inyecta la lista limpia de vuelta a Morin.

**6. Expliquen por qué `reverse_with_deng` es un ejemplo de reutilización de algoritmos sobre una interfaz común.**

Permite que `SEList` o `DLList` puedan invertirse lógicamente aprovechando la función base de un solo tipo de lista.

**7. ¿Qué costo adicional introduce la conversión entre estructuras y cuándo vale la pena aceptarlo?**

Cada conversión requiere O(n) tiempo extra y O(n) espacio auxiliar. Vale la pena cuando la complejidad de la operación meta como un Sort O(N \log N) eclipsa este overhead lineal.

#### Bloque 7 - Comparación enlazado vs contiguo, variantes y evidencia experimental


**1. Comparen `ArrayDeque` y `LinkedDeque`: ¿qué cambia en representación y qué cambia en costo observable?**

En representación, `ArrayDeque` usa un solo bloque circular; `LinkedDeque` usa nodos dispersos. En costo, `Array` es rápido de acceder pero penaliza ocasionalmente en redimensionamientos; `Linked` no sufre ráfagas O(n) pero su memoria es fragmentada.

**2. ¿Qué significa que una representación contigua tenga mejor localidad de memoria?**

Cuando la CPU carga un elemento contiguo a caché, carga también los siguientes. Operar sobre ellos es mucho más rápido que seguir punteros a ubicaciones aleatorias de RAM.

**3. ¿Qué tipo de operaciones favorecen más a la representación enlazada?**

Mover, unir, separar listas enteras y mutar un elemento en medio cuando ya se tiene el puntero o iterador en mano.

**4. En el benchmark, ¿qué comparación sirve mejor para discutir acceso aleatorio y cuál sirve mejor para discutir operaciones en extremos?**

`random_get_arraydeque vs random_get_dllist` expone los saltos de memoria de O(1) vs O(N). Los tests `_ends` discuten la competitividad en operaciones O(1) puras en extremos.

**5. ¿Por qué el benchmark no debe leerse como prueba absoluta de superioridad de una estructura sobre otra?**

Los tiempos de benchmark varían por lenguaje, estado previo de la memoria, la caché del CPU específica y la "constante oculta" del asignador (`new`).

**6. ¿Qué idea intenta mostrar `XorList` respecto al ahorro de punteros?**

Suprimir un puntero uniendo el conocimiento bidireccional (`prev` y `next`) en un único entero `link = prev XOR next`. Si vienes de `prev`, calculas `next` con `link XOR prev`.

**7. ¿Qué desventaja práctica introduce una estructura como `XorList` aunque sea interesante desde el punto de vista del espacio?.**

La lectura es unidireccional dependiente del paso anterior; es imposible saltar a un nodo intermedio y recorrerlo si no se conoce la dirección del nodo que se acaba de dejar atrás. Además, compromete el recolector de basura en otros lenguajes.

#### Bloque 8 - Cierre comparativo y preparación de sustentación


¿Qué cambia cuando pasamos de "usar arreglos dinámicos" a "diseñar estructuras enlazadas y adaptadores sobre nodos"?

El gran salto reside en la representación, cambiamos arreglos matemáticamente direccionables por pequeños bloques enlazados a través de punteros independientes en memoria, el Heap. Como consecuencia inmediata, perdemos el acceso eficiente por rango/índice; llegar al n-ésimo elemento ya no se calcula, se navega (O(N)), dependiendo ahora del acceso por posición.
Sin embargo, ganamos en agilidad para inserciones y eliminaciones locales, dado que un cambio de estructura interna solo exige manipular los enlaces directos del entorno, aislando el costo en O(1). Para amortizar las ventajas de ambos universos, estructuras híbridas como `SEList` combinan una matriz de bloques que compensan la pérdida de localidad de memoria limitando la carga excesiva de punteros por elemento. Finalmente, esta flexibilidad nodal favorece una poderosa reutilización mediante adaptadores o puentes, donde a partir de una lista cruda se pueden restringir las interfaces y extender comportamientos algorítmicos complejos como ordenamiento y seguimiento de mínimos, sin reescribir la gestión de memoria inferior.

#### Autoevaluación breve

- Qué podemos defender con seguridad: La utilidad crucial del nodo `dummy` para absorber los casos borde de los límites de la lista doblemente enlazada, y la asignación LIFO/FIFO hacia Stack y Queue respectivamente.

- Qué todavía confundimos: La diferencia exacta de micro-optimizaciones entre usar una `MinQueue` con dos pilas amortizadas frente a una estructura plana normal, y cómo fluye exactamente el bitwise de `XorList`.

- Qué evidencia usaríamos en una sustentación: Referenciaríamos las funciones puente para demostrar cómo se enriquece Morin usando abstracciones mayores, y usaríamos el caso de `removeLast` de `SLList` como advertencia del límite natural del simple enlace.




