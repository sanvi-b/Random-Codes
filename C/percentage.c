#include <stdio.h>
void main ()
{
    float sub1,sub2,sub3,sub4,sub5;
    float percentage;
    printf ("Enter marks for five subjects out of 40:");
    scanf ("%f%f%f%f%f", &sub1, &sub2, &sub3, &sub4, &sub5);
    percentage= ((sub1+sub2+sub3+sub4+sub5)/200)*100;
    printf ("The percentage is %f",percentage);
}
