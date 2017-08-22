#ifndef COLLECTIONTHREAD_H
#define COLLECTIONTHREAD_H
#include <QThread>

class CollectionThread : public QThread
{
    Q_OBJECT
public:
//    CollectionThread(Ycapi * ycapi,QObject *parent = 0);
    CollectionThread(QObject *parent = 0);
signals:
    void log(QString str);
public slots:
    void run();
    void stop();

private:
    bool running;
    std::string getstring(int n);
//    Ycapi *ycappublic:

};

#endif // COLLECTIONTHREAD_H
