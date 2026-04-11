#include <iostream>
#include <cstring>   // for strlen, strcpy

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size == capacity)
        throw std::runtime_error("List is full");
    
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
    if (size == 0)
        throw std::runtime_error("No Students in list.");

    double sum = 0.0;
    for (int i = 0; i < size; ++i) 
        sum += gpas[i];

    return sum/size;
}
