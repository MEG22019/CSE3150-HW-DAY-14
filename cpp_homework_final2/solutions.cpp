#include <iostream>
#include <cstring>   // for strlen, strcpy
#include "starter_main.cpp" // Include the header for function prototypes

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size >= capacity) {
        std::cout << "Cannot add student: capacity reached." << std::endl;
        return;
    }
    names[size] = new char[strlen(name) + 1];
    strcpy(names[size], name);
    gpas[size] = gpa;
    size++;
}

void updateGPA(double *gpaPointer, double newGPA) {
    *gpaPointer = newGPA;
}

void printStudent(const char* name, double gpa) {
    std::cout << "Name: " << name << ", GPA: " << gpa << std::endl;
}

double averageGPA(const double gpas[], int size) {
    if (size == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += gpas[i];
    }
    return sum / size;
}

