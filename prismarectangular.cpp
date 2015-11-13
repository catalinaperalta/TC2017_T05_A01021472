#include "prismarectangular.h"
#include "ui_prismarectangular.h"

PrismaRectangular::PrismaRectangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrismaRectangular)
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

PrismaRectangular::~PrismaRectangular()
{
    delete ui;
}

void PrismaRectangular::paintEvent(QPaintEvent * p)
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
            drawPrismaRect(painter);
        }
    }
}

void PrismaRectangular::drawPrismaRect(QPainter & paint)
{
           int x0 = 0;
           int y0 = 50;
           int x1 = 50;
           int y1 = 50;
           int x2 = 0;
           int y2 = -100;
           int x3 = 50;
           int y3 = -100;


           int x4 = x0+30;
           int y4 = y0-50;
           int x5 = x1+30;
           int y5 = y1-50;
           int x6 = x2+30;
           int y6 = y2-50;
           int x7 = x3+30;
           int y7 = y3-50;

           paint.drawLine(x0,y0,x1,y1);
           paint.drawLine(x2,y2,x3,y3);
           paint.drawLine(x2,y2,x0,y0);
           paint.drawLine(x3,y3,x1,y1);

           paint.drawLine(x4,y4,x5,y5);
           paint.drawLine(x6,y6,x7,y7);
           paint.drawLine(x6,y6,x4,y4);
           paint.drawLine(x7,y7,x5,y5);

           paint.drawLine(x0,y0,x4,y4);
           paint.drawLine(x1,y1,x5,y5);
           paint.drawLine(x2,y2,x6,y6);
           paint.drawLine(x3,y3,x7,y7);
}

void PrismaRectangular::on_pushButton_clicked()
{
    paint = true;
    transformations.clear();
    QTransform object;
    object.translate(centerX, centerY);
    transformations.push_back(object);
    update();
}

void PrismaRectangular::on_pushButton_2_clicked()
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

void PrismaRectangular::on_pushButton_3_clicked()
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

void PrismaRectangular::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1.5,1.5);
    transformations.push_back(zoomIn);
    update();
}

void PrismaRectangular::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.7,0.7);
    transformations.push_back(zoomOut);
    update();
}

void PrismaRectangular::on_pushButton_6_clicked()
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
