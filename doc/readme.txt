## Setup/Installation
No installtion is required. To use the program simply download and run cgpa-x.x.exe from the /bin folder (x.x represents the version number, choose the highest). For the source file see /source folder.

## Documentations:
(For version 0.2.1) The program offers two methods of solution defined as method 1 and method 2. The user will prompted to choose one

Method 1 follows the previous convention and requires the user to input grade and credit earned for every courses taken. Hence this method takes longer but eliminates any error margin on final CGPA.

Method 2 simplies matters by accounting for a pre existing CGPA (as such from previous semester). This should be only used if the user has taken credit courses before and can supply a cgpa and credit count for them. However, care should be taken as this method allows a margin for error (plus or minus 0.01) since most values are rounded of figures. Desipite this, in most cases, the final rounded cgpa should be accurate to two decimal places as is usually required.

Caution:
The program can't validate whether or not your previous cgpa, credits and grades agree with each other. If your final cgpa is >4 or something that seems way off from what it should be, chances are you have entered a legal but incosistent combination of previous cgpa, credit and grade. See documentation for more details.

Once a method is chosen, the user will be promted to enter details as required. Any invalid input at any point within the porgram will terminate the program with appropiate error message. After all required inputs have been gathered the program will generate a course table for the courses supplied, calculate the final cgpa and waiver eligibilty as per IUB Greenbook for Autumn 2019.

Tips to avoid errors:

    The course id input is optional and can be left blank but cannot exceed 7 characters (eg. EEE223L is 7 characters)
    Accpeted course credit values are 0, 1, 3 and 4 only
    Accpeted grades are A though D and F only
    Grade values are case insensitive meaning both B+ and b+ yield the same result

(For version 0.2.0) The program now offers two methods of solution defined as method 1 and method 2. The user will prompted to choose one

Method 1 follows the previous convention and requires the user to input grade and credit earned for every courses taken. Hence this method takes longer but gives the exact CGPA without any error margins.

Method 2 simplies matters by accounting for a pre existing CGPA (as such from previous semester). This should be only used if the user has taken credit courses before and can supply a cgpa and credit count for them. However, care should be taken as this method allows a margin for error since most values are rounded of figures. Desipite this, in most cases, the final rounded cgpa should be accurate to two decimal places as is usually required.

WARNING: (as of version 0.2.0) Method 2 does not account for retakes. In that case, this user is adviced to enter only non retake courses and manually adjust the output cgpa for retakes OR use method 1 with only the latest grade earned for retake courses.

Once a method is chosen, the user will be promted to enter details as required. Any invalid input at any point within the porgram will terminate the program with appropiate error message. After all required inputs have been gathered the program will generate a course table for the courses supplied, calculate the final cgpa and waiver eligibilty as per IUB Greenbook for Autumn 2019.

Tips to avoid errors:

    The course id input is optional an can be left blank
    Accpeted course credit values are 0, 1, 3 and 4 only
    Accpeted grades are A though D and F only
    Grade values are case insensitive meaning both B+ and b+ yield the same result



(For versions upto v0.1.1) To start, enter the number of courses you wish to evaluate. The program will then sequentially ask you the details (id, credit and grade obtained) for each course. The course id is optional an can be left blank. However, incorrect CREDIT value (apart from 0, 1 or 3) or GRADE (A through D and F only) values will TERMINATE the program. GRADE values are CASE INSENSITIVE meaning both B+ and b+ yield the same result.

WARNING:

    Care should be taken as not all inputs are extensively validated
    In case of retakes use the latest earned grade only. The program does not validate retakes
    Incomplete grades such as 'W', 'Z' or 'I' is not accepted as they do not affect the cgpa in any way



(For versions prior to 0.1.1): For proper alignment of output table, use consistent naming conventions (eg. CSC121, EEE221 OR CSC 121, eee 221 OR leave ALL blank)
Releases:
cgpa-0.2.1.exe - executable for version 0.2.1 (August 30, 2019)
cgpa-0.2.1.cpp - source code for version 0.2.1 (August 30, 2019)
cgpa-0.2.0.exe - executable for version 0.2.0 (August 29, 2019)
cgpa-0.2.0.cpp - source code for version 0.2.0 (August 29, 2019)
cgpa-0.1.1.exe - executable for version 0.1.1 (August 28, 2019)
cgpa-0.1.1.cpp - source code for version 0.1.1 (August 28, 2019)
cgpa-0.1.0.exe - executable for version 0.1.0 (August 27, 2019)
cgpa-0.1.0.cpp - source code for version 0.1.0 (August 27, 2019)
cgpa-0.0.exe - executable for intitial release (August 26, 2019)
cgpa-0.0.cpp - source code for initial release (August 26, 2019)
Release notes:

v0.1.0:

    [important] tuition waiver based on cgpa feature added
    calculation of course grade points merged with course details input
    total credit and total grade point earned merged with course details input

v0.1.1:

    [important] course id limited to 7 characters to improve visual corrections for output table
    waiver calculation made a seperate function
    table and cgpa output made a seperate function
    course details input made a seperate function
    
v0.2.0:

    [important] added feature to use previous semester cgpa
    revised program structure
    better error handling and validations
    code redesigned

v0.2.1:

    [important] method 2 now considers retakes!
    no global variables! the ex global variables are now locally created
    changes made currentSemesterDetails function and now it takes parameters
    slight changes made to method functions and some output messages

