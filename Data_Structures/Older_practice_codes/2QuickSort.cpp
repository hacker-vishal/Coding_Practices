#include<iostream>
using namespace std;

namespace ass15
{

	template<typename T>
	class ISort
	{
	public:
		virtual void SortArr(T* coll, int size) = 0;
	};

	template<typename T, int size>
	class ArrayContainer
	{
		T* ar;
		ISort<T>* srt;
	public:
		ArrayContainer(T* ar) :ar(ar), srt(NULL)
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
				while (coll[i] <= pivot && i <= high)
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
	//-------------
	int main()
	{
		int arr[10] = { 25, 5,10,2,15,1,20,3,30,4 };
		ArrayContainer<int, 10> cnt(arr);
		QuickSort<int> qSrt;
		cnt.SetSort(&qSrt);
		cnt.Sort();
		cnt.Display();
		return 0;
	}
}