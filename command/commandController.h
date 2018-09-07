#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QQueue>
#include <QPair>

class CommandController : public QObject
{
    Q_OBJECT
public:
    explicit CommandController(QObject *parent = nullptr);

    typedef struct {
        // uniqual ident device
        QString deviceIdent;
        // dev command
        int devCommand;
        // bytearray for command buf
        QByteArray commandOptionData;
        // buffer for transmit settings, firmware and other data
        QList<QPair<QString,QByteArray>>commandOptionArg;
    }sCommandData;

    bool addCommandToStack(sCommandData commandData);
    bool getCommandFirstCommandFromStack(sCommandData &devCommandData);
    bool commandsIsEmpty();

private:

    QQueue<sCommandData> commandQueue;
};

#endif // COMMANDCONTROLLER_H