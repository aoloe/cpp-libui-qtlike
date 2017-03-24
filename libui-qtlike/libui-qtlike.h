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
    MenuBar *getMenuBar();
    void show();
private:
    MenuBar *menuBar; // a dummy menubar: libui only has one
    uiWindow *mainWindow;
};

class Action
{
public:
	/**
     * @brief see the qt specification:  http://doc.qt.io/qt-4.8/qaction.html#MenuRole-enum
     */
    enum MenuRole
    {
		NoRole,
		TextHeuristicRole,
		ApplicationSpecificRole,
		AboutQtRole,
		AboutRole,
		PreferencesRole,
		QuitRole
    };

    Action(string label, MainWindow *window);
    string const text() {return label;};
	MenuRole getMenuRole() {return menuRole;}
	void setMenuRole(MenuRole role) {menuRole = role;}

private:
    string label;
    MainWindow *window;
	MenuRole menuRole;
};

}

#endif // LIBUIQTIZED_H
