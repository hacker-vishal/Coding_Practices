#include<iostream>
using namespace std;

class Magic
{
	int m;
	int f;
	int l;
	int sum;
	int arr[10][10];
	int r;
	int c;
	void Init()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
				arr[i][j]=0;
			}
		}
	}


	bool IsTopRow()
	{
		return r==0 && c!=m-1;
	}
	bool IsLastColumn()
	{
		return c==m-1 && r!=0;
	}
	bool IsDiagnalFillable()
	{
		return r!=0 && c!=m-1 && arr[r-1][c+1]==0;
	}
	void MoveLastRow()
	{
		r=m-1;
	}
	void MoveFirstColumn()
	{
		c=0;
	}
	void MoveNextRow()
	{
		r++;
	}
	void MovePreviousRow()
	{
		r--;
	}
	void MoveNextColumn()
	{
		c++;
	}

	void MoveDiagonal()
	{
		MovePreviousRow();
		MoveNextColumn();
	}
	void ForwardL()
	{
		MoveLastRow();
		MoveNextColumn();
	}
	void ReverseL()
	{
		MoveFirstColumn();
		MovePreviousRow();
	}
public:
	
	Magic(int m,int f):m(m),f(f),r(0),c(m/2),l(m*m+f-1),sum((f+l)/2*m)
	{
		Init();
	}
	void FillArray()
	{
		while(f<=l)
		{
			arr[r][c]=f++;
			if(IsTopRow())
				ForwardL();
			else if(IsLastColumn())
				ReverseL();
			else if(IsDiagnalFillable())
				MoveDiagonal();
			else
				MoveNextRow();

		}
	}
	void Display()
	{
		cout<<"Sum="<<sum<<'\n';
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<arr[i][j]<<'\t';
			}
			cout<<"\n\n";
		}
	}

};

int main()
{
	Magic mag(5,1);
	mag.FillArray();

	mag.Display();
	return 0;
}