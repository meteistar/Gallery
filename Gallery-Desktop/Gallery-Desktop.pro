QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    albumlistwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    albumlistwidget.h \
    mainwindow.h

FORMS += \
    albumlistwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Gallery-Core/release/ -lGallery-Core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Gallery-Core/debug/ -lGallery-Core

INCLUDEPATH += $$PWD/../Gallery-Core
DEPENDPATH += $$PWD/../Gallery-Core

RESOURCES += \
    resource.qrc
