#include "../../libui-qtlike/libui-qtlike.h"
#include <vector>

using namespace std;

// qt like example based on
// http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html

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
    // UI::Menu *fileMenu = menuBar()->addMenu(tr("&File"));
    UI::Menu *fileMenu = menuBar()->addMenu("_File");
    // UI::Action *newAction = new UI::Action(tr("&New"), this);
    UI::Action *newAction = new UI::Action("_New", this);
    // newAction->setShortcuts(UI::KeySequence::New);
    // connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAction);
}

int main(int argc, char *argv[])
{
    UI::Application app(argc, argv);

    MainWindow mainWin;
    // qt seems to magically find the main window from app.. do we need get app and mainWin to know each other?
    mainWin.show();
    return app.exec();
}
