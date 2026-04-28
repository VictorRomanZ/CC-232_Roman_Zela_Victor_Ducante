# PC2 - CC232

### Estudiante
- Nombre: Roman Zela Victor Ducante
- Código: 20220050A
- Problema asignado: CF 1838D — Bracket Walk
- Enlace: https://codeforces.com/problemset/problem/1838/D

---

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

---

### Tema principal


### Resumen de la solución

El problema pide determinar, tras cada flip de un carácter, si la cadena de paréntesis es "caminable": es decir, si existe alguna forma de recorrer la cadena, se puede mover libremente izquierda y derecha, tal que los caracteres escritos formen una secuencia de paréntesis válida.
La idea clave es que, como el movimiento es libre, se puede escribir cualquier par de caracteres extra en cualquier punto. Esto lleva a la condición simple de que la cadena es caminable si y solo si su longitud es par, y el conjunto de posiciones malas, donde el carácter no coincide con lo esperado según su paridad, cumple que la primera posición mala es impar y la última es par.