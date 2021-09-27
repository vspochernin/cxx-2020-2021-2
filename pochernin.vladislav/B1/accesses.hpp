#ifndef ACCESSES_HPP
#define ACCESSES_HPP

#include <vector>
#include <forward_list>

namespace pochernin
{
  template< typename T >
  struct bracketsAccess
  {
    using ItemType = T;
    using Container = std::vector< ItemType >;
    using Iterator = size_t;

    static Iterator begin(Container&)
    {
      return 0;
    }
    static Iterator end(Container& container)
    {
      return container.size();
    }
    static ItemType& get(Container& container, Iterator& iterator)
    {
      return container[iterator];
    }
  };

  template < typename T >
  struct atAccess
  {
    using ItemType = T;
    using Container = std::vector< ItemType >;
    using Iterator = size_t;

    static Iterator begin(Container&)
    {
      return 0;
    }
    static Iterator end(Container& container)
    {
      return container.size();
    }
    static ItemType& get(Container& container, Iterator& iterator)
    {
      return container.at(iterator);
    }
  };

  template < typename T >
  struct iteratorAccess
  {
    using ItemType = T;
    using Container = std::forward_list< ItemType >;
    using Iterator = typename Container::iterator;

    static Iterator begin(Container& container)
    {
      return container.begin();
    }
    static Iterator end(Container& container)
    {
      return container.end();
    }
    static ItemType& get(Container&, Iterator& iterator)
    {
      return *iterator;
    }
  };
}

#endif
