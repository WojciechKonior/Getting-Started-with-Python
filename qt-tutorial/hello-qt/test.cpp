#include "test.h"

Test::Test(QObject* parent):QObject(parent)
{
    qInfo()<<"Test: constructed (parent: " << this->parent() << ")";
}

Test::~Test()
{
    qInfo()<<"Test: deconstructed (parent: " << this->parent() << ")";
}

void Test::dostuff()
{
    qInfo()<<"Test: doing stuff";
    emit close();
}

void Test::say_hello(const char* txt)
{
    qInfo()<<"Hello" << txt;
}