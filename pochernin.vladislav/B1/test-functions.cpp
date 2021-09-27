#include <boost/test/unit_test.hpp>

#include "functions.hpp"

BOOST_AUTO_TEST_CASE(isAscendingTest)
{
  BOOST_CHECK(pochernin::isAscending("ascending"));
  BOOST_CHECK(!pochernin::isAscending("descending"));
  BOOST_CHECK_THROW(pochernin::isAscending(""), std::invalid_argument);
  BOOST_CHECK_THROW(pochernin::isAscending("adwuodhoa"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(isNumberTest)
{
  BOOST_CHECK(pochernin::isNumber("123"));
  BOOST_CHECK(!pochernin::isNumber("123ad2"));
  BOOST_CHECK(!pochernin::isNumber("2 3"));
  BOOST_CHECK(!pochernin::isNumber("a a"));
}
