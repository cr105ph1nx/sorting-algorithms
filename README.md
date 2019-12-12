# Sorting Algorithms and Dynamic Structures

## Problematic
A lot of real-time problems involve looking for elements in an array or any other data structure. This search becomes almost cumbersome when it is done in a voluminous structure (several thousand elements) and disordered, hence the need to sort these structures to facilitate research. In this work, I implement some array sorting methods (by selection, bubble, insertion described below), to generalize them later to matrixes and linked lists.

## Description of methods

**1. Selection Sort :**
This technique consists of sequentially traversing the array to be sorted. At iteration i, the smallest value (respectively the largest value if it is in a descending order) of the array is interchanged with the value in the index i. At the end of an iteration, one element of the vector is correctly placed (i.e, it is in its correct position).

**2. Bubble Sort :** 
The smallest (respectively largest) elements of the array "rise" (like bubbles) towards the beginning of the array to reach their final position. Once every element reassembled, the array is sorted. This technique is done by successive permutations of consecutive elements t [i] and t [i + 1] after comparing them.

**3. Insertion Sort :**
This technique consists in considering at each step, an element t [i] of the array and looking for its insertion position, by shifting the other elements so as to "release" the insertion position of the element. At each step, a part of the array is already ordered and a new value is inserted in the appropriate place.

# Part I
Implementation of the three fore-described sorting methods for an array of integers of size n <= 1000.

# Part II
Generalization of these methods in the sorting of matrixes, the program answers the following criterias:
1. Sort a matrix of integers, row by row, independently of each other (each line will be sorted separately).
2. Sort all the elements of the matrix of integers.
3. Sort a matrix of characters where each line represents a string of characters in alphabetical order of words (one word per line).

## Part III
Implementation of another sorting algorithm (Quicksort).

## Part IV
Adaptation of two sorting methods to sort a linked list (dynamic structure) of words (strings).

## More
1. Each sorting program (or algorithm) displays the state of the array (matrix or list) after each swapping of elements in order to see the progress of the sort.
2. Each sorting program (or algorithm) displays at the end the number of comparisons made and the number of swappings performed. These two numbers are calculated in each algorithm and vary from one run to another.
