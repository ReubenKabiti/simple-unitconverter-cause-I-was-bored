#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_from_textChanged(const QString &arg1);

    void updateLengths();

    void on_optFrom_currentTextChanged(const QString &arg1);

    void on_optTo_currentTextChanged(const QString &arg1);

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QList<QString> m_units;
    QList<float> m_bases;
};

#endif // MAINWINDOW_H
