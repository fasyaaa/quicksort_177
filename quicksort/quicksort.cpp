#include<iostream>
using namespace std;


int arr[20];				// Array of integers to hold values
int cmp_count = 0;			// number of comparasion
int mov_count = 0;			// number of data movements
int n;

void input() {
	while (true) 
	{
		cout << "Masukkan panjang element array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
// swap the element at_index x with the element at index y

void swap(int x, int y)
{
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)						//langkah 1
		return;

	//partition the list isnto two parts
	//one containing element less that or equal to pivot
	//outher containing element

	pivot = arr[low];					//langkah 2

	i = low + 1;						//langkah 3
	j = high;							//langkah 4

	while (i <= j)						//langkah 10
	{
		//search for an element greather than pivot
		while ((arr[i] <= pivot) && (i <= high))			//langkah 5
		{
			i++;											//langkah 6
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))				//langkah 7
		{
			j--;											//langkah 8
			cmp_count++;
		}
		cmp_count++;
		//if the greater element is on the left the element
		if (i < j)											//langkah 9
		{
			//swap the element at index i with the eleement at index j 
			swap(i, j);
			mov_count++;
		}
	}

	//if j now containt the index of the last element in the sorted list
	if (low < j)											//langkah 11
	{
		//move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort of the list on the left pivot using quick sort
	q_short(low, j - 1);									//langkah 12

	//sprt the list on the right of pivot using quick sort
	q_short(j + 1, high);									//langkah 13
}

void display() 
{
	cout << "\n----------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n----------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\nNumber of comparasion: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}


int main()
{
	input();
	q_short(0, n - 1);							//sort the array using quick sort
	display();
	system("pause");

	return 0;
}

