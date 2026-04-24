### Lista de ejercicios - Semana 3


#### Ejercicio 1. Operaciones posicionales en `SLList`

1. SLList basa su orden lógico en referencias. Su estructura principal suele componerse de:
    - Nodos: Pequeños bloques de memoria que almacenan el dato y un puntero de referencia para el siguiente nodo(next).
    - Punteros: Head, que es el puntero de inicio y tail que es el puntero final.
    - Contador: Es una variable entera que rastreará el tamaño de la lista.

2. 
- get(i) y set(i, x): Ambas operaciones necesitan alcanzar exactamente el nodo ubicado en la posición i. Para lograrlo, inicializan un puntero temporal en head y ejecutan un bucle que sigue la referencia next exactamente i veces. Una vez que el bucle se detiene sobre el nodo deseado, se lee su valor o se sobrescribe con x.
- add(i, x): Para insertar un nodo en una posición intermedia, la lista necesita manipular las referencias del nodo anterior. Por lo tanto, el recorrido secuencial inicia en head y se detiene un paso antes, en la posición i - 1. Una vez localizado el predecesor, se crea el nuevo nodo, su puntero next se enlaza al nodo que actualmente ocupaba la posición i, y el next del predecesor se actualiza para apuntar al nuevo nodo.
- removeAt(i): Al igual que la inserción, la eliminación requiere acceder al predecesor. El bucle avanza desde head hasta llegar al nodo en i - 1. Una vez allí, se modifica el puntero next del predecesor para que salte el nodo i y apunte directamente al nodo i + 1. Esto desliga al nodo i de la secuencia lógica, permitiendo liberar su memoria.
    
3. Dado que la memoria no es contigua, no se puede usar una fórmula matemática para saltar directamente a la posición i. El algoritmo está obligado a iniciar en head y avanzar secuencialmente a través de los enlaces next. Llegar a la posición i (o a la i - 1 en el caso de inserciones/eliminaciones) toma una cantidad de pasos directamente proporcional a la distancia desde el inicio. Esto cuesta $\mathcal{O}(i)$.

4. 
        // Función auxiliar para imprimir el estado de la lista y facilitar la depuración.
    template<typename T>
    void printList(ods::SLList<T>& list, const std::string& label) {
        std::cout << label << " (tamaño " << list.size() << "): [";
        for (int i = 0; i < list.size(); ++i) {
            std::cout << list.get(i) << (i == list.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }

    int main() {
        std::cout << "--- Iniciando prueba de operaciones posicionales en SLList ---" << std::endl;

        ods::SLList<int> list;
        printList(list, "Estado inicial");
        assert(list.size() == 0);

        // 1. Inserción al inicio (add en la posición 0)
        std::cout << "\n1. Probando inserción al inicio: add(0, 10)" << std::endl;
        list.add(0, 10);
        printList(list, "Después de add(0, 10)");
        assert(list.size() == 1);
        assert(list.get(0) == 10);
        std::cout << "-> Verificación correcta." << std::endl;

        // 2. Inserción al final (add en la posición list.size())
        std::cout << "\n2. Probando inserción al final: add(1, 30)" << std::endl;
        list.add(list.size(), 30); // list.size() es 1 en este punto
        printList(list, "Después de add(1, 30)");
        assert(list.size() == 2);
        assert(list.get(0) == 10);
        assert(list.get(1) == 30);
        std::cout << "-> Verificación correcta." << std::endl;

        // 3. Inserción intermedia (add)
        std::cout << "\n3. Probando inserción intermedia: add(1, 20)" << std::endl;
        list.add(1, 20);
        printList(list, "Después de add(1, 20)");
        assert(list.size() == 3);
        assert(list.get(0) == 10);
        assert(list.get(1) == 20);
        assert(list.get(2) == 30);
        std::cout << "-> Verificación correcta." << std::endl;

        // Se añade un elemento más para que la eliminación intermedia sea más clara
        list.add(list.size(), 40);
        printList(list, "Añadiendo 40 al final");
        assert(list.size() == 4); // Lista ahora es: [10, 20, 30, 40]

        // 4. Eliminación intermedia (removeAt)
        std::cout << "\n4. Probando eliminación intermedia: removeAt(1)" << std::endl;
        int removed_value = list.removeAt(1); // Se elimina el 20
        printList(list, "Después de removeAt(1)");
        assert(removed_value == 20);
        assert(list.size() == 3);
        assert(list.get(0) == 10);
        assert(list.get(1) == 30);
        assert(list.get(2) == 40);
        std::cout << "-> Verificación correcta." << std::endl;

        std::cout << "\n--- Todas las pruebas de operaciones posicionales pasaron con éxito. ---" << std::endl;

        return 0;
    }

5. Una estructura contigua ofrece acceso por índice en `O(1)` pero sus inserciones/eliminaciones son costosas (`O(n-i)`) por el desplazamiento de elementos. En contraste, una `SLList` enlazada tiene acceso lento (`O(i)`) por su recorrido secuencial, pero las modificaciones locales son muy baratas. La elección depende del uso: contigua para acceso frecuente y enlazada para inserciones/eliminaciones constantes.

#### Ejercicio 2. Inversión de una `SLList` sin memoria auxiliar

1. Revisar la idea general de `reverse()` para listas simplemente enlazadas.
    La inversión de una lista simplemente enlazada sin memoria auxiliar se basa en un algoritmo iterativo que recorre la lista una sola vez, reconfigurando los punteros next de cada nodo para que apunten en la dirección opuesta. En cada paso, el puntero next de current se redirige para que apunte a prev, y luego ambos punteros avanzan una posición.

2. Implementar o reimplementar `SLList::reverse()` sin usar recursión, sin arreglos temporales y sin crear nodos nuevos.
    Para implementación se puede añadir a la clase SLList, no utiliza recursión ni estructuras de datos auxiliares, solo un número constante de punteros.

3. Explicar cuál es la invariante del bucle durante la inversión.
    Al inicio de cada iteración, la sublista que comienza en prev representa el prefijo invertido de la lista original y la sublista que comienza en current representa el sufijo restante que aún no ha sido procesado.

4. Verificar experimentalmente que la lista queda invertida y que `tail` también queda consistente.
    Verifica que la lista y sus punteros head y tail quedan consistentes después de la inversión.

5. Justificar por qué el tiempo de ejecución es `O(n)` y el espacio extra es `O(1)`.
    Dentro del bucle, solo se realizan operaciones de asignación de punteros, que tienen un costo constante O(1). El tiempo total es proporcional al número de elementos. Este algoritmo solo utiliza un número fijo de punteros auxiliares (prev, current, next) para llevar a cabo la inversión, sin importar el tamaño de la lista.

#### Ejercicio 3. Verificación estructural con `checkSize()`

1. Diseñar una rutina `checkSize()` para `SLList` y otra para `DLList`.
    La idea es crear una función privada checkSize() para cada tipo de lista, podemos ejecutar para asegurarnos de que nuestras operaciones de add o remove no hayan roto la estructura. Es una herramienta de depuración que nos da confianza en nuestro código.

2. Hacer que ambas recorran la estructura completa y verifiquen que el número real de nodos coincide con el tamaño lógico almacenado.

    Para `SLList`, `checkSize()` debe contar los nodos y verificar la coherencia de los punteros `head` y `tail`. Se recorre la lista desde `head` hasta llegar a `nullptr`, contando cada nodo. El total debe ser igual a `n`.
   
        -   Si `n == 0`, se verifica que `head` y `tail` son `nullptr`.
        -   Si `n > 0`, se verifica que `head` y `tail` no son `nullptr`, que el último nodo del recorrido es efectivamente `tail`, y que `tail->next` es `nullptr`.


3. En el caso de `SLList`, verificar además la coherencia entre `head`, `tail` y el último nodo real.
    Para `DLList`, que usa un nodo centinela `dummy`, la verificación se centra en la naturaleza circular de la lista y la consistencia de los punteros `prev`.

    Se recorre la lista partiendo de `dummy->next` hasta volver a `dummy`. El número de nodos visitados debe ser igual a `n`.
        -   El puntero `prev` del primer nodo (`dummy->next`) debe apuntar a `dummy`.
        -   El puntero `next` del último nodo (`dummy->prev`) debe apuntar a `dummy`.
        -   Para cada nodo `u` en la lista, se debe cumplir la invariante `u->next->prev == u` y `u->prev->next == u`.


4. En el caso de `DLList`, verificar además la consistencia de los enlaces `prev` y `next` alrededor del nodo centinela `dummy`.
    Aquí, checkSize() se asegura de que la lista sea circularmente correcta, el prev del primer nodo debe apuntar a dummy y el next del último también. Para cada nodo, verificamos que su next apunte a un nodo cuyo prev sea él mismo.

5. Probar ambas rutinas después de varias secuencias de `add`, `remove`, `push`, `pop` y `rotate`.

