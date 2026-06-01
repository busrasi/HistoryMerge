#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "GameBoardModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GameBoardModel boardModel;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gameBoardModel", &boardModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
        );

    engine.loadFromModule("HistoryMerge", "Main");

    return app.exec();
}