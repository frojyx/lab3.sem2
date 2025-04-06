#include "functions.h"

binary* secureBinaryMemoryAllocation()
{
    binary* array = NULL;
    array = (binary*)malloc(1 * sizeof(binary));
    if (array == NULL)
    {
        printf("\nMemory allocation error, program terminated!\n");
        exit(EXIT_FAILURE);
    }
    return array;
}

binary* secureBinaryMemoryReallocation(binary* array, int size)
{
    binary* new_array = (binary*)realloc(array, size * sizeof(binary));
    if (new_array == NULL)
    {
        printf("\nMemory allocation error, program terminated!\n");
        exit(EXIT_FAILURE);
    }
    return new_array;
}

binary* ConvertIntegerToBinary(int number)
{
    binary* array =  secureBinaryMemoryAllocation();
    for (int index = 0; index < 32; index++)
    {
        array = secureBinaryMemoryReallocation(array, index + 1);
        array[index].bit = number >> index;
    }
    return array;
}

void ShiftNumber(binary *array)
{
    for (int i = 1; i < 32; i++)
    {
        array[i-1].bit = array[i].bit;
    }
}

int ConvertBinaryToInteger(binary *array )
{
    int res = 0;
    for (int index = 0; index < 32; index++)
    {
        res += array[index].bit * powerOfTwo(index);
    }
    return res;
}

int powerOfTwo(int exponent)
{
    int result = 1;
    for (int index = 0; index < exponent; index++)
        result *= 2;
    return result;
} 

void Task1()
{
    printf("\n");
    int number;
    printf("Введите число:\n");
    integerVerification(&number);
    binary* array = secureBinaryMemoryAllocation();
    if (number >= 0){
        array = ConvertIntegerToBinary(number);
        ShiftNumber(array);
        number = ConvertBinaryToInteger(array);
        printf("\nВаше число :\n%d\n", number);
    }
    else {
        array = ConvertIntegerToBinary(-number);
        ShiftNumber(array);
        number = ConvertBinaryToInteger(array);
        printf("\nВаше число :\n%d\n", -number);
    }
    free(array);
}


