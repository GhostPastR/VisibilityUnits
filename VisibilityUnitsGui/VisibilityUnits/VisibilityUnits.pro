TARGET = VisibilityUnits

SOURCES += \
        listunits.cpp \
        unit.cpp

HEADERS += \
    listunits.h \
    unit.h

include(../project.pri)
out = $$setPath(../)
out = $$configLib()
