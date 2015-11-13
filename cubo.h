#ifndef CUBO_H
#define CUBO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Cubo;
}

class Cubo : public QDialog
{
    Q_OBJECT

public:
    explicit Cubo(QWidget *parent = 0);
    ~Cubo();

private:
    Ui::Cubo *ui;
    bool paint;
    QVector<QTransform> transformations;

    double centerX, centerY;

protected:
    void paintEvent(QPaintEvent * p);
    void drawCube(QPainter & paint);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};

#endif // CUBO_H
