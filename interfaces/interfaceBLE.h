#ifndef INTERFACEBLE_H
#define INTERFACEBLE_H

#include <QObject>
#include "interfacesAbstract.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class InterfaceBLE : public interfacesAbstract
{
    Q_OBJECT
public:
    explicit InterfaceBLE();
    ~InterfaceBLE();
    InterfaceBLE(const InterfaceBLE &);

public slots:

    void initInterface() override;
    bool openInterface(QString name, QStringList arg) override;
    bool isOpen() override;
    void closeInterface() override;
    bool sendData(QByteArray &pData) override;
    bool readData(QByteArray &pData) override;

    QString getInterfaceName() override;
    QStringList getInfoInterface(QString name) override;
    QStringList getAvailableList() override;

private slots:
    void aboutClose() override;

private:
    QSerialPort *portHandler;

};

#endif // INTERFACEBLE_H
