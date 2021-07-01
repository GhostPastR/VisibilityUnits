#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QFrame>

class Unit;
class QPainter;
class ListUnits;

class MainFrame : public QFrame
{
    Q_OBJECT
public:
    explicit MainFrame(QWidget* parent = nullptr);
    ~MainFrame();

    void caldVisibility();

public slots:
    void update();

protected:
    void paintEvent(QPaintEvent *event);

private:
    std::shared_ptr<ListUnits> units;

    void drawUnit(int dx, int dy, const Unit &unit, QPainter &painter);
};

#endif // MAINFRAME_H
