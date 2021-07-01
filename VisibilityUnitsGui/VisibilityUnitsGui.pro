TEMPLATE = subdirs

SUBDIRS += \
    ConsoleCalcVisibility \
    VisibilityUnits \
    Gui \

Gui.depends = VisibilityUnits
ConsoleCalcVisibility.depends = VisibilityUnits
