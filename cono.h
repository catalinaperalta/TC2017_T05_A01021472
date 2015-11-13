#ifndef CONO_H
#define CONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Cono;
}

class Cono : public QDialog
{
    Q_OBJECT

public:
    explicit Cono(QWidget *parent = 0);
    ~Cono();

private:
    Ui::Cono *ui;
    bool paint;
    QVector<QTransform> transformations;

    double centerX, centerY;

protected:
    void paintEvent(QPaintEvent * p);
    void drawCono(QPainter & paint);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

};

#endif // CONO_H
