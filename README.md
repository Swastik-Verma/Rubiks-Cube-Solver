# Rubik’s Cube Solver (C++)

## Overview
This project is a **complete Rubik’s Cube solver implemented from scratch in C++**, focusing on **efficient cube modeling, graph search algorithms, and heuristic optimization**.  
The project explores how classical **graph algorithms and AI search techniques** can be applied to solve a complex combinatorial problem like the Rubik’s Cube.

The implementation is **modular, extensible, and performance-oriented**, allowing multiple cube representations and solver strategies.

---

## Objectives
- Model the Rubik’s Cube efficiently in different representations
- Implement and compare multiple **search-based solvers**
- Use **heuristics and pattern databases** to optimize solving
- Build a strong foundation for advanced Rubik’s Cube solvers

---

## Cube Representations
To study performance and memory trade-offs, the cube is modeled in **three different ways**:

### 1️. 3D Array Representation
- Intuitive and easy to visualize
- Useful for understanding cube mechanics and debugging

### 2️. 1D Array Representation
- More compact than 3D arrays
- Faster comparisons and hashing

### 3. Bitboard Representation
- Uses **6 × 64-bit integers**
- Highly memory-efficient and fast
- Ideal for heuristic-based solvers and pattern databases

Each representation supports:
- All **18 standard Rubik’s Cube moves**
- Equality comparison and hashing
- Solver compatibility

---

## Solvers Implemented
The project includes multiple solvers based on **graph traversal and heuristic search**:

### 1. Breadth-First Search (BFS)
- Guarantees the shortest solution
- Used mainly for:
  - Exploring the state space
  - Generating pattern databases
- Limited by memory for deeper scrambles

### 2. Depth-First Search (DFS)
- Memory efficient
- Explores deeply but does not guarantee shortest solution

### 3. Iterative Deepening DFS (IDDFS)
- Combines BFS optimality with DFS memory efficiency
- Gradually increases depth limit

### 4. Iterative Deepening A* (IDA*)
- Uses **heuristic pruning**
- Employs **pattern databases** to estimate distance to solution
- Capable of solving deeper scrambles efficiently

---

## Heuristics & Pattern Databases
- Implemented a **Corner Pattern Database**
- Generated using BFS from the solved state
- Stored efficiently for fast lookup
- Used as an **admissible heuristic** in IDA*
- Significantly reduces the search space

---

## Technologies Used
- **Language:** C++
- **Core Concepts:**
  - Graph algorithms
  - Heuristic search
  - Bit manipulation
  - Hashing (`unordered_map`, `unordered_set`)
  - Memory optimization
- **Compiler:** g++

---
