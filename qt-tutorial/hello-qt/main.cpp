#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qInfo()<<"What is your name: ";

    QTextStream qin(stdin);
    QString name = qin.readLine();

    qInfo() << "Hello " << name;

    Test *obj = new Test(&app);
    Test *subobj = new Test(obj);
    QObject::connect(obj, &Test::close, &app, &QCoreApplication::quit, Qt::QueuedConnection);
    obj->dostuff();

    QList<Test*> list;
    for(int i = 0; i<10; i++)
        list.append(new Test());

    qDeleteAll(list);
    list.clear();

    int e = app.exec();

    qInfo() << "Exiting: " << e;

    return e;
}