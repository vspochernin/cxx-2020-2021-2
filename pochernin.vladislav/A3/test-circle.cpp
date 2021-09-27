#include <boost/test/unit_test.hpp>

#include "circle.hpp"
#include "test-functions.hpp"

namespace lab = pochernin;

namespace pochernin
{
  const double radius = 200.0;
  const double negativeValue = -10.0;
  const point_t startPos = {10.0, 20.0};
}

BOOST_AUTO_TEST_SUITE(Circle)

BOOST_AUTO_TEST_CASE(ConstWidthHeightAreaWhenMoving)
{
  lab::Circle testCircle(lab::radius, lab::startPos);
  lab::checkConstWidthHeightArea(testCircle);
}

BOOST_AUTO_TEST_CASE(QuadraticChangeAreaWhenScale)
{
  lab::Circle testCircle(lab::radius, lab::startPos);
  lab::checkQuadraticChangeAreaWhenScale(testCircle);
}

BOOST_AUTO_TEST_CASE(HandlingIncorrectParameters)
{
  BOOST_CHECK_THROW(lab::Circle(lab::negativeValue, lab::startPos), std::invalid_argument);
  lab::Circle testCircle(lab::radius, lab::startPos);
  BOOST_CHECK_THROW(testCircle.scale(lab::negativeValue), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
