#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "Server.h"
#include <QDebug>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

class HttpServer : public IServer
{
public:
    HttpServer();

    virtual void init();
    virtual void start();
    virtual void stop();

protected:
    void startAccept();
    void session( boost::shared_ptr< boost::asio::ip::tcp::socket > sock );

private:
    std::vector< boost::shared_ptr< boost::thread > > _threads;

    boost::asio::io_service service;
    boost::asio::ip::tcp::endpoint ep;
    boost::asio::ip::tcp::acceptor acc;

    bool _isInit;
};

#endif // HTTPSERVER_H
