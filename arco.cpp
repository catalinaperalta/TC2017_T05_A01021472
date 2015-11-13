#include "arco.h"
#include "ui_arco.h"
#include <math.h>

#define PI 3.1415

Arco::Arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arco)
{
    ui->setupUi(this);
    ui->pushButton->setText("Original");
    ui->pushButton_3->setText("Traslación");
    ui->pushButton_4->setText("Zoom in");
    ui->pushButton_5->setText("Zoom out");
    ui->pushButton_6->setText("Reflexión");
    ui->pushButton_2->setText("Rotación");

    paint = false;
    angle = 0;
    radius = 0;

    centerX = width()/2;
    centerY = height()/2;
}

Arco::~Arco()
{
    delete ui;
}

void Arco::paintEvent(QPaintEvent * p)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    if(paint)
    {
        QString rad = ui->plainTextEdit_3->toPlainText();
        QString ang = ui->plainTextEdit_4->toPlainText();

        int _radius = rad.toInt();
        int _angle = ang.toInt();

        if(!rad.isEmpty() && !ang.isEmpty())
        {
            for(int i = 0; i<transformations.size(); i++)
            {
                painter.setTransform(transformations[i], true);
                drawArco(_radius, _angle, painter);
            }

            update();
        }

    }
}

void Arco::drawArco(int radius, int angle, QPainter & paint)
{
        int x = 0;
        int y = radius;
        double p = 5.0/4.0-y;

        int maxx = 0;
        int maxy = 0;

        int oct = (angle - (angle % 45)) / 45;
        double limit1 = tan((90.0 - (angle % 90)) * PI / 180.0) * x;
        double limit2 = tan((45.0 + (angle % 45)) * PI / 180.0) * x;

        if (oct > 0 || (oct == 0 && y > limit1))
            paint.drawPoint(maxx+x,maxy-y);
        if (oct > 1 || (oct == 1 && y <= limit2))
            paint.drawPoint(maxx+y,maxy-x);
        if (oct > 2 || (oct == 2 && y > limit1))
            paint.drawPoint(maxx+y,maxy+x);
        if (oct > 3 || (oct == 3 && y <= limit2))
            paint.drawPoint(maxx+x,maxy+y);
        if (oct > 4 || (oct == 4 && y > limit1))
            paint.drawPoint(maxx-x,maxy+y);
        if (oct > 5 || (oct == 5 && y <= limit2))
            paint.drawPoint(maxx-y,maxy+x);
        if (oct > 6 || (oct == 6 && y > limit1))
            paint.drawPoint(maxx-y,maxy-x);
        if (oct > 7 || (oct == 7 && y <= limit2))
            paint.drawPoint(maxx-x,maxy-y);

        while(y > x)
        {
            if(p < 0)
                p += 2.0 * x + 3.0;
            else {
                p += 2.0 * (x - y) + 5.0;
                y--;
            }

            x++;


            int maxx = 0;
            int maxy = 0;

            int oct = (angle - (angle % 45)) / 45;
            double limit1 = tan((90.0 - (angle % 90)) * PI / 180.0) * x;
            double limit2 = tan((45.0 + (angle % 45)) * PI / 180.0) * x;

            if (oct > 0 || (oct == 0 && y > limit1))
                paint.drawPoint(maxx+x,maxy-y);
            if (oct > 1 || (oct == 1 && y <= limit2))
                paint.drawPoint(maxx+y,maxy-x);
            if (oct > 2 || (oct == 2 && y > limit1))
                paint.drawPoint(maxx+y,maxy+x);
            if (oct > 3 || (oct == 3 && y <= limit2))
                paint.drawPoint(maxx+x,maxy+y);
            if (oct > 4 || (oct == 4 && y > limit1))
                paint.drawPoint(maxx-x,maxy+y);
            if (oct > 5 || (oct == 5 && y <= limit2))
                paint.drawPoint(maxx-y,maxy+x);
            if (oct > 6 || (oct == 6 && y > limit1))
                paint.drawPoint(maxx-y,maxy-x);
            if (oct > 7 || (oct == 7 && y <= limit2))
                paint.drawPoint(maxx-x,maxy-y);
        }
}

void Arco::on_pushButton_clicked()
{
    paint = true;
    transformations.clear();
    QTransform object;
    object.translate(centerX, centerY);
    transformations.push_back(object);
    update();
}

void Arco::on_pushButton_2_clicked()
{
    QString ang = ui->plainTextEdit_5->toPlainText();

    if(!ang.isEmpty())
    {
        double angulo = ang.toDouble();
        QTransform rotation;
        rotation.rotate(angulo);
        transformations.push_back(rotation);
        update();
    }

}

void Arco::on_pushButton_3_clicked()
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

void Arco::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1.5,1.5);
    transformations.push_back(zoomIn);
    update();
}

void Arco::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.7,0.7);
    transformations.push_back(zoomOut);
    update();
}

void Arco::on_pushButton_6_clicked()
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
