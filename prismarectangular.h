#ifndef PRISMARECTANGULAR_H
#define PRISMARECTANGULAR_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class PrismaRectangular;
}

class PrismaRectangular : public QDialog
{
    Q_OBJECT

public:
    explicit PrismaRectangular(QWidget *parent = 0);
    ~PrismaRectangular();

private:
    Ui::PrismaRectangular *ui;
    bool paint;
    QVector<QTransform> transformations;

    double centerX, centerY;

protected:
    void paintEvent(QPaintEvent * p);
    void drawPrismaRect(QPainter & paint);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};

#endif // PRISMARECTANGULAR_H
