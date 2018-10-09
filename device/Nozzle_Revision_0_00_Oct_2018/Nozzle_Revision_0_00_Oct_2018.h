#ifndef  NOZZLE_REV_0_00_H
#define  NOZZLE_REV_0_00_H

#include <QObject>
#include <QVector>
#include "device/deviceAbstract.h"
#include "command/commandController.h"
#include "Nozzle_Revision_0_00_Oct_2018_Data.h"

class Nozzle_Revision_0_00_Oct_2018 : public DeviceAbstract
{
public:
    Nozzle_Revision_0_00_Oct_2018(QString nameDevice);
    ~Nozzle_Revision_0_00_Oct_2018();

    static constexpr char* name = "Nozzle Revision 0.00 Oct 2018";

    QString getDevTypeName() override;
    QStringList getPropertyData() override;
    QStringList getCurrentData() override;
    DeviceAbstract::E_State getState() override;
    void setState(DeviceAbstract::E_State) override;
    QPair<QStringList,QStringList> getSettings() override;
    QStringList getErrors() override;
    QString getUniqIdent() override;
    bool makeDataToCommand(CommandController::sCommandData &commandData) override;
    bool placeDataReplyToCommand(QByteArray &commandArrayReplyData, CommandController::sCommandData commandReqData) override;

    CommandController::sCommandData getCommandToCheckConnected() override;
    CommandController::sCommandData getCommandToGetType() override;
    CommandController::sCommandData getCommandtoCheckPassword() override;
    QList<CommandController::sCommandData> getCommandListToInit() override;
    QList<CommandController::sCommandData> getCommandListToCurrentData() override;
    QList<CommandController::sCommandData> getCommandCustom(QString operation, QPair<QStringList, QStringList> data) override;
    QList<CommandController::sCommandData> getCommandCustom(QString operation) override;
    QList<int> getChart() override;
    ServiceDevicesAbstract* getServiceAbstract() override;

    QList<QString>getCurrentOtherData();
    void parseCommandReply(Nozzle_Revision_0_00_Oct_2018_Data::sConsoleReplyBuff command, CommandController::sCommandData commandReqData);

private slots:
    void setDefaultValues();

private:
    Nozzle_Revision_0_00_Oct_2018_Data::S_lls_data lls_data;
    QList<int> *chartData;
    QString uniqIdentId;
};

#endif // NOZZLE_REV_0_00_H