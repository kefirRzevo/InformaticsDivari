#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool comp(int x, int y);
void BubbleSort(int a[], int size, bool comparator(int x, int y));
void InsertionSort(int a[], int size, bool comparator(int x, int y));
void SelectionSort(int a[], int size, bool comparator(int x, int y));
void print(int a[], int size);

bool comp(int x, int y)
{
    if(x > y)
        return true;
    else
        return false;
}

void BubbleSort(int a[], int size, bool comparator(int x, int y))
{
    int n;
    while(size)
    {
        n = 0;
        for (int j = 1; j < size; j++)
            if (comparator(a[j-1], a[j]))
            {
                int t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
                n = j;
            }
        size = n;
    }
}
void InsertionSort(int a[], int size, bool comparator(int x, int y))
{
    int i = 0, j = 0;
    double number = 0;

    for (i = 1; i < size; i++)
    {
        number = a[i];
        for (j = i - 1;; j--)
        {
            if (comparator(a[j], number))
            a[j + 1] = a[j];
            else
            {
                a[j + 1] = number;
                break;
            }
         
            if (j == 0)
            {  
                if (comparator(a[j], number))
                    a[0] = number;
                break;
            }
      }
   }
}

void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void SelectionSort(int a[], int size, bool comparator(int x, int y))
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (comparator(a[j-1], a[j]))
                min = j;
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int n;
    printf("Enter massiv's size \n");
    scanf("%d", &n);

    int mas[n];
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 100 - 50;
        printf("%d ", mas[i]);
    }
    printf("\n");

    BubbleSort(mas, n, comp);
    print(mas, n);

    InsertionSort(mas, n, comp);
    print(mas, n);

    SelectionSort(mas, n, comp);
    print(mas, n);
    return 0;
}