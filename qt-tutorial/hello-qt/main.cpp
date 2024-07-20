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
#include <QStorageInfo>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

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

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

void compileTime()
{
#ifdef Q_OS_LINUX
    qInfo() << "Hello from Linux";
#endif
}

void runTime()
{
    QSysInfo info;
    qInfo() << "prettyProductName:" << info.prettyProductName();
    qInfo() << "productType:" << info.productType();
    qInfo() << "productVersion:" << info.productVersion();
    qInfo() << "machineHostName:" << info.machineHostName();
    qInfo() << "machineUniqueId:" << info.machineUniqueId();
    qInfo() << "currentCpuArchitecture:" << info.currentCpuArchitecture();
    qInfo() << "buildCpuArchitecture:" << info.buildCpuArchitecture();
    qInfo() << "buildAbi:" << info.buildAbi();
}

void determine_os()
{
    compileTime();
    runTime();
}

void display_storage(QStorageInfo &storage)
{
    qInfo() << "---" << storage.displayName() << "---";
    qInfo() << "Root:" << storage.rootPath();
    qInfo() << "Name:" << storage.name();
    qInfo() << "Is root?:" << storage.isRoot();
    qInfo() << "Block size:" << storage.blockSize()/1024 << "KB";
    qInfo() << "Total size:" << storage.bytesTotal()/1024/1024 << "MB";
    qInfo() << "Available:" << storage.bytesAvailable()/1024/1024 << "MB";
    qInfo() << "Free:" << storage.bytesFree()/1024/1024 << "MB";
    qInfo() << "File system:" << storage.fileSystemType();
    qInfo() << "Is ready?:" << storage.isReady();
    qInfo() << "Is read only?:" << storage.isReadOnly();
    qInfo() << "Root path:" << storage.rootPath();
    qInfo() << "-----------";
}

void storage_info()
{
    QStorageInfo root = QStorageInfo::root();
    display_storage(root);
    for(auto &volume : QStorageInfo::mountedVolumes())
        display_storage(volume);

    for(auto &vol : QStorageInfo::mountedVolumes())
        qInfo() << vol.displayName() << "\t" << vol.device() << "\t" << vol.name() << "\t" << vol.fileSystemType() << "\t" << vol.bytesTotal();
}

void qmessage_handler_examples()
{
    QTextStream usrInput(stdin);
    QTextStream print(stdout);

    print << "Give me some text: " << Qt::flush;
    QString text = usrInput.readLine();
    print << "You've written: " << text << "\n";
    print.flush();

    qInstallMessageHandler(myMessageOutput);

    qDebug() << "Debug info";
    qInfo() << "Some info";
    qWarning() << "Some warning";
    qCritical() << "Critical info";
    qFatal("Fatal error");

    qInstallMessageHandler(0);
}

void test_list(QString path, bool recursive = false)
{
    QDir root(path);
    if(!root.exists())
    {
        qWarning() << "Path not found!";
        return;
    }

    QFileInfoList list = root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries);

    for(QFileInfo file : list)
    {
        qInfo() << "-----------------";
        qInfo() << file.fileName();

        if(recursive && file.isDir()) test_list(file.absoluteFilePath(), recursive);
    }
}

void test_modify(QDir root)
{
    if(root.exists("test"))
    {
        qInfo() << "already exists";
        root.rename("test", "test2");
        root.rmpath("test2/a/b/c");
        return;
    }

    root.mkdir("test");
    root.mkpath("test/a/b/c");
    root.rmpath("test");
}

void directory_info()
{
    qInfo() << QDir::currentPath();

    QDir dir;
    qInfo() << dir.absolutePath();

    test_list(dir.absolutePath(), true);
    test_modify(dir);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qInfo() << app.applicationFilePath();

    // qt_qobject(&app);
    // qt_user_input();
    // qt_delete_all();
    // smart_pointers();
    // qt_qstring();
    // qt_qstringview();
    // QtQByteArray::qt_qbytearray();
    // QtQList::qt_qlist();
    // QtQMap::qt_qmap();
    // qmessage_handler_examples();
    // determine_os();
    // storage_info();
    directory_info();


    int e = app.exec();
    qInfo() << "Exiting: " << e;
    return e;
}
