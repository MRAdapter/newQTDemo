#include "pdfwidget.h"
#include <QPainter>
//#include <QPdfWriter>
#include <QPrinter>
#include <math.h>
#include <QFile>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#define  pxPerUm 72/25.4
PDFWidget::PDFWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(1366,768);
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
    QDesktopWidget *d=QApplication::desktop();
    int width=d->width(); //屏幕宽度
    int height=d->height(); //屏幕高度
    qDebug("%d~~%d",width,height);
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
}

void PDFWidget::saveBtn_click()
{
    //    QFile pdf_file("/Users/wxt/Desktop/demo.pdf");

    //    pdf_file.open(QIODevice::WriteOnly);
    //    QPdfWriter *pdf_writer = new QPdfWriter(&pdf_file);

    //    QPainter *pdf_painter= new QPainter(pdf_writer);
    //    pdf_writer->setPageSize(QPagedPaintDevice::Custom);
    //    float pdf_width = fiveParams[0]*pxPerUm;
    //    float pdf_height = fiveParams[1]*pxPerUm;
    //    pdf_writer->setPageSizeMM(QSizeF(pdf_width,pdf_width));

    //    pdf_painter->setPen(Qt::black);
    //    pdf_painter->setBrush(Qt::black);
    //    //画圆
    //    float spaceLong= fiveParams[2]*pxPerUm;
    //    int xCount = pdf_width/spaceLong;
    //    int yCount = pdf_height/spaceLong;
    //    float x = 0;
    //    float y = 0;
    //    float width = fiveParams[3]*pxPerUm;
    //    float height = fiveParams[4]*pxPerUm;
    //    for(int i= 0;i<yCount;i++){
    //        y = i*spaceLong*sqrt(3)/2;
    //        for(int j=0;j<xCount;j++){
    //            if(i%2){
    //                x = j*spaceLong;
    //            }else{
    //                x = j*spaceLong+0.5*spaceLong;
    //            }
    //            pdf_painter->drawEllipse(QRectF(x,y,width,height));
    //        }
    //    }
    //    delete pdf_painter;
    //    delete pdf_writer;
    //    pdf_file.close();

    QPrinter printer_pixmap(QPrinter::ScreenResolution);
    printer_pixmap.setPageSize(QPrinter::Custom);  //设置纸张大小为A4
    float pdf_width = fiveParams[0]*pxPerUm;
    float pdf_height = fiveParams[1]*pxPerUm;
    printer_pixmap.setPaperSize(QSizeF(400.0, 400.0), QPrinter::Millimeter);
    printer_pixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
    printer_pixmap.setOutputFileName("E:\\test_pixmap.pdf");   //设置输出路径
    //    QPixmap pixmap = QPixmap::grabWidget(main_widget, main_widget->rect());  //获取界面的图片

    QPainter painter_pixmap;
    painter_pixmap.begin(&printer_pixmap);
    painter_pixmap.setPen(Qt::black);
    painter_pixmap.setBrush(Qt::black);
    //画圆
    float WspaceLong= fiveParams[2]*pxPerUm;
    float HspaceLong= WspaceLong*sqrt(3)/2;
    int xCount = pdf_width/WspaceLong;
    int yCount = pdf_height/HspaceLong;
    float x = 0;
    float y = 0;
    float width = fiveParams[3]*pxPerUm;
    float height = fiveParams[4]*pxPerUm;
//    for(int i= 0;i<200;i++){
//        y = i*0.5+0.5*0.25;
//        for(int j=0;j<200;j++){
//            if(i%2){
//                x = j*0.5+0.5*0.25;
//            }else{
//                x = j*0.5+0.5*0.5+0.5*0.25;
//            }
//            painter_pixmap.drawEllipse(QRectF(x,y,0.25,0.25));
//        }
//    }
//    painter_pixmap.drawRect(0,0,40*pxPerUm*sqrt(2),40*pxPerUm*sqrt(2));
    QPixmap pixmap = QPixmap::grabWidget(this, this->rect());  //获取界面的图片
    QRect rect = painter_pixmap.viewport();
    int multiple = rect.width()/pixmap.width();
    painter_pixmap.scale(multiple, multiple); //将图像(所有要画的东西)在pdf上放大multiple-1倍
    painter_pixmap.drawPixmap(0, 0, pixmap);
    qDebug("%f",pxPerUm);
    painter_pixmap.end();
    QMessageBox::information(this,tr("提示"),tr("保存成功！！！"));
}
