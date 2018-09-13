#include <stdio.h>

int main()
{
    int *data;
    int ROWS = 4;
    int COLS = 4;
    int worldMap[4][4] =
	{
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16},
	};
    int i;
    int j;
    data = &worldMap[0][0];
    for (i = 0; i < ROWS; i++) 
    {
        for (j = 0; j < COLS; j++) 
        {
            printf("%d ", *(data + i * COLS + j));
        }
    printf("\n");
    }
    return(0);
}