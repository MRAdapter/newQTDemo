#include "mainwidget.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    mainWidget w;
    w.show();

    return a.exec();
}
