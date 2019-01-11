#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "os2.h"
#include <pthread.h>

int **to_build_matr(int number)
{
    int const n = number;
    int **A;
    int i = 1, j = 0, k, p = n / 2;

    A = (int**)malloc(sizeof(int*) * n);
    while (j < n)
    {
        A[j] = (int*)malloc(sizeof(int) * n);
        j++;
    }
    for (k = 1; k <= p; k++) {
        for (j = k - 1; j < n - k + 1; j++)
            A[k - 1][j] = i++;
        for (j = k; j < n - k + 1; j++)
            A[j][n - k] = i++;
        for (j = n - k - 1; j >= k - 1; --j)
            A[n - k][j] = i++;
        for (j = n - k - 1; j >= k; j--)
            A[j][k - 1] = i++;
    }
    if (n % 2 == 1)
        A[p][p] = n * n;
    return (A);
}

int main(void)
{
    int **matr;
    int count_of_ints = 50;
    int arr_int[count_of_ints];
    int fd = open("/home/echufy/CLionProjects/os2_process/test_process.txt",  O_WRONLY|O_CREAT);;
    double start_time, end_time;
    int i = -1;

    while (++i < count_of_ints)
        arr_int[i] = rand() / 80000000;
    i = 0;
    fork();
    while (i < count_of_ints)
    {
        start_time = getCPUTime();
//        dprintf(fd, "PID : %d, для числа : %d\n", getpid(), arr_int[i]);
        matr = to_build_matr(arr_int[i]);
//        for (int j = 0; j < arr_int[i]; j++)
//        {
//            for (int k = 0; k < arr_int[i]; k++)
            //    dprintf(fd, " %4d ", matr[j][k]);
          //  dprintf(fd, "\n");
//        }
        //dprintf(fd, "\n\n\n\n");
        end_time = getCPUTime();
        dprintf(fd, "for process with number : %d the speaad is %f\n\n\n", arr_int[i],end_time - start_time);
        i++;
        sleep(1);
    }
    sleep(20);
    return (0);
}