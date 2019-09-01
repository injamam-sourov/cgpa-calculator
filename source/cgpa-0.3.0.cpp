/* 
CGPA calculator v0.3.0 
Changelog: 
[1] [important] no longer prints current semester course table! course id input is now only used for user reference
[2] cleaned up code from head to tail for better readablity. quite many small changes made
*/
#include <iostream>
#include <sstream>
using namespace std;

// message to be displayed at various points
const string MESSAGE = "------- Generic GPA Calculator -------\n\n# The porgram offers two methods to calculate CGPA:\n  (1) using details of every courses you've taken\n  (2) using previous cgpa and credit earned\n\n";
const string WARNINGS = "# WARNINGS:\n# Course credit can be 0,1,3 or 4 only\n # Care should be taken as not all inputs are extensively validated\n# Course id is optional and can be left blank. However, there's a maximum limit of 7 characters (eg. CSE 123)\n# Course grade is case insensitive ('B+' is same as 'b+') and can be any value from A though D and F only\n";
const string M1 = "# This method uses every grade and credit values for all your courses\n# To start, enter the number of courses you wish to evaluate and fill in the details\n";
const string M2 = "# This method uses previous semester cgpa and only require course details for the new semester\n# An error margin of 0.01 should be allowed on the final cgpa\n\nCaution: The program can't validate whether or not your previous cgpa, credits and grades agree with each other. If your final cgpa seems way off from what it should be, chances are you have entered a legal but incosistent combination of previous cgpa, credit and grade. See documentation for more details.\n";

// function declarations
int get_method(string prompt, string error);
void method1();
void method2();
void currentSemesterDetails(int &currentCredit, float &currentGradePoint, int numberOfRetakes);
int get_numberOfCourses(string prompt, string error, int max);
string get_id(string prompt, string error);
float get_cgpa0(string prompt, string error);
int get_credit(string prompt, string error);
int get_credit0(string prompt, string error);
float get_grade( int credit, string prompt, string error);
bool check_retakes(string prompt, string error);
void get_retakeDetails(int &credit0, float &gradePoint0, int &numberOfRetakes);
void waiver(float cgpa);





// program starts here
int main() {
	// initial message
    cout << MESSAGE;

    // select method 1 or 2
    int method= get_method("Which method would you like to use? (1 or 2): ", "invalid input, try again!\n");
	
    // call method based on selection
    if(method==1) method1(); else method2();

    system("pause"); // [3]
    return 0;
}

// fucntion to get method from user
int get_method(string prompt, string error){
    string temp; // temporary variable to store string input
    int method; 
    bool test= true; // variable to validate input
    do 
    {
        cout << prompt; 
        getline(cin, temp); // get input
        // convert string to int
        stringstream ss(temp);  // see [5] or [see stringstream documentation]  
        ss >> method;  // insert read value into var credit
        // validate credit value
        if(method==1 || method==2){
            test=false;
        } else {
            cout << error;
        }
    } while (test);
    // when validation passed, return credit value
    return method;
}

// program method 1
void method1() {
    //method 1 message
    cout << M1 << endl;

    // define variables whose values will be set by currentSemesterDetails function
    int totalCredit=0;
    float totalGradePoint=0;

    // variable that function currentSemesterDetails needs but method 1 does not
    int numberOfRetakes=0;

    // call function currentSemseterDetails. here current semester refers to every courses taken
    currentSemesterDetails(totalCredit, totalGradePoint, numberOfRetakes);

    // calcualte and print cgpa
    float cgpa= totalGradePoint/totalCredit;
    cout << "\nCurrent CGPA: " << cgpa << endl;
    
    // call function waiver 
    waiver(cgpa);
}

// program method 2
void method2(){
    //method 2 message
    cout << M2 << endl;

    // get previous credit and cgpa and calculate previous grade point
    float cgpa0= get_cgpa0("Previous semester cgpa? ", "invalid cgpa, try again! Note: only values between 0 and 4 is accepeted\n");
    int credit0= get_credit0("Previous semester credit completed? ", "invalid credit, only values between 3 and 200 is accepeted\n");
    float gradePoint0 = cgpa0*credit0;

    // check if there are any retakes this semester and get previous course details if needed
    bool retakeExist= check_retakes("Did you retake any course this semester? (y or n) ", "invalid input, try again!\n");
    // variable whose value will be set by get_retakeDetails function and later used by currentSemesterDetails() for validation
    int numberOfRetakes=0;
    if(retakeExist){
        // call retake function
        get_retakeDetails(credit0, gradePoint0, numberOfRetakes);
    }
    
    // define variables whose values will be set by currentSemesterDetails function
    int currentCredit=0;
    float currentGradePoint=0;

    // call function currentSemesterDetails. here current semester refers to every courses taken
    currentSemesterDetails(currentCredit, currentGradePoint, numberOfRetakes);

    // total credit and grade point earned
    int totalCredit= currentCredit+credit0;
    float totalGradePoint= currentGradePoint+gradePoint0;
    
    // calculate and print cgpa
    float cgpa=totalGradePoint/totalCredit;
    cout << "\nCurrent CGPA: " << cgpa << endl;

    // call function waiver 
    waiver(cgpa);
}

// function to get current semester course details
void currentSemesterDetails(int &currentCredit, float &currentGradePoint, int numberOfRetakes) {
    cout << "Enter details of courses taken this semester. You should inlcude any retake courses and their new grades\n\n---Current semester details---" << endl;

    // get number of courses taken 
    int numberOfCourses = get_numberOfCourses("Number of courses completed? ","invalid input, try again! Note: only values between 1 and 39 are accepted!\n", 40);

    // validate for retakes
    while(numberOfCourses < numberOfRetakes)
    {
        cout << "number of courses taken this semester cannot be less than the number of courses retaken" << endl;
        numberOfCourses = get_numberOfCourses("Number of courses completed? ","invalid input, try again! Note: Note: only values between 1 and 39 are accepted!\n", 40);
    }

    // variables to store current course details 
    string courseId[numberOfCourses], courseGrade[numberOfCourses];;
    int courseCredit[numberOfCourses]; 
    float courseGradePoint[numberOfCourses];
    // loop and get current course details (except course grade which will be set by function point_to_grade)
    for(int i=0; i<numberOfCourses; i++) {
        cout << "(" << i+1 << ") ";  // print the course number indicator within the loop
        courseId[i]= get_id("Course Id (Optional): ", "invalid input, try again! Note: course id should not exceed 7 charecters. Try EEE123 or EEE123L or leave blank\n");
        courseCredit[i]= get_credit("Credit(s): ", "invalid input, try again! Note: a course can be of 1, 3 or 4 credits only\n");
        courseGradePoint[i]= get_grade(courseCredit[i], "Grade obtained: ", "invalid grade, try again! Note: only grades A through D and F is accepted\n");
        // note:get_grade() returns the grade point based on grade input. the grade input is not stored anywhere

        // set current semester credit and grade point 
        currentCredit += courseCredit[i]; 
        currentGradePoint += courseGradePoint[i];
    }
}

// function to get number of courses
int get_numberOfCourses(string prompt, string error, int max){
    string temp;  // temporary variable to store string input
    int numberOfCourses;
    bool test= true;  // variable to validate input

    do{
        cout << prompt;
        getline(cin, temp);  // get input
        // convert string to int
        stringstream ss(temp);  // see [5] or [see stringstream documentation]
        ss >> numberOfCourses;  // insert read value into var numberOfCourses

        // validate number of courses
        if(numberOfCourses>0 && numberOfCourses<max){
            test=false;
        } else{
            cout << error;
        }
    } while(test);
    
    // when validation passed, return number of courses
    return numberOfCourses;
}

// function to get course id
string get_id(string prompt, string error){
    string id;
    bool test= true;  // variable to validate input

    do{
        cout << prompt;
        getline(cin, id);  // get input

        // validate course id
        if(id.length()<=7){
            test= false;
        } else {
            cout << "invalid input, try again! Note: course id should not exceed 7 charecters. Try EEE123L or EEE 123 or leave blank" << endl;
        }
    } while(test);

    // when validation passed, return course id
    return id;
}

// function to get current credit value (0, 1, 3 and 4)
int get_credit(string prompt, string error){
    string temp; // temporary variable to store string input
    int credit; 
    bool test= true; // variable to validate input
    do 
    {
        cout << prompt; 
        getline(cin, temp); // get input
        // convert string to int
        stringstream ss(temp);  // see [5] or [see stringstream documentation]  
        ss >> credit;  // insert read value into var credit
        // validate credit value
        if(credit==1 || credit==3 || credit==4){
            test=false;
        } else {
            cout << error;
        }
    } while (test);
    // when validation passed, return credit value
    return credit;
}

// function to get course grade and return course grade point using credit and grade
float get_grade(int credit, string prompt, string error){
    string grade;
    float gradePoint;
    bool test= true;
    
    do{
        cout << prompt;
        getline(cin, grade);  // get input

        // validtion on grade
        if(grade=="a" || grade=="A"){
            gradePoint= 4*credit;
            test= false;
        } else if(grade=="a-" || grade=="A-"){
            gradePoint= 3.7*credit;
            test= false;
        } else if(grade=="b+" || grade=="B+"){
            gradePoint= 3.3*credit;
            test= false;
        } else if(grade=="b" || grade=="B"){
            gradePoint= 3*credit;
            test= false;
        } else if(grade=="b-" || grade=="B-"){
            gradePoint= 2.7*credit;
            test= false;
        } else if(grade=="c+" || grade=="C+"){
            gradePoint= 2.3*credit;
            test= false;
        } else if(grade=="c" || grade=="C"){
            gradePoint= 2*credit;
            test= false;
        } else if(grade=="c-" || grade=="C-"){
            gradePoint= 1.7*credit;
            test= false;
        } else if(grade=="d+" || grade=="D+"){
            gradePoint= 1.3*credit;
            test= false;
        } else if(grade=="d" || grade=="D"){
            gradePoint= 1*credit;
            test= false;
        } else if(grade=="f" || grade=="F"){
            gradePoint= 0;
            test= false;
        } else {
            cout << error;
        }    
    } while(test);

    // when validation passed, return grade point
    return gradePoint;
}

// function to set waiver as of Autumn 2019 IUB
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

// function to get previous cgpa value (0 to 4)
float get_cgpa0(string prompt, string error){
    string temp; // temporary variable to store string input
    float cgpa; 
    bool test= true; // variable to validate input
    do 
    {
        cout << prompt; 
        getline(cin, temp); // get input
        // convert string to int
        stringstream ss(temp);  // see [5] or [see stringstream documentation]  
        ss >> cgpa;  // insert read value into var credit
        // validate credit value
        if(cgpa>=0 || cgpa<=4){
            test=false;
        } else {
            cout << error;
        }
    } while (test);
    // when validation passed, return credit value
    return cgpa;
}

// function to get previous credit value (same as get_credit except values can be 3 to 200)
int get_credit0(string prompt, string error){
    string temp; // temporary variable to store string input
    int credit; 
    bool test= true; // variable to validate input
    do 
    {
        cout << prompt; 
        getline(cin, temp); // get input
        // convert string to int
        stringstream ss(temp);  // see [5] or [see stringstream documentation]  
        ss >> credit;  // insert read value into var credit
        // validate credit value
        if(credit>2 || credit<200){
            test=false;
        } else {
            cout << error;
        }
    } while (test);
    // when validation passed, return credit value
    return credit;
}

// function to check if there are any retakes
bool check_retakes(string prompt, string error){
    string temp;  // temporary variable to store string input
    char answer; 
    bool retake;  // variable that dertemines if retake exists
    bool test= true;  // variable to validate input
    do 
    {
        cout << prompt; 
        getline(cin, temp);  // get input
        // convert string to char
        stringstream ss(temp);  // see [5] or [see stringstream documentation]  
        ss >> answer;  // insert read value into var answer
        // validate user answer (y or n)
        if(answer=='Y' || answer=='y'){
            retake= true;
            test= false;
        } else if(answer=='N' || answer=='n'){
            retake= false;
            test= false;
        } else {
            cout << error;
        }
    } while (test);
    // when validation passed, return credit value
    return retake;
}

// function to get retake course details
void get_retakeDetails(int &credit0, float &gradePoint0, int &numberOfRetakes) {
    // get number of courses retaken
    numberOfRetakes = get_numberOfCourses("How many course(s) did you retake this semester? ", "invalid input, try again! Note: only values between 1 and 10 are accepted for retakes!\n", 10);  
    // variables to store previous course details
    int pCredit[numberOfRetakes];
    string pGrade[numberOfRetakes];
    float pGradePoint[numberOfRetakes];
    // loop and get previous course details
    for(int i=0; i<numberOfRetakes; i++){
        cout << "(" << i+1 << ") ";  // print the course number indicator within the loop
        pCredit[i]= get_credit("Retake Course credit: ", "invalid input, try again! Note: a retake course can be of 1, 3 or 4 credits only\n");
        pGradePoint[i]= get_grade(pCredit[i], "Previous grade: ", "invalid grade, try again! Note: only grades A through D and F is accepted\n");
        
        // set previous credit and grade point without retaken course(s)
        credit0 -= pCredit[i]; 
        gradePoint0 -= pGradePoint[i];
    }
}

/* remarks: had to convert all gradepoint types to float for point-to-grade to work
[2] if loop condition changed to i=1; i<=numberOfCourses; i++ it doesn't work. why?
[3] temporary soltion to prevent .exe from exiting immediately.
[5] https://stackoverflow.com/questions/20594520/what-exactly-does-stringstream-do/44782764 or see string stream documentation
*/