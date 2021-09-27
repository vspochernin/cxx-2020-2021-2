#include <boost/test/unit_test.hpp>

#include <sstream>
#include <algorithm>

#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(testStruct)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    pochernin::DataStruct dataStruct;
    std::stringstream stream("3,5,qwerty");
    stream >> dataStruct;
    BOOST_CHECK_EQUAL(dataStruct.key1, 3);
    BOOST_CHECK_EQUAL(dataStruct.key2, 5);
    BOOST_CHECK_EQUAL(dataStruct.str, "qwerty");
  }

  BOOST_AUTO_TEST_CASE(incorrectInput)
  {
    pochernin::DataStruct dataStruct;
    std::stringstream stream("incorrect");
    stream >> dataStruct;
    BOOST_CHECK(stream.fail());
  }

  BOOST_AUTO_TEST_CASE(sorting)
  {
    pochernin::DataStruct dataStruct1;
    pochernin::DataStruct dataStruct2;
    std::vector< pochernin::DataStruct > vec;
    std::stringstream stream1("3,5,qwerty");
    std::stringstream stream2("1,2,asd");
    stream1 >> dataStruct1;
    stream2 >> dataStruct2;
    vec.push_back(dataStruct1);
    vec.push_back(dataStruct2);
    std::sort(vec.begin(), vec.end());
    BOOST_CHECK_EQUAL(vec[0].key1, 1);
    BOOST_CHECK_EQUAL(vec[0].key2, 2);
    BOOST_CHECK_EQUAL(vec[0].str, "asd");
    BOOST_CHECK_EQUAL(vec[1].key1, 3);
    BOOST_CHECK_EQUAL(vec[1].key2, 5);
    BOOST_CHECK_EQUAL(vec[1].str, "qwerty");
  }

BOOST_AUTO_TEST_SUITE_END()
