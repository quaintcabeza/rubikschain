#include <point.h>

class Matrix {
    // This class represents a 3 by 3 matrix.

    int matrix_[3][3];

  public:
    // CREATORS
    Matrix(int l1, int l2, int l3,
           int m1, int m2, int m3,
           int n1, int n2, int n3);

    // ACCESSORS
    Point rotate(const Point& point) const;
        // Rotate the specified 'point' by performing matrix transformation,
        // and return the result.

    void print(std::ostream& os = std::cout) const;
        // Print this object to the specified stream.
};

inline
std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    matrix.print(os);
    return os;
}
