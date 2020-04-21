#include "Window.h"
#include <cstring>

using namespace std;
    Window :: Window(){}
    Window :: Window(const string owner, const string title, const string color)
    {
        this -> owner = owner;
        this -> title = title;
        this -> color = color;
    }

    Window :: Window(const Window &window)
    {
        this -> owner = window.owner;
        this -> title = window.title;
        this -> color = window.color;
    }
    void Window :: print() const
    {   cout << "Owner: " << owner << "\tTitle: \t" << title << "\tColor: " << color << endl;    }

    void Window :: setOwner(const string owner)
    {   this -> owner = owner;  }

    void Window :: setTitle(const string title)
    {   this -> title = title;  }

    void Window :: setColor(const string color)
    {   this -> color = color;  }

    string Window :: getOwner() const
    {
        return owner;
    }
    string Window :: getTitle() const
    {
        return title;
    }

    string Window :: getColor() const
    {
        return color;
    }

    /// Вторая лабораторная работа

    Window& Window :: operator = (const Window &otherWindow)
    {
        this -> owner = otherWindow.owner;
        this -> title = otherWindow.title;
        this -> color = otherWindow.color;
        return *this;
    }

    bool Window :: operator == (const Window &otherWindow) const
    {
        return ((this->owner == otherWindow.owner) && (this->title == otherWindow.title) && (this->color == otherWindow.color));
    }

    bool Window :: operator != (const Window &otherWindow) const
    {
        return ((this->owner != otherWindow.owner) || (this->title != otherWindow.title) || (this->color != otherWindow.color));
    }

    bool Window :: operator > (const Window &otherWindow) const
    {
        if (this->owner > otherWindow.owner)
            return true;
        if (this->owner < otherWindow.owner)
            return false;
        if (this->title > otherWindow.title)
            return true;
        if (this->title < otherWindow.title)
            return false;
        if (this->color > otherWindow.color)
            return true;
        if (this->color < otherWindow.color)
            return false;
        return false;
    }

    bool Window :: operator < (const Window &otherWindow) const
    {
        if (this->owner < otherWindow.owner)
            return true;
        if (this->owner > otherWindow.owner)
            return false;
        if (this->title < otherWindow.title)
            return true;
        if (this->title > otherWindow.title)
            return false;
        if (this->color < otherWindow.color)
            return true;
        if (this->color > otherWindow.color)
            return false;
        return false;
    }

    bool Window :: operator >= (const Window &otherWindow) const
    {
        if (this->owner > otherWindow.owner)
            return true;
        if (this->owner < otherWindow.owner)
            return false;
        if (this->title > otherWindow.title)
            return true;
        if (this->title < otherWindow.title)
            return false;
        if (this->color > otherWindow.color)
            return true;
        if (this->color < otherWindow.color)
            return false;
        return true;
    }

    bool Window :: operator <= (const Window &otherWindow) const
    {
        if (this->owner < otherWindow.owner)
            return true;
        if (this->owner > otherWindow.owner)
            return false;
        if (this->title < otherWindow.title)
            return true;
        if (this->title > otherWindow.title)
            return false;
        if (this->color < otherWindow.color)
            return true;
        if (this->color > otherWindow.color)
            return false;
        return true;
    }

    ostream& operator << (ostream &out, const Window &window)
    {
        out << "\tOwner:\t" << window.owner << "\tTitle:\t" << window.title << "\tColor:\t" << window.color << ";";
        return out;
    }

    istream& operator >> (istream &in, Window &window)
    {
        in >> window.owner;
        in >> window.title;
        in >> window.color;
        return in;
    }
