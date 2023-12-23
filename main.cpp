#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Student structure to store student information
struct Student {
    std::string name;
    double biology;
    double physics;
    double chemistry;
    double totalMarks;
    int rank;

    // Constructor to initialize the student
    Student(std::string n, double bio, double phy, double chem)
        : name(n), biology(bio), physics(phy), chemistry(chem) {
        totalMarks = bio + phy + chem;
    }
};

// Function to calculate ranks based on total marks
void calculateRanks(std::vector<Student>& students) {
    // Sort students based on total marks in descending order
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.totalMarks > b.totalMarks;
    });

    // Assign ranks
    int rank = 1;
    for (auto& student : students) {
        student.rank = rank++;
    }
}

// Function to print and write ranks to a file
void printAndWriteRanks(const std::vector<Student>& students, const std::string& fileName) {
    std::ofstream outFile(fileName);

    std::cout << "Name\tTotal Marks\tSchool Rank\tClass Rank\n";
    outFile << "Name\tTotal Marks\tSchool Rank\tClass Rank\n";

    for (const auto& student : students) {
        std::cout << student.name << "\t" << student.totalMarks << "\t\t" << student.rank << "\t\t" << student.rank << "\n";
        outFile << student.name << "\t" << student.totalMarks << "\t\t" << student.rank << "\t\t" << student.rank << "\n";
    }

    outFile.close();
}

int main() {
    // Create vector to store students
    std::vector<Student> students;

    // Populate the vector with sample data (you can modify this part)
    students.push_back(Student("Student1", 80, 90, 85));
    students.push_back(Student("Student2", 75, 85, 92));
    // ... add more students ...

    // Calculate ranks
    calculateRanks(students);

    // Print and write ranks to a file
    printAndWriteRanks(students, "rank_output.txt");

    return 0;
}
