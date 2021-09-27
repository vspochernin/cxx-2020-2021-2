#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

namespace pochernin
{
  class FactorialContainer
  {
  public:
    using ValueType = unsigned int;

    class FactorialIterator: public std::iterator< std::bidirectional_iterator_tag, ValueType >
    {
    public:
      bool operator==(const FactorialIterator& rhs) const;
      bool operator!=(const FactorialIterator& rhs) const;
      const ValueType& operator*() const;
      const ValueType* operator->() const;
      FactorialIterator& operator++();
      FactorialIterator operator++(int);
      FactorialIterator& operator--();
      FactorialIterator operator--(int);

    private:
      friend class FactorialContainer;

      ValueType number_;
      ValueType factorial_;

      explicit FactorialIterator(ValueType number);
    };

    FactorialIterator begin() const noexcept;
    FactorialIterator end() const noexcept;
  };
}

#endif
