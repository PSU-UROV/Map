#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow()
	: ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

#include "mainwindow.moc"
