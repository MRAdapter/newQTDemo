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
    label1->setGeometry(QRect(50,30,100,25));
    label1->setText("背景宽:(单位mm)");

    label2 = new QLabel(this);
    label2->setGeometry(QRect(50,60,100,25));
    label2->setText("背景高:(单位mm)");

    label3 = new QLabel(this);
    label3->setGeometry(QRect(50,90,100,25));
    label3->setText("点间距:(单位mm)");

    label4 = new QLabel(this);
    label4->setGeometry(QRect(50,120,100,25));
    label4->setText("小图宽:(单位mm)");

    label5 = new QLabel(this);
    label5->setGeometry(QRect(50,150,100,25));
    label5->setText("小图高:(单位mm)");

    bigWidth = new QTextEdit(this);
    bigWidth->setGeometry(QRect(200,30,100,25));

    bigHeight = new QTextEdit(this);
    bigHeight->setGeometry(QRect(200,60,100,25));

    spaceLong = new QTextEdit(this);
    spaceLong->setGeometry(QRect(200,90,100,25));

    elementWidth = new QTextEdit(this);
    elementWidth->setGeometry(QRect(200,120,100,25));

    elementHeight = new QTextEdit(this);
    elementHeight->setGeometry(QRect(200,150,100,25));

    sureBtn = new QPushButton(this);
    sureBtn->setGeometry(50,200,100,25);
    sureBtn->setText("确认");
    this->connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtn_click()));

    backBtn = new QPushButton(this);
    backBtn->setGeometry(200,200,100,25);
    backBtn->setText("取消");
    this->connect(backBtn,SIGNAL(clicked()),this,SLOT(backBtn_click()));
}

void fiveParamsWidget::sureBtn_click()
{
    QString needSendStr =bigWidth->toPlainText()+","+bigHeight->toPlainText()+","+spaceLong->toPlainText()+","+elementWidth->toPlainText()+","+elementHeight->toPlainText();
    sendFiveParams(needSendStr);
    this->close();
}

void fiveParamsWidget::backBtn_click()
{
    this->close();
}
