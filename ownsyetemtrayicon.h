#ifndef OWNSYETEMTRAYICON_H
#define OWNSYETEMTRAYICON_H

#include <QObject>
#include <QSystemTrayIcon>

#define SAFE_DELETE(p) if(p) {delete p;p=nullptr;}

#ifdef __GNUC__
#define CN(ch)          QString::fromLocal8Bit(ch)
#else
#define CN(ch)          QStringLiteral(ch)
#endif

class QMenu;
class QTimer;

class OwnSyetemTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    OwnSyetemTrayIcon();
    ~OwnSyetemTrayIcon();

    // 托盘闪烁的控制
    void startTrayFlash();
    void stopTrayFlash();

private slots:
    // 托盘下鼠标事件的响应的处理
    void slotActivated(QSystemTrayIcon::ActivationReason reason);

signals:
    // 托盘下菜单点击信号
    void sigNormalShow();
    void sigClose();

private:
    // 托盘闪烁的实际实现
    void iconFlash();

private:
    // 托盘下菜单对象
    QMenu *m_menu;
    // 控制闪烁的定时器
    QTimer *m_flashTimer;
    // 决定是闪还是烁
    bool m_flashStatus;
};


#endif // OWNSYETEMTRAYICON_H
