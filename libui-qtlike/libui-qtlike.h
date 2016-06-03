#ifndef LIBUIQTIZED_H
#define LIBUIQTIZED_H

#include<string>

#include "../libui/ui.h"

using namespace std;

namespace UI {

class Application
{
public:
    // Application(); // TODO: check if this exists in Qt
    Application(int argc, char *argv[]);
    int exec();
private:
    int returnCode{1};
};

class Action;

class Menu
{
public:
    Menu(const string label);
    void addAction(Action *action);
private:
    uiMenu* menu;
};

class MenuBar
{
public:
    MenuBar();
    Menu *addMenu(string label);
};

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();
    MenuBar *menuBar();
    void show();
private:
    MenuBar *mMenuBar; // a dummy menubar: libui only has one
    uiWindow *mainWindow;
};

class Action
{
public:
    Action(string label, MainWindow *window);
    string const text() {return label;};
private:
    string label;
    MainWindow *window;
};

}

#endif // LIBUIQTIZED_H
