#ifndef H_QTQLIST
#define H_QTQLIST

#include <QDebug>
#include <QList>
#include <QRandomGenerator>
#include <QSharedPointer>

class Test2
{
public:
    Test2(){qInfo()<<"Test: construction";}
    ~Test2(){qInfo()<<"Test: deconstruction";}
};

class QtQList
{
public:
    static void qt_qlist()
    {
        creating_adding_data();
        modifying_data();
        searching_list();
        memory_stuff();
    }

    static void memory_stuff()
    {
        QList<Test2*> list;
        for(int i = 0; i<5;i++)
            list.append(new Test2());

        qDeleteAll(list);
        list.clear();

        QList<QSharedPointer<Test2>> smart_list;
        for(int i = 0; i<5; i++)
        {
            QSharedPointer<Test2> item(new Test2);
            smart_list.append(item);
        }

        smart_list.removeFirst();
        smart_list.clear();
    }

    static void searching_list()
    {
        QList<int> list = getNumbers();
        int item = 999;
        list.insert(0, item);
        list.append(item);

        //First
        int fpos = list.indexOf(item, 0);
        qInfo() << "Position of " << item << " is " << fpos;

        //Last
        int lpos = list.lastIndexOf(item);
        qInfo() << "Last" << lpos;

        //All
        int pos = list.indexOf(item);
        do{
            qInfo() << "At" << pos;
            pos = list.indexOf(item, pos + 1);
        }while(pos > -1);


        for(const auto& item : list)
            qInfo() << list.indexOf(item) << "=" << item;

        qInfo() << "Contains" << list.contains(item);

        //Get a slice
        QList<int> items = list.mid(0,2);
        qInfo()<<list;
        qInfo()<<items;

    }

    static void modifying_data()
    {
        QList<int> list = getNumbers();

        // direct mod
        list[0] = 5;
        // list.at(0) = 4; // bad

        //appending
        list.append(99);
        list << 3000 << 4000;

        //inserting
        list.insert(0, 55);
        list.insert(1, 255);

        //removing
        list.removeAt(1);
        list.removeOne(99);
        list.removeAll(255);
        // list.remove(1,2); // removes 2 elements starting from 1st index
        
        for(const auto& item : list)
            qInfo() << list.indexOf(item) << "=" << item;

    }

    static QList<int> getNumbers()
    {
        QList<int> list; 

        //use the operator
        list << 300 << 400 << 500;
        int max = QRandomGenerator::global()->bounded(1, 10);
        for(int i = 0; i<max; i++)
        {
            list.append(QRandomGenerator::global()->bounded(1, 100));
        }

        return list;
    }

    static void test_numbers()
    {
        QList<int> list = getNumbers();
        qInfo() << list;

        qInfo() << "Length" << list.length();
        qInfo() << "Count" << list.count();
        qInfo() << "Size" << list.size();

        for(int i = 0; i<list.length(); i++)
        {
            qInfo() << i << "=" << list.at(i) << "(is const) or" << list[i] << "(is modifiable)";
        }

        for(const auto& item:list)
        {
            qInfo() << item;
        }
    }

    static void creating_adding_data()
    {
        test_numbers();
    }
};

#endif