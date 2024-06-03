#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//div, modf, fmod, trunc, found, ceil, floor, pow, rand, srand

int main(int argc, char*argv[])
{   
    div_t res = div(10, 3);
    printf("10/3 = (%d, %d)\n", res.quot, res.rem);

    double nr = 2.2;
    double i;
    double rem = modf(nr, &i);
    printf("%lf = %lf + %lf\n", nr, i + rem);

    rem = fmod(10.1, 3.0);
    printf("10.1%3.0 = %lf\n", rem);

    double x = 4.4;
    double y = round(x);
    double z = ceil(x);
    double u = floor(x);
    double v = trunc(x);

    printf("round, ceil, floor, trunc = %lf, %lf, %lf, %lf\n", y, z, u, v);

    srand(time(NULL));
    x = (double)(rand()%20);
    printf("%lf^2 = %lf\n", x, pow(x,2.0));

    printf("\nDone.\n");
    return 0;
}