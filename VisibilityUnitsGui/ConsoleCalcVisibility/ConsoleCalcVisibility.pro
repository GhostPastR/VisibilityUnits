TEMPLATE = app

SOURCES += \
        main.cpp

include(../project.pri)
out = $$setPath(../)
out = $$addLibs(VisibilityUnits)

