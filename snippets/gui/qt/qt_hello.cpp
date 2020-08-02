#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QWidget window;
    window.setFixedSize(100, 80);

    QPushButton *buttonInfo = new QPushButton("Info", &window);
    buttonInfo->setGeometry(10, 10, 80, 30);

    QPushButton *buttonQuit = new QPushButton("Quit", &window);
    buttonQuit->setGeometry(10, 40, 80, 30);

    window.show();

    // Add your code here
    return app.exec();
}