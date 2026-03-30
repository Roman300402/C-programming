# C-Programming: Mathematical & Algorithmic Problems 🧮

Este repositorio contiene una colección de soluciones programadas en **C**, enfocadas en la resolución de problemas de optimización, estructuras de datos dinámicas y cálculo simbólico. 

Todos los proyectos fueron desarrollados originalmente para la asignatura de **Programación II** en la **Escuela Superior de Física y Matemáticas (ESFM)** del **IPN**.

---

## 🚀 Proyectos Destacados

### 1. El Problema de la Mochila (Knapsack Problem) 🎒
Implementación del problema de optimización combinatoria 0-1.
* **Método**: Programación Dinámica para maximizar el beneficio bajo restricciones de capacidad.
* **Complejidad**: Pseudo-polinomial $O(nc)$, optimizando tiempo y espacio.
* **Aplicaciones**: Incluye documentación sobre su uso en logística y criptografía (Sistema Merkle-Hellman).

### 2. Algoritmos de Búsqueda y Ordenamiento 🔍
Un sistema integral para la manipulación de arreglos con visualización en tiempo real.
* **Ordenamiento**: Implementación de Quicksort, Mergesort, Heapsort, Shellsort y métodos directos.
* **Búsqueda**: Algoritmos de búsqueda lineal, binaria y mediante tablas de Hash.
* **Interfaz**: Renderizado gráfico en consola mediante histogramas para observar el comportamiento de cada algoritmo.

### 3. Derivador Simbólico (Expression Trees) 📐
Motor de cálculo diferencial que procesa funciones matemáticas y genera su derivada.
* **Estructura**: Construcción de Árboles de Expresión a partir de notación postfija.
* **Lógica**: Uso de Pilas dinámicas y recursividad para aplicar reglas de la suma, producto, potencia y cadena.
* **Funciones**: Soporta variables, constantes y funciones trigonométricas.

---

## 📂 Estructura de Documentación
El repositorio incluye archivos complementarios que detallan la base teórica de los proyectos:
* **Presentaciones**: Historia del problema (Richard Karp, 1972) e imágenes del funcionamiento.
* **Memorias Técnicas**: Definiciones formales, análisis de complejidad y variantes como la mochila de múltiple elección.

## 🛠️ Requisitos e Instalación
1. **Compilador**: Requiere GCC (MinGW para Windows o GCC estándar en Linux).
2. **Compilación**: 
   ```bash
   gcc nombre_del_archivo.c -o programa
   ./programa
