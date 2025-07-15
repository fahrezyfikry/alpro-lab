// Group 2:
// 2802658250 - Hasbi Rajab Assadiqi
// 2802669746 - Yosua Maranatha Siahaan
// 2802663931 - Septia Dini Rahayu
// 2802658263 - Fikry Fahrezy Ramadhan
// 2802680225 - Ranidya Putri Hantari

#include <stdio.h>

int main() {
    printf("Enter payment amount: ");

    float payment;
    scanf("%f", &payment);

    int discount_multiplier = 5;
    int discount_base = 100000;
    int discount_coupon = payment / discount_base;
    printf("Discount Coupon QTY: %d\n", discount_coupon);

    int discount = discount_coupon * discount_multiplier;
    printf("Discount: %d\n", discount);

    float discount_percentage = (float) discount / (float) 100;
    printf("Discount Percentage: %.2f\n", discount_percentage);

    float discount_amount = (payment * discount_percentage);
    printf("Discount amount: %.2f\n", discount_amount);

    float final_payment = payment - discount_amount;
    printf("Final payment amount: %.2f\n", final_payment);

    return 0;
}
