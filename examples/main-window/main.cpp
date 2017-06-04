#include "../../libui-qtlike/libui-qtlike.h"
#include <vector>

using namespace std;

// qt like example based on
// http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html
// /usr/lib/x86_64-linux-gnu/qt5/examples/widgets/mainwindows/mainwindow/main.cpp

class MainWindow : public UI::MainWindow
{
public:
    MainWindow();
private:
    void createActions();
};

MainWindow::MainWindow()
{
    createActions();
}

void MainWindow::createActions()
{
    // UI::Menu *fileMenu = getMenuBar()->addMenu(tr("&File"));
    UI::Menu *fileMenu = getMenuBar()->addMenu("_File");
    // UI::Action *newAction = new UI::Action(tr("&New"), this);
    UI::Action *newAction = new UI::Action("_New", this);
    newAction->setShortcuts(UI::Keyboard::KeySequence(UI::Keyboard::Modifier::Ctrl | UI::Keyboard::Key::P));
    // connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAction);
    UI::Action *quitAction = new UI::Action("_Quit", this);
    quitAction->setMenuRole(UI::Action::MenuRole::QuitRole);
    fileMenu->addAction(quitAction);
}

int main(int argc, char *argv[])
{
    UI::Application app(argc, argv);

    MainWindow mainWin;
    // qt seems to magically find the main window from app.. do we need get app and mainWin to know each other?
    mainWin.show();
    return app.exec();
}
