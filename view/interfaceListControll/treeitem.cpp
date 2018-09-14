#include "treeitem.h"

TreeItem::TreeItem(QString content, bool isParent, QObject *parent) :
    QObject(parent),
    m_content(content),
    m_childItems(QList<TreeItem*>()),
    m_isOpen(false),
    m_isCurrent(false)
{
    this->m_isParent = isParent;
}

const QString &TreeItem::content() const{
    return m_content;
}

void TreeItem::setContent(const QString &content){
    if(content != m_content){
        m_content = content;
        emit contentChanged();
    }
}

const QList<TreeItem *> &TreeItem::childItems() const{
    return m_childItems;
}

const QList<QObject *> TreeItem::childItemsAsQObject() const{
    QList<QObject *> res;
    res.reserve(m_childItems.count());
    for(auto i : m_childItems)
        res.append(i);
    return res;
}

void TreeItem::addChildItem(TreeItem *childItem){
    m_childItems.append(childItem);
    emit childItemsChanged();
    if(m_childItems.count() == 1)
        emit hasChildChanged();
}

bool TreeItem::isOpen() const{
    return m_isOpen;
}

void TreeItem::setIsOpen(bool isOpen){
    if(isOpen != m_isOpen){
        m_isOpen = isOpen;
        emit isOpenChanged();
    }
}

bool TreeItem::isCurrent() const {
    return m_isCurrent;
}

bool TreeItem::isParent() const {
    return m_isParent;
}

void TreeItem::setIsCurrent(bool isCurrent) {
//    if(m_isParent) {
//        for(auto it: m_childItems) {
//            it->setIsCurrent(false);
//        }
//        emit contentChanged();
//    } else {

//    }
    m_isCurrent = isCurrent;
    emit currentIndexIsChanged(m_isParent, this);
    emit isCurrentChanged();
}

bool TreeItem::hasChild() const{
    return !m_childItems.isEmpty();
}
