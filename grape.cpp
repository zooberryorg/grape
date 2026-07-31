#include "grape.h"
#include "./ui_grape.h"

GrapeW::GrapeW(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::grape)
{
    ui->setupUi(this);
}

GrapeW::~GrapeW()
{
    delete ui;
}
