#include<iostream>
using namespace std;
int dp[100000],temp[100000];
void merge1(int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (dp[i] < dp[j])
		{
			temp[k] = dp[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = dp[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = dp[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = dp[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		dp[i] = temp[i-low];
	}
}
void MergeSort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(low, mid);
		MergeSort(mid+1, high);

		// Merge them to get sorted output.
		merge1(low, high, mid);
	}
}
int main()
{
    int size1;
    cin>>size1;
    for(int i=0;i<size1;i++)
    {
        cin>>dp[i];
    }
    MergeSort(0,size1-1);
    for(int i=0;i<size1;i++)
    {
        cout << dp[i] << " " ;
    }
    return 0;
}
