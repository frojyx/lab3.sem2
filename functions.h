#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <limits.h>
#include <ctype.h>

#define RED "\033[31m"   
#define END "\033[0m"    
#define ENTER 13        
#define INT_LIMIT 10     

typedef struct
{
    unsigned int bit : 1;
} binary;

typedef struct {
    char* NumCheck;
    int sum;
}BankData;

typedef struct {
    int number;
    char* lastname;
    BankData info;
}client;

binary* secureBinaryMemoryAllocation();
binary* secureBinaryMemoryReallocation(binary* array, int size);
binary* ConvertIntegerToBinary(int number);
client* secureClientMemoryAllocation();

int ConvertBinaryToInteger(binary* array);
void InputClients(int *countClients, client** p);
void ShiftNumber(binary* array);
void Task1();
void Task2();
void countCheckOfPerson(int countClients, client* p,int * countCheck);
void DeleteClients(client* arr, int *countClients);
void Task2Menu(client* arr, int *   countClients, int countCheck);
void AddClient(int* countClients, client** arr);
void FreeClients(client* arr, int countClients);
int PassportVerification();
char* LastNameVerification();
int CountClientsAndSumVerification(int* value, int min, int max);
char* NumCheckVerification();
int integerVerification(int* value);
