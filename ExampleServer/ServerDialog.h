#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include "HttpServer.h"
#include <QtWidgets>

class ServerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ServerDialog(QWidget *parent = 0);

signals:

public slots:
    void onStartServer();
    void onStopServer();

private:
    QPushButton *_pBtnStartServer;
    QPushButton *_pBtnStopServer;
    QLabel *_pLblStateServer;

    HttpServer _httpServer;
};

#endif // SERVERDIALOG_H
