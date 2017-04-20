#include <rubikschain.h>
#include <vectorutil.h>
#include <cassert>

// MANIPULATORS
void RubiksChain::append(Axis::Value axis, int direction)
{
    blocks_.push_back(
        { axis, VectorUtil::translationVectorFromAxis(axis, direction) });
}

Block RubiksChain::pop()
{
    Block block = blocks_.front();
    blocks_.pop_front();
    return block;
}

void RubiksChain::rotate(Axis::Value about)
{
    for (auto&& block : blocks_) {
        block = VectorUtil::rotate(block, about);
    }
}

// ACCESSORS
Block RubiksChain::peek() const
{
    return blocks_.front();
}

bool RubiksChain::empty() const
{
    return blocks_.empty();
}

void RubiksChain::print(std::ostream& os) const
{
    for (auto&& block : blocks_) {
        os << std::endl << block;
    }
}

