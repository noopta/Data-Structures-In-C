/************************islamAnuptaA1.c**************
 Student Name: Anupta Islam Email Id: anupta
Due Date: Oct. 7th, 2020 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.




****COMPILING MY PROGRAM*****
For the command line, use the following gcc command:
"gcc -o a1 -Wall -lm -std=c99 islamAnuptaA1.c"
After creating the executable, enter "./a1" on the command line, hit enter and program should begin.

********Running the Program***********
Running: ./a1

******STEP BY STEP GUIDE FOR ENTERING USER INPUT********
1. You will be initially asked to enter a 1 or 0 to determine which type of time (AM / PM or 24-hour) you wish to use. (TASK 1)
2. Enter the hour you want to use. (TASK 1)
3. Enter the minutes you want to use. (TASK 1)
4. If it is am / pm time you will be asked to provide an 'a' or a 'p' to determine which time you are referring to. (TASK 1)
5. You will be asked if you want to stay in a hotel, enter 0 for no and 1 for yes. (TASK 2)
6. If yes, you will be asked to enter which hotel. You MUST type in a string (e.g. "Marriott", "Sheraton", etc.), I compared the input string with the hotel names. (TASK 2)
7. You will be asked if you want a ride to the hotel. Enter 0 for no and 1 for yes.
8. You will then be asked the birth day number. Enter the value and hit enter.
9. Finally, the results will be displayed on screen.

 ********************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int totalCost;
    int timeFormat;
    int hotelChoice;
    int inputHour;
    int inputMinutes;
    int hotelCost;
    int numNights;
    int rideChoice, rideCost;
    char inputChar;
    int pmHours;
  //  int counter = 0;
    // int amHours;
    int dobLength;
    int discountedTotal = 0;
    double convertedTotal = 1.0;
    int firstCost;
    int firstSplit;
    int secondSplit;
    int sumSplits;
    double netBill;
    double taxValue = 1.13;
    bool discountOneCheck = false;
    bool discountTwoCheck = false;
    char timeFrame[1];
    char userString[20];
    char dobValue[2];

    printf("Enter 1 for a 12-hour format, or 2 for a 24-hour format:\n");

    scanf("%d", &timeFormat);

    if (timeFormat == 1)
    {
        printf("\nEnter time in 12 hour format\n");

        printf("Enter the hour: \n");
        scanf("%d", &inputHour);

        printf("Enter the minutes: \n");
        scanf("%d", &inputMinutes);

        printf("Enter a 'p' to indicate PM or an 'a' to indicate AM:\n");
        scanf(" %c", &inputChar);

        if (inputChar == 'p')
        {
            memcpy(timeFrame, "pm", 2);
            if ((inputHour < 10) && (inputMinutes < 10))
            {
                printf("You entered 0%d:0%d pm\n", inputHour, inputMinutes);
                pmHours = inputHour + 12;
                printf("In 24 hour format - you entered %d:0%d pm\n", pmHours, inputMinutes);
            }
            else if ((inputHour >= 10) && (inputMinutes >= 10))
            {
                printf("You entered %d:%d pm\n", inputHour, inputMinutes);
                if (inputHour == 12)
                {
                    pmHours = 0;
                    printf("In 24 hour format - you entered 0%d:%d pm\n", pmHours, inputMinutes);
                }
                else
                {
                    pmHours = inputHour + 12;
                    printf("In 24 hour format - you entered %d:%d pm\n", pmHours, inputMinutes);
                }
            }
            else if ((inputHour >= 10) && (inputMinutes < 10))
            {
                printf("You entered %d:%d pm\n", inputHour, inputMinutes);
                if (inputHour == 12)
                {
                    pmHours = 0;
                    printf("In 24 hour format - you entered 0%d:%d pm\n", pmHours, inputMinutes);
                }
                else
                {
                    pmHours = inputHour + 12;
                    printf("In 24 hour format - you entered %d:%d pm\n", pmHours, inputMinutes);
                }
            }
            else if ((inputHour < 10) && (inputMinutes >= 10))
            {
                printf("You entered 0%d:%d pm\n", inputHour, inputMinutes);
                pmHours = inputHour + 12;
                printf("In 24 hour format - you entered %d:%d pm\n", pmHours, inputMinutes);
            }
        }
        else if (inputChar == 'a')
        {
            memcpy(timeFrame, "am", 2);
            if ((inputHour < 10) && (inputMinutes < 10))
            {
                printf("You entered 0%d:0%d am\n", inputHour, inputMinutes);
                printf("In 24 hour format - you entered 0%d:0%d am\n", inputHour, inputMinutes);
            }
            else if ((inputHour >= 10) && (inputMinutes >= 10))
            {
                printf("You entered %d:%d am\n", inputHour, inputMinutes);
                printf("In 24 hour format - you entered %d:%d am\n", inputHour, inputMinutes);
            }
            else if ((inputHour >= 10) && (inputMinutes < 10))
            {
                printf("You entered %d:%0d am\n", inputHour, inputMinutes);
                printf("In 24 hour format - you entered %d:%0d am\n", inputHour, inputMinutes);
            }
            else if ((inputHour < 10) && (inputMinutes >= 10))
            {
                printf("You entered 0%d:%d am\n", inputHour, inputMinutes);
                printf("In 24 hour format - you entered %0d:%d am\n", inputHour, inputMinutes);
            }
        }
        else
        {
            printf("Invalid input.\n");
        }

        //Checking which flight is closest

        //IF ITS AN AM TIME ELSE ITS A PM
        if (timeFrame[0] == 97)
        {
            //if the time is before 7 am or 12 am or it is at 7 am and is at 7:14
            if ((inputHour < 7) || (inputHour == 12) || (inputHour == 7 && inputMinutes <= 14))
            {
                firstCost = 231;
                printf("Closest departure time is 7:15 am, arriving at 8:255 am\n");
                printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 8) || ((inputHour == 8) && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 8:15 am, arriving at 9:25 am\n");
                //  printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 9) || ((inputHour == 9) && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 9:15 am, arriving at 10:25 am\n");
                // printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 10) || ((inputHour == 10) && (inputMinutes <= 14)))
            {
                firstCost = 283;
                printf("Closest departure time is 10:15 am, arriving at 11:25 am\n");
                // printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 11) || ((inputHour == 11) && (inputMinutes <= 14)))
            {
                firstCost = 283;
                printf("Closest departure time is 11:15 am, arriving at 12:25 pm\n");
                printf("cost is %d\n", firstCost);
            }
        } // else its a PM time
        else
        {
            if ((inputHour == 12) || ((inputHour >= 1) && (inputHour < 3)) || ((inputHour == 3) && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 3:15 pm, arriving at 4:25 p.m.\n");
                printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 4) || ((inputHour) == 4 && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 4:15 pm, arriving at 5:25 p.m.\n");
                printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 5) || ((inputHour == 5) && (inputMinutes <= 14)))
            {
                firstCost = 401;
                printf("Closest departure time is 5:15 pm, arriving at 6:25 p.m.\n");
                //   printf("cost is %d\n", firstCost);
            }
        }

        //TASK THREE for the 24 hour time frame
        printf("Would you like a hotel in Montreal? Enter 1 for yes and 0 for no\n");
        scanf("%d", &hotelChoice);

        if (hotelChoice == 0)
        {
            hotelCost = 0;
            numNights = 0;
            //  printf("hotel cost: %d\n", hotelCost);
            //  printf("numNights: %d\n", numNights);
        }

        else if (hotelChoice == 1)
        {

            printf("Enter which hotel you would like (Marriott, Sheraton, or Double Tree):\n");
            scanf("%s", userString);
            if (strcmp("Marriott", userString) == 0)
            {
                printf("Enter amount of nights you would like to stay at the Marriott: \n");
                scanf("%d", &numNights);

                hotelCost = numNights * 248;
            }
            else if (strcmp("Sheraton", userString) == 0)
            {
                printf("Enter amount of nights you would like to stay at the Sheraton: \n");
                scanf("%d", &numNights);

                hotelCost = numNights * 90;
            }
            else if (strcmp("Double", userString) == 0)
            {
                printf("Enter amount of nights you would like to stay at the Double Tree: \n");
                scanf("%d", &numNights);
                hotelCost = numNights * 128;
            }
        }

        //TASK FOUR asking for a ride to the hotel
        if (hotelChoice > 0)
        {
        }
        printf("Do you need a ride to the hotel? If you are not booking a hotel, enter 0.\n");
        printf("Enter 1 for yes and 0 for no:\n");
        scanf("%d", &rideChoice);

        if (rideChoice == 0)
        {
            rideCost = 0;
            //printf("%d\n", rideCost);
        }
        else if (rideChoice == 1)
        {
            if (strcmp(userString, "Marriott") == 0)
            {
                rideCost = 0;
            }
            else if (strcmp(userString, "Sheraton") == 0)
            {
                rideCost = 25;
            }
            else if (strcmp(userString, "Double") == 0)
            {
                rideCost = 20;
            }
        }

        totalCost = firstCost + rideCost + hotelCost;

        printf("Your total cost before taxes is: $%d\n", totalCost);

        printf("Enter your day of birth:\n");
        scanf("%s", dobValue);

        dobLength = strlen(dobValue);

        if (dobLength == 1)
        {
            firstSplit = dobValue[0] - '0';
            sumSplits = firstSplit;
        }
        if (dobLength == 2)
        {
            firstSplit = dobValue[0] - '0';
            secondSplit = dobValue[1] - '0';
            sumSplits = firstSplit + secondSplit;
        }

        if (totalCost % 11 == 0)
        {
            //   printf("Discount one applied! Total was a multiple of 11.\n");
            convertedTotal = (double)totalCost - (totalCost * 0.05);
            discountOneCheck = true;
            // printf("Total after discount one: $%.2f\n", convertedTotal);
        }

        if ((fmod(convertedTotal, sumSplits) == 0.00) || (totalCost % sumSplits == 0))
        {
            //  printf("Discount two applied! Total after discount was a multiple of the sum of your date of birth numbers.\n");
            discountTwoCheck = true;
            if (discountedTotal == 0)
            {

                convertedTotal = (double)totalCost - (totalCost * 0.05);
            }
            else
            {
                convertedTotal = (double)discountedTotal - (discountedTotal * 0.05);
            }

            discountTwoCheck = true;
            //  printf("Total after discount two: $%.2f\n", convertedTotal);
        }

        if ((discountOneCheck) || (discountTwoCheck))
        {

            printf("Your total cost comes to:\n");
            printf("Cost of closest departure flight: $%d\n", firstCost);
            printf("Cost of Hotel for %d days: $%d\n", numNights, hotelCost);
            printf("Cost of Ride: $%d\n\n", rideCost);

            printf("Total cost before tax: $%d\n", totalCost);

            if (discountOneCheck)
            {
                printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
            }
            else if (!discountOneCheck)
            {
                printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
            }

            if (discountTwoCheck)
            {
                printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
            }
            else if (!discountTwoCheck)
            {
                printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");
            }
            if ((discountTwoCheck) && (discountOneCheck))
            {
                printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
                printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
            }

            printf("\nTotal cost after discounts 1 and 2: $%.2f\n", convertedTotal);
            netBill = convertedTotal * taxValue;
            printf("\nFinally, your total cost after taxes: $%.2f\n", netBill);

        }
        else
        {

            printf("Your total cost comes to:\n");
            printf("Cost of closest departure flight: $%d\n", firstCost);
            printf("Cost of Hotel for %d days: $%d\n", numNights, hotelCost);
            printf("Cost of Ride: $%d\n", rideCost);

            printf("Total cost before tax: $%d\n", totalCost);

            printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
            printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");

            convertedTotal = (double)totalCost;
            printf("Total cost after discounts 1 and 2: $%.2f\n", convertedTotal);
            netBill = totalCost * taxValue;
            printf("\nFinally, your total cost after taxes: $%.2f\n", netBill);


        }
    }
    //DO INPUT = 1 AFTER
    else if (timeFormat == 2)
    {
        printf("Enter the hour: \n");
        scanf("%d", &inputHour);

        printf("Enter the minutes: \n");
        scanf("%d", &inputMinutes);

        if (inputHour >= 12)
        {
            memcpy(timeFrame, "pm", 2);
            printf("You entered %d:%d\n", inputHour, inputMinutes);
            inputHour = inputHour - 12;
            if (inputHour >= 10)
            {
                printf("In 12 hour format - you entered %d:%d %c%c\n", inputHour, inputMinutes, timeFrame[0], timeFrame[1]);
            }
            else
            {
                printf("In 12 hour format - you entered 0%d:%d %c%c\n", inputHour, inputMinutes, timeFrame[0], timeFrame[1]);
            }
        }
        else
        {
            memcpy(timeFrame, "am", 2);
            printf("You entered 0%d:%d\n", inputHour, inputMinutes);
            printf("In 12 hour format - you entered 0%d:%d %c%c\n", inputHour, inputMinutes, timeFrame[0], timeFrame[1]);
        }

        //Checking which flight is closest

        //IF ITS AN AM TIME ELSE ITS A PM
        if (timeFrame[0] == 97)
        {
            //if the time is before 7 am or 12 am or it is at 7 am and is at 7:14
            if ((inputHour < 7) || (inputHour == 12) || (inputHour == 7 && inputMinutes <= 14))
            {
                firstCost = 231;
                printf("Closest departure time is 7:15 am\n");
                //  printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 8) || ((inputHour == 8) && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 8:15 am\n");
                //  printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 9) || ((inputHour == 9) && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 9:15 am\n");
                // printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 10) || ((inputHour == 10) && (inputMinutes <= 14)))
            {
                firstCost = 283;
                printf("Closest departure time is 10:15 am\n");
                // printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 11) || ((inputHour == 11) && (inputMinutes <= 14)))
            {
                firstCost = 283;
                printf("Closest departure time is 11:15 am\n");
                printf("cost is %d\n", firstCost);
            }
        }
        // else its a PM time
        else
        {
            if ((inputHour == 12) || ((inputHour >= 1) && (inputHour < 3)) || ((inputHour == 3) && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 3:15 pm, arriving at 4:25 p.m.\n");
                printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 4) || ((inputHour) == 4 && (inputMinutes <= 14)))
            {
                firstCost = 226;
                printf("Closest departure time is 4:15 pm, arriving at 5:25 p.m.\n");
                printf("cost is %d\n", firstCost);
            }
            else if ((inputHour < 5) || ((inputHour == 5) && (inputMinutes <= 14)))
            {
                firstCost = 401;
                printf("Closest departure time is 5:15 pm, arriving at 6:25 p.m.\n");
                //   printf("cost is %d\n", firstCost);
            }
        }

        //TASK THREE for the 24 hour time frame
        printf("Would you like a hotel in Montreal? Enter 1 for yes and 0 for no\n");
        scanf("%d", &hotelChoice);

        if (hotelChoice == 0)
        {
            hotelCost = 0;
            numNights = 0;
            //  printf("hotel cost: %d\n", hotelCost);
            //  printf("numNights: %d\n", numNights);
        }

        else if (hotelChoice == 1)
        {

            printf("Enter which hotel you would like (Marriott, Sheraton, or Double Tree):\n");
            scanf("%s", userString);
            if (strcmp("Marriott", userString) == 0)
            {
                printf("Enter amount of nights you would like to stay at the Marriott: \n");
                scanf("%d", &numNights);

                hotelCost = numNights * 248;
            }
            else if (strcmp("Sheraton", userString) == 0)
            {
                printf("Enter amount of nights you would like to stay at the Sheraton: \n");
                scanf("%d", &numNights);

                hotelCost = numNights * 90;
            }
            else if (strcmp("Double", userString) == 0)
            {
                printf("Enter amount of nights you would like to stay at the Double Tree: \n");
                scanf("%d", &numNights);
                hotelCost = numNights * 128;
            }
        }

        //TASK FOUR asking for a ride to the hotel
        if (hotelChoice > 0)
        {
        }
        printf("Do you need a ride to the hotel? If you are not booking a hotel, enter 0.\n");
        printf("Enter 1 for yes and 0 for no:\n");
        scanf("%d", &rideChoice);

        if (rideChoice == 0)
        {
            rideCost = 0;
            printf("%d\n", rideCost);
        }
        else if (rideChoice == 1)
        {
            if (strcmp(userString, "Marriott") == 0)
            {
                rideCost = 0;
            }
            else if (strcmp(userString, "Sheraton") == 0)
            {
                rideCost = 25;
            }
            else if (strcmp(userString, "Double") == 0)
            {
                rideCost = 20;
            }
        }

        totalCost = firstCost + rideCost + hotelCost;

        printf("Your total cost before taxes is: $%d\n", totalCost);

        printf("Enter your day of birth:\n");
        scanf("%s", dobValue);

        dobLength = strlen(dobValue);

        if (dobLength > 1)
        {
            firstSplit = dobValue[0] - '0';
            sumSplits = firstSplit;
        }
        if (dobLength == 2)
        {
            firstSplit = dobValue[0] - '0';
            secondSplit = dobValue[1] - '0';
            sumSplits = firstSplit + secondSplit;
        }

        if (totalCost % 11 == 0)
        {
            //   printf("Discount one applied! Total was a multiple of 11.\n");
            convertedTotal = (double)totalCost - (totalCost * 0.05);
            discountOneCheck = true;
            // printf("Total after discount one: $%.2f\n", convertedTotal);
        }

        if ((fmod(convertedTotal, sumSplits) == 0.00) || (totalCost % sumSplits == 0))
        {
            //  printf("Discount two applied! Total after discount was a multiple of the sum of your date of birth numbers.\n");
            discountTwoCheck = true;
            if (discountedTotal == 0)
            {
                convertedTotal = (double)totalCost - (totalCost * 0.05);
            }
            else
            {
                convertedTotal = (double)discountedTotal - (discountedTotal * 0.05);
            }

            discountTwoCheck = true;
            //  printf("Total after discount two: $%.2f\n", convertedTotal);
        }

        if ((discountOneCheck) || (discountTwoCheck))
        {

            printf("Your total cost comes to:\n");
            printf("Cost of closest departure flight: $%d\n", firstCost);
            printf("Cost of Hotel for %d days: $%d\n", numNights, hotelCost);
            printf("Cost of Ride: $%d\n\n", rideCost);

            printf("Total cost before tax: $%d\n", totalCost);

            if (discountOneCheck)
            {
                printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
            }
            else if (!discountOneCheck)
            {
                printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
            }

            if (discountTwoCheck)
            {
                printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
            }
            else if (!discountTwoCheck)
            {
                printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");
            }
            if ((discountTwoCheck) && (discountOneCheck))
            {
                printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
                printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
            }

            printf("\nTotal cost after discounts 1 and 2: $%.2f\n", convertedTotal);
            netBill = convertedTotal * taxValue;
            printf("\nFinally, your total cost after taxes: $%.2f\n", netBill);


        }
        else
        {

            printf("Your total cost comes to:\n");
            printf("Cost of closest departure flight: $%d\n", firstCost);
            printf("Cost of Hotel for %d days: $%d\n", numNights, hotelCost);
            printf("Cost of Ride: $%d\n", rideCost);

            printf("Total cost before tax: $%d\n", totalCost);

            printf("Sorry - you missed out on 5%% discount because the total cost was not a multiple of 11\n");
            printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digits in your day of birth\n");

            printf("\nTotal cost after discounts 1 and 2: $%d\n", totalCost);
            netBill = totalCost * taxValue;
            printf("\nFinally, your total cost after taxes: $%.2f\n", netBill);
        }


    }
    else
    {
        printf("Invalid input.\n");
    }
  }
