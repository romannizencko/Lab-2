#include <string>
#include <iostream>

using namespace std;
class Window
{
private:
    string owner;
    string title;
    string color;
public:
    Window();
    Window( const string owner, const string title, const string color);
    Window(const Window &window);
    void print() const;
    void setOwner(const string owner);
    void setTitle(const string title);
    void setColor(const string color);
    string getOwner() const;
    string getTitle() const;
    string getColor() const;

    Window& operator = (const Window &otherWindow);
    bool operator == (const Window &otherWindow) const;
    bool operator != (const Window &otherWindow) const;
    bool operator > (const Window &otherWindow) const;
    bool operator < (const Window &otherWindow) const;
    bool operator <= (const Window &otherWindow) const;
    bool operator >= (const Window &otherWindow) const;
    friend ostream& operator << (ostream &out, const Window &window);
    friend istream& operator >> (istream &in, Window &window);
};
