#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<stdlib.h>
#include<time.h>

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
                std::cout << (*this)(i, j) << ' ';
            }
            std::cout << '\n';
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
            std::cout<<"Nie ma odwrotnej macierzy bo macierz nie jest kwadratowa.\n";
        }
        double det = determinant();
        if (det == 0)
        {
            std::cout<<"Nie ma odwrotnej macierzy bo wyznacznik rowny 0\n";
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
                adjoint(j,i) = std::pow(-1, i + j) * sub_matrix.determinant();
            }
        }
        return adjoint * (1.0/det);
    }
    
    //metoda obliczajaca wyznacznik macierzy maksymalnie 3x3 za pomoca metody Algorytmu Laplace'a
    double determinant() const
	{
    if (rows_ != cols_)
    {
        std::cout << "Macierz musi byc kwadratowa, aby obliczyc wyznacznik." << '\n';
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
	
	    return std::max(max_nonzero_rows, max_nonzero_cols);
	}
	
	//metoda obliczajaca dopelnienie algebraiczne elementow macierzy wejsciowej
	Matrix algebraic_complement() const
	{
    	if (rows_ != cols_)
    	{
        	std::cout << "Macierz musi byc kwadratowa, aby obliczyc dopelnienie algebraiczne." << '\n';
        	return Matrix(0, 0);
    	}

    	Matrix complement(rows_, cols_);
    	for (int i = 0; i < rows_; i++)
    	{
        	for (int j = 0; j < cols_; j++)
        	{
            	complement(i, j) = std::pow(-1, i + j) * (*this)(i, j);
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
    std::vector<int> data_;
};

int main()
{
	srand(time(0));
	
    std::cout << "Podaj liczbe wierszy macierzy: ";
    int rows;
    std::cin >> rows;

    std::cout << "Podaj liczbe kolumn macierzy: ";
    int cols;
    std::cin >> cols;

    Matrix m(rows, cols);
    
	int choice;
	std::cout<<"Podaj sposob wczytania danych do macierzy (1 - reczny, 2 - losowy)";
	std::cin>>choice;
	
	if (choice==1){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Podaj element macierzy [" << i << "][" << j << "]: ";
            std::cin >> m(i, j);
        }
    }
	}
	else if (choice == 2)
	{
	for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //std::cout << "Podaj element macierzy [" << i << "][" << j << "]: ";
            m(i, j)=rand()%10;
        }
    }
	}
	else
	std::cout<<"Zly wybor!";

    std::cout << "Macierz wejsciowa:" << '\n';
    m.print();
	
	std::cout << std::endl;
	
    Matrix m_transposed = m.transpose();
    std::cout << "Macierz po transpozycji:" << '\n';
    m_transposed.print();
    
    std::cout << std::endl;
    //Matrix m_reversed = m.reverse();
    //std::cout << "Macierz po odwroceniu:" << '\n';
    //m_reversed.print();
    
    double det = m.determinant();
    //std::cout << std::fixed << std::setprecision(2);
	std::cout << "Wyznacznik macierzy wejsciowej: " << det << '\n';
	
	std::cout << std::endl;
	
	int degree = m.degree();
	std::cout << "Stopien macierzy wejsciowej: " << degree << '\n';
	
	std::cout << std::endl;
	
	Matrix m_algebraic_complement = m.algebraic_complement();
	std::cout << "Macierz dopelnien algebraicznych macierzy wejsciowej:" << '\n';
	m_algebraic_complement.print();
	
	std::cout << std::endl;
	
	//std::cout << std::fixed << std::setprecision(2);
	Matrix m_reversed = m.reverse();
    std::cout << "Macierz odwrotna (moga pojawic sie same 0 gdy wartosci sa bliskie zeru, gdyz to liczby calkowite)\n";
	std::cout<<"Najlepiej sprawdzac recznie.\n";
    m_reversed.print();

    return 0;
}
