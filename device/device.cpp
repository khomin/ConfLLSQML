#include "./device/device.h"
#include <QDebug>
#include "other/crc.h"

Device::Device(DeviceAbstract::E_DeviceType type,
               QString deviceUniqIdentName) {
    this->type = type;
    this->deviceUniqIdentName = deviceUniqIdentName;
    if(type == DeviceAbstract::Type_Progress_Tmk24) {
        this->progressTmk24 = new Progress_tmk24();
    } else {
        this->progressTmk13 = new Progress_tmk13();
    }
}

Device::Device(const Device& val) {}

Device::~Device() {}

void Device::setState(E_State state) {
    this->state = state;
}

DeviceAbstract::E_State Device::getState() {
    return state;
}

DeviceAbstract::E_DeviceType Device::getType() {
    return type;
}

QStringList Device::getSettings() {
    QStringList ret;
    if(type == Type_Progress_Tmk24) {
        ret = progressTmk24->getSettings();
    } else if(type == Type_Progress_Tmk13) {
        ret = progressTmk13->getSettings();
    } else {
        qDebug() << "Device type undefined!";
    }
    return ret;
}

bool Device::setSettings(QStringList setts) {
    bool res = false;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->setSettings(setts);
    } else if(type == Type_Progress_Tmk13) {
        res = progressTmk13->setSettings(setts);
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

QStringList Device::getPropertyData() {
    QStringList res;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->getPropertyData();
    } else if(type == Type_Progress_Tmk13) {
        res = progressTmk13->getPropertyData();
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

QList<CommandController::sCommandData> Device::getCommandListToIdlePoll() {
    QList<CommandController::sCommandData> res;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->getCommandListToIdlePoll(deviceUniqIdentName);
    } else if(type == Type_Progress_Tmk13) {
        res = progressTmk13->getCommandListToIdlePoll(deviceUniqIdentName);
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

QStringList Device::getParameters() {
    if(type == Type_Progress_Tmk24) {
        return progressTmk24->getPropertyData();
    } else if(type == Type_Progress_Tmk13) {
        return progressTmk13->getPropertyData();
    } else {
        qDebug() << "Device type undefined!";
    }
    return QStringList();
}

QString Device::getUniqIdent() {
    return deviceUniqIdentName;
}

bool Device::makeDataToCommand(CommandController::sCommandData &commandData) {
    bool res = false;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->makeDataToComand(commandData);
    } else if(type == Type_Progress_Tmk13) {
        res = progressTmk13->makeDataToComand(commandData);
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

bool Device::placeReplyDataOfCommand(QByteArray &commandArray) {
    bool res = false;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->placeDataReplyToCommand(commandArray);
    } else if(type == Type_Progress_Tmk13) {
        res = progressTmk13->placeDataReplyToCommand(commandArray);
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

QStringList Device::getDeviceAvaibleTypes() {
    QStringList res;
    for(auto it=deviceAvailableTypesList.begin(); it!=deviceAvailableTypesList.end(); it++) {
        res.push_back((*it).second);
    }
    return res;
}

QList<int> Device::getDeviceCurrentChart() {
    QList<int>res;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->getChart();
    } else if(type == Type_Progress_Tmk13) {
        res = progressTmk13->getChart();
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

QList<QString> Device::getDeviceCurrentOtherData() {
    QList<QString> res;
    if(type == Type_Progress_Tmk24) {
        res = progressTmk24->getCurrentOtherData();
    } else if(type == Type_Progress_Tmk13) {
    } else {
        qDebug() << "Device type undefined!";
    }
    return res;
}

void Device::addCommandReadSettingsAfterIniit() {
    if(type == Type_Progress_Tmk24) {
        progressTmk24->getCurrentOtherData();
    } else if(type == Type_Progress_Tmk13) {
    } else {
        qDebug() << "Device type undefined!";
    }
}

QString Device::getCaptionToTypeDevice(DeviceAbstract::E_DeviceType type) {
    QString res;
    if(!deviceAvailableTypesList.empty()) {
        auto it = deviceAvailableTypesList.begin();
        while(it!=deviceAvailableTypesList.end()) {
            if(type == (*it).first) {
                return (*it).second;
            }
            it++;
        }
    }
    return res;
}

DeviceAbstract::E_DeviceType Device::getDeviceTypeFromTypeCaption(QString typeDevText) {
    DeviceAbstract::E_DeviceType retType = Type_Progress_default;
    if(!deviceAvailableTypesList.empty()) {
        auto it = deviceAvailableTypesList.begin();
        while(it!=deviceAvailableTypesList.end()) {
            if(typeDevText == (*it).second) {
                return (*it).first;
            }
            it++;
        }
    }
    return retType;
}
