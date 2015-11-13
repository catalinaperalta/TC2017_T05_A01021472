#ifndef PRISMATRIANGULAR_H
#define PRISMATRIANGULAR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class PrismaTriangular;
}

class PrismaTriangular : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaTriangular(QWidget *parent = 0);
    ~PrismaTriangular();

private:
    Ui::PrismaTriangular *ui;
    bool paint;
    QVector<QTransform> transformations;

    double centerX, centerY;

protected:
    void paintEvent(QPaintEvent * p);
    void drawPrismaTri(QPainter & paint);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};

#endif // PRISMATRIANGULAR_H
