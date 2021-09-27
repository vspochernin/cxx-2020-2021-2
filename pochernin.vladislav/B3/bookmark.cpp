#include "bookmark.hpp"

#include <iomanip>

bool pochernin::operator<(const Bookmark& lhs, const Bookmark& rhs)
{
  return lhs.name < rhs.name;
}

std::istream& pochernin::operator>>(std::istream& in, Bookmark& bookmark)
{
  in >> std::ws >> bookmark.name;
  if (!checkBookmarkName(bookmark.name))
  {
    bookmark.name = "";
  }
  return in;
}

bool pochernin::checkBookmarkName(const std::string& name)
{
  for (auto&& i: name)
  {
    if (!std::isdigit(i) && !std::isalpha(i) && (i != '-'))
    {
      return false;
    }
  }
  return true;
}
