# Student Academic Report Generator

## Overview
This project is a C++ program that reads multiple student records from an input file, calculates tuition and academic standing for each student, and generates a formatted report on the screen and in an output file.

The program processes each valid student record and computes:
- final numeric grade
- letter grade
- academic standing
- total tuition amount due

It also calculates summary statistics such as:
- number of valid student records
- total of grades
- minimum grade
- maximum grade

## Features
- Reads student data from a text file
- Calculates tuition based on credits and cost per credit
- Determines final letter grade
- Determines academic standing
- Displays formatted per-student results
- Writes results to an output file
- Computes summary statistics for all valid records

## Technologies Used
- C++
- File input/output
- Functions
- Selection statements
- Basic data processing

## Files
- `main.cpp` – main C++ source file
- `input.txt` – input file containing student records
- `output.txt` – generated report file

## How It Works
Each student record includes:
- student name
- number of credits
- cost per credit
- final numeric grade

For each record, the program:
1. Reads the input data
2. Validates the record
3. Computes tuition
4. Assigns a letter grade
5. Determines academic standing
6. Prints the student report
7. Updates summary statistics
8. Writes the results to the output file

## How to Compile and Run

```bash
g++ main.cpp -o report
./report
# On Windows:
report.exe
