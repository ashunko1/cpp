#ifndef SERVER_H
#define SERVER_H

class IServer
{
public:
    virtual void init() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif // SERVER_H
