#include <iostream>
#include "library.h"
using namespace std;

void Library::add_book(Book book)
{
    Books.push_back(book);
    cout << "Added:" << book.get_name() << endl;
}

void Library::find_book(int book_ID)
{
    for (auto & b : Books)
    {
        if (b.get_ID() == book_ID)
        {
            b.print_message();
            return;
        }
    }

    cout << "Find Failed" << endl;
}

void Library::delete_book(int book_ID)
{
    for (int i = 0;i < Books.size();i++)
    {
        if (Books[i].get_ID() == book_ID)
        {
            cout << "Deleted:" << Books[i].get_name() << endl;
            Books.erase(Books.begin() + i);

            return ;
        }
    }

    cout << "Delete Failed" << endl;
}

void Library::borrow_book(int book_ID, string borrower)
{
    for (auto & b : Books)
    {
        if (b.get_ID() == book_ID && !b.get_state())
        {
            b.change_state(borrower);
            cout << "Borrowed:" << b.get_name() << endl;
            return ;
        }
    }

    cout << "Borrow Failed" << endl;
}

void Library::return_book(int book_ID)
{
    for (auto & b : Books)
    {
        if (b.get_ID() == book_ID && b.get_state())
        {
            b.change_state();
            cout << "Returned:" << b.get_name() << endl;
            return ;
        }
    }

    cout << "Return Failed" << endl;
}