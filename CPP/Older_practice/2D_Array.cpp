#include <iostream>


using namespace std;


class Matrix
{
public:
        int matrix[5][5];


        Matrix() :matrix{ {1, 2, 3, 4, 5},
                                          {6, 7, 8, 9, 10},
                                          {11, 12, 13, 14, 15},
                                          {16, 17, 18, 19, 20},
                                          {61, 72, 38, 29, 50} }
        {


        }




        class Helper
        {
                friend class Matrix;
        public:
                Matrix* matrix_ptr;
                int r_idx;


                Helper(Matrix* ptr, int index) :matrix_ptr(ptr), r_idx(index)
                {
                }


                class Helper2
                {
                        friend class Matrix;
                        friend class Helper2;
                public:
                        Helper* helper_ptr;
                        int c_idx;


                        Helper2(Helper* ptr, int c_index) :helper_ptr(ptr), c_idx(c_index)
                        {
                        }


                        operator int()
                        {
                                cout << "reading...\n";
                                int val = helper_ptr->matrix_ptr->matrix[helper_ptr->r_idx][c_idx];
                                return val;
                        }


                        Helper2& operator=(int val)
                        {
                                cout << "writing...\n";
                                helper_ptr->matrix_ptr->matrix[helper_ptr->r_idx][c_idx] = val;
                                return *this;
                        }


                        Helper2& operator=(Helper2& par)
                        {
                                cout << "reading and writing...\n\n\n";
                                int to_assign = par.helper_ptr->matrix_ptr->matrix[par.helper_ptr->r_idx][par.c_idx];
                                helper_ptr->matrix_ptr->matrix[helper_ptr->r_idx][c_idx] = to_assign;
                                return *this;
                        }


                };


                Helper2 operator[](int col_idx)
                {
                        return Helper2(this, col_idx);
                }


        };


        
        Helper operator[](int row_idx)
        {
                //cout << "row_idx: " << row_idx << "\n";
                return Helper(this, row_idx);
        }


        friend ostream& operator<<(ostream& os, Matrix& obj)
        {
                for (int i = 0; i < 5; i++)
                {
                        for (int j = 0; j < 5; j++)
                        {
                                cout << obj.matrix[i][j] << " ";
                        }


                        cout << "\n";
                }


                return os;
        }


};




int main()
{
        Matrix arr;


        int x = arr[2][3];//reading
        arr[3][2] = 999;//writing
        arr[1][2] = arr[3][1];//read/write


        cout << arr;


        return 0;
}
