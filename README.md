# 🖥️ Sistemas Distribuidos — Algoritmos de Sincronización de Relojes

Este repositorio fue creado para la materia **Sistemas Distribuidos**, correspondiente al **4° año de la carrera Ingeniería en Sistemas de Información**, bajo la cátedra de **Ulises Rapallini** y **Ernesto Ledesma**.

El objetivo del trabajo práctico es implementar y comprender distintos **algoritmos de sincronización de relojes** en sistemas distribuidos: **Lamport**, **Berkeley** y **Cristian**, simulando su funcionamiento mediante programas en **C++**.

---

## 📚 Contenidos

El repositorio contiene tres implementaciones independientes, cada una en su propio archivo `.cpp`:

| Algoritmo | Archivo | Descripción breve |
|------------|----------|------------------|
| 🧩 **Lamport** | `lamport.cpp` | Implementa **relojes lógicos**, garantizando el **orden causal** de los eventos en un sistema distribuido. No mide tiempo real, sino relaciones de precedencia entre eventos. |
| 🕒 **Berkeley** | `berkeley.cpp` | Simula **relojes físicos distribuidos**, donde un nodo maestro consulta el tiempo de los demás y calcula un **ajuste promedio** para sincronizar todos los relojes. |
| ⏱️ **Cristian** | `cristian.cpp` | Sincroniza un **cliente con un servidor de tiempo**, estimando el retardo de red y ajustando el reloj del cliente con base en la hora del servidor. |

---

## ⚙️ Requisitos

Antes de ejecutar los programas, asegurate de tener instalado un compilador de C++.

### 🔧 En Linux
```bash
sudo apt update
sudo apt install g++
