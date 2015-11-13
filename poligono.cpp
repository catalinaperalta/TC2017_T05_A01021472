#include "poligono.h"
#include "ui_poligono.h"

Poligono::Poligono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligono)
{
    ui->setupUi(this);
    ui->pushButton->setText("Original");
    ui->pushButton_3->setText("Traslación");
    ui->pushButton_4->setText("Zoom in");
    ui->pushButton_5->setText("Zoom out");
    ui->pushButton_6->setText("Reflexión");
    ui->pushButton_2->setText("Rotación");
    paint = false;
    sides = 0;

    centerX = width()/2;
    centerY = height()/2;
}

void Poligono::paintEvent(QPaintEvent * p)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    if(paint)
    {
        QString numSides = ui->plainTextEdit->toPlainText();

        if(!numSides.isEmpty())
        {
            painter.setPen(pen);
            sides = numSides.toInt();

            for(int i = 0; i<transformations.size(); i++)
            {
                painter.setTransform(transformations[i], true);
                drawPolygon(sides, painter);
            }

        }
    }
}

void Poligono::drawPolygon(int sides, QPainter & paint)
{
    double radio = 100;
        double angulo = (double)360.0/(double)sides;
        double xCentro = 0.0;
        double yCentro = 0.0;

        int xi,yi,xf,yf;
        double val = M_PI / 180;
        angulo *= val;
        int i = 0;

        for(i=1; i<=sides; i++)
        {
            xi = xCentro + (radio * cos(angulo*i));
            yi = yCentro + (radio * sin(angulo*i));

            xf = xCentro + (radio * cos(angulo*(i+1)));
            yf = yCentro + (radio * sin(angulo*(i+1)));
            paint.drawLine(xi, yi, xf, yf);

        }
}

void Poligono::on_pushButton_clicked()
{
    paint = true;
    transformations.clear();
    QTransform object;
    object.translate(centerX, centerY);
    transformations.push_back(object);
    update();
}

void Poligono::on_pushButton_2_clicked()
{
    QString ang = ui->plainTextEdit_4->toPlainText();

    if(!ang.isEmpty())
    {
        double angulo = ang.toDouble();
        QTransform rotation;
        rotation.rotate(angulo);
        transformations.push_back(rotation);
        update();
    }
}

void Poligono::on_pushButton_3_clicked()
{
    QString x = ui->plainTextEdit_2->toPlainText();
    QString y = ui->plainTextEdit_3->toPlainText();

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

void Poligono::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1.5,1.5);
    transformations.push_back(zoomIn);
    update();
}

void Poligono::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.7,0.7);
    transformations.push_back(zoomOut);
    update();
}

void Poligono::on_pushButton_6_clicked()
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
