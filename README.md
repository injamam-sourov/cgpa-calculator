# cgpa-calculator
This repository contains the source code and the executables for my private project to build a simple cgpa calculator in C++. To run the program download and run the latest release <a href="bin/cgpa-0.2.1.exe">cgpa-0.2.1.exe</a>. All binaries and sources can be found in the <b>/bin</b> and <b>/source</b> directories respectively.

### How it works?
This program is designed as a console/teminal application to output the Cumulative Grade Point Average (CGPA) and a table for the courses supplied to it.</br>

<b>(For version 0.2.1)</b> The program offers two methods of solution defined as method 1 and method 2. The user will prompted to choose one</br>

<b>Method 1</b> follows the previous convention and requires the user to input grade and credit earned for every courses taken. Hence this method takes longer but eliminates any error margin on final CGPA.</br>

<b>Method 2</b> simplies matters by accounting for a pre existing CGPA (as such from previous semester). This should be only used if the user has taken credit courses before and can supply a cgpa and credit count for them. However, care should be taken as this method allows a margin for error (plus or minus 0.01) since most values are rounded of figures. Desipite this, in most cases, the final rounded cgpa should be accurate to two decimal places as is usually required.</br></br>

<b>Caution:</b></br>The program can't validate whether or not your previous cgpa, credits and grades agree with each other. If your final cgpa is >4 or something that seems way off from what it should be, chances are you have entered a legal but incosistent combination of previous cgpa, credit and grade. See documentation for more details.</br>

Once a method is chosen, the user will be promted to enter details as required. Any invalid input at any point within the porgram will terminate the program with appropiate error message. After all required inputs have been gathered the program will generate a course table for the courses supplied, calculate the final cgpa and waiver eligibilty as per IUB Greenbook for Autumn 2019.</br>

<b>Tips to avoid errors:</b>
<ul>
  <li>The course id input is optional and can be left blank but cannot exceed 7 characters (eg. EEE223L is 7 characters)</li>
  <li>Accpeted course credit values are 0, 1, 3 and 4 only</li>
  <li>Accpeted grades are A though D and F only</li>
  <li>Grade values are case insensitive meaning both B+ and b+ yield the same result</li>
</ul>

<b>(For previous versions):</b> For best results see documentaion to learn about certain conventions and limitiations for the particular release.

### Releases:
<a href="bin/cgpa-0.2.1.exe">cgpa-0.2.1.exe</a> - executable for version 0.21 (August 30, 2019)</br>
<a href="source/cgpa-0.2.1.cpp">cgpa-0.2.1.cpp</a> - source code for version 0.2.1 (August 30, 2019)</br>
<a href="bin/cgpa-0.2.0.exe">cgpa-0.2.0.exe</a> - executable for version 0.2.0 (August 29, 2019)</br>
<a href="source/cgpa-0.2.0.cpp">cgpa-0.2.0.cpp</a> - source code for version 0.2.0 (August 29, 2019)</br>
<a href="bin/cgpa-0.1.1.exe">cgpa-0.1.1.exe</a> - executable for version 0.1.1 (August 28, 2019)</br>
<a href="source/cgpa-0.1.1.cpp">cgpa-0.1.1.cpp</a> - source code for version 0.1.1 (August 28, 2019)</br>
<a href="bin/cgpa-0.1.0.exe">cgpa-0.1.0.exe</a> - executable for version 0.1.0 (August 27, 2019)</br>
<a href="source/cgpa-0.1.0.cpp">cgpa-0.1.0.cpp</a> - source code for version 0.1.0 (August 27, 2019)</br>
<a href="bin/cgpa-0.0.exe">cgpa-0.0.exe</a> - executable for intitial release (August 26, 2019)</br>
<a href="source/cgpa-0.0.cpp">cgpa-0.0.cpp</a> - source code for initial release (August 26, 2019)</br>

### Release notes:
<b>v0.2.1:</b> 
<ul>
  <li><b>[important]</b> method 2 now considers retakes!</li>
  <li> no global variables! the ex global variables are now locally created</li>
  <li>changes made currentSemesterDetails function and now it takes parameters</li>
  <li>slight changes made to method functions and some output messages</li>
</ul>
<b>v0.2.0:</b> 
<ul>
  <li><b>[important]</b> added feature to use previous semester cgpa</li>
  <li> revised program structure</li>
  <li>better error handling and validations</li>
  <li>code redesigned</li>
</ul>
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
