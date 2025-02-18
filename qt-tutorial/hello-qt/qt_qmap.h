#ifndef H_QT_QMAP
#define H_QT_QMAP

#include <QDebug>
#include <QMap>
#include <QString>
#include <QSharedPointer>
#include "test.h"

typedef QMap<QString, QSharedPointer<Test>> TestMap;

class QtQMap
{
public:
    static void qt_qmap()
    {
        creating_qmap();
        
    }

    static void displaying_qmap(TestMap& tests)
    {
        foreach(QString key, tests.keys())
        {
            QSharedPointer<Test> ptr = tests.value(key);
            qInfo() << key << ptr;
        }
    }

    static void modifying_item(TestMap& tests)
    {
        QSharedPointer<Test> ptr(new Test());
        // tests.insert("test", ptr);
        tests["test"] = ptr;

        //searching for items
        qInfo() << "Exists:" << tests.contains("test");
        auto iter = tests.find("test");
        if(iter != tests.end()) qInfo() << iter.key() << iter.value();

        for(const auto& value : tests.values())
            qInfo() << value;

        for(const auto& key : tests.keys())
            qInfo() << key;

        if(!tests.contains("test"))
            qWarning() << "Cat not found";
            return;
        
        tests.remove("test");
        tests.clear();
    }

    static TestMap getTests()
    {
        TestMap tests;

        for(int i = 0; i<5; i++)
        {
            QSharedPointer<Test> ptr(new Test());
            tests.insert(QString("test"+QString::number(i)), ptr);
        }

        return tests;
    }

    static void creating_qmap()
    {
        QMap<QString, double> lucky;
        lucky.insert(QString("Wojtek"), 36);
        qInfo() << lucky;
        qInfo() << "My lucky number is:"<< lucky["Wojtek"];

        TestMap tests = getTests();
        qInfo() << tests;
        displaying_qmap(tests);

        modifying_item(tests);
    }
};

#endif