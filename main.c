#include <stdio.h>
#include <stdlib.h>

typedef struct ellipse_s
{
    int cx;
    int cy;
    int rx;
    int ry;
    char fill[10];
} ellipse_t;


int main(void)
{

    ellipse_t ellipse = {100, 50, 100, 50, "red"};
    ellipse_t ellipse2 = {100, 50, 50, 25, "black"};
    
    char viewport[] = "<svg viewBox='0 0 200 100' xmlns='http://www.w3.org/2000/svg'>\n";
    char end_viewport[] = "\n</svg>";

    FILE *write_file = fopen("test.svg", "w");

    if (fprintf(write_file, "%s", viewport) &&
    fprintf(write_file, "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' fill='%s' />", ellipse.cx, ellipse.cy, ellipse.rx, ellipse.ry, ellipse.fill) &&
    fprintf(write_file, "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' fill='%s' />", ellipse2.cx, ellipse2.cy, ellipse2.rx, ellipse2.ry, ellipse2.fill) &&
    fprintf(write_file, "%s", end_viewport) <0) {
        printf("Something went wrong");
    }
    
    fclose(write_file);
    
    return 0;
}