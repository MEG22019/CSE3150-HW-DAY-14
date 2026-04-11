
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);

// TODO: implement updateGPA
void updateGPA(double *gpaPointer, double newGPA);

// TODO: implement printStudent
void printStudent(const char* name, double gpa);

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    // VLAs, not covered
    //char* names[capacity];
    //double gpas[capacity];
    int capacity = std::stoi(argv[1]);

    char** names = new char*[capacity];
    double* gpas = new double[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                char tempName[100];
                double tempGPA;
                std::cout << "Enter name: ";
                std::cin >> tempName;

                std::cout << "Enter GPA: ";
                std::cin >> tempGPA;

                try{
                    addStudent(tempName, tempGPA, names, gpas, size, capacity);
                } catch (const std::runtime_error& msg) {
                    std::cout << msg.what() << std::endl;
                }
                break;

            }
            case 2: {
                // TODO: implement menu logic
                int index;
                double newGPA;
                std::cout << "Enter student index: ";
                std::cin >> index;
                if (index >= 0 && index < size){
                    std::cout << "Enter new GPA: ";
                    std::cin >> newGPA;
                    updateGPA(&gpas[index], newGPA);
                } else {
                    std::cout << "Invalid index" << std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                for (int i = 0; i < size; ++i) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try{
                    double avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << avg << "(rounded:"<< static_cast<int>(avg) << ")"<< std::endl;
                } catch (const std::runtime_error& msg) {
                    std::cout << msg.what() << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);


    // TODO: free memory
    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }
    delete[] names;
    delete[] gpas;

    return 0;
}
