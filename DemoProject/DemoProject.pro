# -------------------------------------------------
# Project created by QtCreator 2017-08-17T09:17:38
# -------------------------------------------------
TARGET = DemoProject
TEMPLATE = app
SOURCES += main.cpp \
    widget.cpp \
    datapool.cpp \
    displaythread.cpp \
    collectionthread.cpp \
    configure.cpp \
    canparser.cpp \
    basedatapool.cpp \
    clusterdatapool.cpp \
    alertevent.cpp \
    alerteventlistener.cpp \
    cancache.cpp \
    parsethread.cpp \
    modbusutil.cpp \
    modbustcpserverthread.cpp
HEADERS += widget.h \
    displayThread.h \
    displaythread.h \
    collectionthread.h \
    configure.h \
    datapool.h \
    canparser.h \
    structs.h \
    ycapi/ycapi.h \
    basedatapool.h \
    clusterdatapool.h \
    alertevent.h \
    eventlistener.h \
    alerteventlistener.h \
    cancache.h \
    parsethread.h \
    modbusutil.h \
    modbus-version.h \
    modbus-tcp.h \
    modbus-rtu.h \
    modbus.h \
    modbustcpserverthread.h
FORMS += widget.ui
INSTALLS += target
RESOURCES += resources.qrc
OTHER_FILES += 
LIBS += -L../ycapi \
    -lycapi
LIBS += -L/opt/libmodbus/install/lib \
    -lmodbus
INCLUDEPATH += ../ycapi
