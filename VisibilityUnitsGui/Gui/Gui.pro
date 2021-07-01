QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainframe.cpp \
    widget.cpp

HEADERS += \
    mainframe.h \
    widget.h

FORMS += \
    widget.ui

include(../project.pri)
out = $$setPath(../)
out = $$addLibs(VisibilityUnits)

