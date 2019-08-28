// CGPA calculator v0.1 - refactored
/* changelog:
[1] [important] course id limited to 7 characters to improve visual corrections for output table 
[2] waiver calculation made a seperate function
[3] table and cgpa output made a seperate function
[4] course details input made a seperate function

*/
#include <iostream>
using namespace std;

const string MESSAGE = "# To start, enter the number of courses you wish to evaluate.\n# Course id is optional and can be left blank. However, there's a maximum limit of 7 characters (eg. CSE 123)\n# Course credit can be 0,1 or 3 only\n# Course grade is case insensitive ('B+' is same as 'b+') and can be any value from A though D and F only\n# WARNING: Care should be taken as not all inputs are extensively validated\n";

// set variables for use by functions
string courseId[40], courseGrade[40];
int courseCredit[40], totalCredit=0; 
float courseGradePoint[40], totalGradePoint=0;

// function to get course details 
int getCourseDetails(int numberOfCourses, string courseId[], int courseCredit[], string courseGrade[]) {
    for(int i=0; i<numberOfCourses; i++) { // [2] 
        cout << "("<< i+1 << ") Course " << " id (Optional): ";
        getline(cin, courseId[i]);
            // validations on course name
            if(courseId[i].length()>7){
                cout << "course id should not exceed 7 charecters. Try EEE123 or EEE 123 or leave blank, terminating program!" << endl;
                system("pause"); // [3]
                return 0;
            }
        cout << "Credit(s): ";
        cin >> courseCredit[i];
        cin.get();  // [1]
            //validation on course credit
            if(courseCredit[i] !=3 && courseCredit[i] !=1 && courseCredit[i] !=0){
                cout << "a course can be of 0, 1 or 3 credits, terminating program!" << endl;
                system("pause"); // [3]
                return 0;
            }
        // calculate total credits
        totalCredit += courseCredit[i]; 
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
        //calculate grade point
        totalGradePoint += courseGradePoint[i]; 
    }
    return 0;
}


// function to output course table and cgpa
void output(int numberOfCourses, string courseId[], int courseCredit[], string courseGrade[], float courseGradePoint[], float cgpa){
    string space;
    cout << "\nCourseId - Credit - Grade - Point" << endl;
    for(int i=0; i<numberOfCourses; i++){
        //visual corrections for output table
        if(courseGrade[i].length() == 2) space="      "; else space="       ";
        switch (courseId[i].length())
        {
        case 0:
            courseId[i].append("        ");
            break;
        case 1:
            courseId[i].append("       ");
            break;
        case 2:
            courseId[i].append("      ");
            break;
        case 3:
            courseId[i].append("     ");
            break;
        case 4:
            courseId[i].append("    ");
            break;
        case 5:
            courseId[i].append("   ");
            break;
        case 6:
            courseId[i].append("  ");
            break;
        case 7:
            courseId[i].append(" ");
            break;
        default:
            break;
        }
        cout << courseId[i] << "   " << courseCredit[i] << "        " << courseGrade[i] << space << courseGradePoint[i] << endl;
    } 
    cout << "\nCGPA: " << cgpa << endl;
}

//function to calculate waiver based on IUB policy as of autumn 2019
void waiver(float cgpa){
    string waiver; 
    if(cgpa>=3.845) waiver="100%";
    else if(cgpa>=3.795 && cgpa<=3.844) waiver="75%";
    else if(cgpa>=3.695 && cgpa<=3.794) waiver="50%";
    else if(cgpa>=3.505 && cgpa<=3.694) waiver="30%";
    else if(cgpa>=3.255 && cgpa<=3.504) waiver="20% (only for students enrolled before summer 2019)";
    else waiver="none";
    cout << "Tuition waiver: " << waiver << endl;
}

int main() {
    cout << "------- Generic GPA Calculator -------\n" << endl;
    cout << MESSAGE << endl;

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

    // get course names, credits and grades 
    getCourseDetails(numberOfCourses, courseId, courseCredit, courseGrade);

    // calculate cgpa
    float cgpa=0;
    cgpa = totalGradePoint/totalCredit;
    
    // output course table and cgpa
    output(numberOfCourses, courseId, courseCredit, courseGrade, courseGradePoint, cgpa); 
    
    //calculate waiver from cgpa
    waiver(cgpa); 

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

