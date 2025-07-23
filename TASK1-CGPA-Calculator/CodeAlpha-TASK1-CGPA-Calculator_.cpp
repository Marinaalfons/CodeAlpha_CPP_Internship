#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Course {
    string name;
    char grade;
    int credit_hours;
    double grade_points;
};

void processSemester(int number_of_courses, vector<Course>& courses, double& total_credits, double& total_grade_points) {
                         
for (int n = 0; n < number_of_courses; n++) {
cout << "please enter the name of course " << n + 1 << " :";
cin >> courses[n].name;

cout << "please enter the grade (A/B/C/D/f) for course " << courses[n].name << " :";
cin >> courses[n].grade;

// Check if the grade is valid 
while (courses[n].grade != 'A' && courses[n].grade != 'a' &&
       courses[n].grade != 'B' && courses[n].grade != 'b' &&
       courses[n].grade != 'C' && courses[n].grade != 'c' &&
       courses[n].grade != 'D' && courses[n].grade != 'd' &&
       courses[n].grade != 'F' && courses[n].grade != 'f') {
	cout << "please enter the correct grade (A/B/C/D/F) for course " << n << " :";
cin >> courses[n].grade;}

// Convert grade to grade points
switch (courses[n].grade) {
    case 'A': case 'a': courses[n].grade_points = 4.0; break;
    case 'B': case 'b': courses[n].grade_points = 3.0; break;
    case 'C': case 'c': courses[n].grade_points = 2.0; break;
    case 'D': case 'd': courses[n].grade_points = 1.0; break;
    case 'F': case 'f': courses[n].grade_points = 0.0; break;  }

cout << "please enter credit hours for course " << courses[n].name << " :";
cin >> courses[n].credit_hours;

//Check if credit hours is positive
while (courses[n].credit_hours <= 0) {
    cout << "please enter correct credit hours for course " << courses[n].name << " :";
    cin >> courses[n].credit_hours;  }

    cout << "-------------------------------------------------------------" << endl;

    total_credits += courses[n].credit_hours;
    total_grade_points += (courses[n].credit_hours * courses[n].grade_points);
    }
}

int main() {
    int number_of_courses, number_of_courses_2;
    double total_credits = 0, total_grade_points = 0;
    double total_credits_2 = 0, total_grade_points_2 = 0;
    double GPA, GPA_2, CGPA;

    // semester1
    cout << "please enter the number of courses (semester 1)  =  ";
    cin >> number_of_courses;
    cout << "_____________________________________________________________" << endl;

    vector<Course> courses_sem1(number_of_courses);
    processSemester(number_of_courses, courses_sem1, total_credits, total_grade_points);

    // semester2
    cout << "*************************************************************" << endl;
    cout << "please enter the number of courses (semester 2)  =  ";
    cin >> number_of_courses_2;
    cout << "_____________________________________________________________" << endl;

    vector<Course> courses_sem2(number_of_courses_2);
    processSemester(number_of_courses_2, courses_sem2, total_credits_2, total_grade_points_2);

    GPA = total_grade_points / total_credits;
    GPA_2 = total_grade_points_2 / total_credits_2;
    CGPA = (total_grade_points + total_grade_points_2) / (total_credits + total_credits_2);

    system("cls");  

cout << "\nCourses - Semester 1:\n";
for (int n = 0; n < number_of_courses; n++) {
cout << "- " << courses_sem1[n].name <<endl<< " | Grade: " << courses_sem1[n].grade<< " | Credit Hours: " << courses_sem1[n].credit_hours << " | Grade Points: " << courses_sem1[n].grade_points << endl<<endl;}
cout << "\nCourses - Semester 2:\n";
for (int i = 0; i < number_of_courses_2; i++) {
cout << "- " << courses_sem2[i].name<<endl<< " | Grade: " << courses_sem2[i].grade<< " | Credit Hours: " << courses_sem2[i].credit_hours<< " | Grade Points: " << courses_sem2[i].grade_points << endl<<endl;}

    cout << "\nGPA for Semester 1: " << GPA<< "\nGPA for Semester 2: " << GPA_2;
    cout << "\nFinal Cumulative GPA (CGPA): " << CGPA << endl;

    return 0;
}