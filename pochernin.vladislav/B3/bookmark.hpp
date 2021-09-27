#ifndef BOOKMARK_HPP
#define BOOKMARK_HPP

#include <string>
#include <iosfwd>

namespace pochernin
{
  struct Bookmark
  {
    std::string name;
  };
  bool operator<(const Bookmark& lhs, const Bookmark& rhs);
  std::istream& operator>>(std::istream& in, Bookmark& bookmark);
  bool checkBookmarkName(const std::string& name);
}

#endif
