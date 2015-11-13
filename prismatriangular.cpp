#include "prismatriangular.h"
#include "ui_prismatriangular.h"

PrismaTriangular::PrismaTriangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaTriangular)
{
    ui->setupUi(this);
    ui->pushButton->setText("Original");
    ui->pushButton_3->setText("Traslación");
    ui->pushButton_4->setText("Zoom in");
    ui->pushButton_5->setText("Zoom out");
    ui->pushButton_6->setText("Reflexión");
    ui->pushButton_2->setText("Rotación");

    paint = false;

    centerX = width()/2;
    centerY = height()/2;
}

PrismaTriangular::~PrismaTriangular()
{
    delete ui;
}

void PrismaTriangular::paintEvent(QPaintEvent * p)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    if(paint)
    {
        for(int i = 0; i<transformations.size(); i++)
        {
            painter.setTransform(transformations[i], true);
            drawPrismaTri(painter);
        }
    }
}

void PrismaTriangular::drawPrismaTri(QPainter & paint)
{
     int x1 = 0;
     int y1 = -70;
     int x2 = -45;
     int y2 = -100;
     int x3 = 45;
     int y3 = -100;
     int _x1 = 0;
     int _y1 = 0;
     int _x2 = -45;
     int _y2 = -35;
     int _x3 = 45;
     int _y3 = -35;

     paint.drawLine(x1,y1,x2,y2);
     paint.drawLine(x1,y1,x3,y3);
     paint.drawLine(x2,y2,x3,y3);
     paint.drawLine(_x1,_y1,_x2,_y2);
     paint.drawLine(_x1,_y1,_x3,_y3);
     paint.drawLine(_x2,_y2,_x3,_y3);
     paint.drawLine(x1,y1,_x1,_y1);
     paint.drawLine(x2,y2,_x2,_y2);
     paint.drawLine(_x3,_y3,x3,y3);
}

void PrismaTriangular::on_pushButton_clicked()
{
    paint = true;
    transformations.clear();
    QTransform object;
    object.translate(centerX, centerY);
    transformations.push_back(object);
    update();
}

void PrismaTriangular::on_pushButton_2_clicked()
{
    QString ang = ui->plainTextEdit_3->toPlainText();

    if(!ang.isEmpty())
    {
        double angulo = ang.toDouble();
        QTransform rotation;
        rotation.rotate(angulo);
        transformations.push_back(rotation);
        update();
    }
}

void PrismaTriangular::on_pushButton_3_clicked()
{
    QString x = ui->plainTextEdit->toPlainText();
    QString y = ui->plainTextEdit_2->toPlainText();

    if(!x.isEmpty() && !y.isEmpty())
    {
        int _x = x.toInt();
        int _y = y.toInt();

        QTransform trans;
        trans.translate(_x, _y);
        transformations.push_back(trans);
        update();
    }
}

void PrismaTriangular::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1.5,1.5);
    transformations.push_back(zoomIn);
    update();
}

void PrismaTriangular::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.7,0.7);
    transformations.push_back(zoomOut);
    update();
}

void PrismaTriangular::on_pushButton_6_clicked()
{
    int _x = 1;
    int _y = 1;

    if(ui->radioButton->isChecked())
        _x = -1;
    else if(ui->radioButton_2->isChecked())
        _y = -1;

    QTransform reflexion;
    reflexion.scale(_x,_y);
    transformations.push_back(reflexion);
    update();
}
