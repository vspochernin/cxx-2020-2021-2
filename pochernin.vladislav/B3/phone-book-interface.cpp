#include "phone-book-interface.hpp"

#include "phone-book.hpp"

using PBI = pochernin::PhoneBookInterface;

PBI::PhoneBookInterface(PhoneBook& book):
  book_(std::make_unique < PhoneBook >(book)),
  bookmarks_({std::make_pair< Bookmark, PBI::constIterator >({"current"}, book_->begin())})
{}

void PBI::add(const Note& note)
{
  book_->add(note);
  if (bookmarks_.size() == 1)
  {
    bookmarks_.at({"current"}) = book_->begin();
  }
}

bool PBI::empty() const
{
  return book_->empty();
}

bool PBI::contains(const Bookmark& bookmark) const
{
  return (bookmarks_.find(bookmark) != bookmarks_.end());
}

void PBI::show(const Bookmark& bookmark, std::ostream& out) const
{
  out << *(bookmarks_.at(bookmark));
}

void PBI::insertBefore(const Bookmark& bookmark, const Note& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    book_->insertBefore(bookmarks_.at(bookmark), note);
  }
}

void PBI::insertAfter(const Bookmark& bookmark, const Note& note)
{
  if (book_->empty())
  {
    add(note);
  }
  else
  {
    book_->insertAfter(bookmarks_.at(bookmark), note);
  }
}

void PBI::store(const Bookmark& bookmark, const Bookmark& newBookmark)
{
  constIterator iterator = bookmarks_.at(bookmark);
  bookmarks_.insert(std::make_pair(newBookmark, iterator));
}

void PBI::move(const Bookmark& bookmark, const Step& step)
{
  constIterator iterator = bookmarks_.at(bookmark);
  if (step.type == Step::first)
  {
    iterator = book_->begin();
  }
  else if (step.type == Step::last)
  {
    if (book_->empty())
    {
      iterator = book_->end();
    }
    else
    {
      iterator = std::prev(book_->end());
    }
  }
  else if (step.type == Step::specific)
  {
    std::advance(iterator, step.steps);
  }
  bookmarks_.at(bookmark) = iterator;
}

void PBI::deleteNote(const Bookmark& bookmark)
{
  constIterator iterator = bookmarks_.at(bookmark);
  std::map< Bookmark, constIterator >::iterator i = bookmarks_.begin();
  while (i != bookmarks_.end())
  {
    if (i->second == iterator)
    {
      if (std::next(i->second) == book_->end())
      {
        i->second = book_->begin();
      }
      else
      {
        i->second = std::next(iterator);
      }
    }
    i = std::next(i);
  }
  book_->deleteNote(iterator);
}
