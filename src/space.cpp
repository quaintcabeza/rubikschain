#include <space.h>
#include <cmath>
#include <vectorutil.h>

// CREATORS
Space::Space()
{
    lowerBound_ = { 0, 0, 0 };
    upperBound_ = { 0, 0, 0 };
    append({{0, 0, 0}, {Axis::X, {0, 0, 0}} });
}

// MANIPULATORS
void Space::append(const Unit& unit)
{
    units_.push_back(unit);
    lowerBound_.x = std::min(lowerBound_.x, unit.position.x);
    lowerBound_.y = std::min(lowerBound_.y, unit.position.y);
    lowerBound_.z = std::min(lowerBound_.z, unit.position.z);
    upperBound_.x = std::max(upperBound_.x, unit.position.x);
    upperBound_.y = std::max(upperBound_.y, unit.position.y);
    upperBound_.z = std::max(upperBound_.z, unit.position.z);
}

// ACCESSORS
bool Space::isEmpty(const Point& position) const
{
    for (auto&& unit: units_) {
        if (unit.position == position) {
            return false;
        }
    }
    return true;
}

bool Space::isBounded(const Point& bounds) const
{
    return (upperBound_.x - lowerBound_.x < bounds.x) &&
           (upperBound_.y - lowerBound_.y < bounds.y) &&
           (upperBound_.z - lowerBound_.z < bounds.z);
}

const Unit& Space::last() const
{
    return units_.back();
}

void Space::print(std::ostream& os) const
{
    for (auto&& unit : units_) {
        os << std::endl << unit;
    }
}

void Space::printInstructions(std::ostream& os) const
{
    for (Units::const_iterator
           it = units_.begin() + 1; it != units_.end(); ++it) {
        os << std::endl
           << VectorUtil::translationVectorText(it->block.translationVector);
    }
}
