# cgpa-calculator
This repository contains the source code and the executables for my private project to build a simple cgpa calculator in C++. To run the program download and run the latest release <a href="bin/cgpa-0.2.0.exe">cgpa-0.2.0.exe</a>. All binaries and sources can be found in the <b>/bin</b> and <b>/source</b> directories respectively.

### How it works?
This program is designed as a console/teminal application to output the Cumulative Grade Point Average (CGPA) and a table for the courses supplied to it.</br></br>
To start, enter the number of courses you wish to evaluate. The program will then sequentially ask you the details (id, credit and grade obtained) for each course. The course id is optional an can be left blank. However, incorrect credit values (apart from 0, 1, 3 or 4) or grade (A through D and F only) values will terminate the program. Grade values are case insensitive meaning both B+ and b+ yield the same result.</br></br>
<b>WARNING:</b> 
<ul>
  <li>Care should be taken as not all inputs are extensively validated</li>
  <li>In case of retakes use the latest earned grade only. The program does not validate retakes</li>
  <li>Incomplete grades such as 'W', 'Z' or 'I' is not accepted as they do not affect the cgpa in any way</li>
</ul>

<b>(For version 0.0 only):</b> For proper alignment of output table, use consistent naming conventions (eg. CSC121 OR CSC 121 OR leave all blank)

### Releases
<a href="bin/cgpa-0.2.0.exe">cgpa-0.2.0.exe</a> - executable for version 0.2.0 (August 29, 2019)</br>
<a href="source/cgpa-0.2.0.cpp">cgpa-0.2.0.cpp</a> - source code for version 0.2.0 (August 29, 2019)</br>
<a href="bin/cgpa-0.1.1.exe">cgpa-0.1.1.exe</a> - executable for version 0.1.1 (August 28, 2019)</br>
<a href="source/cgpa-0.1.1.cpp">cgpa-0.1.1.cpp</a> - source code for version 0.1.1 (August 28, 2019)</br>
<a href="bin/cgpa-0.1.0.exe">cgpa-0.1.0.exe</a> - executable for version 0.1.0 (August 27, 2019)</br>
<a href="source/cgpa-0.1.0.cpp">cgpa-0.1.0.cpp</a> - source code for version 0.1.0 (August 27, 2019)</br>
<a href="bin/cgpa-0.0.exe">cgpa-0.0.exe</a> - executable for intitial release (August 26, 2019)</br>
<a href="source/cgpa-0.0.cpp">cgpa-0.0.cpp</a> - source code for initial release (August 26, 2019)</br>

### Release notes:
<b>v0.1.0:</b> 
<ul>
  <li><b>[important]</b> tuition waiver based on cgpa feature added as a function</li>
  <li><b>[important]</b> course id limited to 7 characters to improve visual corrections for output table</li>
  <li>calculation of course grade points merged with course details input</li>
  <li>total credit and total grade point earned merged with course details input</li>
  <li>course table and cgpa output made a seperate function</li>
  <li>opening message stored as a constant MESSAGE</li>
  <li>array courseName changed to courseId</li>
</ul>
<b>v0.2.0:</b> 
<ul>
  <li>To be updated</li>
</ul>
