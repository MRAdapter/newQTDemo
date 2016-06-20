#include "mainwidget.h"
#include <qdebug.h>
mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1366,768);
    this->setWindowTitle("主界面");
    fiveParams[0]= 40.0;
    fiveParams[1]= 40.0;
    fiveParams[2]= 0.117;
    fiveParams[3]= 0.06;
    fiveParams[4]= 0.06;
    //fiveparamsBtn
    fiveParamsBtn = new QPushButton(this);
    fiveParamsBtn->setGeometry(QRect(50,25,300,25));
    fiveParamsBtn->setText("默认参数(单位mm):40.0,40.0,0.117,0.06,0.06");
    this->connect(fiveParamsBtn,SIGNAL(clicked()),this,SLOT(fiveParams_click()));
    //makeBtn
    makePDFBtn = new QPushButton(this);
    makePDFBtn->setGeometry(QRect(50,200,100,25));
    makePDFBtn->setText("制作界面");
    this->connect(makePDFBtn,SIGNAL(clicked()),this,SLOT(makePDF_click()));
}

mainWidget::~mainWidget()
{

}

void mainWidget::fiveParams_click()
{
    fiveParamsView = new fiveParamsWidget(this);
    //关联信号和槽函数
    connect(fiveParamsView,SIGNAL(sendFiveParams(QString)),this,SLOT(receiveFiveParams(QString)));
    fiveParamsView->show();
}

void mainWidget::makePDF_click()
{
    pdfWidget = new PDFWidget(this);
    pdfWidget->fiveParams[0] = fiveParams[0];
    pdfWidget->fiveParams[1] = fiveParams[1];
    pdfWidget->fiveParams[2] = fiveParams[2];
    pdfWidget->fiveParams[3] = fiveParams[3];
    pdfWidget->fiveParams[4] = fiveParams[4];
    pdfWidget->show();
}

void mainWidget::receiveFiveParams(QString fiveRecive)
{
    QStringList strlist=fiveRecive.split(",");
    fiveParams[0] = strlist[0].toFloat();
    fiveParams[1] = strlist[1].toFloat();
    fiveParams[2] = strlist[2].toFloat();
    fiveParams[3] = strlist[3].toFloat();
    fiveParams[4] = strlist[4].toFloat();
    //    QString name = QString("%f").arg(fiveRecive[0]);
    fiveParamsBtn->setText(fiveRecive);
}
