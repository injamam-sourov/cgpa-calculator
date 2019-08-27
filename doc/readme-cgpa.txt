--- Setup/Installation ---
To run the program simply download and run the cgpa-x.x.exe file (where x.x represents the version) from the home page. Previous releases can be found in the /bin directory.
The view the source code check out the /source folder.

--- How it works? ---
This program is designed as a console/teminal application to output the Cumulative Grade Point Average (CGPA) and a table for the courses supplied to it.
To start, enter the number of courses you wish to evaluate. The program will then sequentially ask you for the course name/id, credit and grade obtained. for each course. The course name/id is optional an can be left blank. However, incorrect CREDIT value (apart from 0, 1 or 3) or GRADE (A through D and F only) values will TERMINATE the program. GRADE values are CASE INSENSITIVE meaning both B+ and b+ yeild the same result.
WARNING: Care should be taken as not all inputs are extensively validated. Incomplete grades such as 'W', 'Z' or 'I' is not accepted as they do not affect the cgpa in any way.
Tip: For proper alignment of output table, use consistent naming conventions (eg. CSC121, EEE221 OR CSC 121, eee 221 OR leave ALL blank).

--- Release notes ---
v0.0 - very basic/barebone gpa calculator without any formatting or error messages.
v0.1 - added generic documentation
