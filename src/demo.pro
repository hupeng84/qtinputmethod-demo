TEMPLATE = app
TARGET = demo
QT += qml quick
SOURCES += main.cpp
#CONFIG += lang-en_GB
CONFIG += link_pkgconfig
#CONFIG += disable-desktop
static {
    QT += svg
    QTPLUGIN += qtvirtualkeyboardplugin
}

#LIBS += -L. -lqtpinyin

RESOURCES += \
    demo.qrc

OTHER_FILES += main.qml 
