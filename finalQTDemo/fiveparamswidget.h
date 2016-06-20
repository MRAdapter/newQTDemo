#ifndef FIVEPARAMSWIDGET_H
#define FIVEPARAMSWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
class fiveParamsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit fiveParamsWidget(QWidget *parent = 0);
private:
        QTextEdit * bigWidth;
        QTextEdit * bigHeight;
        QTextEdit * spaceLong;
        QTextEdit * elementWidth;
        QTextEdit * elementHeight;

        QLabel * label1;
        QLabel * label2;
        QLabel * label3;
        QLabel * label4;
        QLabel * label5;

        QPushButton * sureBtn;
        QPushButton * backBtn;

signals:
    void  sendFiveParams(QString);
private slots:
    void sureBtn_click();
    void backBtn_click();
};

#endif // FIVEPARAMSWIDGET_H
