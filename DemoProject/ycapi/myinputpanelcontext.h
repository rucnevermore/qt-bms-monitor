#ifndef MYINPUTPANELCONTEXT_H
#define MYINPUTPANELCONTEXT_H

#include <QInputContext>
//#include "myinputpanel.h"
class MyInputPanel;
class InputMethod;

class MyInputPanelContext : public QInputContext
{
    Q_OBJECT
public:
    MyInputPanelContext();
    ~MyInputPanelContext();
    //输入事件过滤
    bool filterEvent(const QEvent* event);

    //返回输入方式的识别码
    QString identifierName();

    //返回输入编码方式
    QString language();

    //输入是否发送完
    bool isComposing() const;

    void reset();

private slots://发送接收到的字符到有光标焦点的窗口
    void sendCharacter(QChar character);
    void sendStr(QString str);

private://更新软键盘位置
    void updatePosition();

private:
    //MyInputPanel *inputPanel;
    InputMethod  *inputPanel;
    
};

#endif // MYINPUTPANELCONTEXT_H
