#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <cstring>
#include <functional>

namespace pochernin
{
  template < typename Container >
  void print (const Container& container, const char* delimiter = "")
  {
    using Iterator = typename Container::const_iterator;

    Iterator end = container.end();
    for (Iterator current = container.begin(); current != end; current++)
    {
      std::cout << *current << delimiter;
    }
    std::cout << "\n";
  }

  template < typename ItemType >
  std::function< bool(ItemType, ItemType) > comparisonType(bool isAscending)
  {
    if (isAscending)
    {
      return std::less< ItemType >();
    }
    else
    {
      return std::greater< ItemType >();
    }
  }

  template < typename Access, typename ItemType >
  void sort(typename Access::Container& container, std::function< bool(ItemType, ItemType) > cmp)
  {
    typename Access::Iterator begin = Access::begin(container);
    typename Access::Iterator end = Access::end(container);
    for (typename Access::Iterator i = begin; i != end; i++)
    {
      typename Access::ItemType extremum = Access::get(container, i);
      typename Access::Iterator extremumIterator = i;
      for (typename Access::Iterator j = i; j != end; j++)
      {
        typename Access::ItemType x = Access::get(container, j);
        if (cmp(x, extremum))
        {
          extremum = x;
          extremumIterator = j;
        }
      }
      std::swap(Access::get(container, i), Access::get(container, extremumIterator));
    }
  }

  bool isAscending(const char* sortingDirection);
  void fillRandom(double* array, int size);
  bool isNumber(const char* string);
}

#endif
