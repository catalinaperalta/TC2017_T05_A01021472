#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "poligono.h"
#include "cubo.h"
#include "prismarectangular.h"
#include "prismatriangular.h"
#include "cono.h"
#include "arco.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Poligono");
    ui->pushButton_2->setText("Arco");
    ui->pushButton_3->setText("Cubo");
    ui->pushButton_4->setText("Prisma Rectangular");
    ui->pushButton_5->setText("Prisma Triangular");
    ui->pushButton_6->setText("Cono");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Poligono p;
    p.setModal(true);
    p.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Cubo c;
    c.setModal(true);
    c.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    PrismaRectangular pr;
    pr.setModal(true);
    pr.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    PrismaTriangular ptr;
    ptr.setModal(true);
    ptr.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    Cono c;
    c.setModal(true);
    c.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Arco a;
    a.setModal(true);
    a.exec();
}
