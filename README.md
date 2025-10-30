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
```
### 🪟 En Windows
- Usando Visual Studio Code con la extensión C/C++ de Microsoft

---

## 🚀 Instrucciones de uso

1. Clonar el repositorio
```bash
git clone https://github.com/tu_usuario/sistemas-distribuidos.git
cd sistemas-distribuidos
```

2. Compilar el programa deseado
Ejemplo para el algoritmo de Lamport:
```bash
g++ lamport.cpp -o lamport
```

3. Ejecutar el programa
```bash
./lamport
```

O en Windows:
```bash
lamport.exe
```

4. Repetí el proceso para los demás archivos (berkeley.cpp, cristian.cpp).

---

## 🧩 Estructura del repositorio
```bash
sistemas-distribuidos/
├── lamport.cpp      # Relojes lógicos de Lamport
├── berkeley.cpp     # Sincronización promedio de Berkeley
├── cristian.cpp     # Sincronización cliente-servidor de Cristian
├── README.md        # Este archivo
```
---
## 👨‍💻 Autores y cátedra

**Materia**: Sistemas Distribuidos
**Carrera**: Ingeniería en Sistemas de Información (4° año)
**Docentes**: Ulises Rapallini y Ernesto Ledesma

**Autores**:

- Fraisinet, Máximo Exequiel
- Leal, Pablo Valentín
- Martínez, Ignacio Gabriel
- Moreyra, Omar Sebastián
- Guiffrey, Leandro Ezequiel

**Año**: 2025
