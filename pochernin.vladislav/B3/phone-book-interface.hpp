#ifndef PHONE_BOOK_INTERFACE_HPP
#define PHONE_BOOK_INTERFACE_HPP

#include <memory>
#include <map>

#include "phone-book.hpp"
#include "note.hpp"
#include "bookmark.hpp"
#include "step.hpp"

namespace pochernin
{
  class PhoneBookInterface
  {
  public:
    using constIterator = PhoneBook::constIterator;

    explicit PhoneBookInterface(PhoneBook& book);

    void add(const Note& note);
    void insertBefore(const Bookmark& bookmark, const Note& note);
    void insertAfter(const Bookmark& bookmark, const Note& note);
    bool empty() const;
    bool contains(const Bookmark& bookmark) const;
    void show(const Bookmark& bookmark, std::ostream& out) const;
    void store(const Bookmark& bookmark, const Bookmark& newBookmark);
    void move(const Bookmark& bookmark, const Step& step);
    void deleteNote(const Bookmark& bookmark);

  private:
    std::unique_ptr< PhoneBook > book_;
    std::map< Bookmark, constIterator > bookmarks_;
  };
}

#endif
