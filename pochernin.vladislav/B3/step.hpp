#ifndef STEP_HPP
#define STEP_HPP

#include <iosfwd>

namespace pochernin
{
  struct Step
  {
    enum type_t
    {
      first,
      last,
      specific,
      error
    };
    type_t type = error;
    int steps = 0;
    bool isCorrect() const;
  };
  std::istream& operator>>(std::istream& in, Step& step);
}

#endif
