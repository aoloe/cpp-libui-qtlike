#include "../libui/ui.h"
#include "libui-qtlike.h"

#include <string>

namespace UI {

Application::Application(int argc, char *argv[])
{
	uiInitOptions o = {0};
	if (uiInit(&o) != NULL) {
        returnCode = -1;
    }
}
int Application::exec()
{
    uiMain();
    return returnCode;
}

// TODO: label to char*?
Menu::Menu(const string label)
: menu{uiNewMenu(label.c_str())}
{
    // TODO: check how the pointer should be managed
}

void Menu::addAction(Action *action)
{
    uiMenuAppendItem(menu, action->text().c_str());
}

MenuBar::MenuBar()
{
}

Menu *MenuBar::addMenu(string label)
{
    auto menu = new Menu(label);
    return menu;
}

MainWindow::MainWindow()
: mMenuBar{new MenuBar}
{
}

MainWindow::~MainWindow()
{
    delete mMenuBar;
}

MenuBar *MainWindow::menuBar()
{
    return mMenuBar;
}

void MainWindow::show()
{
    mainWindow = uiNewWindow("Hello", 320, 240, 1);
    uiWindowOnClosing(mainWindow, [](uiWindow *w, void *data){uiQuit(); return 1;}, NULL);
    uiControlShow(uiControl(mainWindow));
}

Action::Action(string label, MainWindow *window)
: label{label}, window{window}
{
}

}
