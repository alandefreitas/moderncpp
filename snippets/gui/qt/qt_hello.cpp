#include <QApplication>
#include <QPushButton>
#include <iostream>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(100, 80);

    auto *buttonInfo = new QPushButton("Info", &window);
    buttonInfo->setGeometry(10, 10, 80, 30);
    QApplication::connect(buttonInfo, &QPushButton::clicked,
                          [] { std::cout << "Info" << std::endl; });

    auto *buttonQuit = new QPushButton("Quit", &window);
    buttonQuit->setGeometry(10, 40, 80, 30);
    QApplication::connect(buttonQuit, &QPushButton::clicked,
                          [] { QApplication::quit(); });

    window.show();
    return app.exec();
}
