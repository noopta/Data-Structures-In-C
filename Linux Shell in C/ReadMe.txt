Test Cases: 

Running with no arguements
eg. enter "ls" after compiling the file with the makefile and writing ./ish on the terminal
Output should list all the files in the folder.

Running with an arguement
eg. "ls -1" will list all the files from top to bottom 

Exit
eg. Enter "exit" in the shell command line to exit the program

Program to make yourself
I created an addition function. It takes 3 arguements and is called by typing "add".
Expected input: "add 2 3"
Output: The sum of the two numbers is 5.

Greatest Common Devisor 
eg. Takes three arguements including "gcd" and finds the greatest common divisor between the two numbers

Args counter
eg. Enter the command "args" followed by some arguements and the shell will list the amount of arguments entered.

In my program I created a "loop" function. At first I set up a do while loop to promopt the user,
then got the command line arguemnts and parse through it using lex.c's getln() function.
After that I created an "execute" function that takes in the args and iterates through
to check what function to execute depending on the user input. 

I used while loops to iterate through the args variable passed into my execute function
to try and detect certain characters or strings. Once detected a certain action would take place.
I used if statements instead of creating and calling functions because it was easier for
me to read my code when I had all the functions beside eachother instead of spread throughout my ish.c file.

At the end I free args to prevent memory leaks.

Anupta Islam
1007108 