// CGPA calculator v0.2.1 - added retakes features
/*
Changelog: 
[1] [important] method 2 now considers retakes!
[2] no global variables! the ex global variables are now locally created by both methods 1,2
[3] changes made currentSemesterDetails and now takes parameters
[4] slight changes made to method functions and some output messages
*/

#include <iostream>
using namespace std;

// message to be displayed at various points
const string MESSAGE = "------- Generic GPA Calculator -------\n\n# The porgram offers two methods to calculate CGPA:\n  (1) using details of every courses you've taken\n  (2) using previous cgpa and credit earned\n\nWhich method would you like to use? (1 or 2): ";
const string WARNINGS = "# WARNINGS:\n# Course credit can be 0,1,3 or 4 only\n # Care should be taken as not all inputs are extensively validated\n# Course id is optional and can be left blank. However, there's a maximum limit of 7 characters (eg. CSE 123)\n# Course grade is case insensitive ('B+' is same as 'b+') and can be any value from A though D and F only\n";
const string M1 = "(METHOD 1)\n# This method uses every grade and credit values for all your courses\n# To start, enter the number of courses you wish to evaluate and fill in the details\n";
const string M2 = "(METHOD 2)\n# This method uses previous semester cgpa and only require course details for the new semester\n# However, since cgpa is usually rounded off to nearest 0.01 there exist a boundary for error albeit small (plus or minus 0.01)\n# In most cases this small error should not be serious and the final cgpa rounded to 2 decimal places should be accurate\n";

//function declarations
int method1();
int method2();
int currentSemesterDetails(int &currentCredit, float &currentGradePoint, int numberOfRetakes);
int retake(int &credit0, float &gradePoint0);
void waiver(float cgpa);
void output(int numberOfCourses, string courseId[], int courseCredit[], string courseGrade[], float courseGradePoint[], float cgpa);

// main method - Program starts here
int main() {
	// initial message
    cout << MESSAGE;
    
    // select program method
    int method;
    cin >> method;
    cin.get(); // [1]

    // check selection
    int error;
    if(method==1){
        error = method1();
        if(error==1){
            return 0;
        }
    } else if(method==2){
        error = method2();
        if(error==1){
            return 0;
        }
    } else {
        cout << "invalid selection, enter either 1 or 2" << endl;
    }
	
    system("pause"); // [3]
    return 0;
}

// --- Functions ---

// generate a course table and print cgpa
void output(int numberOfCourses, string courseId[], int courseCredit[], string courseGrade[], float courseGradePoint[]){
    string space;
    cout << "\n--- Current Semester course table---" << endl;
    cout << "CourseId - Credit - Grade - Point" << endl;
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
}
// get semester course details and call output function
int currentSemesterDetails(int &currentCredit, float &currentGradePoint, int numberOfRetakes) {
    cout << "---Current semester details---" << endl;
    int numberOfCourses;
    cout << "Number of courses completed? ";
    cin >> numberOfCourses;
    cin.get(); // [1] 
        // validations on number of courses
        if(numberOfCourses < numberOfRetakes){
            cout << "number of courses taken this semester cannot be less than the number of retakes taken" << endl;
        }
        else if(numberOfCourses<1 || numberOfCourses>40 ){
        cout << "invalid input, only values between 1 and 40 are accepted, terminating program!" << endl;
        return 1;
        }

    // get course ids, credits and grades [add validations to each]
    string courseId[numberOfCourses], courseGrade[numberOfCourses];
    int courseCredit[numberOfCourses]; 
    float courseGradePoint[numberOfCourses];
    
    for(int i=0; i<numberOfCourses; i++) {
        // get course id
        cout << "("<< i+1 << ") Course " << " Id (Optional): ";
        getline(cin, courseId[i]);
            // validations on course id
            if(courseId[i].length()>7){
                cout << "course id should not exceed 7 charecters. Try EEE123 or EEE 123 or leave blank, terminating program!" << endl;
                return 1;
            }

        // get course credit
        cout << "Credit(s): ";
        cin >> courseCredit[i];
        cin.get();  // [1]
            //validation on course credit [4]
            if(courseCredit[i] !=4 && courseCredit[i] !=3 && courseCredit[i] !=1 && courseCredit[i] !=0){
                cout << "a course can be of 0, 1, 3 or 4 credits, terminating program!" << endl;
                return 1;
            }

        //get course grade
        cout << "Grade obtained: ";
        getline(cin, courseGrade[i]);
            //validation on grade and calculate course grade points
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
                return 1;
            }

        // calculate semester credit and grade point 
        currentCredit += courseCredit[i]; 
        currentGradePoint += courseGradePoint[i];
    }
    // course table
    output(numberOfCourses, courseId, courseCredit, courseGrade, courseGradePoint);

    return 0;
}
// calculate waiver as of Autumn 2019 IUB
void waiver(float cgpa){
    string waiver; 
    if(cgpa>=3.845) waiver="100%";
    else if(cgpa>=3.795 && cgpa<=3.844) waiver="75%\n";
    else if(cgpa>=3.695 && cgpa<=3.794) waiver="50%\n";
    else if(cgpa>=3.505 && cgpa<=3.694) waiver="30%\n";
    else if(cgpa>=3.255 && cgpa<=3.504) waiver="20% (only for students enrolled before summer 2019)\n";
    else waiver="none";
    cout << "Tuition waiver: " << waiver << endl;
}
// retake
int retake(int &credit0, float &gradePoint0, int &numberOfRetakes) {
    // get how many courses taken this semester were retakes and set value to the supplied var numberOfRetakes 
    cout << "How many course(s) did you retake this semester? (if none enter 0) ";
    cin >> numberOfRetakes;
        // validation on number of retakes
        if(numberOfRetakes<0 || numberOfRetakes>10 ){
        cout << "invalid input, only values between 0 and 10 are accepted for retakes, terminating program!" << endl;
        return 1;
        }

    int pCredit[numberOfRetakes];
    string pGrade[numberOfRetakes];
    float pGradePoint[numberOfRetakes];

    for(int i=0; i<numberOfRetakes; i++) {
        // retake course credit
        cout << "("<< i+1 << ") Retake Course " << " credit: ";
        cin >> pCredit[i];
        cin.get();  // [1]
            //validation on retake course credit [4]
            if(pCredit[i] !=4 && pCredit[i] !=3 && pCredit[i] !=1 && pCredit[i] !=0){
                cout << "a retake course can be of 0, 1, 3 or 4 credits, terminating program!" << endl;
                return 1;
            }

        //previous grade
        cout << "Previous grade: ";
        getline(cin, pGrade[i]);
            //validation on grade and calculate course grade points
            if(pGrade[i]=="a" || pGrade[i]=="A"){
                pGradePoint[i]=4*pCredit[i];
            } else if(pGrade[i]=="a-" || pGrade[i]=="A-"){
                pGradePoint[i]=3.7*pCredit[i];
            } else if(pGrade[i]=="b+" || pGrade[i]=="B+"){
                pGradePoint[i]=3.3*pCredit[i];
            } else if(pGrade[i]=="b" || pGrade[i]=="B"){
                pGradePoint[i]=3*pCredit[i];
            } else if(pGrade[i]=="b-" || pGrade[i]=="B-"){
                pGradePoint[i]=2.7*pCredit[i];
            } else if(pGrade[i]=="c+" || pGrade[i]=="C+"){
                pGradePoint[i]=2.3*pCredit[i];
            } else if(pGrade[i]=="c" || pGrade[i]=="C"){
                pGradePoint[i]=2*pCredit[i];
            } else if(pGrade[i]=="c-" || pGrade[i]=="C-"){
                pGradePoint[i]=1.7*pCredit[i];
            } else if(pGrade[i]=="d+" || pGrade[i]=="D+"){
                pGradePoint[i]=1.3*pCredit[i];
            } else if(pGrade[i]=="d" || pGrade[i]=="D"){
                pGradePoint[i]=1*pCredit[i];
            } else if(pGrade[i]=="f" || pGrade[i]=="F"){
                pGradePoint[i]=0;
            } else {
                cout << "Invalid grade. Please note that only grades A thought D and F is accepted. Grades such as W, Z or I " <<
                        "that do not affect CGPA are not accepted, terminating program!" << endl;
                return 1;
            }
        // calculate semester credit and grade point [GLOBAL varialbes]
        credit0 -= pCredit[i]; 
        gradePoint0 -= pGradePoint[i];
    }
    return 0;
}
//method 1: cgpa using every course details
int method1(){
    //method 1 message
    cout << M1 << endl;
    // define variables whose values will be set by currentSemesterDetails function
    int totalCredit=0;
    float totalGradePoint=0;

    // variable that currentSemesterDetails needs but method 1 does not
    int numberOfRetakes=0;

    // call currentSemseterDetails function. here current semester refers to every courses taken
    int error = currentSemesterDetails(totalCredit, totalGradePoint, numberOfRetakes);
    if (error==1){
        return 1;
    }
    // cgpa
    float cgpa=totalGradePoint/totalCredit;
    cout << "\nCurrent CGPA: " << cgpa << endl;

    // call waiver function
    waiver(cgpa);
    
    return 0;
}
// method 2: cgpa using previous semester cgpa0 and credit0
int method2(){
    //method 2 message
    cout << M2 << endl;

    // caution message for method 2
    
    cout << "Caution: The program can't validate whether or not your previous cgpa, credits and grades agree with each other. If your final cgpa is >4 or something that seems way off from what it should be, chances are you have entered a legal but incosistent combination of previous cgpa, credit and grade. See documentation for more details.\n" << endl;
    
    // get previous credit and cgpa 
    int credit0;
    float cgpa0, gradePoint0;
    cout << "Previous semester cgpa? ";
    cin >> cgpa0;
    cin.get(); // [1]
        //validations on previous cgpa
        if(cgpa0<0 || cgpa0>4){
            cout << "invalid cgpa, only values between 0 and 4 is accepeted" << endl;
            return 1;
        } 

    cout << "Previous semester credit completed? ";
    cin >> credit0;
    cin.get(); // [1]
        //validations on previous credit
        if(credit0<1 || credit0>200){
            cout << "invalid credit, only values between 1 and 200 is accepeted" << endl;
            return 1;
        }
    gradePoint0 = cgpa0*credit0;
    
    // define variable whose value will be set by retake function and later used by currentSemesterDetails() for validation
    int numberOfRetakes;
    // call retake function
    int rError = retake(credit0, gradePoint0, numberOfRetakes);
    if (rError==1){
        return 1;
    }
    
    // define variables whose values will be set by currentSemesterDetails function
    int currentCredit=0;
    float currentGradePoint=0;
    //call currentSemseterDetails function
    cout << "Enter details of courses taken this semester. You should inlcude the retake courses and their new grades (if any)" << endl;
    int error = currentSemesterDetails(currentCredit, currentGradePoint, numberOfRetakes);
    if (error==1){
        return 1;
    }

    // total credit and grade point earned
    int totalCredit= currentCredit+credit0;
    float totalGradePoint= currentGradePoint+gradePoint0;
    
    // cgpa
    float cgpa=totalGradePoint/totalCredit;
    cout << "\nCurrent CGPA: " << cgpa << endl;

    // call waiver fucntion
    waiver(cgpa);

    return 0;
}

/* remarks:
[1] solves problem: trailing /n from previous cin disrupts first input of 
getline making it seem as if the first getline input within the loop is skipped.
[2] if loop condition changed to i=1; i<=numberOfCourses; i++ it doesn't work. why?
[3] temporary soltion to prevent .exe from exiting immediately.
[4][PROBLEM] NaN input for all [int] does not give the required error message. for some reason numberOfCourses and credit0 seems to be working fine!
*/


