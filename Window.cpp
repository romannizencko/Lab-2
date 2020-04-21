#include "Window.h"
#include <cstring>

using namespace std;
    Window :: Window(){}
    Window :: Window(string owner, string title, string color)
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
    void Window :: print()
    {   cout << "Owner: " << owner << "\tTitle: \t" << title << "\tColor: " << color << endl;    }

    void Window :: setOwner(string owner)
    {   this -> owner = owner;  }

    void Window :: setTitle(string title)
    {   this -> title = title;  }

    void Window :: setColor(string color)
    {   this -> color = color;  }

    string Window :: getOwner()
    {
        return owner;
    }
    string Window :: getTitle()
    {
        return title;
    }

    string Window :: getColor()
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

    bool Window :: operator == (const Window &otherWindow)
    {
        return ((this->owner == otherWindow.owner) && (this->title == otherWindow.title) && (this->color == otherWindow.color));
    }

    bool Window :: operator != (const Window &otherWindow)
    {
        return ((this->owner != otherWindow.owner) || (this->title != otherWindow.title) || (this->color != otherWindow.color));
    }

    bool Window :: operator > (const Window &otherWindow)
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

    bool Window :: operator < (const Window &otherWindow)
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

    bool Window :: operator >= (const Window &otherWindow)
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

    bool Window :: operator <= (const Window &otherWindow)
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
