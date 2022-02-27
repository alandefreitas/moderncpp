//[headers Headers
#include <QApplication>
#include <QPushButton>
//]
#include <iostream>

int main(int argc, char **argv) {
    //[QApplication Create Qt Application
    QApplication app(argc, argv);
    //]

    //[windows Create window
    QWidget window;
    window.setFixedSize(100, 80);
    //]

    //[button Create button and attach to window
    auto *buttonInfo = new QPushButton("Info", &window);
    buttonInfo->setGeometry(10, 10, 80, 30);
    //]

    //[button_cb Set button callback
    QApplication::connect(buttonInfo, &QPushButton::clicked,
                          [] { std::cout << "Info" << std::endl; });
    //]

    //[button_quit Create quit button
    auto *buttonQuit = new QPushButton("Quit", &window);
    buttonQuit->setGeometry(10, 40, 80, 30);
    //]

    //[button_quit_cb Set quit button callback
    QApplication::connect(buttonQuit, &QPushButton::clicked,
                          [] { QApplication::quit(); });
    //]

    //[run Run application
    window.show();
    return app.exec();
    //]
}