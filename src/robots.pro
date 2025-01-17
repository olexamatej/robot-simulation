QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 -g debug

SOURCES += $$files(*.cpp, true)

HEADERS += $$files(*.hpp, true)

EXCLUDE += build

RESOURCES = assets.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target