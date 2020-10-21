#include <QApplication>
#include <QPushButton>
#include <thread>

int main(int argc, char **argv) {
    std::thread t([&]() {
        QApplication app(argc, argv);

        QWidget window;
        window.setFixedSize(100, 80);

        QPushButton *buttonInfo = new QPushButton("Info", &window);
        buttonInfo->setGeometry(10, 10, 80, 30);

        QPushButton *buttonQuit = new QPushButton("Quit", &window);
        buttonQuit->setGeometry(10, 40, 80, 30);

        window.show();

        return app.exec();
    });

    t.join();

    // Add your code here
}