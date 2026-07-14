# ALFIDO-TECH-TASK2
# C Algorithm Analysis: Sorting, Searching & Greedy Approaches

Welcome to my algorithm project repository! This project focuses on implementing key data structures and algorithms using the C programming language. The goal here is to understand how these algorithms work under the hood, analyze their time complexities, and track how fast they run when given different sizes of input data.

This repository documents my implementation logic for divide-and-conquer sorting, fast searching, and greedy optimization methods.

## Current Progress: Algorithmic Implementations

Inside this repository, you will find three separate, clean C programs:

* **QuickSort  (`01_Quick_sort.c`):**
    * **Divide & Conquer:** Uses a pivot element to recursively partition and sort an array.
    * **Runtime Tracking:** Uses system clock ticks to measure exactly how long the sorting takes, making it easy to see performance differences between small and large datasets.
* **Binary Search System (`02_Binary_search.c`):**
    * **Fast Lookups:** Implements classic binary search logic by continuously cutting the search space in half.
    * **Input Preparation:** Since binary search strictly requires a sorted list, this program runs a bubble sort step on user inputs first to ensure accurate searching.
* **Fractional Knapsack System (`03_knapsack.c`):**
    * **Greedy Choice Strategy:** Calculates the value-per-weight density for a set of items and sorts them to prioritize the most valuable ones.
    * **Fractional Splitting:** Fits whole items into a bag until it reaches capacity, then smoothly computes how much fractional value can be taken from the remaining item.

## Tech Stack & Concepts Covered

* **Language:** C (Standard C99/C11)
* **Key Concepts:**
    * **Recursion:** Using recursive logic to implement highly efficient sorting.
    * **Performance Evaluation:** Utilizing `<time.h>` to capture execution speeds.
    * **Dynamic Array Allocation:** Managing array sizes effectively using `malloc` based on user inputs.
    * **Console Interaction:** Handling data inputs and menu formatting cleanly using `scanf` and `printf`.
* **Tools:** GCC Compiler, VS Code

## How to Run

1. Make sure you have the GCC compiler installed on your system.
2. Clone this repository to your computer.
3. Open your terminal in the project directory.
4. Compile the files individually:
   ```bash
   gcc 01_Quick_sort.c -o 01_Quick_sort
   # OR
   gcc 02_Binary_search.c -o 02_Binary_search
   # OR
   gcc 03_knapsack.c -o 03_knapsack
5. Run the compiled executable:
   ```bash
   ./01_Quick_sort
   # OR
   ./02_Binary_search
   # OR
   ./03_knapsack
   ```