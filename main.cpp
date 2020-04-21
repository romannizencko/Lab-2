#include "Window.h"
#include <stdlib.h>

using namespace std;

void menu()
{
    cout << "\n\t\t\t***Menu***" << endl;
    cout << "\t00)Return to selection window" << endl;
    cout << "\t01)Print information about window" << endl;
    cout << "\t02)Set window's owner" << endl;
    cout << "\t03)Set window's title" << endl;
    cout << "\t04)Set window's color" << endl;
    cout << "\t05)Get owner" << endl;
    cout << "\t06)Get title" << endl;
    cout << "\t07)Get color" << endl;
    cout << "\t08)Copy window" << endl;
    cout << "\t09)Delete this window" << endl;
    ///вторая лабораторная
    cout << "\t10)Sinchronization this window with one other" << endl;
    cout << "\t11)Sort the list of Windows" << endl;
}

void showAllWindows(const short countOfWindow, Window  * const Windows)
{
    for (short i = 0; i < countOfWindow; i++)
    {
        cout << i+1 << ")";
        Windows[i].print();
    }
}

int main()
{
    string tmpOwner, tmpTitle, tmpColor;
    short var = 0, countOfWindow = 1, i = 0, y = 0;
    Window *Windows = new Window[countOfWindow], *tmpWindows;
    while (1)
    {
        cout << "\nSelect window(up to" << countOfWindow << ") or close program(input 0)\n" << endl;
        showAllWindows(countOfWindow, Windows);
        cin >> i;
        if (i == 0)
        {
            delete Windows;
            return 0;
        }

        while (i != 0)
        {
            menu();
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    cout << "\n" << Windows[i-1];
                    break;
                case 2:
                    cout << "\nEntry owner:" << endl;
                    cin >> tmpOwner;
                    Windows[i-1].setOwner(tmpOwner);
                    break;
                case 3:
                    cout << "\nEntry title:" << endl;
                    cin >> tmpTitle;
                    Windows[i-1].setTitle(tmpTitle);
                    break;
                case 4:
                    cout << "\nEntry color:" << endl;
                    cin >> tmpColor;
                    Windows[i-1].setColor(tmpColor);
                    break;
                case 5:
                    cout << "\nOwner:\t" << (tmpOwner = Windows[i-1].getOwner()) << endl;
                    break;
                case 6:
                    cout << "\nTitle:\t" << (tmpTitle = Windows[i-1].getTitle()) << endl;
                    break;
                case 7:
                    cout << "\nColor:\t" << (tmpColor = Windows[i-1].getColor()) << endl;
                    break;
                case 8:{
                    countOfWindow++;
                    tmpWindows = new Window[countOfWindow];
                    for (y = 0; y < countOfWindow-1; y++)
                    {
                        tmpWindows[y] = Windows[y];
                        delete &(Windows[y]);
                    }
                    delete Windows;
                    Windows = tmpWindows;
                    Window newWindow(Windows[i-1]);
                    Windows[countOfWindow-1] = newWindow;
                    break;}
                case 9:{
                    Windows[i-1] = Windows[countOfWindow-1];
                    delete &(Windows[countOfWindow-1]);
                    countOfWindow --;
                    tmpWindows = new Window[countOfWindow];
                    for (y = 0; y < countOfWindow; y++)
                    {
                        tmpWindows[y] = Windows[y];
                        delete &(Windows[y]);
                    }
                    delete Windows;
                    Windows = tmpWindows;
                    i = 0;
                    break;
                    }
///вторая лабораторная
                case 10:{
                    short var;
                    showAllWindows(countOfWindow, Windows);
                    cout << "\nSelect window for sinchronization this window with it: ";
                    cin >> var;
                    Windows[i-1] = Windows [var-1];
                    break;}
                case 11:{
                    i = 0;
                    short x,y;
                    if (countOfWindow < 2) break;
                    for (x = 0; x < countOfWindow; ++x)
                    {
                        for (y = 0; y < countOfWindow-1-x; ++y)
                        {
                            if (Windows[y] > Windows[y+1])
                            {
                                Window tmpwindow(Windows[y]);
                                Windows[y] = Windows[y+1];
                                Windows[y+1] = tmpwindow;
                            }
                        }
                    }}
            }
        }
    }
}
