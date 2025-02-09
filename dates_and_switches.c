#include <stdio.h>

int main(void) {
  int month, day, year;

  // Standard date form
  printf("Enter date (mm/dd/yyyy): ");
  // Split the user input into 3 variables for the date
  scanf("%d /%d /%d", &month, &day, &year);

  // Check if the month is valid
  if (month < 1 || month > 12) {
    printf("Invalid date\n");
    return 1;
  }

  // Check if the day is valid for the given month
  if ((month == 2 && (day < 1 || day > 29)) || // February
      ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) || // April, June, September, November
      (day < 1 || day > 31)) { // All other months
    printf("Invalid date\n");
    return 1;
  }

  // Print the month
  switch(month) {
    case 1:
      printf("January ");
      break;
    case 2:
      printf("February ");
      break;
    case 3:
      printf("March ");
      break;
    case 4:
      printf("April ");
      break;
    case 5:
      printf("May ");
      break;
    case 6:
      printf("June ");
      break;
    case 7:
      printf("July ");
      break;
    case 8:
      printf("August ");
      break;
    case 9:
      printf("September ");
      break;
    case 10:
      printf("October ");
      break;
    case 11:
      printf("November ");
      break;
    case 12:
      printf("December ");
      break;
  }

  // Print the day
  printf("%d", day);

  // Print the suffix for a given day
  switch(day) {
    case 1: case 21: case 31:
      printf("st");
      break;
    case 2: case 22:
      printf("nd");
      break;
    case 3: case 23:
      printf("rd");
      break;
    default:
      printf("th");
  }

  // Print the year
  printf(", %d\n", year);
  
  return 0;
}
