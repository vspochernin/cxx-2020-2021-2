#include "factorial-container.hpp"

#include <stdexcept>
#include <cassert>

#include "functions.hpp"

using FC = pochernin::FactorialContainer;
using FI = pochernin::FactorialContainer::FactorialIterator;
using ValueType = pochernin::FactorialContainer::ValueType;


FI::FactorialIterator(ValueType number):
  number_(number),
  factorial_(getFactorial(number))
{}

bool FI::operator==(const FI& rhs) const
{
  return ((number_ == rhs.number_) && (factorial_ == rhs.factorial_));
}

bool FI::operator!=(const FI& rhs) const
{
  return !(this->operator==(rhs));
}

const ValueType& FI::operator*() const
{
  return factorial_;
}

const ValueType* FI::operator->() const
{
  return std::addressof(factorial_);
}

FI& FI::operator++()
{
  assert(number_ < maxNumber);
  number_++;
  factorial_ *= number_;
  return *this;
}

FI FI::operator++(int)
{
  FI temp = *this;
  ++(*this);
  return temp;
}

FI& FI::operator--()
{
  assert(number_ > minNumber);
  factorial_ /= number_;
  number_--;
  return *this;
}

FI FI::operator--(int)
{
  FI temp = *this;
  --(*this);
  return temp;
}

FI FC::begin() const noexcept
{
  return FI(minNumber);
}

FI FC::end() const noexcept
{
  return FI(maxNumber);
}
