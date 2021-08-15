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

    // ������˸�Ŀ���
    void startTrayFlash();
    void stopTrayFlash();

private slots:
    // ����������¼�����Ӧ�Ĵ���
    void slotActivated(QSystemTrayIcon::ActivationReason reason);

signals:
    // �����²˵�����ź�
    void sigNormalShow();
    void sigClose();

private:
    // ������˸��ʵ��ʵ��
    void iconFlash();

private:
    // �����²˵�����
    QMenu *m_menu;
    // ������˸�Ķ�ʱ��
    QTimer *m_flashTimer;
    // ������������˸
    bool m_flashStatus;
};


#endif // OWNSYETEMTRAYICON_H
