/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along with this program.
    If not, see <https://www.gnu.org/licenses/>.
    For any future references, you can also find this program at
    <https://github.com/gufranyes/SimpleDriver-What2Eat>.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Initialization of variables.
int passedCount = 0;
int kebabShort = 0;
int burgerShort = 0;
int pastaShort = 0;
int lahmacunShort = 0;
int saladShort = 0;
int tempDishIndex;

// Function that secures system in case wrong choices of user while selecting menu type.
int secureChoice()
{
    int menuChoice;
    bool properChoice = false;
    while (!properChoice)
    {
        char *str;
        printf("Will you write dishes or would you prefer a pre-defined menu?\n 1- We will write what we want.\n 2- BRING THE MENU!\n Choice : ");
        scanf("%d", &menuChoice);
        if (menuChoice == 1 || menuChoice == 2)
        {
            properChoice = true;
        }
        else
        {
            printf("\nPlease enter a valid number!\n");
            properChoice = false;
        }
    }
    printf("Your Choice : %d\n", menuChoice);
    return menuChoice;
}

// Function that checks dishes which passed the pre-defined threshold.
int checkThreshold(int count, int passed, int dishID)
{
    if (count >= 12) // Upper half for 5 people
    {
        passed++;

        switch (dishID)
        {
        case 1:
            kebabShort = 1;
            tempDishIndex = 0; // In order to know if there is only one dish which passed the threshold.
            break;
        case 2:
            burgerShort = 1;
            tempDishIndex = 1;
            break;
        case 3:
            pastaShort = 1;
            tempDishIndex = 2;
            break;
        case 4:
            lahmacunShort = 1;
            tempDishIndex = 3;
            break;
        case 5:
            saladShort = 1;
            tempDishIndex = 4;
            break;
        }
    }

    return passed;
}

int main()
{
    // Initialization of variables.
    int nameSize;
    const char name[20];

    printf("How many people do we have today : ");
    scanf("%d", &nameSize);

    printf("Who are gonna eat today? Names please.\n");
    char nameList[nameSize][20];

    // Loop to take names of students. I know I could just take numbers, it would be easier. But this looks better and user feels more special.
    for (int i = 0; i < nameSize;)
    {
        printf("%d : ", ++i);
        scanf("%s", name);
        strcpy(nameList[i], name);
    }
    printf("\n"); // Just to look good.

    // Iterate through 2D Array to print names.
    for (int i = 1; i <= nameSize; i++)
    {
        printf("Name %d : ", i);
        puts(nameList[i]);
    }
    printf("\n"); // Just to look good.
    int menuChoice = secureChoice();

    // Too much workload at this point. Maybe I can add this part later.
    if (menuChoice == 1)
    {
        printf("\n404 Error Not Found. Redirecting to the MENU...\n\n");
        menuChoice = 2;
    }

    // Pre-Defined Menu Option - People selects items.
    if (menuChoice == 2)
    {
        // Initialization of variables.
        int input;
        char dishNameList[5][20] = {"Kebab", "Burger", "Pasta", "Lahmacun", "Salad"};
        int kebab = 0;
        int burger = 0;
        int pasta = 0;
        int lahmacun = 0;
        int salad = 0;

        // Loop to take user preferences.
        for (int i = 0; i < nameSize; i++)
        {
            printf("\nMenu\n1-Kebab\n2-Burger\n3-Pasta\n4-Lahmacun\n5-Salad\n(Please type only numbers)\n");
            printf("\n%s\n", nameList[i + 1]); // Print user's name
            for (int j = 5; j > 0; j--)
            {
                printf("Enter Your %d. Preference: ", (6 - j));
                scanf("%d", &input);
                switch (input) // Switch - Case to calculate preference value of dishes in case to check threshold and make a short list.
                {
                case 1:
                    kebab += j;
                    break;
                case 2:
                    burger += j;
                    break;
                case 3:
                    pasta += j;
                    break;
                case 4:
                    lahmacun += j;
                    break;
                case 5:
                    salad += j;
                    break;
                }
            }
        }

        printf("\n\n First Round \n\n");

        // Calculating how many dishes passed the threshold.
        passedCount = checkThreshold(kebab, passedCount, 1);
        passedCount = checkThreshold(burger, passedCount, 2);
        passedCount = checkThreshold(pasta, passedCount, 3);
        passedCount = checkThreshold(lahmacun, passedCount, 4);
        passedCount = checkThreshold(salad, passedCount, 5);
        int shortDishList[] = {kebabShort, burgerShort, pastaShort, lahmacunShort, saladShort};

        if (passedCount == 0)
            printf("You are eating at home/dorm today\n");
        else if (passedCount == 1)
            printf("We will eat %s today\n", dishNameList[tempDishIndex]); // If there is only one dish which pass the threshold, it will directly be the winner.
        else
        {
            printf("After threshold : \n");
            for (int i = 0; i < 5; i++)
            {
                if (shortDishList[i] != 0)
                {
                    printf("%d-", i + 1);
                    puts(dishNameList[i]);
                }
            }

            // Resetting values of dishes.
            kebab = 0;
            burger = 0;
            pasta = 0;
            lahmacun = 0;
            salad = 0;

            for (int i = 1; i <= nameSize; i++)
            {
                printf("\n%s will choose now.\n", nameList[i]);

                for (int j = 1; j <= passedCount; j++)
                {
                    printf("%d. Choice: ", j);
                    scanf("%d", &input);

                    switch (input)
                    {
                    case 1:
                        if (kebabShort == 1)
                        {
                            kebab += passedCount + 1 - j;
                        }
                        break;
                    case 2:
                        if (burgerShort == 1)
                        {
                            burger += passedCount + 1 - j;
                        }
                        break;
                    case 3:
                        if (pastaShort == 1)
                        {
                            pasta += passedCount + 1 - j;
                        }
                        break;
                    case 4:
                        if (lahmacunShort == 1)
                        {
                            lahmacun += passedCount + 1 - j;
                        }
                        break;
                    case 5:
                        if (saladShort == 1)
                        {
                            salad += passedCount + 1 - j;
                        }
                        break;
                    }
                }
            }

            printf("\n\nSecond Round\n\n");

            int max = 0;
            int indexFinal = -1;
            int shortMaxList[] = {kebab, burger, pasta, lahmacun, salad};
            // Loop to calculate which dish is the most preferred.

            for (int i = 0; i < 5; i++)
            {
                if (shortMaxList[i] > max)
                {
                    max = shortMaxList[i];
                    indexFinal = i;
                }
            }

            printf("You will eat %s today, folks!\n\n", dishNameList[indexFinal]);
        }
    }
    return 0;
}