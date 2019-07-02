#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QGeoRoute>
#include <QGeoPath>
#include <QQuickView>
#include <QQmlComponent>
#include <QQmlContext>
#include <QThread>
#include "myThread.h"
#include "graph.h"
#include "read.h"
#include <set>
#include <QGeoCoordinate>
#include <QAtomicInteger>
#include <QMutex>
#include <QFileInfo>
#include<chrono>
#include"../../Mapping/convex_hull/src/grahamScan.h"
#define nNodos 5
#define nodoini 4362423164
#define distMax 100000
#ifndef LAVAINA
#define LAVAINA
#endif

using namespace std::chrono;

//chorrillos 4362423164  miraflores 263615940 lima 791159777
int main(int argc, char *argv[])
{
    int numThreads = QThread::idealThreadCount();
    graph g1;
    rd gg;
    gg.getGraph(&g1);
    g1.iniciar_taxis(nNodos);


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QGeoPath geopath;





    for (list<Node<Graph<Traits>>*>::iterator  j = lista.begin(); j != lista.end(); ++j) {
        geopath.addCoordinate(QGeoCoordinate((*j)->get_y(), (*j)->get_x()));
    }

    engine.rootContext()->setContextProperty("geopath", QVariant::fromValue(geopath));
    engine.load(QUrl::fromLocalFile(QFileInfo("main.qml").absoluteFilePath()));
    QQmlComponent component(&engine,QUrl::fromLocalFile(QFileInfo("main.qml").absoluteFilePath()));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
