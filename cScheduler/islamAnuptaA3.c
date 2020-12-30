/************************islamAnuptaA3.c**************
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

#define NUMBER_PROFS 6
#define NUMBER_COURSES 10

// Task 1
void readCourseProfData(char filename[50], char courseNames[NUMBER_COURSES][50], char profNames[NUMBER_PROFS][30], int courseID[NUMBER_COURSES])
{
    FILE *fp;
    int i = 0;
    int j = 0;
    int stringLength = 0;
    char line[100];

    fp = fopen(filename, "r");
    if(fp != NULL){
      // if the file isn't empty then read the course information
      while (!feof(fp))
      {
          if (i < 10)
          {
              fgets(line, sizeof(line), fp);
              strcpy(courseNames[i], line);
              // removing the newline character from the end of each string from fgets
              stringLength = strlen(courseNames[i]);
              if (courseNames[i][stringLength - 1] == '\n')
              {
                  courseNames[i][stringLength - 1] = '\0';
              }

              i++;
          }
          else if (i >= 10 && i < 16)
          {
              fgets(line, sizeof(line), fp);
              strcpy(profNames[j], line);

              // removing the newline character from the end of each string from fgets
              stringLength = strlen(profNames[j]);
              if (profNames[j][stringLength - 1] == '\n')
              {
                  profNames[j][stringLength - 1] = '\0';
              }
              j++;
              if (i == 15)
              {
                  j = 0;
              }
              i++;
          }

          else if ((i >= 16) && (i < 26))
          {
              fscanf(fp, "%d", &courseID[j]);
              j++;
              i++;
          }
      }
    } else {
      printf("Error: courses file not found. Exiting program.\n");
      exit(0);
    }
}

// Task 2

void readData(char filename[50], char data[NUMBER_PROFS][NUMBER_COURSES])
{
    int i;
    int j;
    FILE *fp;
    char line[100];
    int stringLength;

    // opening the file
    fp = fopen(filename, "r");
    if(fp != NULL){
      // looping through the file
      while (!feof(fp))
      {
          for (i = 0; i < NUMBER_PROFS; i++)
          {
              // reading in input line by line and then removing the newline at the end of each line
              fgets(line, sizeof(line), fp);
              stringLength = strlen(line);
              if (line[stringLength - 1] == '\n')
              {
                  line[stringLength - 1] = '\0';
              }
              for (j = 0; j < NUMBER_COURSES; j++)
              {
                  line[j] = tolower(line[j]);
                  data[i][j] = line[j];
              }
          }
      }
    } else {
      printf("Error: data file not found. Exiting program.\n");
      exit(0);
    }
}

// Task 3
int numProfsTeachingNCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char profNames[NUMBER_PROFS][30])
{
    int charCounter = 0;
    int teacherCounter = 0;
    int i, j;

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            // check each character and if yes then increase the character counter
            if (data[i][j] == 'y')
            {

                charCounter++;
            }
        }

        // at the end of each loop check if the char counter is greater than or equal to n
        // print the prof name if yes and increase the teacher counter
        if (charCounter >= n)
        {
            printf("Professor %s teaches %d courses\n", profNames[i], n);
            teacherCounter++;
        }
        charCounter = 0;
    }
    return teacherCounter;
}

// Task 4
int numProfsTeachingNLevelCourses(char data[NUMBER_PROFS][NUMBER_COURSES], int n, int courseID[NUMBER_COURSES], char profNames[NUMBER_PROFS][30])
{
    int i;
    int j;
    int courseTaughtCounter = 0;
    int extraCounter = 0;
    int profCounter = 0;

    n = n / 100;

    if (n == 1)
    {
        // first year course
        for (i = 0; i < NUMBER_PROFS; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (data[i][j] == 'y')
                {
                    courseTaughtCounter++;
                }
            }

            for (j = 2; j < NUMBER_COURSES; j++)
            {
                if (data[i][j] == 'y')
                {
                    extraCounter++;
                }
            }

            if ((extraCounter == 0) && (courseTaughtCounter <= 2) && (courseTaughtCounter > 0))
            {
                printf("Professor %s teaches level %d courses only\n", profNames[i], n);
                profCounter++;
            }

            extraCounter = 0;
            courseTaughtCounter = 0;
        }
    }
    else if (n == 2)
    {
        // second year course
        for (i = 0; i < NUMBER_PROFS; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (data[i][j] == 'y')
                {
                    extraCounter++;
                }
            }

            for (j = 2; j < 5; j++)
            {
                if (data[i][j] == 'y')
                {
                    courseTaughtCounter++;
                }
            }

            for (j = 5; j < NUMBER_COURSES; j++)
            {
                if (data[i][j] == 'y')
                {
                    extraCounter++;
                }
            }

            if ((extraCounter == 0) && (courseTaughtCounter <= 3) && (courseTaughtCounter > 0))
            {
                printf("Professor %s teaches level %d courses only\n", profNames[i], n);
                profCounter++;
            }

            extraCounter = 0;
            courseTaughtCounter = 0;
        }
    }
    else if (n == 3)
    {
        // third year course
        for (i = 0; i < NUMBER_PROFS; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (data[i][j] == 'y')
                {
                    extraCounter++;
                }
            }

            for (j = 5; j < 8; j++)
            {
                if (data[i][j] == 'y')
                {
                    courseTaughtCounter++;
                }
            }

            for (j = 8; j < NUMBER_COURSES; j++)
            {
                if (data[i][j] == 'y')
                {
                    extraCounter++;
                }
            }

            if ((extraCounter == 0) && (courseTaughtCounter <= 2) && (courseTaughtCounter > 0))
            {
                printf("Professor %s teaches level %d courses only\n", profNames[i], n);
                profCounter++;
            }

            extraCounter = 0;
            courseTaughtCounter = 0;
        }
    }
    else if (n == 4)
    {
        // fourth year course
        for (i = 0; i < NUMBER_PROFS; i++)
        {
            for (j = 0; j < 7; j++)
            {
                if (data[i][j] == 'y')
                {
                    extraCounter++;
                }
            }

            for (j = 7; j < NUMBER_COURSES; j++)
            {
                if (data[i][j] == 'y')
                {
                    courseTaughtCounter++;
                }
            }

            if ((extraCounter == 0) && (courseTaughtCounter <= 3) && (courseTaughtCounter > 0))
            {
                printf("Professor %s teaches level %d courses only\n", profNames[i], n);
                profCounter++;
            }

            extraCounter = 0;
            courseTaughtCounter = 0;
        }
    }

    // check which level course n is
    // if it is a first year course then check each prof for the courseTaughtCounter
    // if the courseTaughtCounter for the first two courses is greater than 0 and equal or less than two
    // then the prof teaches the first year courses
    // have an extra counter to count 'y' for all the other course levels
    // if the extraCounter > 0 then don't print the name else print the name

    return profCounter;
}

// Task five
int coursesWithNProfs(char data[NUMBER_PROFS][NUMBER_COURSES], int n, char courseNames[NUMBER_COURSES][50])
{
    int i;
    int j = 0;
    int allCourses[NUMBER_COURSES] = {0};
    int coursesTaughtByNProfs = 0;

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            if (data[i][j] == 'y')
            {
                allCourses[j] = allCourses[j] + 1;
            }
        }
    }

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if (n == allCourses[i])
        {
            printf("%s has %d professors teaching it\n", courseNames[i], n);
            coursesTaughtByNProfs++;
        }
    }

    return coursesTaughtByNProfs;
}

// Task 6
float avgNumCourses(char data[NUMBER_PROFS][NUMBER_COURSES])
{
    int i;
    int j;
    float averageNumberOfCourses = 0;
    int coursesTaughtCounter = 0;

    for (i = 0; i < NUMBER_PROFS; i++)
    {
        for (j = 0; j < NUMBER_COURSES; j++)
        {
            if (data[i][j] == 'y')
            {
                coursesTaughtCounter++;
            }
        }
    }

    averageNumberOfCourses = coursesTaughtCounter / 6;
    return averageNumberOfCourses;
}

// Task 7
int getCourseName(int courseNum, int courseID[NUMBER_COURSES], char cNameFound[50], char courseNames[NUMBER_COURSES][50])
{
    int i;
    int courseCodeFound = 0;
    int codeFoundChecker = 0;

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if (courseNum == courseID[i])
        {
            courseCodeFound = i;
            codeFoundChecker = 1;
        }
    }

    if (codeFoundChecker == 1)
    {
        strcpy(cNameFound, courseNames[courseCodeFound]);
        return codeFoundChecker;
    }
    else
    {

        return codeFoundChecker;
    }
}

// Task 8

int getCourseNum(char cName[50], int courseID[NUMBER_COURSES], int *cNumFound, char courseNames[NUMBER_COURSES][50])
{
    int outputInt = 0;
    int i;
    int indexLocation;

    for (i = 0; i < NUMBER_COURSES; i++)
    {
        if (strcmp(cName, courseNames[i]) == 0)
        {
            *cNumFound = courseID[i];
            indexLocation = i;
            outputInt = 1;
        }
    }

    printf("cNumFound = %d at %d\n", *cNumFound, indexLocation);

    return outputInt;
}

// Task 9

void generateReport(char data[NUMBER_PROFS][NUMBER_COURSES], int courseID[NUMBER_COURSES], char courseNames[NUMBER_COURSES][50], char profNames[NUMBER_PROFS][30])
{
    // print and analyze on each iteration of the loop
    int i;
    int j = 0;
    int teacherIsHere = 0;

    printf("***********************************\n");
    for (i = 0; i < NUMBER_COURSES; i++)
    {
        teacherIsHere = 0;
        printf("%d. Course No: CIS%d\n", i + 1, courseID[i]);
        printf("    Course Name: %s\n", courseNames[i]);
        printf("    Taught by: ");

        for (j = 0; j < NUMBER_PROFS; j++)
        {

            if (data[j][i] == 'y')
            {
                printf("%s, ", profNames[j]);
                teacherIsHere = 1;
            }
        }

        if (teacherIsHere == 0)
        {
            printf("None");
        }
        printf("\n\n");
    }
    printf("***********************************\n");
  }
