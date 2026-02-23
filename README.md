# APC_C
A command-line calculator implemented in C that performs arithmetic on integers of unlimited size. The program supports addition, subtraction, 
multiplication, and division by representing numbers using doubly linked lists, enabling computations beyond standard integer limits.


# Features
Handles arbitrarily large signed integers

Supports +, -, *, and / operations

Implements manual digit-by-digit arithmetic

Uses custom doubly linked list data structure

Includes input validation and error handling (e.g., division by zero)


# Implementation Details
Each digit is stored in a node of a doubly linked list

Arithmetic operations are performed using classic algorithms (carry, borrow, long multiplication, long division)

Designed without using built-in big integer libraries
