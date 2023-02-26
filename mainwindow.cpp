#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_units.append("Meter");
    m_units.append("Inch");
    m_units.append("Foot");
    m_units.append("Yard");

    m_bases.append(1);
    m_bases.append(0.0254);
    m_bases.append(0.3048);
    m_bases.append(0.9144);

    ui->optFrom->addItems(m_units);
    ui->optTo->addItems(m_units);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_from_textChanged(const QString &arg1)
{
    updateLengths();
}

void MainWindow::updateLengths()
{
    QString text = ui->optFrom->currentText();

    float base = m_bases[m_units.indexOf(text)];
    if (ui->from->text().length() == 0)
        return;
    float from = ui->from->text().toFloat();

    float intermediate = base * from;

    float base2 = m_bases[m_units.indexOf(ui->optTo->currentText())];

    float answer = intermediate / base2;
    QString answerStr = QString::number(answer);
    ui->to->setText(answerStr);
}


void MainWindow::on_optFrom_currentTextChanged(const QString &arg1)
{
    updateLengths();
}

void MainWindow::on_optTo_currentTextChanged(const QString &arg1)
{
    updateLengths();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,
                         "About",
                         "Unit Converter - A simple tool to convert between lengths.\n"
                         "Created by Reuben Kabiti Junior\n"
                         "Have fun (or try not to ;-) )");

}






