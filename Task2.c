#include "functions.h"

client* secureClientMemoryAllocation()
{
    client* array = NULL;
    array = (client*)malloc(1 * sizeof(client));
    if (array == NULL)
    {
        printf("\nMemory allocation error, program terminated!\n");
        exit(EXIT_FAILURE);
    }
    return array;
}

client* secureClientMemoryReallocation(client* array, int size)
{
    client* new_array = (client*)realloc(array, size * sizeof(client));
    if (new_array == NULL)
    {
        printf("\nMemory allocation error, program terminated!\n");
        exit(EXIT_FAILURE);
    }
    return new_array;
}

void InputClients(int *countClients,client **p)
{
    int temp;
    printf("Введите количество клиентов.\n");
    CountClientsAndSumVerification(&temp,0,100000);
    *countClients = temp;
    for (int i = 0; i < *countClients; i++)
    {
        *p = secureClientMemoryReallocation(*p, i + 1);
        printf("\nВведите данные %d клиента.\n", i + 1);
        printf("Введите номер паспорта.\n");
        (*p)[i].number = PassportVerification();
        printf("\nВведите фамилию клиента.\n");
        (*p)[i].lastname = LastNameVerification();
        printf("\nВведите номер счёта.\n");
        (*p)[i].info.NumCheck = NumCheckVerification();
        printf("\nВведите сумму вклада.\n");
        CountClientsAndSumVerification(&(*p)[i].info.sum, 0, 1000000);
        printf("\n");
    }
}

void OutputClients(int countClients, client* p)
{
    system("cls");
    for (int i = 0; i < countClients; i++)
    {
        printf("\nДанные %d клиента.\n", i + 1);
        printf("Номер паспорта:\n%d", p[i].number);
        printf("\nФамилия клиента:\n%s", p[i].lastname);
        printf("\nНомер счёта:\n%s", p[i].info.NumCheck);
        printf("\nСумма вклада:\n%d", p[i].info.sum);
        printf("\n");
    }
}

void countCheckOfPerson(int countClients, client* p,int * countCheck)
{
    int numPassport;
    int counter=0;
    printf("Задайте номер паспорта.\n");
    PassportVerification(&numPassport);
    for (int i = 0; i < countClients; i++)
    {
        if (numPassport == p[i].number) counter++;
    }
    *countCheck = counter;
}

void DeleteClients(client* arr,int *countClients)
{
    char* LastnameForDelete=NULL;
    printf("Задайте фамилию клиента.\n");
    LastnameForDelete = LastNameVerification();
    for (int i = 0; i < *countClients; i++)
    {
        if (strcmp(LastnameForDelete, arr[i].lastname) == 0)
        {
            free(arr[i].lastname);
            free(arr[i].info.NumCheck);
            for ( int j = i; j+1 < *countClients; j++)
            {
               arr[j].lastname = arr[j + 1].lastname;
               arr[j].number = arr[j + 1].number;
               arr[j].info.sum = arr[j + 1].info.sum;
               arr[j].info.NumCheck = arr[j + 1].info.NumCheck;
            }
            (*countClients)--;
            i--;
        }
    }
    free(LastnameForDelete);
}

void AddClient(int *countClients,client ** p)
{
    int temp;
    printf("Введите количество клиентов для дозаписи:\n");
    CountClientsAndSumVerification(&temp,0,100000);
    for (int i = (*countClients); i < (*countClients) + temp; i++)
    {
        *p = secureClientMemoryReallocation(*p, i + 1);
        printf("\nВведите данные %d клиента.\n", i + 1);
        printf("Введите номер паспорта.\n");
        (*p)[i].number = PassportVerification();
        printf("\nВведите фамилию клиента.\n");
        (*p)[i].lastname = LastNameVerification();
        printf("\nВведите номер счёта.\n");
        (*p)[i].info.NumCheck = NumCheckVerification();
        printf("\nВведите сумму вклада.\n");
        CountClientsAndSumVerification(&(*p)[i].info.sum, 0, 1000000);
        printf("\n");
    }
    (*countClients) += temp;
}

void FreeClients(client* arr, int countClients) {
    for (int i = 0; i < countClients; i++) {
        free(arr[i].lastname);
        free(arr[i].info.NumCheck);
    }
    free(arr);
}

void Task2()
{
    printf("\n");
    int countCheck=0;
    client* arr = secureClientMemoryAllocation();
    int countClients=0;
    Task2Menu(arr, &countClients, countCheck);
    FreeClients(arr, countClients);
}

void Task2Menu(client * arr,int *countClients,int countCheck) {

    int answer;
    do {
        answer = 0;
        printf("Выберите действие.");
        printf("\n+================================+\n1.Ввод клиентов.\n2.Дозапись клиентов.\n3.Вывод клиентов\n4.Количество счетов клиента.\n5.Удаление клиентов.\n6.Очистка консоли.\n7.Конец программы.\n+================================+\n\n");
        while (answer < '1' || answer > '7') answer = _getch();
        if (answer == '1') {
            InputClients(countClients, &arr);
        }
        else if (answer == '2') {
            AddClient(countClients, &arr);
        }
        else if (answer == '3') {
            OutputClients(*countClients, arr);
        }
        else if (answer == '4') {
            countCheckOfPerson(*countClients, arr, &countCheck);
            printf("Количество счетов у человека с данным номером паспорта %d\n\n", countCheck);
        }
        else if (answer == '5') {
            DeleteClients(arr, countClients);
            OutputClients(*countClients, arr);
        }
        else if (answer == '6') {
            system("cls");
        }
    } while (answer != '7');
}

