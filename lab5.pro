QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++2a
CXXFLAGS += -O2
QMAKE_CXXFLAGS += -O2
QMAKE_CXXFLAGS += -std=c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    vscomputerform.cpp

HEADERS += \
    board.h \
    game.h \
    mainwindow.h \
    vscomputerform.h

FORMS += \
    game.ui \
    mainwindow.ui \
    vscomputerform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    background.jpeg \
    irobot.jpg \
    move_sound.mp3 \
    move_sound.wav

RESOURCES += \
    background.jpeg \
    irobot.jpg

APP_QML_FILES.files = background.jpeg irobot.jpg
APP_QML_FILES.path = Contents/Resources
QMAKE_BUNDLE_DATA += APP_QML_FILES
