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















