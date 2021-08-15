#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ownsyetemtrayicon.h"

#include <QMessageBox>
#include <QPushButton>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  , m_trayIcon(new OwnSyetemTrayIcon)
  , m_realClose(false)
{
    ui->setupUi(this);

    initTrayIcon();
}

MainWindow::~MainWindow()
{
    delete ui;

    SAFE_DELETE(m_trayIcon);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if (m_realClose) {
        e->accept();
        return;
    }

    QMessageBox msgbox;
    msgbox.setWindowTitle(CN("�ر���ʾ"));
    msgbox.setText(CN("������˹رհ�ť�������룺"));
    msgbox.addButton(QMessageBox::Yes)->setText(CN("��С��������"));
    msgbox.addButton(QMessageBox::No)->setText(CN("�˳�����"));

    if (msgbox.exec() == QMessageBox::No) {
        e->accept();

    } else {
        e->ignore();
        m_trayIcon->show();
        this->hide();

        QTimer::singleShot(1000, m_trayIcon, &OwnSyetemTrayIcon::startTrayFlash);
    }
}

void MainWindow::initTrayIcon()
{
    if (m_trayIcon) {
        connect(m_trayIcon, &OwnSyetemTrayIcon::sigNormalShow, this, [this]{this->show();
                                                                            this->m_trayIcon->stopTrayFlash();});
        connect(m_trayIcon, &OwnSyetemTrayIcon::sigClose, this, [this]{ this->m_realClose=true;
                                                                        this->close();});

        m_trayIcon->show();
    }
}

