#include < iostream >
using namespace std;

namespace nmBinSrch
{
	
	
template<typename T>
class ISort
{
public:
	virtual void SortArr(T* coll, int size) = 0;
};

template<typename T,int size>
class ArrayContainer
{
	T* ar;
	ISort<T>* srt;
public:
	ArrayContainer(T* ar):ar(ar),srt(NULL)
	{
	}
	void SetSort(ISort<T>* srt)
	{
		this->srt = srt;
	}
	void Sort()
	{
		if (srt != NULL) {
			this->srt->SortArr(ar, size);
		}
	}

	void Display()
	{
		cout << "________________________________________\n";
		for (size_t i = 0; i < size; i++)
		{
			cout << ar[i] << ' ';
		}
		cout << "\n________________________________________\n";
	}
};



template<typename T>
class QuickSort :public ISort<T>
{
	int partition(T* coll, int low, int high)
	{
		int pivot = coll[low];
		int i = low, j = high;
		while (i <= j)
		{
			while (coll[i] <= pivot && i<=high)
			{
				i++;
			}
			while (coll[j] > pivot)
			{
				j--;
			}
			if (i < j)
			{
				swap(coll[i], coll[j]);
			}
		}
		swap(coll[low], coll[j]);
		return j;

	}
	void QSort(T* coll, int low, int high)
	{
		if (low < high)
		{
			
			int part = partition(coll, low, high);
			
			QSort(coll, low, part - 1);
			QSort(coll, part + 1, high);
		}
	}
public:
	void SortArr(T* coll, int size)
	{
		QSort(coll, 0, size - 1);
	}
};
	
	
    int binarySearch(int arr[], int left, int right, int x) {
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == x) {
                return mid;
            }
            else if (arr[mid] < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }

    int main() {
       
        int num;
        int output;

        // cout << "Please enter 10 elements ASCENDING order" << endl;
        // for (int i = 0; i < 10; i++) {
            // cin >> myarr[i];
        // }
		
		int arr[10] = {25, 5,10,2,15,1,20,3,30,4 };
		ArrayContainer<int, 10> cnt(arr);
		QuickSort<int> qSrt;
		cnt.SetSort(&qSrt);
		cnt.Sort();
		cnt.Display();
		
		
        cout << "Please enter an element to search" << endl;
        cin >> num;

        output = binarySearch(arr, 0, 9, num);

        if (output == -1) {
            cout << "No Match Found" << endl;
        }
        else {
            cout << "Match found at position: " << output << endl;
        }

        return 0;
    }

}