#include "tasks.hpp"

#include <iostream>
#include <string>
#include <sstream>

#include "phone-book.hpp"
#include "phone-book-interface.hpp"
#include "note.hpp"
#include "bookmark.hpp"
#include "step.hpp"
#include "functions.hpp"

void pochernin::task1(std::istream& in, std::ostream& out)
{
  pochernin::PhoneBook book;
  pochernin::PhoneBookInterface interface(book);
  std::string string;
  while(std::getline(in, string))
  {
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add")
    {
      Note note;
      input >> note;
      if ((note.number == "") || (note.name == ""))
      {
        pochernin::invalidCommand(out);
      }
      else
      {
        interface.add(note);
      }
    }
    else if (command == "store")
    {
      Bookmark bookmark;
      Bookmark newBookmark;
      input >> bookmark >> newBookmark;
      if (!interface.contains(bookmark) || (bookmark.name == "") || (newBookmark.name == ""))
      {
        pochernin::invalidBookmark(out);
      }
      else
      {
        interface.store(bookmark, newBookmark);
      }
    }
    else if (command == "insert")
    {
      std::string position;
      Bookmark bookmark;
      Note note;
      input >> position >> bookmark >> note;
      if (!interface.contains(bookmark) || (bookmark.name == ""))
      {
        pochernin::invalidBookmark(out);
      }
      else if ((note.number == "") || (note.name == ""))
      {
        pochernin::invalidCommand(out);
      }
      else if (position == "before")
      {
        interface.insertBefore(bookmark, note);
      }
      else if (position == "after")
      {
        interface.insertAfter(bookmark, note);
      }
      else
      {
        pochernin::invalidCommand(out);
      }
    }
    else if (command == "delete")
    {
      Bookmark bookmark;
      input >> bookmark;
      if (!interface.contains(bookmark) || (bookmark.name == ""))
      {
        pochernin::invalidBookmark(out);
      }
      else
      {
        interface.deleteNote(bookmark);
      }
    }
    else if (command == "show")
    {
      Bookmark bookmark;
      input >> bookmark;
      if (!interface.contains(bookmark) || (bookmark.name == ""))
      {
        pochernin::invalidBookmark(out);
      }
      else if (interface.empty())
      {
        pochernin::empty(out);
      }
      else
      {
        interface.show(bookmark, out);
      }
    }
    else if (command == "move")
    {
      Bookmark bookmark;
      Step step;
      input >> bookmark >> step;
      if (!interface.contains(bookmark) || (bookmark.name == ""))
      {
        pochernin::invalidBookmark(out);
      }
      else if (!step.isCorrect())
      {
        pochernin::invalidStep(out);
      }
      else
      {
        interface.move(bookmark, step);
      }
    }
    else
    {
      pochernin::invalidCommand(out);
    }
  }
}
