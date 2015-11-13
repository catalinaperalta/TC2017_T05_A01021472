#include "cono.h"
#include "ui_cono.h"

Cono::Cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cono)
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

Cono::~Cono()
{
    delete ui;
}

void Cono::paintEvent(QPaintEvent * p)
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
            drawCono(painter);
        }
    }
}

void Cono::drawCono(QPainter & paint)
{
        int x1 = 0;
        int y1 = 90;
        paint.drawEllipse(-25,-17,50,25);
        paint.drawLine(x1,y1,-25,0);
        paint.drawLine(x1,y1,25,0);
}

void Cono::on_pushButton_clicked()
{
    paint = true;
    transformations.clear();
    QTransform object;
    object.translate(centerX, centerY);
    transformations.push_back(object);
    update();
}

void Cono::on_pushButton_2_clicked()
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

void Cono::on_pushButton_3_clicked()
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

void Cono::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(1.5,1.5);
    transformations.push_back(zoomIn);
    update();
}

void Cono::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.7,0.7);
    transformations.push_back(zoomOut);
    update();
}

void Cono::on_pushButton_6_clicked()
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
