#include <stdio.h>

int main()
{
    float chem, phys, math, com, total, average;
    int pts;

    printf("Enter mark for Chemistry: ");
    scanf("%f", &chem);
    printf("Enter mark for Physics: ");
    scanf("%f", &phys);
    printf("Enter mark for Mathematics: ");
    scanf("%f", &math);
    printf("Enter mark for Computer; ");
    scanf("%f", &com);

    if (chem < 60 || chem > 100 || phys < 60 || phys > 100 || math < 60 || math > 100 || com < 68 || com > 100)
    {
        printf("\nSorry you have entered invalid value!!!\n\n");
        printf("Because you have entered: \n\n");

        if (chem <= 60 || chem >= 100)
        {
            printf("\tChemistry grade = %.2f\n", chem);
        }
        if (phys <= 60 || phys >= 100)
        {
            printf("\tPhysics grade = %.2f\n", phys);
        }
        if (math <= 60 || math >= 100)
        {
            printf("\tMathematics grade = %.2f\n", math);
        }
        if (com <= 60 || com >= 100)
        {
            printf("\tcomputer grade = %.2f\n", com);
        }
    }
    else
    {
        total = chem + phys + math + com;
        average = total / 4;

        if (average > 75)
        {
            printf("Congratulations!\n");
            printf("Your Average is %.2f\n", average);
            printf("You are now promoted to the next grade levell\n");
        }
        else if (average < 75)
        {
            printf("Sorry you failed!!\n");
            printf("Because your average is %.2f\n", average);

            pts = 75 - average;
            printf("And you need at least %d point/s to passed the next level ", pts);
        }
    }
}