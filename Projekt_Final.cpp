#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include <fstream>
using namespace std;

class Matrix
{
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows * cols) {}

    int& operator()(int row, int col) { return data_[row * cols_ + col]; }
    int operator()(int row, int col) const { return data_[row * cols_ + col]; }

    void print() const
    {
        for (int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < cols_; j++)
            {
                cout << (*this)(i, j) << ' ';
            }
            cout << '\n';
        }
    }

    //metoda dokonujaca transpozycji macierzy
    Matrix transpose() const
    {
        Matrix transposed(cols_, rows_);

        for (int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < cols_; j++)
            {
                transposed(j, i) = (*this)(i, j);
            }
        }

        return transposed;
    }

    //metoda dokonujaca obliczenia odwrotnej macierzy
    Matrix reverse() const
    {
        if (rows_ != cols_)
        {
            cout<<"Nie ma odwrotnej macierzy bo macierz nie jest kwadratowa.\n";
        }
        double det = determinant();
        if (det == 0)
        {
            cout<<"Nie ma odwrotnej macierzy bo wyznacznik rowny 0\n";
        }
        Matrix adjoint(rows_,cols_);
        for (int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < cols_; j++)
            {
                Matrix sub_matrix(rows_-1,cols_-1);
                for (int k = 0; k < rows_-1; k++)
                {
                    for (int l = 0; l < cols_-1; l++)
                    {
                        int row = (k < i) ? k : k + 1;
                        int col = (l < j) ? l : l + 1;
                        sub_matrix(k,l) = (*this)(row,col);
                    }
                }
                adjoint(j,i) = pow(-1, i + j) * sub_matrix.determinant();
            }
        }
        return adjoint * (1.0/det);
    }

    //metoda obliczajaca wyznacznik macierzy maksymalnie 3x3 za pomoca metody Algorytmu Laplace'a
    double determinant() const
	{
    if (rows_ != cols_)
    {
        cout << "Macierz musi byc kwadratowa, aby obliczyc wyznacznik." << '\n';
        return 0.0;
    }

    //Algorytm Laplace'a dla dowolnego rozmiaru
    double det = 0.0;
    if (rows_ == 1)
    {
        return data_[0];
    }
    else if (rows_ == 2)
    {
        return data_[0] * data_[3] - data_[1] * data_[2];
    }
    else
    {
        for (int i = 0; i < rows_; i++)
        {
            //tworzenie podmacierzy dla kolejnych elementów na pierwszej przekatnej
            Matrix submatrix(rows_-1, cols_-1);
            for (int j = 1; j < rows_; j++)
            {
                int submatrix_col = 0;
                for (int k = 0; k < rows_; k++)
                {
                    if (k == i) continue;
                    submatrix.data_[(j-1) * (rows_-1) + submatrix_col] = data_[j * rows_ + k];
                    submatrix_col++;
                }
            }

            //obliczanie wyznacznika przy uzyciu algorytmu Laplace'a dla podmacierzy
            det += pow(-1, i) * data_[i] * submatrix.determinant();
        }
    }
    return det;
	}

	//metoda obliczajaca stopien macierzy
	int degree() const
	{
    	int max_nonzero_rows = 0;
    	for (int i = 0; i < rows_; i++)
    	{
        	bool row_is_zero = true;
        	for (int j = 0; j < cols_; j++)
        	{
            	if ((*this)(i, j) != 0)
            	{
                	row_is_zero = false;
                	break;
            	}
        	}
        	if (!row_is_zero)
        	{
            	max_nonzero_rows++;
        	}
    	}

    	int max_nonzero_cols = 0;
    	for (int j = 0; j < cols_; j++)
    	{
        	bool col_is_zero = true;
        	for (int i = 0; i < rows_; i++)
        	{
            	if ((*this)(i, j) != 0)
            	{
                	col_is_zero = false;
                	break;
            	}
        	}
        	if (!col_is_zero)
        	{
            	max_nonzero_cols++;
        	}
    	}

	    return max(max_nonzero_rows, max_nonzero_cols);
	}

	//metoda obliczajaca dopelnienie algebraiczne elementow macierzy wejsciowej
	Matrix algebraic_complement() const
	{
    if (rows_ != cols_)
    {
        cout << "Matrix must be square to calculate algebraic complement." << '\n';
        return Matrix(0, 0);
    }

    Matrix complement(rows_, cols_);
    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            int submatrix_i = 0, submatrix_j = 0;
            Matrix submatrix(rows_ - 1, cols_ - 1);
            for (int k = 0; k < rows_; k++)
            {
                if (k == i) continue;

                for (int l = 0; l < cols_; l++)
                {
                    if (l == j) continue;
                    submatrix(submatrix_i, submatrix_j++) = (*this)(k, l);
                }
                submatrix_i++;
                submatrix_j = 0;
            }
            complement(i, j) = pow(-1, i + j) * submatrix.determinant();
        }
    }
    return complement;
	}

	Matrix operator*(const double &rhs) const {
    Matrix result(rows_, cols_);
    for (int i = 0; i < data_.size(); i++) {
        result.data_[i] = data_[i] * rhs;
    }
    return result;
	}

private:
    int rows_;
    int cols_;
    vector<int> data_;
};

int main()
{
	srand(time(0));

    cout << "Podaj liczbe wierszy macierzy: ";
    int rows;
    cin >> rows;

    cout << "Podaj liczbe kolumn macierzy: ";
    int cols;
    cin >> cols;

    Matrix m(rows, cols);

	int choice;
	cout<<"Podaj sposob wczytania danych do macierzy (1 - reczny, 2 - losowy, 3 - z pliku): ";
	cin>>choice;

	if (choice==1){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Podaj element macierzy [" << i << "][" << j << "]: ";
            cin >> m(i, j);
        }
    }
	}
	else if (choice == 2)
	{
	for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //cout << "Podaj element macierzy [" << i << "][" << j << "]: ";
            m(i, j)=rand()%10;
        }
    }
	}
	else if (choice ==3)
	{
		string fileName;
        cout << "Podaj nazwe pliku: ";
        cin >> fileName;
        ifstream file(fileName.c_str());
	for (int i = 0; i < rows; i++)
	{
	for (int j = 0; j < cols; j++)
	{
	file >> m(i, j);
	}
	}
	}
	else
	{
		cout<<"Zly wybor!";
		return 0;
	}


    cout << "Macierz wejsciowa:" << '\n';
    m.print();

	cout << endl;

    Matrix m_transposed = m.transpose();
    cout << "Macierz po transpozycji:" << '\n';
    m_transposed.print();

    cout << endl;
    //Matrix m_reversed = m.reverse();
    //cout << "Macierz po odwroceniu:" << '\n';
    //m_reversed.print();

    double det = m.determinant();
    //cout << std::fixed << std::setprecision(2);
	cout << "Wyznacznik macierzy wejsciowej: " << det << '\n';

	cout << endl;

	int degree = m.degree();
	cout << "Stopien macierzy wejsciowej: " << degree << '\n';

	cout << endl;

	Matrix m_algebraic_complement = m.algebraic_complement();
	cout << "Macierz dopelnien algebraicznych macierzy wejsciowej:" << '\n';
	m_algebraic_complement.print();

	cout << endl;

	//cout << fixed << setprecision(2);
	Matrix m_reversed = m.reverse();
    cout << "Macierz odwrotna (moga pojawic sie same 0 gdy wartosci sa bliskie zeru, gdyz to liczby calkowite)\n";
	cout<<"Najlepiej sprawdzac recznie.\n";
    m_reversed.print();

    return 0;
}
