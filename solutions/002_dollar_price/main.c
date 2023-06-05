#include <stdio.h>

// Days included in the month
#define MONTH_DAYS 30

int main() {
  float month_prices[MONTH_DAYS];
  float highest_price;

  for (size_t i = 0; i < MONTH_DAYS; i++) {
    // Retrieve price for current day
    float dollar_price = 0.00;
    printf("Dollar Price for the %lu day of the month: ", i + 1);
    scanf("%f", &dollar_price);

    month_prices[i] = dollar_price;

    if (i == 0) {
      // This is the first iteration
      highest_price = dollar_price;
    } else {
      if (dollar_price > highest_price) {
        highest_price = dollar_price;
      }
    }
  }

  printf("The highest price was: %.2f\n", highest_price);

  return 0;
}
