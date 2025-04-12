# Generador de r-Combinaciones en Orden Lexicográfico

Este proyecto genera todas las combinaciones posibles de elegir **r** elementos de un conjunto de **n** elementos, manteniendo el orden lexicográfico. El programa escribe las combinaciones generadas en un archivo CSV y verifica que la cantidad de combinaciones coincida con el valor teórico C(n, r).

---

## Autor

**IKER GERARDO SANCHEZ ARMENTA**

---

## Requisitos del Sistema

- **Compilador C++:** Se recomienda utilizar *g++* versión 7.0 o superior (se requiere soporte para C++11 o posterior).
- **Sistema Operativo:** Compatible con Windows, Linux, macOS, o cualquier sistema que soporte compiladores modernos de C++.

---

## Instrucciones de Compilación y Ejecución

### Compilación

Para compilar el programa, abre una terminal y ejecuta el siguiente comando:

```bash
g++ -O2 -std=c++11 main.cpp -o combinaciones
