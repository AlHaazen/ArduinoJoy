#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>

#include <QDebug>
#include <SerialStream.h>
#include <QByteArray>
#include <string>
#include <stdlib.h>


using namespace std;

using namespace LibSerial;



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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *qport;
    bool m_Active=false;
    string Buttons[8]{ "Right", "Left", "Down", "Up", "Q", "W", "B", "A"}; //МАсив чарів і всьо збс
    bool pb[8], pbn[8];
};

#endif // MAINWINDOW_H
