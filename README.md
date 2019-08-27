# cgpa-calculator
This repository contains the source code and the executables for my private project to build a simple cgpa calculator in C++.

### How it works?
This program is designed as a console/teminal application to output the Cumulative Grade Point Average (CGPA) and a table for the courses supplied to it.</br></br>
To start, enter the number of courses you wish to evaluate. The program will then sequentially ask you for the course name/id, credit and grade obtained. for each course. The course name/id is optional an can be left blank. However, incorrect CREDIT value (apart from 0, 1 or 3) or GRADE (A through F only) values will TERMINATE the program. GRADE values are CASE INSENSITIVE meaning both B+ and b+ yeild the same result.</br></br>
<b>WARNING:</b> Care should be taken as not all inputs are extensively validated. Incomplete grades such as 'W', 'Z' or 'I' is not accepted since they do not affect the cgpa in any way.</br></br>
<b>Tip:</b> For proper alignment of output table, use consistent naming conventions (eg. CSC121, EEE221 OR CSC 121, eee 221 OR leave ALL blank)

### Releases
<a href="cgpa-0.1.exe">cgpa-0.1.exe</a> - executable for version 0.1 (August 27, 2019)</br>
<a href="source-0.1.cpp">source-0.1.cpp</a> - source code for version 0.1 (August 27, 2019)</br>
<a href="cgpa-0.0.exe">cgpa-0.0.exe</a> - executable for intitial release (August 26, 2019)</br>
<a href="source-0.0.cpp">source-0.0.cpp</a> - source code for initial release (August 26, 2019)</br>
