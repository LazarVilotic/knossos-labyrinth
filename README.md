# Knossos Labyrinth Robot Simulation 🤖🏛️

A console-based 2D grid game implemented in C++ demonstrating object-oriented programming concepts. The game simulates a robot navigating through a procedurally generated maze, avoiding the mythical Minotaur while collecting power-ups to survive and escape.

## 🌟 Key Features

* **Procedural Maze Generation:** Dynamically generates an $N \times M$ grid ensuring a valid path from start to exit using **BFS (Breadth-First Search)** path validation.
* **Smart Enemy AI:** The Minotaur roams randomly but switches to aggressive tracking mode when the robot is within 1 tile range.
* **Power-up Architecture:** Built using **OOP Inheritance & Polymorphism** to provide modular, temporary buffs lasting exactly 3 turns.
* **Game State Persistence:** Automatically logs execution metadata, timestamps, final game outcomes, and a snapshot of the grid map to an external text file upon game over.
* **Performance Benchmark:** Tracks and displays the exact time elapsed (in milliseconds) to generate and validate the labyrinth.

## 🛠️ Power-Ups & Special Effects

Every power-up inherits from a base `Predmet` class and triggers a random status effect upon collision:
* **Hammer (`Cekic`):** Allows the robot to smash and walk through internal walls (`#`).
* **Sword (`Mac`):** Empowers the robot to destroy the Minotaur directly.
* **Shield (`Stit`):** Protects the robot by deflecting the Minotaur's next immediate attack.
* **Fog of War (`MaglaRata`):** Restricts the user's rendering viewport to a strict $3 \times 3$ sub-matrix centered around the robot.

## 📂 Project Architecture

* `Lavirint` - Handles dynamic 2D array matrix allocations, procedural wall generation, and BFS validations.
* `Igra` - Controls the core turn-based execution loop alternating between player input and enemy AI updates.
* `Predmet` - Base class for items, overridden by `Mac`, `Stit`, `Cekic`, and `MaglaRata` subclasses.
* `ObradaDatoteka` - Manages low-level file I/O operations and final reports logging.

## 🚀 How to Run

1. Clone the repository:
   ```bash
   git clone [https://github.com/yourusername/knossos-labyrinth-cpp.git](https://github.com/yourusername/knossos-labyrinth-cpp.git)
