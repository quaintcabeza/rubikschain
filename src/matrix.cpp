#include <matrix.h>
#include <iostream>

// CREATORS
Matrix::Matrix(int l1, int l2, int l3,
               int m1, int m2, int m3,
               int n1, int n2, int n3)
{
    matrix_[0][0] = l1;
    matrix_[0][1] = l2;
    matrix_[0][2] = l3;
    matrix_[1][0] = m1;
    matrix_[1][1] = m2;
    matrix_[1][2] = m3;
    matrix_[2][0] = n1;
    matrix_[2][1] = n2;
    matrix_[2][2] = n3;
}

// ACCESSORS
void Matrix::print(std::ostream& os) const
{
    for (int i = 0; i < 3; ++i) {
        os << std::endl;
        for (int j = 0; j < 3; ++j) {
            os << "  " << matrix_[i][j];
        }
    }
    os << std::endl;
}

Point Matrix::rotate(const Point& p) const
{
    return {
        matrix_[0][0]*p.x + matrix_[0][1]*p.y + matrix_[0][2]*p.z,
        matrix_[1][0]*p.x + matrix_[1][1]*p.y + matrix_[1][2]*p.z,
        matrix_[2][0]*p.x + matrix_[2][1]*p.y + matrix_[2][2]*p.z
    };
}
