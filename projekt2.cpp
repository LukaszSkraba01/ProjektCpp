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

    return 0;
}
