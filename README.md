# libui-qtlike

Qt-like library that interfaces with `libui`.

`libui` being a C lightweight multi-platform UI library, `libui-qtlike` provides a `C++` interface.

Instead of inventing a new class design, it provides an interface that is as close to the Qt one as possible.  
A welcome side effect being that one can easily start a project with `libui` and, if the project get bigger and needs a more powerful library, it's easy to switch to Qt.

Of course, the UI of a `libui-qtlike` will not look like Qt, except if you are using the Qt backend.

The initial implementation aims at get one of the basic Qt examples to run: <http://doc.qt.io/qt-5/qtwidgets-mainwindows-application-example.html>

## Current state

Currently, it's possible to create a main window with a menu:

~~~.cpp
#include "libui-qtlike/libui-qtlike.h"
#include <vector>

using namespace std;

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
    UI::Menu *fileMenu = menuBar()->addMenu("_File");
    UI::Action *newAction = new UI::Action("_New", this);
    fileMenu->addAction(newAction);
}

int main(int argc, char *argv[])
{

    UI::Application app(argc, argv);

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
~~~

## Building

Currently, `libui-qtlike` has only been tested on Linux.

- compile `libui` and copy the `.h` and `.so` files in the `libui/` directory
- compile and run the example:

  ~~~.sh
  mkdir build/
  cd build/
  cmake ..
  make
  ./main-window
  ~~~

## Differences to Qt

- The Q from the Qt classes is replaced by the UI namespace.

## Todo

### Next tasks

- add the quit menu entry

### Other tasks

- do not define the title and the size of the window in the `MainWindow` creator, or let the user change it after the fact (or add them as parameters to the `MainWindow`'s creator, if Qt does it thise way)
- find a command line parser with a similar interface (or one that can be made compatible)
- how to implement signals and slots?
  - <https://testbit.eu/cpp11-signal-system-performance/> / <https://testbit.eu/~timj/blogstuff/simplesignal.cc>
  - <http://www.codeproject.com/Articles/867044/Yassi-Yet-Another-Signal-Slot-Implementation>
- a `tr()` translation module.
  - <https://github.com/tinygettext/tinygettext/blob/master/LICENSE.md>
  - gettext

    ~~~.cpp
    #include <libintl.h>
    #include <iostream>
    #define _(x) gettext(x)

    int main (){
            std::cout << _("hello, world!\n");
    }
    ~~~

  - <https://github.com/cbeck88/spirit-po>
  - <http://helloworld922.blogspot.ch/2013/07/thread-safe-signalsslots-using-c11.html>
  - <http://simmesimme.github.io/tutorials/2015/09/20/signal-slot/>
- using utf-8: http://utfcpp.sourceforge.net/
### Long term
