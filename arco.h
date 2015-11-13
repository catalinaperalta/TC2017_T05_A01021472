#ifndef ARCO_H
#define ARCO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Arco;
}

class Arco : public QDialog
{
    Q_OBJECT

public:
    explicit Arco(QWidget *parent = 0);
    ~Arco();

private:
    Ui::Arco *ui;
    bool paint;
    int angle;
    int radius;
    QVector<QTransform> transformations;

    double centerX, centerY;

protected:
    void paintEvent(QPaintEvent * p);
    void drawArco(int radius, int angle, QPainter & paint);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};

#endif // ARCO_H
