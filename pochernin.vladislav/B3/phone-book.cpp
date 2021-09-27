#include "phone-book.hpp"

using PB = pochernin::PhoneBook;

void PB::add(const Note& note)
{
  data_.push_back(note);
}

PB::constIterator PB::begin() const
{
  return data_.cbegin();
}

PB::constIterator PB::end() const
{
  return data_.cend();
}

bool PB::empty() const
{
  return data_.empty();
}

void PB::insertBefore(constIterator iterator, const Note& note)
{
  data_.insert(iterator, note);
}

void PB::insertAfter(constIterator iterator, const Note& note)
{
  constIterator temp = std::next(iterator);
  if (temp == end())
  {
    add(note);
  }
  else
  {
    data_.insert(temp, note);
  }
}

void PB::deleteNote(constIterator iterator)
{
  data_.erase(iterator);
}
