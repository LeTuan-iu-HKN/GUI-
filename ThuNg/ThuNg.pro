QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend.cpp \
    data_structure.cpp \
    file.cpp \
    function.cpp \
    init.cpp \
    main.cpp \
    mainwindow.cpp \
    program_object.cpp

HEADERS += \
    backend.h \
    data_structure.h \
    file.h \
    function.h \
    init.h \
    library.h \
    mainwindow.h \
    program_object.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    D:/infor.txt \
    D:/money.txt
