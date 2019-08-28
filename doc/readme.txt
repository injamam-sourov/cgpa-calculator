## Setup/Installation
No installtion is required. To use the program simply download and run cgpa-x.x.exe from the /bin folder (x.x represents the version number, choose the highest). For the source file see /source folder.

## How it works?

This program is designed as a console/teminal application to output the Cumulative Grade Point Average (CGPA) and a table for the courses supplied to it.

To start, enter the number of courses you wish to evaluate. The program will then sequentially ask you the details (id, credit and grade obtained) for each course. The course id is optional an can be left blank. However, incorrect CREDIT value (apart from 0, 1 or 3) or GRADE (A through D and F only) values will TERMINATE the program. GRADE values are CASE INSENSITIVE meaning both B+ and b+ yield the same result.

WARNING:

    Care should be taken as not all inputs are extensively validated
    In case of retakes use the latest earned grade only. The program does not validate retakes
    Incomplete grades such as 'W', 'Z' or 'I' is not accepted as they do not affect the cgpa in any way



(For versions prior to 0.1.1 only): For proper alignment of output table, use consistent naming conventions (eg. CSC121, EEE221 OR CSC 121, eee 221 OR leave ALL blank)
Releases

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
