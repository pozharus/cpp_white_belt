/*
 * SearchRepNegNum.c
 *
 * Created: 21.05.2020 17:32:11
 * Author : Yaroslav;
 */

#include <stdlib.h>
#include <stdio.h>
#define ARRAY_LENGTH 1200


int SearchAndRepNegNum(int *num_array, int array_lenght) {
    int count = 0;
    for(int j = 0; j < array_lenght; j++) {
        if(num_array[j] < 0) {
            num_array[j] = abs(num_array[j]);
            ++count;
        }
    }
    return count;
}

int* CreateArrAndAllocMem(int array_lenght) {
    int* num_array;
    if(array_lenght <= 400) {
        num_array= (int*)malloc(array_lenght * sizeof(int)); //Выделяем память под ARRAY_LENGTH элементов;
        return num_array;
    } else {
        num_array = NULL;
        return NULL;
    }
}

void FillArray(int *num_array, int array_lenght) {
    for(int i = 0; i < array_lenght; i++) { /*Заполняем массив случайными числами в диапазоне int16_t;*/
        num_array[i] = rand()%20000-10000;
    }
}

void FreeMem(const *num_array) {
    free(*num_array);
}

void PrintArr(int *num_array, int array_lenght) {
    for(int i = 0; i < array_lenght; i++) {
        printf("%i", num_array[i]);
        printf("%s", " ");
    }
    printf("%s", "End of Array  ");
}


int main(void)
{

    int* num_array= CreateArrAndAllocMem(ARRAY_LENGTH);

    if(num_array == NULL) {
        return 1;
    }

    FillArray(num_array, ARRAY_LENGTH);

    PrintArr(num_array, ARRAY_LENGTH);

    int negNum = SearchAndRepNegNum(num_array, ARRAY_LENGTH);

    PrintArr(num_array, ARRAY_LENGTH);

    printf("%s", "Count of replace: ");
    printf("%i", negNum);

    FreeMem(num_array);

    return 0;

}
