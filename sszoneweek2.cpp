#include <iostream>
#include <vector>

using namespace std;

struct Course {
    string name;
    int credits;
    char grade;
};

double calculateGPA(char grade) {
    // Define a mapping from grades to grade points
    switch (grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        default:
            return 0.0;
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    // Input each course's details
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter name of course " << i+1 << ": ";
        cin >> courses[i].name;
        cout << "Enter credits for course " << i+1 << ": ";
        cin >> courses[i].credits;
        cout << "Enter grade for course " << i+1 << " (A, B, C, D): ";
        cin >> courses[i].grade;
    }

    double totalCredits = 0;
    double totalGradePoints = 0;

    // Calculate total grade points and credits
    for (const Course& course : courses) {
        double gradePoint = calculateGPA(course.grade);
        totalCredits += course.credits;
        totalGradePoints += gradePoint * course.credits;
    }

    // Calculate CGPA
    double cgpa = totalGradePoints / totalCredits;

    // Output the CGPA
    cout << "Your Cumulative Grade Point Average (CGPA) is: " << cgpa << endl;

    return 0;
}
