#include<stdio.h>
#include<math.h>

const double X_MIN = -1.0e+150;
const double X_MAX =  1.0e+150;
const double X_BORDER_LEFT  = -3.0;
const double X_BORDER_RIGHT =  3.0;

void printHeader();
void printValidation();
double inputNumber();
double calculateZ1(double x);
double calculateZ2(double x);

int main (void) {
    printHeader();
    printValidation();

    double x;

    printf("Please enter x:\n");
    x = inputNumber();

    printf("z1 = %lf\n", calculateZ1(x));
    printf("z2 = %lf\n", calculateZ2(x));

    return 0;
}

void printHeader () {
    printf("Variant:\t16\nAuthor:\t\tMykola Ponomarenko\n");
}

void printValidation() {
    printf("Range of permissible values: [%e;%.lf]u(%.lf;%e]\n", X_MIN, X_BORDER_LEFT, X_BORDER_RIGHT, X_MAX);
}

double inputNumber()
{
    double side;
    char check;

    do
    {
        if (scanf_s("%lf%c", &side, &check, 1) != 2 || check != '\n')
        {
            printf("Invalid number. Please, try again.\n");
            while (getchar() != '\n');
        }
        else
        {
            if (side < X_MIN || side > X_MAX || (side > X_BORDER_LEFT && side <= X_BORDER_RIGHT))
            {
                printValidation();
                check = 0;
            }
        }
    } while (check != '\n');

    printf("Your value was saved correctly.\n");
    return side;
}

double calculateZ1(double x) {
    return (pow(x, 2) + 2 * x - 3 + (x + 1) * sqrt(pow(x, 2) - 9)) /
        (pow(x, 2) - 2 * x - 3 + (x - 1) * sqrt(pow(x, 2) - 9));
}

double calculateZ2(double x) {
    return sqrt((x + 3) / (x - 3));
}