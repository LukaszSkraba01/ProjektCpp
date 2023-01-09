#include <iostream>
#include <vector>

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

    // Nowa metoda dokonujaca transpozycji macierzy
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
    
    // Nowa metoda dokonujaca odwrócenia macierzy
    Matrix reverse() const
    {
        Matrix reversed(rows_, cols_);

        for (int i = 0; i < rows_; i++)
        {
            for (int j = 0; j < cols_; j++)
            {
                reversed(i, j) = (*this)(rows_ - i - 1, cols_ - j - 1);
            }
        }

        return reversed;
    }
    
    //nowa metoda obliczajaca wyznacznik macierzy maksymalnie 3x3 za pomoca metody Algorytmu Laplace'a
    double determinant() const
	{
    	if (rows_ != cols_)
    	{
        	std::cout << "Macierz musi byc kwadratowa, aby obliczyc wyznacznik." << '\n';
        	return 0.0;
    	}

    	// Algorytm Laplace'a
    	if (rows_ == 1)
    	{
  	    	return data_[0];
    	}
 	   if (rows_ == 2)
    	{
       		return data_[0] * data_[3] - data_[1] * data_[2];
   		}
    	if (rows_ == 3)
    	{
        	return data_[0] * data_[4] * data_[8] + data_[1] * data_[5] * data_[6] + data_[2] * data_[3] * data_[7] - data_[2] * data_[4] * data_[6] - data_[1] * data_[3] * data_[8] - data_[0] * data_[5] * data_[7];
    	}
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
	
private:
    int rows_;
    int cols_;
    std::vector<int> data_;
};

int main()
{
    std::cout << "Podaj liczbe wierszy macierzy: ";
    int rows;
    std::cin >> rows;

    std::cout << "Podaj liczbe kolumn macierzy: ";
    int cols;
    std::cin >> cols;

    Matrix m(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Podaj element macierzy [" << i << "][" << j << "]: ";
            std::cin >> m(i, j);
        }
    }

    std::cout << "Macierz wejsciowa:" << '\n';
    m.print();

    Matrix m_transposed = m.transpose();
    std::cout << "Macierz po transpozycji:" << '\n';
    m_transposed.print();
    
    Matrix m_reversed = m.reverse();
    std::cout << "Macierz po odwroceniu:" << '\n';
    m_reversed.print();
    
    double det = m.determinant();
	std::cout << "Wyznacznik macierzy wejsciowej: " << det << '\n';
	
	int degree = m.degree();
	std::cout << "Stopien macierzy wejsciowej: " << degree << '\n';

    return 0;
}
