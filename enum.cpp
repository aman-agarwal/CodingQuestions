#include <cstdio>

int main(int argc, char **argv)
{
    enum color_t {RED, GREEN, YELLOW, BLUE};
    color_t color;
 
    color = GREEN;
    printf("%d\n", color);

    return 0;
}
