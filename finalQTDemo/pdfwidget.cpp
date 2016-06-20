#include "pdfwidget.h"
#include <QPainter>
#include <QPdfWriter>
#include <math.h>
#include <QFile>
#include <QMessageBox>
#define  pxPerUm 72/25.4
PDFWidget::PDFWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(800,800);
    this->setWindowTitle("最后效果");
    this->setAutoFillBackground(true);
    //设置背景色
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(192,253,123));
    this->setPalette(palette);
    this->update();

    //设置saveBtn
    saveBtn = new QPushButton(this);
    saveBtn->setGeometry(50,200,100,25);
    saveBtn->setText("保存图片");
    this->connect(saveBtn,SIGNAL(clicked()),this,SLOT(saveBtn_click()));
}

void PDFWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);  //设置画笔为红色
    painter.setPen(pen);  //选择画笔
    painter.setBrush(Qt::black);
    float spaceLong= fiveParams[2]*100*pxPerUm;
    int xCount = fiveParams[0]*pxPerUm/spaceLong;
    int yCount = fiveParams[1]*pxPerUm/spaceLong;
    float x = 0;
    float y = 0;
    float width = fiveParams[3]*100*pxPerUm;
    float height = fiveParams[4]*100*pxPerUm;
    for(int i= 0;i<yCount;i++){
        y = i*spaceLong*sqrt(3)/2;
        for(int j=0;j<xCount;j++){
            if(i%2){
                x = j*spaceLong;
            }else{
                x = j*spaceLong+0.5*spaceLong;
            }
            painter.drawEllipse(QRectF(x,y,width,height));
        }
    }
    painter.end();
    //    int i;
    //    QPainter painter(this);
    //    QPen pen;
    //    pen.setColor(QColor(255,0,0));  //设置画笔为红色
    //    painter.setPen(pen);  //选择画笔
    //    //画网格地图
    //    for(i=0;i<=100;i=i+Block)
    //    {
    //        painter.drawLine(0,i,this->width(),i);
    //    }
    //    for(i=0;i<=100;i=i+Block)
    //    {
    //        painter.drawLine(i,0,i,this->height());
    //    }


    //    painter.end();
}

void PDFWidget::saveBtn_click()
{
    QFile pdf_file("/Users/wxt/Desktop/demo.pdf");

    pdf_file.open(QIODevice::WriteOnly);
    QPdfWriter *pdf_writer = new QPdfWriter(&pdf_file);

    QPainter *pdf_painter= new QPainter(pdf_writer);
    pdf_writer->setPageSize(QPagedPaintDevice::Custom);
    float pdf_width = fiveParams[0]*pxPerUm;
    float pdf_height = fiveParams[1]*pxPerUm;
    pdf_writer->setPageSizeMM(QSizeF(pdf_width,pdf_width));

    pdf_painter->setPen(Qt::black);
    pdf_painter->setBrush(Qt::black);
    //画圆
    float spaceLong= fiveParams[2]*pxPerUm;
    int xCount = pdf_width/spaceLong;
    int yCount = pdf_height/spaceLong;
    float x = 0;
    float y = 0;
    float width = fiveParams[3]*pxPerUm;
    float height = fiveParams[4]*pxPerUm;
    for(int i= 0;i<yCount;i++){
        y = i*spaceLong*sqrt(3)/2;
        for(int j=0;j<xCount;j++){
            if(i%2){
                x = j*spaceLong;
            }else{
                x = j*spaceLong+0.5*spaceLong;
            }
            pdf_painter->drawEllipse(QRectF(x,y,width,height));
        }
    }
    delete pdf_painter;
    delete pdf_writer;
    pdf_file.close();
    QMessageBox::information(this,tr("提示"),tr("保存成功！！！"));
}
