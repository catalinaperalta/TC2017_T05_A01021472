#ifndef POLIGONO_H
#define POLIGONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui
{
    class Poligono;
}

class Poligono : public QDialog
{
    Q_OBJECT

public:
    explicit Poligono(QWidget * parent = 0);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::Poligono * ui;
    bool paint;
    QVector<QTransform> transformations;
    int sides;
    double centerX, centerY;

protected:
    void paintEvent(QPaintEvent * p);
    void drawPolygon(int sides, QPainter & paint);
};

#endif // POLIGONO_H
