#include "userqmlplugin.h"

#include <QPainter>

UserQMLCppPaintedItem::UserQMLCppPaintedItem(QQuickItem *parent)
    : QQuickPaintedItem(parent) {
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void UserQMLCppPaintedItem::paint(QPainter *painter) {
    QPen pen(QColor::fromRgb(186, 224, 255), 2);
    QBrush brush(QColor::fromRgb(186, 224, 255));

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(0, 0, 100, 100);
}

UserQMLCppPaintedItem::~UserQMLCppPaintedItem() {}
