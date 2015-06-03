#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralWidget->setLayout(ui->verticalLayout_2);
    for(int i=0;i<8;i++)
    {
        pb[i]=0;
        pbn[i]=0;
    }





}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_Active=!m_Active;
    if(m_Active)
    {
        SerialStream ar;
        ar.Open("/dev/ttyUSB0");
        ar.SetBaudRate(SerialStreamBuf::BAUD_57600);
        ar.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);

        if(!ar.IsOpen())
        {
            ui->textEdit->setTextColor(Qt::red);
            ui->textEdit->insertPlainText("Something is wrong, check connection\n");
            ui->textEdit->setTextColor(Qt::black);
        }


        unsigned char str;
        QByteArray res;
        while(ar.IsOpen())
        {
            res.clear();
            ar>>str;
            res.append(str);

            int q=str;
            q=255-q;

            for(int i=0;i<8;i++)
            {
                pb[i]=pbn[i];
                pbn[i]=0;
            }


            vector<string> vec;
            vec.clear();
            for(int i=0;i<8;i++)
            {
                int w=q&1;
                if(w==1)
                {
                    pbn[i]=true;
                    vec.push_back(Buttons[i]);
                }


                q>>=1;
            }

            for(int i=0;i<8;i++)
            {
                QString sp,su;
                sp="xte \'keydown "+QString::fromStdString(Buttons[i])+"\'";
                su="xte \'keyup "+QString::fromStdString(Buttons[i])+"\'";
                if(pbn[i]==1 && pb[i]==0)
                    system(sp.toStdString().c_str());

                if(pbn[i]==0 && pb[i]==1){
                    system(su.toStdString().c_str());system(su.toStdString().c_str());}
            }


        }
        ar.Close();

    }
}

//            foreach (string s,vec) {


//            qDebug()<<QString::fromStdString(s);
//            QString ss="xte 'keydown "+ QString::fromStdString(s) + "\'";
//            QString ss2="xte 'keyup "+ QString::fromStdString(s) + "\'";
//            system(ss.toStdString().c_str());
//            system(ss2.toStdString().c_str());
//            }



