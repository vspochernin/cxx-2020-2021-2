#include <boost/test/unit_test.hpp>

#include "factorial-container.hpp"

BOOST_AUTO_TEST_SUITE(testFactorialContainer)

  BOOST_AUTO_TEST_CASE(checkFactorials)
  {
    pochernin::FactorialContainer fc;
    pochernin::FactorialContainer::FactorialIterator iterator = fc.begin();
    unsigned int factorial = 1;
    size_t i = 2;
    while (iterator != fc.end())
    {
      BOOST_CHECK(*iterator == factorial);
      factorial*= i;
      i++;
      iterator++;
    }
  }

BOOST_AUTO_TEST_SUITE_END()
