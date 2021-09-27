#include "note.hpp"

#include <iostream>

void pochernin::makeEmpty(Note& note)
{
  note.name = "";
  note.number = "";
}

bool pochernin::checkNumber(const std::string& number)
{
  if (number.empty())
  {
    return false;
  }

  for (auto&& i: number)
  {
    if (!std::isdigit(i))
    {
      return false;
    }
  }

  return true;
}

bool pochernin::checkName(std::string& name)
{
  if (name.empty() || (name.front() != '\"'))
  {
    return false;
  }
  else
  {
    name.erase(name.begin());
  }

  if (name.empty() || (name.back() != '\"'))
  {
    return false;
  }
  else
  {
    name.erase(name.end() - 1);
  }

  if (name.empty())
  {
    return false;
  }

  size_t i = 0;
  while (i < name.size())
  {
    if (name[i] == '\"')
    {
      return false;
    }
    else if (name[i] == '\\')
    {
      if (i == (name.size() - 1))
      {
        return false;
      }
      else
      {
        name.erase(i, 1);
      }
    }
    i++;
  }

  return true;
}

std::istream& pochernin::operator>>(std::istream& in, Note& note)
{
  std::string number;
  in >> std::ws >> number;
  if (!checkNumber(number))
  {
    makeEmpty(note);
    return in;
  }

  std::string name;
  std::getline(in >> std::ws, name);
  if (!checkName(name))
  {
    makeEmpty(note);
    return in;
  }

  note.number = number;
  note.name = name;
  return in;
}

std::ostream& pochernin::operator<<(std::ostream& out, const Note& note)
{
  out << note.number << " " << note.name << "\n";
  return out;
}
