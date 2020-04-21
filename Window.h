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
    Window(string owner, string title, string color);
    Window(const Window &window);
    void print();
    void setOwner(string owner);
    void setTitle(string title);
    void setColor(string color);
    string getOwner();
    string getTitle();
    string getColor();

    Window& operator = (const Window &otherWindow);
    bool operator == (const Window &otherWindow);
    bool operator != (const Window &otherWindow);
    bool operator > (const Window &otherWindow);
    bool operator < (const Window &otherWindow);
    bool operator <= (const Window &otherWindow);
    bool operator >= (const Window &otherWindow);
    friend ostream& operator << (ostream &out, const Window &window);
    friend istream& operator >> (istream &in, Window &window);
};
