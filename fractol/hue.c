#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int	*huetorgb(int hue, double r, double g, double b)
{
    double h;
    double c;
    double x;

    hue = hue % 360;
    h = hue / 60.0;
    c = 1.0;
    x = c * (1.0 - fabs(fmod(h, 2) - 1.0));

    r = (h >= 1 && h < 2) || (h >= 4 && h < 5) ? x : ((h >= 0 && h < 1) || (h >= 5 && h < 6) ? c : r);
    g = (h >= 3 && h < 4) || (h >= 0 && h < 1) ? x : ((h >= 1 && h < 2) || (h >= 2 && h < 3) ? c : g);
    b = (h >= 5 && h < 6) || (h >= 2 && h < 3) ? x : ((h >= 3 && h < 4) || (h >= 4 && h < 5) ? c : b);
    /*if (h >= 0 && h < 1)
    {
        r = c;
        g = x;
    } else if (h >= 1 && h < 2)
    {
        r = x;
        g = c;
    } else if (h >= 2 && h < 3)
    {
        g = c;
        b = x;
    } else if (h >= 3 && h < 4)
    {
        g = x;
        b = c;
    } else if (h >= 4 && h < 5)
    {
        r = x;
        b = c;
    } else if (h >= 5 && h < 6)
    {
        r = c;
        b = x;
    }*/
    int *rgb = malloc(sizeof(int) * 3);
    rgb[0] = (int)(r * 255);
    rgb[1] = (int)(g * 255);
    rgb[2] = (int)(b * 255);
    return rgb;
}

int main()
{
    int i = 0;
    while (i <= 360)
    {
    	int *rgb = huetorgb(i, 0, 0, 0);
    	printf("Hue: %d -> RGB: (%d, %d, %d)\n", i, rgb[0], rgb[1], rgb[2]);
	free(rgb);
	i++;
    }
    return 0;
}
