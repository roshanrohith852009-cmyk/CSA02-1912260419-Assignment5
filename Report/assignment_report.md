# CSA02 Assignment 5 - CO5
## Modular, Memory-Aware and Persistent Program Engineering

Student: S. Rohith
Register Number: 1912260419
Case Study: District Blood Bank Network

# PART A - DESIGN AND PSEUDOCODE

## A1 - Functional Decomposition
Functions:
- register_donor()
- check_eligibility()
- find_donors()
- update_stock()
- save_donors()
- load_donors()
- save_stock()
- load_stock()

Include a structure chart, prototypes, parameter passing decisions,
const correctness and two multiple-return-value designs.

## A2 - Recursive Design
Explain digital root recursion and power recursion.
Include base cases, recursive cases, call traces and recurrences.
Compare recursion, iteration and the digital-root formula.

## A3 - Pointer Design
Explain p+3, *(p+3), p[3] and *p++.
Include an eight-element memory diagram.
Explain pointer-returning functions and command-line arguments.

## A4 - Dynamic Memory
Explain a growable donor list using realloc().
Include failure handling, memory leaks, dangling pointers and double free.
Compare capacity doubling with fixed increments of ten.

## A5 - File Storage
Design donor text records using fprintf().
Design binary stock records using fwrite().
Explain fseek(), fread() and fwrite() for in-place updates.

# PART B - IMPLEMENTATION AND EXPERIMENTS

## B1 - Recursive Functions
Record tests, call counts for 10, 100, 1000 and 10000,
and compare linear, halving and iterative approaches.

## B2 - Adversarial Inputs
Record long-name tests, missing/read-only file tests,
invalid arguments and AddressSanitizer results.
Compare fgets() and getline().

## B3 - Text versus Binary
Measure 10, 1000, 10000 and 100000 records.
Record file sizes, write/read times and update timings.
Explain portability and format selection.

## B4 - Final Engineering Decision
Record donor memory usage, execution time and memory-safety evidence.
Compare in-memory lists, batch reading and index files.
Give a production recommendation supported by measurements.

## Conclusion
Write the final conclusion using actual program results.
