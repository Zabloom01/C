#include <stdio.h>

int main() {
  
    int appleQuantity;
    double applePrice = 1.49;
    double appleReview;
    int appleReviewDisplay;
    const char appleLocation = 'F';
    // 0 represents Sunday
    int dayOfWeek = 0;
    // Add 3 days from Sunday
    dayOfWeek = (dayOfWeek + 3) % 7;  // This ensures dayOfWeek stays within 0-6

    // Controls the average reviews
    int newReview = 52;
    // Total review score is 823 and then any new review will +/- the average review percent
    appleReview = (823.0 + newReview) / 10;  // Float division to avoid truncation
    appleReviewDisplay = appleReview;  // This will truncate the double to an integer

    // Conditions that control if statement
    appleQuantity = 23;

    // If apple quantity is less than 10 OR it is the fourth day of the week
    // since the fourth day typically has lower sales of apples than any other day
    if(appleQuantity < 10 || dayOfWeek == 3) {
        printf("Sale on apples today, today only they are: $%.2f\n", applePrice * .9);
    }

    // Put all your code above this and if you declare your variables using the given names and types 
    // there is no need to change any of the code below.
    printf(
        "An apple costs: $%.2f, there are %d in inventory found in section: %c and your customers gave it an average review of %d%%!", 
        applePrice, appleQuantity, appleLocation, appleReviewDisplay
    );

    return 0;
}
