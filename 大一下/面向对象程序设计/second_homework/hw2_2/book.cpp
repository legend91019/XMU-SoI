#include <iostream>
#include "book.h"
using namespace std;

Book::Book(int ID, string name, string author, string publishing_house) {
    this->ID = ID;
    this->name = name;
    this->author = author;
    this->publishing_house = publishing_house;
    // 默认初始状态：没被借走，名字为空
    this->state.first = false;
    this->state.second = "";
}

int Book::get_ID()
{
    return ID;
}

string Book::get_name()
{
    return name;
}

string Book::get_author()
{
    return author;
}

string Book::get_publishing_house()
{
    return publishing_house;
}

bool Book::get_state()
{
    return state.first;
}

void Book::change_state()
{
    state.first = false;
    state.second = "";
}

void Book::change_state(string name)
{
    state.second = name;
    state.first = true;
}

void Book::print_message()
{
    cout << "ID:" << get_ID() << endl;
    cout << "name:" << get_name() << endl;
    cout << "author:" << get_author() << endl;
    cout << "publishing_house:" << get_publishing_house() << endl;
    if (get_state() == true) cout << "borrower:" << state.second << endl;
    string now_state;
    if (get_state()) now_state = "borrowed";
    else now_state = "loanable";

    cout << "state:" << now_state << endl;
}