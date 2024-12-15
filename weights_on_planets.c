#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For toupper()
#include <stdlib.h>  // For strtod()

int main() {
    double weight;
    char planet[11];  // This stores up to 10 characters
    char weightInput[50];  // To store the input as a string for validation

    int weightAttempts = 0; // Counter for invalid weight attempts
    int planetAttempts = 0; // Counter for invalid planet attempts

    // Function to check if the string is a valid number
    int isValidWeight(const char *str) {
        int hasDot = 0;
        // Iterate through the string to check if it's a valid number
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '.') {
                if (hasDot) {  // More than one dot makes it invalid
                    return 0;
                }
                hasDot = 1;
            } else if (!isdigit(str[i])) {  // If it's not a digit or dot
                return 0; // returns 0 if invalid
            }
        }
        return 1;  // Valid number (can be integer or decimal)
    }

    // Ask the user how much they weigh
    while (weightAttempts < 5) {
        printf("How much do you weigh (in lbs)?  \n");
        fgets(weightInput, sizeof(weightInput), stdin);  // Read input as a string

        // Remove the trailing newline character from fgets input
        weightInput[strcspn(weightInput, "\n")] = '\0';  // strcspn finds the length of the string without characters

        // Validate the weight input
        if (isValidWeight(weightInput)) {
            weight = strtod(weightInput, NULL);  // strtod converts valid string to double
            break;
        } else {
            // Invalid weight input
            printf("Invalid input for weight. Please enter a valid number.\n");
            weightAttempts++;  // Increment attempt counter
        }
    }

    // If user failed to input weight after 5 attempts, exit the program
    if (weightAttempts == 5) {
        printf("Too many invalid attempts for weight. Goodbye!\n");
        return 0;
    }

    // Ask user what planet they are traveling to.
    while (planetAttempts < 5) {
        printf("What planet are you traveling to? \n");
        scanf("%10s", planet);  // Limit user input to 10 characters

        // Convert the input planet name to uppercase
        for (int i = 0; planet[i]; i++) {
            planet[i] = toupper(planet[i]);  // Makes all characters in the name of the planet uppercase
        }

        // Check if the planet is valid, if strings are equal then it strcmp is 0
        if (strcmp(planet, "MERCURY") == 0 || strcmp(planet, "VENUS") == 0 ||
            strcmp(planet, "MARS") == 0 || strcmp(planet, "JUPITER") == 0 ||
            strcmp(planet, "SATURN") == 0 || strcmp(planet, "URANUS") == 0 ||
            strcmp(planet, "NEPTUNE") == 0) {
            break;  // Valid planet input, exit loop
        } else {
            printf("Sorry, I don't recognize that planet. Please enter a valid planet name.\n");
            planetAttempts++; // Increment planet attempt counter
        }
    }

    // If user failed to input a valid planet after 5 attempts, exit the program
    if (planetAttempts == 5) {
        printf("Too many invalid attempts for planet. Goodbye!\n");
        return 0;
    }

    // Print the planet they chose
    printf("The planet you chose is %s! \n", planet);

    // Calculate the weight based on the planet's gravity
    if (strcmp(planet, "MERCURY") == 0) { //strcmp is string compare
        weight = weight * 0.38;
        printf("On Mercury you weigh %.2f pounds.\n", weight);
    } else if (strcmp(planet, "VENUS") == 0) {
        weight = weight * 0.91;
        printf("On Venus you weigh %.2f pounds.\n", weight);
    } else if (strcmp(planet, "MARS") == 0) {
        weight = weight * 0.38;
        printf("On Mars you weigh %.2f pounds.\n", weight);
    } else if (strcmp(planet, "JUPITER") == 0) {
        weight = weight * 2.34;
        printf("On Jupiter you weigh %.2f pounds.\n", weight);
    } else if (strcmp(planet, "SATURN") == 0) {
        weight = weight * 1.06;
        printf("On Saturn you weigh %.2f pounds.\n", weight);
    } else if (strcmp(planet, "URANUS") == 0) {
        weight = weight * 0.92;
        printf("On Uranus you weigh %.2f pounds.\n", weight);
    } else if (strcmp(planet, "NEPTUNE") == 0) {
        weight = weight * 1.19;
        printf("On Neptune you weigh %.2f pounds.\n", weight);
    }

    return 0;
}
