# cgpa-calculator
This repository contains the source code and the executables for my private project to build a simple cgpa calculator in C++. To run the program download and run cgpa-x.x.exe from the <b>/bin</b> folder (x.x represents the version number, choose the highest). For the source file see <b>/source</b> folder.

### How it works?
This program is designed as a console/teminal application to output the Cumulative Grade Point Average (CGPA) and a table for the courses supplied to it.</br></br>
To start, enter the number of courses you wish to evaluate. The program will then sequentially ask you the details (id, credit and grade obtained) for each course. The course id is optional an can be left blank. However, incorrect CREDIT value (apart from 0, 1 or 3) or GRADE (A through D and F only) values will TERMINATE the program. GRADE values are CASE INSENSITIVE meaning both B+ and b+ yield the same result.</br></br>
<b>WARNING:</b> 
<ul>
  <li>Care should be taken as not all inputs are extensively validated</li>
  <li>In case of retakes use the latest earned grade only. The program does not validate retakes</li>
  <li>Incomplete grades such as 'W', 'Z' or 'I' is not accepted as they do not affect the cgpa in any way</li>
</ul>
</br></br>

<b>(For versions prior to 0.1.1 only):</b> For proper alignment of output table, use consistent naming conventions (eg. CSC121, EEE221 OR CSC 121, eee 221 OR leave ALL blank)

### Releases
<a href="bin/cgpa-0.1.1.exe">cgpa-0.1.1.exe</a> - executable for version 0.1.1 (August 28, 2019)</br>
<a href="source/cgpa-0.1.1.cpp">cgpa-0.1.1.cpp</a> - source code for version 0.1.1 (August 28, 2019)</br>
<a href="bin/cgpa-0.1.0.exe">cgpa-0.1.0.exe</a> - executable for version 0.1.0 (August 27, 2019)</br>
<a href="source/cgpa-0.1.0.cpp">cgpa-0.1.0.cpp</a> - source code for version 0.1.0 (August 27, 2019)</br>
<a href="bin/cgpa-0.0.exe">cgpa-0.0.exe</a> - executable for intitial release (August 26, 2019)</br>
<a href="source/cgpa-0.0.cpp">cgpa-0.0.cpp</a> - source code for initial release (August 26, 2019)</br>

### Release notes:
<b>v0.1.0:</b> 
<ul>
  <li><b>[important]</b> tuition waiver based on cgpa feature added</li>
  <li>calculation of course grade points merged with course details input</li>
  <li>total credit and total grade point earned merged with course details input</li>
</ul>
<b>v0.1.1:</b> 
<ul>
  <li><b>[important]</b> course id limited to 7 characters to improve visual corrections for output table</li>
  <li>waiver calculation made a seperate function</li>
  <li>table and cgpa output made a seperate function</li>
  <li>course details input made a seperate function</li>
<ul>
