#ifndef DEVICESFACTORY_H
#define DEVICESFACTORY_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include "command/commandController.h"
#include "device/deviceAbstract.h"
#include "device/subDevices/Progress_tmk13.h"
#include "device/subDevices/Progress_tmk24.h"

class DevicesFactory : public QObject
{
    Q_OBJECT
public:
    explicit DevicesFactory();
    ~DevicesFactory();

    typedef enum {
        Type_Progress_Tmk24,
        Type_Progress_Tmk13,
        Type_Undefined
    }E_DeviceType;

    typedef enum {
        Type_Update_ChangeStatus,
        Type_Update_Removed,
        Type_Update_Added
    }E_DeviceUpdateType;

public slots:

    bool addNewDevice(E_DeviceType type, QString uniqDevName, QStringList parameters);
    bool removeDevice(QString uniqDevName);

    QString getDeviceName(int index);
    QString getDeviceNameByType(DevicesFactory::E_DeviceType type);

    E_DeviceType getDeviceType(QString typeText);
    E_DeviceType getDeviceType(int index);

    void setDeviceInitCommandByIndex(int index);

    int getDeviceCount();
    QStringList getAvailableDeviceTypes();
    QStringList getDeviceHeaderByIndex(int index);
    QString getDeviceIdTextByIndex(int index);

    int getDeviceStatusByIndex(int index);

    QList<int> getDeviceChartByIndex(int index);
    QList<QString> getDeviceCurrentDataByIndex(int index);
    QStringList getDevicePropertyByIndex(int index);
    QStringList getDeviceProperty(int indexDev);

    DeviceAbstract::E_State getDevStateByIndex(int index);

    void placeReplyDataFromInterface(QByteArray data);

    void setDeviceReInitByIndex(int index);

    void sendCustomCommadToDev(int indexDev, QString operation, QStringList arguments);

signals:
    void writeData(QByteArray data);
    void readReplyData();

    void deviceConnectedSignal(DevicesFactory::E_DeviceType, QString uniqNameId);
    void deviceDisconnectedSignal(DevicesFactory::E_DeviceType, QString uniqNameId);
    void deviceReadyCurrentDataSignal(DevicesFactory::E_DeviceType, QString uniqNameId);
    void deviceReadyPropertiesSignal(DevicesFactory::E_DeviceType, QString uniqNameId);
    void deviceReadyInitSignal(DevicesFactory::E_DeviceType, QString uniqNameId);

    void deviceUpdateTree(DevicesFactory::E_DeviceUpdateType status, int index);

private slots:
    //-- find device by index
    QPair<QString,DeviceAbstract*>* findDeviceByIndex(int index);
    QPair<QString,DeviceAbstract*>* findDeviceByUnicIdent(QString name);
    int findDeviceIndex(QString uniqNameId);
    void devShedullerSlot();

    void deviceEventSlot(DeviceAbstract::E_DeviceEvent type, QString devUniqueId, QString message);

private:
    QVector<QPair<QString,DeviceAbstract*>> deviceMap;

    QVector<CommandController::sCommandData> commandList;

    QTimer* devShedullerTimer;

    int indexProcessedDev = 0;

    const int delayAfterSendCommandMs = 100;
    const int devShedullerControlInterval = 100;
};

#endif // DEVICESFACTORY_H
