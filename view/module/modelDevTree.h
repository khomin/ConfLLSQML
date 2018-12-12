#ifndef MODEL_DEV_TREE_H
#define MODEL_DEV_TREE_H

#include <QObject>

class TreeItem;

class ModelDevTree : public QObject
{
    Q_OBJECT
public:
    explicit ModelDevTree(QObject *parent = 0);

    Q_PROPERTY(QList<QObject*> tree READ treeAsQObjects NOTIFY treeChanged)
    const QList<TreeItem*> &tree() const;
    const QList<QObject*> treeAsQObjects() const;

    void addIo(QString ioName);
    void removeIo(int ioIndex);
    void addDevToIo(int ioIndex, QString devName);
    void removeDevToConnection(int indexConnection, int indexDevice);
    bool changeDevName(QString nameConnection, QString devName, QString devNewName);
    bool changeDevHeader(QString nameConnection, QString devName, QString devNewHeader);
    void removeAll();

    int getDevIndex();
    int getIoIndex();
    void setDevIndex(int);
    void setIoIndex(int);
    void setDevStatus(int devIndex, int status);
    void setIoStatus(int ioIndex, int status);

signals:
    void treeChanged();
    void indexDevIsChanged(int ioIndex, int devIndex);
    void indexIoIsChanged(int ioIndex, int devIndex);

private slots:

    TreeItem* createTreeItem(QString nameInterface);
    TreeItem* createTreeSubItem(QString nameDevice);

    void currentIndexIsChanged(bool isParent, TreeItem *pSender);

    void disconnectaFullTree();
    void connectFullTree();

private:
    QList<TreeItem*> m_tree;

    typedef struct {
        int ioIndex;
        int devIndex;
    }sIndex;

    sIndex curIndex = {0, 0};
};

#endif // MODEL_DEV_TREE_H
