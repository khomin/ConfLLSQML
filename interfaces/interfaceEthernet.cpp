#include "./interfaces/interfaceEthernet.h"

InterfaceEthernet::InterfaceEthernet() {}

InterfaceEthernet::~InterfaceEthernet() {

}

void InterfaceEthernet::initInterface() {

}

bool InterfaceEthernet::openInterface()  {
    return false;
}

bool InterfaceEthernet::isOpen() {
return false;
}

void InterfaceEthernet::closeInterface()  {

}

bool InterfaceEthernet::sendData(QByteArray &pData)  {
    return false;
}

bool InterfaceEthernet::readData(QByteArray &pData)  {
    return false;
}

QString InterfaceEthernet::getInterfaceName()  {

}

QPair<QStringList,QStringList> InterfaceEthernet::getInterfaceProperty() {

}

QStringList InterfaceEthernet::getAvailableList() {

}

QString InterfaceEthernet::getType() {
    return QString::fromLocal8Bit(typeName, strlen(typeName));
}
