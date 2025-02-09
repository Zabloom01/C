#include <stdio.h>
#include <unistd.h> // Required for sleep function

int main() {
  int pin;
  int tries = 0;

  printf("BANK OF CODECADEMY:\n");

  while (1) {
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    tries++;

    if (pin == 1234) { // You could modify this code to allow user to set pin
      printf("PIN accepted\nYou now have access\n");
      break;
    }

    if (tries == 3) {
      printf("Sorry! Your account is locked for 1 minute\n");
      for (int i = 60; i > 0; i--) {
        printf("\rTime remaining: %d seconds", i);
        fflush(stdout);  // This prints the time immediately
        sleep(1); // 
      }
      printf("\n");
    } else if (tries == 4) {
      printf("Warning: All memory will be cleared if the wrong attempt is made again.\n");
      printf("Sorry! Your account is locked for 3 minutes\n");
      for (int i = 180; i > 0; i--) {
        printf("\rTime remaining: %d seconds", i);
        fflush(stdout);
        sleep(1);
      }
      printf("\n");
    } else if (tries >= 5) {
      printf("Too many incorrect attempts. Shutting down the program.\n");
      return 1;
    }
  }

  return 0;
}
