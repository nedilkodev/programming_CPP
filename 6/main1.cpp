#include <iostream>

using namespace std;

template <typename T>
class Matrix
{
protected:
    T **a;
    int size1;
    int size2;

public:
    Matrix() : size1(1), size2(1)
    {
        a = new T *[1];
        a[0] = new T[1]();
    }

    Matrix(int n, int m) : size1(n), size2(m)
    {
        if (n <= 0 || m <= 0)
        {
            cout << "Error: Matrix dimensions must be greater than 0!" << endl;
        }
        a = new T *[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new T[m]();
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < size1; i++)
        {
            delete[] a[i];
        }
        delete[] a;
    }

    T *operator[](const int i) { return a[i]; }
    const T *operator[](const int i) const { return a[i]; }

    Matrix operator+(const Matrix &lhs) const
    {
        Matrix c(size1, size2);
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                c.a[i][j] = a[i][j] + lhs.a[i][j];
            }
        }
        return c;
    }

    Matrix operator-(const Matrix &lhs) const
    {
        Matrix c(size1, size2);
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                c.a[i][j] = a[i][j] - lhs.a[i][j];
            }
        }
        return c;
    }

    Matrix operator*(const Matrix &rhs) const
    {
        Matrix c(size1, rhs.size2);
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < rhs.size2; j++)
            {
                c.a[i][j] = T();
                for (int k = 0; k < size2; k++)
                {
                    c.a[i][j] += a[i][k] * rhs.a[k][j];
                }
            }
        }
        return c;
    }

    friend ostream &operator<<(ostream &os, const Matrix &a)
    {
        for (int i = 0; i < a.size1; i++)
        {
            for (int j = 0; j < a.size2; j++)
            {
                os << a.a[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    friend istream &operator>>(istream &is, const Matrix &a)
    {
        for (int i = 0; i < a.size1; i++)
        {
            for (int j = 0; j < a.size2; j++)
            {
                is >> a.a[i][j];
            }
        }
        return is;
    }
};

template <typename T>
class SquareMatrix : public Matrix<T>
{
public:
    SquareMatrix() : Matrix<T>(1, 1) {}
    SquareMatrix(int n) : Matrix<T>(n, n) {}

    T trace() const
    {
        T sum = T();
        for (int i = 0; i < this->size1; i++)
        {
            sum += this->a[i][i];
        }
        return sum;
    }
};

int main(void)
{

    Matrix<double> a(2, 2);
    cout << "Enter matrix A (2x2):" << endl;
    cin >> a;

    Matrix<double> b(2, 2);
    cout << "Enter matrix B (2x2):" << endl;
    cin >> b;

    cout << endl
         << "Matrix A + B:" << endl
         << (a + b);
    cout << endl
         << "Matrix A - B:" << endl
         << (a - b);
    cout << endl
         << "Matrix A * B:" << endl
         << (a * b);

    cout << endl
         << "Default constructor test (1x1):" << endl;
    Matrix<double> def;
    cout << def;

    cout << endl
         << "Square matrix (3x3):" << endl;
    SquareMatrix<double> sq(3);
    sq[0][0] = 4.5;
    sq[1][1] = 1.0;
    sq[2][2] = 2.0;
    cout << sq;
    cout << "Matrix trace: " << sq.trace() << endl;

    cout << endl
         << "Testing negative dimension exception (-2x2):" << endl;
    Matrix<double> bad(-2, 2);

    return 0;
}