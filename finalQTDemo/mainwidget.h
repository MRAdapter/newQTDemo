#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "pdfwidget.h"
#include <QPushButton>
#include "fiveparamswidget.h"
class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();
private:
       QPushButton * fiveParamsBtn;
       QPushButton * makePDFBtn;
       PDFWidget  * pdfWidget;
       fiveParamsWidget * fiveParamsView;
       float  fiveParams[5];

   public slots:
       void fiveParams_click();
       void makePDF_click();
};

#endif // MAINWIDGET_H
