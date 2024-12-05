#include <stdio.h>

int main() {

  int appleQuantity = 23;
  float applePrice;
  // Review score we want to display to users
  int appleReviewDisplay = 82.5;
  // Helps us to know where the apples are in the store, read-only variable
  const char appleLocation = 'F';
  applePrice = 1.49;

  float appleReview = 90;
  // Cast through redundant
  appleReviewDisplay = (float)appleReview;

printf("An apple costs: $%.2f, there are %d in inventory found in section: %c and your customers gave it an average review of %d%%!", applePrice, appleQuantity, appleLocation, appleReviewDisplay);

}
