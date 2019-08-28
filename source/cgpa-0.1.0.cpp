// CGPA calculator v0.1 - refactored code, added waiver feature
/*
Changelog: 
[1] [important] tuition waiver based on cgpa feature added
[2] calculation of course grade points merged with course details input
[3] total credit and total grade point earned merged with course details input

*/
#include <iostream>
using namespace std;

int main() {
    cout << "------- Generic GPA Calculator -------\n" << endl;
    cout << "# To start, enter the number of courses you wish to evaluate.\n# Course credit can be 0,1 or 3 only\n" <<
            "# Course grade is case insensitive ('B+' is same as 'b+') and can be any value from A though D and F only\n" <<
            "# Course name/id is optional but for properp alignment of output table, use consistent naming conventions " << 
            "(eg. CSC121, EEE221 OR CSC 121, eee 221 OR leave ALL blank)\n" << 
            "# WARNING: Care should be taken as not all inputs are extensively validated\n" << endl;

    // get number of courses taken this semester [add validations]
    int numberOfCourses;
    cout << "Number of courses completed? ";
    cin >> numberOfCourses;
    cin.get(); // [1] 
    
    // validations on number of courses
    if(numberOfCourses<1 || numberOfCourses>40 ){
        cout << "invalid input, only values between 1 and 40 are accepted, terminating program!" << endl;
        system("pause"); // [3]
        return 0;
    }

    // get course names, credits and grades [add validations to each]
    string courseName[numberOfCourses], courseGrade[numberOfCourses];
    int courseCredit[numberOfCourses], totalCredit=0; 
    float courseGradePoint[numberOfCourses], totalGradePoint=0, cgpa=0;
    for(int i=0; i<numberOfCourses; i++) { // [2] 
        cout << "("<< i+1 << ") Course " << " name (Optional): ";
        getline(cin, courseName[i]);
        cout << "Credit(s): ";
        cin >> courseCredit[i];
        cin.get();  // [1]
            //validation on course credit
            if(courseCredit[i] !=3 && courseCredit[i] !=1 && courseCredit[i] !=0){
                cout << "a course can be of 0, 1 or 3 credits, terminating program!" << endl;
                system("pause"); // [3]
                return 0;
            }
        totalCredit += courseCredit[i]; // calculate total credits
        cout << "Grade obtained: ";
        getline(cin, courseGrade[i]);
            //validate and calculate course grade points
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
                cout << "Invalid grade. Please note that only grades A thought D and F is accepted. Grades such as W, Z or I " <<
                        "that do not affect CGPA are not accepted, terminating program!" << endl;
                system("pause"); // [3]
                return 0;
            }
        totalGradePoint += courseGradePoint[i]; //calculate grade point
    }

    // calculate cgpa
    cgpa = totalGradePoint/totalCredit;

    // output course table and cgpa
    string space;
    cout << "\nName - Credit - Grade - Point" << endl;
    for(int i=0; i<numberOfCourses; i++){
        //visual corrections for consistent naming
        if(courseGrade[i].length() == 2) space="      "; else space="       ";
        if(courseName[i] == "") courseName[i]= "    ";
        cout << courseName[i] << "   " << courseCredit[i] << "        " << courseGrade[i] << space << courseGradePoint[i] << endl;
    } 
    cout << "\nCGPA: " << cgpa << endl;;
    
    //IUB waiver calculations as of autumn 2019
    string waiver; 
    if(cgpa>=3.845) waiver="100%";
    else if(cgpa>=3.795 && cgpa<=3.844) waiver="75%";
    else if(cgpa>=3.695 && cgpa<=3.794) waiver="50%";
    else if(cgpa>=3.505 && cgpa<=3.694) waiver="30%";
    else if(cgpa>=3.255 && cgpa<=3.504) waiver="20% (only for students enrolled before summer 2019)";
    else waiver="none";
    cout << "Tuition waiver: " << waiver << endl;

    system("pause"); // [3]
    return 0;
}

/* remarks:
[1] solves problem: trailing /n from previous cin disrupts first input of 
getline making it seem as if the first getline input within the loop is skipped.
[2] if loop condition changed to i=1; i<=numberOfCourses; i++ it doesn't work. why?
[3] temporary soltion to prevent .exe from exiting immediately.
*/

/* program structure:

*/
