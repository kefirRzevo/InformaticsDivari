bool comp(int x, int y);
void BubbleSort(int a[], int size, bool comparator(int x, int y));
void print(int a[], int size);
int* generate(int n);


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
            if (comparator(a[j - 1], a[j]))
            {
                int t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
                n = j;
            }
        size = n;
    }
}

void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int* generate(int n)
{
    int* mas =(int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 100;
    }
    BubbleSort(mas, n, comp);
    print(mas, n);
    return mas;
}