#include "tasks.hpp"

#include <vector>
#include <forward_list>
#include <iostream>

#include "accesses.hpp"
#include "functions.hpp"

void pochernin::task1(const char* sortingDirection)
{
  bool isAscending = pochernin::isAscending(sortingDirection);
  std::vector< int > bracketsVector;
  int n = 0;
  while (std::cin >> n)
  {
    bracketsVector.push_back(n);
  }
  if ((!std::cin.eof() && std::cin.fail()) || std::cin.bad())
  {
    throw(std::runtime_error("Incorrect input in task1\n"));
  }

  if (bracketsVector.empty())
  {
    return;
  }

  std::vector< int > atVector(bracketsVector);
  std::forward_list< int > iteratorForwardList(bracketsVector.begin(), bracketsVector.end());
  std::function< bool(int, int) > cmp = pochernin::comparisonType< int >(isAscending);

  pochernin::sort< bracketsAccess< int >, int >(bracketsVector, cmp);
  pochernin::print(bracketsVector, " ");

  pochernin::sort< atAccess< int >, int >(atVector, cmp);
  pochernin::print(atVector, " ");

  pochernin::sort< iteratorAccess< int >, int >(iteratorForwardList, cmp);
  pochernin::print(iteratorForwardList, " ");
}
