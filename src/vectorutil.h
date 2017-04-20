#ifndef VECTORUTIL
#define VECTORUTIL

#include <block.h>
#include <axis.h>
#include <string>

struct VectorUtil {
    // This class provides a namespace for vector related utility functions.

    static Point translationVectorFromAxis(Axis::Value axis, int direction);
        // Return the translation vector represented by the specified 'axis'
        // and 'direction'.

    static Axis::Value axisFromTranslationVector(const Point& vector);
        // Return the axis represented by the specified translation vector.

    static std::string translationVectorText(const Point& vector);
        // Return a human friendly string representation of the specified
        // 'vector'.

    static Block rotate(const Block& block, Axis::Value about);
        // Return a block that represents the specified 'block' rotated about
        // the specified axis.

    static Point getPosition(const Block& block, const Point& relativeTo);
        // Get the position of the specified 'block' relative to the specified
        // point by using the block's translation vector.
};

#endif
