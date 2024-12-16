void quicksort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = arr[left];
    int i = left, j = right;

    while (i < j)
    {
        while (i < j && arr[j] <= pivot)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] >= pivot)
            i++;
        arr[j] = arr[i];
    }

    arr[i] = pivot;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

/*
Find the k-th largest element in an array
arr: the array
n: the size of the array
k: the k-th largest element
*/
int max_k(int arr[], int n, int k)
{
    quicksort(arr, 0, n - 1);
    return arr[k - 1];
}

int main()
{
    int arr[10] = {4, 1, 6, 8, 3, 2, 9, 7, 5, 0};
    int k = 3;
    return max_k(arr, 10, k);
}