#ifndef H_QTQBYTEARRAY
#define H_QTQBYTEARRAY

#include <QByteArray>
#include <QDebug>

void stats(QByteArray &data)
{
    qInfo() << "Length" << data.length() << "Capacity" << data.capacity();
    qInfo() << data;
}

class QtQByteArray
{
public:
    static void qt_qbytearray()
    {
        qInfo() << "\n*** QByteArray";
        creatingArray();
        sizingArray();
        modifyingData();
        readingData();
        encodingData();
    }

    static void creatingArray()
    {
        // Creating an array
        QByteArray stuff;
        qInfo() << stuff;

        QByteArray data("Hello");
        qInfo() << data;

        QByteArray buffer(10, '\t');
        qInfo() << buffer;

        QByteArray person(QString("Wojtek").toLocal8Bit());
        qInfo() << person;
    }

    static void sizingArray()
    {
        // Sizing the array
        QByteArray data("Hello");
        data.reserve(25);
        stats(data);

        data.resize(10);
        stats(data);

        data.truncate(8);
        stats(data);

        data.clear();
        stats(data);
    }
    static void modifyingData()
    {
        // Modifying the data
        QByteArray data("Hello");
        data.resize(5);
        data.fill('\x02');
        stats(data);

        data.replace(0, 1, QByteArray("Sweet"));
        stats(data);

        data.fill('*');
        data.insert(3, QByteArray("Hello World"));
        stats(data);

        data.append("Wojtek");
        stats(data);

        data.remove(17, 9);
        stats(data);
    }

    static void readingData()
    {
        // reading the data
        QByteArray data("Hello");
        int first = data.indexOf('*');
        int last = data.lastIndexOf('*');
        if (first > -1 && last > -1)
            qInfo() << data.mid(first, last - first + 1);

        data.clear();
        data.append("Wojciech Konior");
        for (int i = 0; i < data.length(); i++)
        {
            qInfo() << "At" << data.at(i) << "or" << data[i];
        }

        foreach (auto item, data.split(' '))
            qInfo() << "itme" << item;
    }

    static void encodingData()
    {
        // encoding data
        QByteArray data("Hello");
        qInfo() << "Repeat" << data.repeated(3);
        data.append(QByteArray("\t\r\n"));
        data.insert(0, QByteArray("   \t\t\t"));
        qInfo() << "Normal" << data;
        qInfo() << "Trimmend" << data.trimmed();

        QByteArray hex = data.toHex();
        qInfo() << "Hex" << hex;

        QByteArray from_hex = QByteArray::fromHex(hex);
        qInfo() << "From Hex" << from_hex;

        QByteArray base64 = data.toBase64();
        qInfo() << "base64" << base64;

        QByteArray fromBase64 = QByteArray::fromBase64(base64);
        qInfo() << "from base64" << fromBase64;
    }
};

#endif