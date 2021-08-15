#include "ownsyetemtrayicon.h"

#include <QMenu>
#include <QTimer>

OwnSyetemTrayIcon::OwnSyetemTrayIcon()
    : QSystemTrayIcon()
    , m_menu(new QMenu)
    , m_flashTimer(new QTimer)
    , m_flashStatus(false)
{
    this->setIcon(QIcon(":/Icon/logo.ico"));

    connect(m_menu->addAction(QIcon(), CN("主界面")), &QAction::triggered, this, &OwnSyetemTrayIcon::sigNormalShow);
    m_menu->addSeparator();
    connect(m_menu->addAction(QIcon(), CN("退出")), &QAction::triggered, this, &OwnSyetemTrayIcon::sigClose);
    this->setContextMenu(m_menu);

    connect(this,&QSystemTrayIcon::activated,this,&OwnSyetemTrayIcon::slotActivated);
    connect(m_flashTimer, &QTimer::timeout,this,&OwnSyetemTrayIcon::iconFlash);
}

OwnSyetemTrayIcon::~OwnSyetemTrayIcon()
{
    SAFE_DELETE(m_menu);
    SAFE_DELETE(m_flashTimer);
}

void OwnSyetemTrayIcon::startTrayFlash()
{
    if (m_flashTimer && m_flashTimer->isActive())
        return;

    m_flashTimer->start(500);
}

void OwnSyetemTrayIcon::stopTrayFlash()
{
    if (m_flashTimer && m_flashTimer->isActive())
        m_flashTimer->stop();

    if (m_flashStatus)
        this->setIcon(QIcon(":/Icon/logo.ico"));
}

void OwnSyetemTrayIcon::iconFlash()
{
    if (m_flashStatus)
        this->setIcon(QIcon(":/Icon/logo.ico"));
    else
        this->setIcon(QIcon(":/Icon/no_logo.ico"));

    m_flashStatus = !m_flashStatus;
}

void OwnSyetemTrayIcon::slotActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        this->showMessage(CN("托盘图标点击"),CN("鼠标左键~"));
        emit sigNormalShow();
        break;
    default:
        break;
    }
}
