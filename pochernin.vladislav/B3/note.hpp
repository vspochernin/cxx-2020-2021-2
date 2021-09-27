#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>
#include <iosfwd>

namespace pochernin
{
  struct Note
  {
    std::string number;
    std::string name;
  };
  std::istream& operator>>(std::istream& in, Note& note);
  std::ostream& operator<<(std::ostream& out, const Note& note);
  void makeEmpty(Note& note);
  bool checkNumber(const std::string& number);
  bool checkName(std::string& name);
}

#endif
