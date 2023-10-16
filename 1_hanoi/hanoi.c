#include <stdio.h>
#include <stdlib.h>

int hanoi(int from, int mid, int to, int disk)
{
    if (disk == 1) 
    {
        printf("Move %d to %d\n", from, to);
        return 0;
    }
    
    hanoi(from, to, mid, disk-1);
    printf("Move %d to %d\n", from, to);
    hanoi(mid, from, to, disk-1);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Correct Usage : [program] [number of disks]\n");
        return 0;
    }

    int disk = atoi(argv[1]);
    if (disk == 0) return 0;
    else hanoi(1, 2, 3, disk);
}