#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include <QStringList>
#include <QScopedPointer>
#include <QSharedPointer>
#include "test.h"
#include <iostream>

QSharedPointer<Test> some_func()
{
    QString name = QString("%1 %2 %3").arg("Wojtek").arg("Konior").arg(36);
    qInfo() << name;

    QChar a = name.at(10);

    for(QChar c : name)
        qInfo()<<c;

    name.append(" hahaha");
    name.replace("hahaha", "Hello World");
    name = name.trimmed();

    qWarning()<<"Compare " << name.compare("Hello World", Qt::CaseSensitivity::CaseInsensitive);
    qCritical()<<"Starts " << name.startsWith("hello", Qt::CaseInsensitive);
    qDebug()<<"Ends " << name.endsWith("world", Qt::CaseInsensitive);
    qInfo()<<"Constains " << name.contains("wojtek", Qt::CaseInsensitive);
    qDebug()<<"Index " << name.indexOf("Konior");

    QStringList list = name.split(" ");

    QScopedPointer<Test> ptr(new Test());
    ptr->say_hello("Wojtek");
    QSharedPointer<Test> ptr2(new Test());

    QString str = "wojtek";

    std::cout << str.toStdString() << std::endl;


    return ptr2;
}

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

    auto ptr = some_func();

    int e = app.exec();

    qInfo() << "Exiting: " << e;

    return e;
}