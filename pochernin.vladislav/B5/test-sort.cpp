#include <boost/test/unit_test.hpp>

#include <ctime>
#include <vector>
#include <chrono>
#include <sstream>

#include "sort-test-tools.hpp"
#include "shape.hpp"
#include "functions.hpp"

BOOST_AUTO_TEST_SUITE(testSort)

  BOOST_AUTO_TEST_CASE(testTest)
  {
    srand(time(0));
    int64_t mySortMilisec = 0;
    int64_t stdSortMilisec = 0;
    for (size_t i = 0; i < pochernin::defaultNumberOfTests; i++)
    {
      pochernin::ShapePool shapePool = pochernin::getShapePool(pochernin::getRandomRatio());
      std::vector< pochernin::Shape > mySortVector(pochernin::defaultVectorSize);
      pochernin::fillRandomShapes(mySortVector, shapePool);
      std::vector< pochernin::Shape > stdSortVector = mySortVector;

      std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
      pochernin::sortShapes(mySortVector);
      std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
      mySortMilisec += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

      begin = std::chrono::steady_clock::now();
      std::sort(stdSortVector.begin(), stdSortVector.end());
      end = std::chrono::steady_clock::now();
      stdSortMilisec += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }

    std::stringstream stream;
    stream << "Number of sorts: " << pochernin::defaultNumberOfTests << ", vector size: "
           << pochernin::defaultVectorSize << "\n";
    stream << "My sort time: " << mySortMilisec << " milliseconds\n";
    stream << "Std sort time: " << stdSortMilisec << " milliseconds\n";
    BOOST_TEST_MESSAGE(stream.str());

    BOOST_CHECK(mySortMilisec < stdSortMilisec);
  }

BOOST_AUTO_TEST_SUITE_END()
