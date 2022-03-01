#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int r, int mid)
{
	int n1 = mid + 1;
	int n2 = r - mid;
	int a[n1];
	int b[n2];
	for (int i = 0; i < n1; i++)
	{
		a[i] = arr[l + i];
	}
	for (int i = 0; i < n2; i++)
	{
		b[i] = arr[i + mid + 1];
	}
	int k = l;
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (a[i] < b[j])
		{
			arr[k] = a[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = b[j];
			j++;
			k++;
		}
	}
	while (i < n1)
	{
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
}
void mergesort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		merge(arr, l, r, mid);
	}
}
int main()
{
	int arr[] = {5, 4, 3, 2, 1};
	mergesort(arr, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}