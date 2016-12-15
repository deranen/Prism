#include <QApplication>
#include <QSurfaceFormat>
#include <QBoxLayout>
#include "TriangleWidget.h"

int main(int argc, char **argv)
{
    QSurfaceFormat format;
    format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(16);

    QSurfaceFormat::setDefaultFormat(format);

    QApplication app(argc, argv);

    QWidget main_window;

    auto* widget1 = new TriangleWidget(&main_window);
    widget1->setRefreshRate(60);

    auto* widget2 = new TriangleWidget(&main_window);
    widget2->setRefreshRate(30);

    auto* widget3 = new TriangleWidget(&main_window);
    widget3->setRefreshRate(15);

    //auto* widget4 = new TriangleWidget(&main_window);
    //widget4->setRefreshRate(7.5);

    auto* layout = new QGridLayout();
    layout->addWidget(widget1, 0, 0);
    layout->addWidget(widget2, 0, 1);
    layout->addWidget(widget3, 1, 0, 1, 2);
    //layout->addWidget(widget4, 1, 1);

    main_window.resize(640, 480);
    main_window.setLayout(layout);
    main_window.show();

    return app.exec();
}