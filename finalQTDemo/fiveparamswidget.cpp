#include "fiveparamswidget.h"

fiveParamsWidget::fiveParamsWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(480,270);
    this->setWindowTitle("设置五个参数");
    this->setAutoFillBackground(true);
    //设置背景色
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,253,123));
    //palette.setBrush(QPalette::Background, QBrush(QPixmap(":/background.png")));
    this->setPalette(palette);
//    设置10个label
    label1 = new QLabel(this);
    label1->setGeometry(QRect(50,25,100,25));
    label1->setText("背景宽:(单位um)");

    label2 = new QLabel(this);
    label2->setGeometry(QRect(50,50,100,25));
    label2->setText("背景高:(单位um)");

    label3 = new QLabel(this);
    label3->setGeometry(QRect(50,75,100,25));
    label3->setText("点间距:(单位um)");

    label4 = new QLabel(this);
    label4->setGeometry(QRect(50,100,100,25));
    label4->setText("小图宽:(单位um)");

    label5 = new QLabel(this);
    label5->setGeometry(QRect(50,125,100,25));
    label5->setText("小图高:(单位um)");

    label1 = new QLabel(this);
    label1->setGeometry(QRect(200,25,100,25));
    label1->setText("背景宽:(单位um)");

    label1 = new QLabel(this);
    label1->setGeometry(QRect(200,50,100,25));
    label1->setText("背景宽:(单位um)");
}
