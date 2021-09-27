#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "test-functions.hpp"

namespace lab = pochernin;

namespace pochernin
{
  const double width = 100.0;
  const double height = 50.0;
  const double negativeValue = - 10.0;
  const point_t startPos = {10.0, 20.0};
}

BOOST_AUTO_TEST_SUITE(Rectangle)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWhenMoving)
{
  lab::Rectangle testRectangle(lab::width, lab::height, lab::startPos);
  lab::checkConstWidthHeightArea(testRectangle);
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  lab::Rectangle testRectangle(lab::width, lab::height, lab::startPos);
  lab::checkQuadraticChangeAreaWhenScale(testRectangle);
}

BOOST_AUTO_TEST_CASE(HandlingIncorrectParameters)
{
  BOOST_CHECK_THROW(lab::Rectangle(lab::negativeValue, lab::height, lab::startPos), std::invalid_argument);
  BOOST_CHECK_THROW(lab::Rectangle(lab::width, lab::negativeValue, lab::startPos), std::invalid_argument);
  lab::Rectangle testRectangle(lab::width, lab::height, lab::startPos);
  BOOST_CHECK_THROW(testRectangle.scale(lab::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
