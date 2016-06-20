#ifndef PDFWIDGET_H
#define PDFWIDGET_H

#include <QWidget>
#include <QPushButton>

class PDFWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PDFWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    float fiveParams[5];
private:
    QPushButton * saveBtn;

signals:

public slots:
    void saveBtn_click();
};

#endif // PDFWIDGET_H
