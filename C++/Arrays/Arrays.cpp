#include <iostream>
#include <ctime>

using namespace std;
void InitArray(int*, size_t size);
void PrintArray(int*, size_t size, const char* str);
void Processing_Array(int a[], int size);
int* Is_subset(int* , int* , int size_a, int size_b);
int BinarySearch(int*, size_t, int);
void InsertSort(int*, size_t);
int MinArray(int*, size_t);
int main()
{
    {//задание 1
        cout << "Task 1" << endl;
        int Size;
        cout << "Enter size of array" << endl;
        cin >> Size;
        int* Array = new int[Size];
        cout << "Enter array" << endl;
        for (int i = 0; i < Size; i++)
        {
            cin >> Array[i];
        }

        for (int i = 0; i < Size; i++) {
            int count = 0;
            for (int j = 0; j < Size; j++)
            {
                if (Array[i] == Array[j])
                    count++;
            }

            if (count % 2 != 0)

            {
                cout << Array[i] << endl;
                break;
            }
        }
    }
    {
        //задание 2
        cout << "Task 2" << endl;
        int Size;
        cout << "Enter size of array" << endl;
        cin >> Size;
        int* Array = new int[Size];
        cout << "Enter array" << endl;
        for (int i = 0; i < Size; i++)
        {
            cin >> Array[i];
        }
        PrintArray(Array, Size, "Initial Array\n");
        int proizv = 1, a1, a2, a3;
        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Size; j++)
            {
                for (int k = 0; k < Size; k++)
                {
                    if (k != j && i != k && j != i && Array[i] * Array[j] * Array[k] > proizv) {
                        a1 = Array[i];
                        a2 = Array[j];
                        a3 = Array[k];
                        proizv = Array[i] * Array[j] * Array[k];
                    }
                }
            }
        }
        cout << "Numbers that are multiplied to the maximum" << a1 << " " << a2 << " " << a3 << endl;
        delete[]Array;

    }
    {
        //задание 3
        cout << "Task 3" << endl;
        int Size1, Size2, Size_new, Size_c;
        cout << "Enter Size of Array 1 and 2\n";
        cin >> Size1 >> Size2;
        if (Size1 > Size2) {
            Size_new = Size1;
        }
        else { Size_new = Size2; }
        Size_c = Size1 + Size2 - 1;
        int* Array1 = new int[Size1];
        int* Array2 = new int[Size2];
        int* Array_new1 = new int[Size_new];
        int* C = new int[Size_c];
        cout << "Enter array 1" << endl;
        for (int i = 0; i < Size1; i++)
        {
            cin >> Array1[i];
        }
        cout << "Enter array 2" << endl;
        for (int i = 0; i < Size2; i++)
        {
            cin >> Array2[i];
        }
        Size1 = Size_new;
        Size2 = Size_new;
        cout << Size_new << endl;
        for (int i = 0; i <= Size_new; i++)
        {
            Array_new1[i] = Array1[i] + Array2[i];
        }
        for (int i = 0; i <= Size1; i++)
        {
            for (int j = 0; j <= Size2; j++)
            {
                C[i + j] += (Array1[i] * Array2[j]);
            }
        }
        PrintArray(Array_new1, Size_new, "New array summa ");
        PrintArray(C, Size_c, "New array product ");
        delete[]Array1;
        delete[]Array2;
    }
    {
        //задание 4
        cout << "Task 4" << endl;
        int Size;
        cout << "Enter size of array" << endl;
        cin >> Size;
        int* Array = new int[Size];
        cout << "Enter array" << endl;
        for (int i = 0; i < Size; i++)
        {
            cin >> Array[i];
        }
        Processing_Array(Array, Size);
        PrintArray(Array, Size, "Sorted Array\n");
        delete[]Array;
    }
    {
        //задание 5
        cout << "Task 5" << endl;
        const size_t maxSize = 100;
        int a[maxSize];
        int size;
        cout << "Enter size: " << endl;
        cin >> size;
        cout << "Enter elements: " << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
        PrintArray(a, size, "Array  ");
        InsertSort(a, size);
        PrintArray(a, size, "Sorted array:");

        int minDifference = 1000000000;
        for (int i = 1; i < size; i++)
        {
            if (a[i] - a[i - 1] < minDifference)
            {
                minDifference = a[i] - a[i - 1];
            }
        }
        int i = 1;
        while (i < size)
        {
            int difference = a[i] - a[i - 1];
            if (difference % minDifference != 0)
            {
                int delitel = 2;
                while (minDifference % delitel != 0)
                {
                    if (delitel == 2)
                    {
                        delitel++;
                    }
                    else
                    {
                        delitel += 2;
                    }
                }
                minDifference /= delitel;
                i = 0;
            }
            i++;
        }
        for (int i = a[0]; i <= a[size - 1]; i += minDifference)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    {
        //задание 6
        cout << "Task 6" << endl;
        int size;
        cout << "Enter size\n";
        cin >> size;
        int* Array = new int[size];
        cout << "Enter array\n";
        for (int i = 0; i < size; i++) {
            cin >> Array[i];
        }
        int size_new = size;
        for (int i = 0; i < size; i++) {
            int* Array_new = new int[size_new];
            for (int j = 0; j < size_new; j++) {
                Array_new[j] = Array[i + j];
            }
            for (int ii = 0; ii < size_new; ii++) {
                if (Array_new[ii] == MinArray(Array_new, size_new)) {
                    swap(Array[i], Array[i + ii]);
                    break;
                }
            }
            size_new--;
        }
        for (int i = 0; i < size; i++) {
            std::cout << Array[i] << " ";
        }
        {
            //задание 7
            cout << "Task 7" << endl;
            int Size;
            cout << "Enter size of array" << endl;
            cin >> Size;
            int* Array = new int[Size];
            srand(static_cast<size_t>(time(0)));
            InitArray(Array, Size);
            PrintArray(Array, Size, "Initial Array\n");
            InsertSort(Array, Size);
            PrintArray(Array, Size, "Sorted Array\n");
            delete[]Array;
        }
        {
            //задание 8
            cout << "Task 8" << endl;
            int Size1;
            cout << "Enter size of array1" << endl;
            cin >> Size1;
            int* Array1 = new int[Size1];
            cout << "Enter array1\n";
            for (int i = 0; i < Size1; i++) {
                cin >> Array1[i];
            }
            int Size2;
            cout << "Enter size of array2" << endl;
            cin >> Size2;
            int* Array2 = new int[Size2];
            cout << "Enter array2\n";
            for (int i = 0; i < Size2; i++) {
                cin >> Array2[i];
            }
            cout<<Is_subset(Array1, Array2, Size1, Size2)<<endl;
            delete[]Array1;
            delete[]Array2;
        }
        system("pause");
        return 0;
    }
}

void InitArray(int* a, size_t size) //функция для создания рандомного массива
{
    for (size_t i = 0; i < size; i++)
    {
        a[i] = rand() % 10 + 1;
    }
}

void PrintArray(int* a, size_t size, const char* str)//функция для вывода массива на консоль
{
    cout << str;
    for (size_t i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << std::endl;
}
void Processing_Array(int a[], int size) { //задание 4
    int min = a[0];
    int mini = 0;
    int i;
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            mini = i;
        }
    }
    cout << "Index min=" << mini << endl;
    for (int i = 1; i < mini; ++i)
    {
        for (int r = 0; r < mini - i; r++)
        {
            if (a[r] < a[r + 1])
            {
                int temp = a[r];
                a[r] = a[r + 1];
                a[r + 1] = temp;
            }
        }
    }
    for (int i = mini + 1; i < size; i++) {
        for (int j = i; j < size - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int* Is_subset(int* a, int* b, int size_a, int size_b) { //функция, определяющая является ли множество В подмножеством А
    int i;
    int* res;
    for (i = 0; i < size_a; i++) {
        int j = i, k = 0;
        while (j < size_a && k < size_b && b[k] == a[j]) {
            j++;
            k++;
        }if (k == size_b)
        {
            return res = a + i;
        }
        return nullptr;
    }
}
int BinarySearch(int* a, size_t size, int key) //задание 7
{
    int l = 0, r = size;
    int m = (l + r) / 2;
    while (l < r)
    {
        if (a[m] < key)
        {
            l = m + 1;
        }
        else if (a[m] > key)
        {
            r = m;
        }
        else
        {
            return m;
        }
        m = (l + r) / 2;
    }
    return l;
}
void InsertSort(int* a, size_t size) //задание 7
{
    for (int i = 1; i < size; i++)
    {
        int position = BinarySearch(a, i, a[i]);
        int temp = a[i];
        for (int j = i; j >= position; j--)
        {
            a[j] = a[j - 1];
        }
        a[position] = temp;
    }
}
int MinArray(int* a, size_t size) //задание 6
{
    int min = 0;
    for (int i = 0; i < size; i++) {
        if (a[min] > a[i]) {
            min = i;
        }
    } 
    return a[min];
}
