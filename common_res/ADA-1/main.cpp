#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QGeoRoute>
#include <QGeoCoordinate>
#include <QQmlComponent>
//#include<graph.h>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlComponent component(&engine,QUrl::fromLocalFile("qrc:/misListas.qml"));
    QObject *misListas = component.create();

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
