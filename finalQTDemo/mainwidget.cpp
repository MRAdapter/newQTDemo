#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
       this->resize(480,270);
       this->setWindowTitle("主界面");
//       fiveParams = {50,50,0.12,0.06,0.06};
       //fiveparamsBtn
       fiveParamsBtn = new QPushButton(this);
       fiveParamsBtn->setGeometry(QRect(50,25,100,25));
       fiveParamsBtn->setText("五个参数");
       this->connect(fiveParamsBtn,SIGNAL(clicked()),this,SLOT(fiveParams_click()));
       //makeBtn
       makePDFBtn = new QPushButton(this);
       makePDFBtn->setGeometry(QRect(300,25,100,25));
       makePDFBtn->setText("制作界面");
}

mainWidget::~mainWidget()
{

}

void mainWidget::fiveParams_click()
{
   fiveParamsView = new fiveParamsWidget(this);
   fiveParamsView->show();
}

void mainWidget::makePDF_click()
{

}
