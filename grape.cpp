#include "grape.h"
#include "./ui_grape.h"

grape::grape(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::grape)
{
    ui->setupUi(this);
}

grape::~grape()
{
    delete ui;
}
