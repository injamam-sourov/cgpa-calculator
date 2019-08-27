// CGPA calculator (v0.0, initial release)
#include <iostream>
using namespace std;

int main() {
    cout << "--- Generic Message ---" << endl;

    // get number of courses taken this semester [add validations]
    int numberOfCourses;
    cout << "Number of courses: ";
    cin >> numberOfCourses;
    cin.get(); // [1] 
    
    // get course names, credits and grades [add validations to each]
    string courseName[numberOfCourses], courseGrade[numberOfCourses];
    int courseCredit[numberOfCourses]; 
    for(int i=0; i<numberOfCourses; i++) { // [2] 
        cout << "Course " << i+1 << " name: ";
        getline(cin, courseName[i]);
        cout << "Credit(s): ";
        cin >> courseCredit[i];
        cin.get();  // [1]
        cout << "Grade obtained: ";
        getline(cin, courseGrade[i]);
    }

    // calculate course grade points
    float courseGradePoint[numberOfCourses];
    for(int i=0; i<numberOfCourses; i++){
        if(courseGrade[i]=="a" || courseGrade[i]=="A"){
            courseGradePoint[i]=4*courseCredit[i];
        } else if(courseGrade[i]=="a-" || courseGrade[i]=="A-"){
            courseGradePoint[i]=3.7*courseCredit[i];
        } else if(courseGrade[i]=="b+" || courseGrade[i]=="B+"){
            courseGradePoint[i]=3.3*courseCredit[i];
        } else if(courseGrade[i]=="b" || courseGrade[i]=="B"){
            courseGradePoint[i]=3*courseCredit[i];
        } else if(courseGrade[i]=="b-" || courseGrade[i]=="B-"){
            courseGradePoint[i]=2.7*courseCredit[i];
        } else if(courseGrade[i]=="c+" || courseGrade[i]=="C+"){
            courseGradePoint[i]=2.3*courseCredit[i];
        } else if(courseGrade[i]=="c" || courseGrade[i]=="C"){
            courseGradePoint[i]=2*courseCredit[i];
        } else if(courseGrade[i]=="c-" || courseGrade[i]=="C-"){
            courseGradePoint[i]=1.7*courseCredit[i];
        } else if(courseGrade[i]=="d+" || courseGrade[i]=="D+"){
            courseGradePoint[i]=1.3*courseCredit[i];
        } else if(courseGrade[i]=="d" || courseGrade[i]=="D"){
            courseGradePoint[i]=1*courseCredit[i];
        } else if(courseGrade[i]=="f" || courseGrade[i]=="F"){
            courseGradePoint[i]=0;
        } else {
            cout << "Invalid grade found, terminating program!";
        }
    }

    // calculate total credits and grade point
    int totalCredit=0;
    float totalGradePoint=0, cgpa=0;
    for(int i=0; i<numberOfCourses; i++){
        totalCredit += courseCredit[i];
        totalGradePoint += courseGradePoint[i];
    }
    cgpa = totalGradePoint/totalCredit;

    // test code
    cout << "Name-Credit-Grade-Point" << endl;
    for(int i=0; i<numberOfCourses; i++){
        cout << courseName[i] << " - " << courseCredit[i] << " - " << courseGrade[i] << " - " << courseGradePoint[i] << endl;
    } 
    cout << "CGPA: " << cgpa << endl;;
    
    
    system("pause"); // temporary soltion to prevent .exe from exiting immediately
    return 0;
}

/* remarks:
[1] solves problem: trailing /n from previous cin disrupts first input of 
getline making it seem as if the first getline input within the loop is skipped.
[2] if loop condition changed to i=1; i<=numberOfCourses; i++ it doesn't work. why?
*/
