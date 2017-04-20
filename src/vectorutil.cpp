#include <vectorutil.h>
#include <matrix.h>
#include <cassert>
#include <sstream>

const Matrix Rx( 1,  0,  0,
                 0,  0, -1,
                 0,  1,  0);
const Matrix Ry( 0,  0,  1,
                 0,  1,  0,
                -1,  0,  0);
const Matrix Rz( 0, -1,  0,
                 1,  0,  0,
                 0,  0,  1);

Point VectorUtil::translationVectorFromAxis(Axis::Value axis, int direction)
{
    assert(direction == 1 || direction == -1);
    switch (axis) {
        case Axis::X: {
            return { direction, 0, 0 };
        } break;
        case Axis::Y: {
            return { 0, direction, 0 };
        } break;
        case Axis::Z: {
            return { 0, 0, direction };
        } break;
    }
}

Axis::Value VectorUtil::axisFromTranslationVector(const Point& vector)
{
    if (0 != vector.x) {
        assert(0 == vector.y);
        assert(0 == vector.z);
        return Axis::X;
    }
    else if (0 != vector.y) {
        assert(0 == vector.x);
        assert(0 == vector.z);
        return Axis::Y;
    }
    else {
        assert(0 != vector.z);
        return Axis::Z;
    }
}

std::string VectorUtil::translationVectorText(const Point& vector)
{
    int direction = vector.x + vector.y + vector.z; // Two of these should be 0
    std::stringstream ss;
    ss << (direction < 0 ? '-' : '+');
    ss << axisFromTranslationVector(vector);
    return ss.str();
}

Block VectorUtil::rotate(const Block& block, Axis::Value about)
{
    Point translationVector;

    switch(about) {
        case Axis::X: {
            translationVector = Rx.rotate(block.translationVector);
        } break;
        case Axis::Y: {
            translationVector = Ry.rotate(block.translationVector);
        } break;
        case Axis::Z: {
            translationVector = Rz.rotate(block.translationVector);
        } break;
    };
    return { axisFromTranslationVector(translationVector), translationVector };
}

Point VectorUtil::getPosition(const Block& block, const Point& relativeTo)
{
    return {
        relativeTo.x + block.translationVector.x,
        relativeTo.y + block.translationVector.y,
        relativeTo.z + block.translationVector.z
    };
}

