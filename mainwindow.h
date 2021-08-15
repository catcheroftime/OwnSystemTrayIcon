#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class OwnSyetemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
   virtual void closeEvent(QCloseEvent *e) override;

private:
    void initTrayIcon();

private:
    Ui::MainWindow *ui;

    OwnSyetemTrayIcon *m_trayIcon;
    bool m_realClose;
};

#endif // MAINWINDOW_H
