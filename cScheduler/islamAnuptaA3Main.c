/************************islamAnuptaMainA3.c**************
Student Name: Anupta Islam    Email Id: anupta
Due Date: 02/12/2020 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certifythat:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computingwith Integrity Tutorial on
Moodle; and
3) I have achieved at least 80% in the Computing with Integrity
Self Test.
I assert that this work is my own. I have appropriately
acknowledged any and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared
 by me specifically for this course.
**********************************************************/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "givenA3.h"

int main(int argc, char *argv[])
{
    // variable declarations
    char theCourses[NUMBER_COURSES][50];
    char theProfs[NUMBER_PROFS][30];
    int theCourseID[NUMBER_COURSES];
    char courseData[NUMBER_PROFS][NUMBER_COURSES];
    int numProfs;
    char inputString[50];
    int cNum = 0;
    int userChoice;
    int nVal;
    int stringLength;
    int inputCourseCode;
    char secondInputString[50];
    int checkIfFound;
    // take in argv[1]
    // if argv is NULL return
    // if argv is an incorrect file then return
    if (argv[1] == NULL)
    {
        printf("No file entered\n");
    } else if(argv[2] == NULL){
      printf("No data file entered\n");
    } else if (argc != 3){
      printf("Incorrect number of files entered. E.g. ./a3 courses.txt data.txt\n");
    }
    else
    {
        // reading the course and prof data
        readCourseProfData(argv[1], theCourses, theProfs, theCourseID);
        // reading the data for if a prof teaches a course
        readData(argv[2], courseData);

        // the menu to choose from
        printf("Enter a number 3-9 to choose an option from the following menu (or anything else to exit):\n");

        printf("3: View the number of professors teaching N courses\n");
        printf("4. View the number of professors teaching Nth level courses only\n");
        printf("5. View how many courses are taught by N profs\n");
        printf("6. View the average number of courses taught by each professor\n");
        printf("7. Get the course name using a course code\n");
        printf("8. Get the course number using the course name\n");
        printf("9. Generate a report\n");

        //getting user input below
        scanf("%d", &userChoice);

        //fflush helps to remove any newlines left by scanf(), a newline leftover
        // will cause fgets() to skip collecting user input
        fflush(stdin);

        // user input loop
        while (userChoice >= 3 && userChoice <= 9)
        {
            // complete task 3
            if (userChoice == 3)
            {
                printf("How many courses? ");
                scanf("%d", &nVal);
                numProfs = numProfsTeachingNCourses(courseData, nVal, theProfs);
                printf("There are %d professors teaching %d courses.\n", numProfs, nVal);
            }
            // complete task 4
            else if (userChoice == 4)
            {
                printf("Level of course? (e.g. 100, 200, 300 as indicated on assignment outline) ");
                scanf("%d", &nVal);
                printf("The number of profs teaching nth level courses is: %d\n", numProfsTeachingNLevelCourses(courseData, nVal, theCourseID, theProfs));
            }
            // complete task 5
            else if (userChoice == 5)
            {
                printf("Number of profs for a course? ");
                scanf("%d", &nVal);
                printf("The number of courses taught by n professors is: %d\n", coursesWithNProfs(courseData, nVal, theCourses));
            }
            // complete task 6
            else if (userChoice == 6)
            {
                printf("The average number of courses taught by each professor is: %.2f\n", avgNumCourses(courseData));
            }
            // complete task 7
            else if (userChoice == 7)
            {
                printf("Search for which course id? ");
                scanf("%d", &inputCourseCode);
                checkIfFound = getCourseName(inputCourseCode, theCourseID, inputString, theCourses);
                if (checkIfFound == 1)
                {
                    printf("The course name found for code %d is: %s\n", inputCourseCode, inputString);
                }
                else if (checkIfFound == 0)
                {
                    printf("The course name was not found for %d\n", inputCourseCode);
                }
            }
            // complete task 8
            else if (userChoice == 8)
            {
                printf("Search for which course name? ");
                fgetc(stdin);
                fgets(secondInputString, 50, stdin);

                stringLength = strlen(secondInputString);
                if (secondInputString[stringLength - 1] == '\n')
                {
                    secondInputString[stringLength - 1] = '\0';
                }

                checkIfFound = getCourseNum(secondInputString, theCourseID, &cNum, theCourses);
                if (checkIfFound == 1)
                {
                    printf("The course code found using %s is: %d\n", secondInputString, cNum);
                    cNum = 0;
                }
                else if (checkIfFound == 0)
                {
                    printf("Course code was not found\n");
                }

                fflush(stdin);
            }
            // complete task 9
            else if (userChoice == 9)
            {
                generateReport(courseData, theCourseID, theCourses, theProfs);
            }

            printf("Enter a number 3-9 to choose an option from the following menu (or anything else to exit):\n");
            scanf("%d", &userChoice);
        }
    }

    return 0;
}
