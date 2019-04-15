#include "HttpServer.h"

HttpServer::HttpServer()
    : service(), acc(service)
{
    _isInit = false;
}

void HttpServer::init()
{
    if( _isInit )
        return;

    try
    {
        boost::asio::ip::tcp::endpoint ep( boost::asio::ip::tcp::v4(), 2001 );
        acc.open( ep.protocol() );
        acc.bind( ep );
        acc.listen();

        _isInit = true;
    }
    catch ( std::exception &e )
    {
    }
}

void HttpServer::start()
{
    startAccept();
}

void HttpServer::stop()
{
    for ( boost::shared_ptr< boost::thread > thread :_threads )
        thread.get()->join();

     acc.close();
}

void HttpServer::startAccept()
{
    {
        boost::thread thread1;
        boost::shared_ptr< boost::asio::ip::tcp::socket > sock(new boost::asio::ip::tcp::socket( service ) );
        acc.accept( *sock );
        boost::shared_ptr< boost::thread > thread( new boost::thread( boost::bind( &HttpServer::session, this, sock ) ) );
        _threads.push_back( thread );
    }

    startAccept();
}

void HttpServer::session( boost::shared_ptr< boost::asio::ip::tcp::socket > sock )
{
    char data[ 512 ];
    size_t len = sock->read_some( boost::asio::buffer( data ) );

    if ( len > 0 )
        boost::asio::write( *sock, boost::asio::buffer( "Ok", 2 ) );
    else
        session(sock);
}







