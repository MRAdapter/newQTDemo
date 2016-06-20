#ifndef FIVEPARAMSWIDGET_H
#define FIVEPARAMSWIDGET_H

#include <QWidget>
#include <QLabel>
class fiveParamsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit fiveParamsWidget(QWidget *parent = 0);
private:
        QLabel * bigWidth;
        QLabel * bigHeight;
        QLabel * spaceLong;
        QLabel * elementWidth;
        QLabel * elementHeight;

        QLabel * label1;
        QLabel * label2;
        QLabel * label3;
        QLabel * label4;
        QLabel * label5;
signals:

public slots:
};

#endif // FIVEPARAMSWIDGET_H
