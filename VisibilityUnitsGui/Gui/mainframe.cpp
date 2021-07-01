#include "mainframe.h"
#include "mainframe.h"
#include <QPainter>
#include <QBrush>
#include <listunits.h>

MainFrame::MainFrame(QWidget* parent) : QFrame(parent)
{
    units = std::make_shared<ListUnits>();
}

MainFrame::~MainFrame()
{

}

void MainFrame::caldVisibility()
{
    units->readFileDataUnits("data_units.txt");
    units->calcVisibilityUnits();
    units->writeFileCount();
    repaint();
}

void MainFrame::update()
{
    repaint();
}

void MainFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for( const auto &i : *units ){
        drawUnit( 150, 150, i, painter );
    }

}

void MainFrame::drawUnit(int dx, int dy, const Unit &unit, QPainter &painter)
{
    float k = 2;
    float k_1_2 = k / 2.;
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);
    int x = unit.x() + dx;
    int y = unit.y() + dy;
    int r = unit.distance();
    painter.drawPoint( k * x, k * y );


    auto angle = atan2f( unit.r_x(), unit.r_y() );
    if( angle < 0 ){
        angle += 2 * M_PI;
    }
    auto span = unit.angle() * 180. / M_PI;
    auto start = 450 - static_cast<int>((angle + unit.angle()/2.)
                                                             * 180./M_PI) % 360;

    QColor color{Qt::green};
    color.setAlpha( 50 );
    pen.setColor(color);
    pen.setWidth(1);
    painter.setBrush(QBrush(color));
    painter.setPen(pen);
    QRectF rectangle(k * x - r * k_1_2, k * y - r * k_1_2, r * k, r * k);
    int startAngle = start * 16;
    int spanAngle = span * 16;
    painter.drawPie(rectangle, startAngle, spanAngle);
}
