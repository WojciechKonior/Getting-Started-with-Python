#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include <QStringList>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QStringView>
#include <QByteArray>
#include "test.h"
#include <iostream>
#include "qt_qbytearray.h"
#include "qt_qlist.h"
#include "qt_qmap.h"

void qt_delete_all()
{
    qInfo() << "\n*** qDeleteAll";
    QList<Test*> list;
    for(int i = 0; i<10; i++)
        list.append(new Test());

    qDeleteAll(list);
    list.clear();
}

void smart_pointers()
{
    qInfo() << "\n*** QScopedPointer, QSharedPointer";
    QScopedPointer<Test> ptr(new Test());
    ptr->say_hello("Wojtek");
    QSharedPointer<Test> ptr2(new Test());
}

void qt_qstring()
{
    qInfo() << "\n*** QString";
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
    QString str = "wojtek";
    std::cout << str.toStdString() << std::endl;

}

void qt_user_input()
{
    qInfo() << "\n*** QTextStream";
    qInfo()<<"What is your name: ";

    QTextStream qin(stdin);
    QString name = qin.readLine();

    qInfo() << "Hello " << name;
}

void qt_qobject(QObject* app)
{
    qInfo() << "\n*** QObject";
    Test *obj = new Test(app);
    Test *subobj = new Test(obj);
    QObject::connect(
        obj, 
        &Test::close, 
        app, 
        &QCoreApplication::quit, 
        Qt::QueuedConnection
    );
    obj->dostuff();
}

void printStringView(QStringView str)
{
    qDebug()<<"This is stringView object: " << str;
    QList<QStringView> list = str.split(' ');
    for (QStringView part : list)
    {
        qDebug() << part;
    }
}

void qt_qstringview()
{
    qInfo() << "\n*** QStringView";
    QString name = "Wojciech Konior";
    printStringView(name);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // qt_qobject(&app);
    // qt_user_input();
    // qt_delete_all();
    // smart_pointers();
    // qt_qstring();
    // qt_qstringview();
    // QtQByteArray::qt_qbytearray();
    // QtQList::qt_qlist();
    QtQMap::qt_qmap();

    int e = app.exec();
    qInfo() << "Exiting: " << e;
    return e;
}