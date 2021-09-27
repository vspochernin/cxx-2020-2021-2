#include "step.hpp"

#include <string>
#include <stdexcept>
#include <iomanip>

bool pochernin::Step::isCorrect() const
{
  return !(type == Step::error);
}

std::istream& pochernin::operator>>(std::istream& in, Step& step)
{
  std::string stepString;
  in >> std::ws >> stepString;
  if (stepString == "first")
  {
    step.type = Step::first;
    step.steps = 0;
  }
  else if (stepString == "last")
  {
    step.type = Step::last;
    step.steps = 0;
  }
  else
  {
    try
    {
      step.type = Step::specific;
      step.steps = std::stoi(stepString);
    }
    catch (std::exception& error)
    {
      step.type = Step::error;
      step.steps = 0;
    }
  }

  return in;
}
