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

//специальная структура для данных потока
typedef struct
{
    int fd;
    int number;
    int pid;
    double start_time;
    int **matr;
    double end_time;
}       pthrData;

void* threadFunc(void* thread_data)
{
    pthrData *data = (pthrData*) thread_data;
    int n = data->number;

    dprintf(data->fd, "thread for number :%d\n", data->number);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dprintf(data->fd, " %4d ", data->matr[i][j]);
        dprintf(data->fd, "\n");
    }
    dprintf(data->fd, "\n\n\n\n");
    return NULL;
}

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
    int count_of_ints = 45;
    int arr_int[count_of_ints];
    pthread_t* threads = (pthread_t*) malloc(sizeof(pthread_t) * count_of_ints);
    pthrData* threadData = (pthrData*) malloc(sizeof(pthrData) * count_of_ints);
    int fd = open("/home/echufy/CLionProjects/os2_thread/test_thread.txt",  O_WRONLY|O_CREAT);;

    for(int i = 0; i < count_of_ints; i++)
        arr_int[i] = rand() / 80000000;
    for(int i = 0; i < count_of_ints; i++)
    {
        threadData[i].fd = fd;
        threadData[i].number = arr_int[i];
        threadData[i].start_time = getCPUTime();
        threadData[i].pid = getpid();
        threadData[i].matr = to_build_matr(arr_int[i]);
        threadData[i].end_time = getCPUTime();
        pthread_create(&(threads[i]), NULL, threadFunc, &threadData[i]);//запускаем потоk
    }
    for(int i = 0; i < count_of_ints; i++)
        pthread_join(threads[i], NULL); // ожидаем выполнения всех потоков
    for (int i = 0; i < count_of_ints; i++)
        dprintf(threadData[i].fd, "for thread with number %d the speed is %f\n",
                threadData[i].number, threadData[i].end_time - threadData[i].start_time);
    for(int i = 0; i < count_of_ints; i++)
        free(threadData[i].matr); //освобождаем память
    free(threads);
    free(threadData);
    return 0;
}



/////ДЛЯ ПРОЦЕССОВ

//int main(void)
//{
//    int **matr;
//    int count_of_ints = 20;
//    int arr_int[count_of_ints];
//    int fd = open("/home/echufy/CLionProjects/os2/test.txt",  O_WRONLY|O_CREAT);;
//    double start_time, end_time;
//    int i = 0;
//
//    while (i < count_of_ints)
//    {
//        arr_int[i] = rand() / 80000000;
////        printf("%d\n", arr_int[i]);
//        i++;
//    }
//    i = 0;
//    fork();
//    while (i < count_of_ints)
//    {
//        start_time = getCPUTime();
//        dprintf(fd, "PID : %d, для числа : %d\n", getpid(), arr_int[i]);
//        matr = to_build_matr(arr_int[i]);
//        for (int j = 0; j < arr_int[i]; j++)
//        {
//            for (int k = 0; k < arr_int[i]; k++)
//                dprintf(fd, " %4d ", matr[j][k]);
//            dprintf(fd, "\n");
//        }
//        dprintf(fd, "\n\n\n\n");
//        end_time = getCPUTime();
//        dprintf(fd, "%f\n\n\n", end_time - start_time);
//        i++;
//        sleep(1);
//    }
//    sleep(20);
//    return (0);
//}