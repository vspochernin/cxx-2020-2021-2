#include <boost/test/unit_test.hpp>

#include <iterator>
#include <algorithm>

#include "shape.hpp"
#include "functions.hpp"

using Shape = pochernin::Shape;

BOOST_AUTO_TEST_SUITE(testShape)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    Shape shape;
    std::stringstream stream("3 (123; 456) (111; 222) (333; 444)");
    stream >> shape;
    BOOST_CHECK_EQUAL(shape.size(), 3);
    BOOST_CHECK_EQUAL(shape[0].x, 123);
    BOOST_CHECK_EQUAL(shape[0].y, 456);
    BOOST_CHECK_EQUAL(shape[1].x, 111);
    BOOST_CHECK_EQUAL(shape[1].y, 222);
    BOOST_CHECK_EQUAL(shape[2].x, 333);
    BOOST_CHECK_EQUAL(shape[2].y, 444);
  }

  BOOST_AUTO_TEST_CASE(incorrectInput1)
  {
    Shape shape;
    std::stringstream stream("3 (123sd;as 0)a ;asd 2 sa");
    BOOST_CHECK_THROW(stream >> shape, std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrectInput2)
  {
    Shape shape;
    std::stringstream stream(" 3 (423;1) (24; \n 1) (23;4)");
    BOOST_CHECK_THROW(stream >> shape, std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(countingTriangles)
  {
    std::vector< Shape > shapes;
    std::stringstream stream("3 (123; 456) (111; 222) (333; 444) \n 3 (1; 4)(1; 2)(3; 4) \n 4 (1; 1)(1; 1)(1; 1)(1; 1) \n");
    std::copy(std::istream_iterator< Shape >(stream), std::istream_iterator< Shape >(), std::back_inserter(shapes));
    unsigned int countOfTriangles = std::count_if(shapes.begin(), shapes.end(), pochernin::isTriangle);
    BOOST_CHECK_EQUAL(countOfTriangles, 2);
  }

  BOOST_AUTO_TEST_CASE(countingRectangles)
  {
    std::vector< Shape > shapes;
    std::stringstream stream("4 (0;0)(0;2)(1;0)(1;2) \n 4 (0;0);(0;1)(1;0)(1;1) \n");
    std::copy(std::istream_iterator< Shape >(stream), std::istream_iterator< Shape >(), std::back_inserter(shapes));
    unsigned int countOfRectangles = std::count_if(shapes.begin(), shapes.end(), pochernin::isRectangle);
    BOOST_CHECK_EQUAL(countOfRectangles, 2);
  }

  BOOST_AUTO_TEST_CASE(countingSqares)
  {
    std::vector< Shape > shapes;
    std::stringstream stream("4 (0;0)(0;2)(1;0)(1;2) \n 4 (0;0);(0;1)(1;0)(1;1) \n");
    std::copy(std::istream_iterator< Shape >(stream), std::istream_iterator< Shape >(), std::back_inserter(shapes));
    unsigned int countOfSquares = std::count_if(shapes.begin(), shapes.end(), pochernin::isSquare);
    BOOST_CHECK_EQUAL(countOfSquares, 1);
  }

BOOST_AUTO_TEST_SUITE_END()
