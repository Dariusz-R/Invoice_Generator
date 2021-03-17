#include "agreementpartiesmodel.h"

#include <QDebug>

//======================================================================
//CONSTRUCTORS==========================================================
//======================================================================

AgreementPartiesModel::AgreementPartiesModel(QObject* parent)
    : QAbstractTableModel(parent),
      numberOfColumns(2),
      numberOfRows(8),
      agreementParties({new Company, new Company})
{

}

//======================================================================
//DESCRUCTORS===========================================================
//======================================================================

AgreementPartiesModel::~AgreementPartiesModel()
{
    qDeleteAll(agreementParties);
}

//======================================================================
//PUBLIC SLOTS==========================================================
//======================================================================

void AgreementPartiesModel::resetAgreementParty(short columnName)
{
    agreementParties.at(columnName)->resetAllMembers();
    emit dataChanged(index(FullNameRow, SupplierColumn), index(VatNumberRow, CustomerColumn));
}

//======================================================================
//PRIVATE METHODS=======================================================
//======================================================================

int AgreementPartiesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return numberOfRows;
}

int AgreementPartiesModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return numberOfColumns;
}

QVariant AgreementPartiesModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole)
        switch (index.row()) {

        case VatNumberRow:
            return agreementParties.at(index.column())->getVatNumber();
        case FullNameRow:
            return agreementParties.at(index.column())->getFullName();
        case CountryRow:
            return agreementParties.at(index.column())->getCountry();
        case StreetRow:
            return agreementParties.at(index.column())->getStreet();
        case CityRow:
            return agreementParties.at(index.column())->getCity();
        case HouseNumberRow:
            return agreementParties.at(index.column())->getHouseNumber();
        case StateRow:
            return agreementParties.at(index.column())->getState();
        case PostalCodeRow:
            return agreementParties.at(index.column())->getPostalCode();
        default:
            return QString("Error - no valid data.");
        }

    return QVariant();
}

QVariant AgreementPartiesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Vertical)
    {
        switch (section) {

        case FullNameRow:
            return "Full Name";
        case HouseNumberRow:
            return "House Number";
        case StreetRow:
            return "Street";
        case PostalCodeRow:
            return "Postal Code";
        case CityRow:
            return "City";
        case StateRow:
            return "State";
        case CountryRow:
            return "Country";
        case VatNumberRow:
            return "VAT Number";
        default:
            return QString("Error - no valid data.");
        }
    }
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section) {

        case SupplierColumn:
            return "Supplier";
        case CustomerColumn:
            return "Customer";
        default:
            return QString("Error - no valid data");
        }
    }
    return QVariant();
}

bool AgreementPartiesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    if(role == Qt::EditRole)
    {
        if(chooseAndExecuteGetter(index) == value)
            return false;

        chooseAndExecuteSetter(index, value.toString());
        emit dataChanged(index, index);
        return true;

    }
    return false;
}

QString AgreementPartiesModel::chooseAndExecuteGetter(const QModelIndex &fieldPosition)
{
    switch (fieldPosition.row()) {

    case FullNameRow:
        return agreementParties.at(fieldPosition.column())->getFullName();
    case HouseNumberRow:
        return agreementParties.at(fieldPosition.column())->getHouseNumber();
    case StreetRow:
        return agreementParties.at(fieldPosition.column())->getStreet();
    case PostalCodeRow:
        return agreementParties.at(fieldPosition.column())->getPostalCode();
    case CityRow:
        return agreementParties.at(fieldPosition.column())->getCity();
    case StateRow:
        return agreementParties.at(fieldPosition.column())->getState();
    case CountryRow:
        return agreementParties.at(fieldPosition.column())->getCountry();
    case VatNumberRow:
        return agreementParties.at(fieldPosition.column())->getVatNumber();
    default:
        return "Error";
    }
}

void AgreementPartiesModel::chooseAndExecuteSetter(const QModelIndex &fieldPosition, const QString &value)
{
    switch (fieldPosition.row()) {

    case FullNameRow:
        agreementParties.at(fieldPosition.column())->setFullName(value);
        break;
    case HouseNumberRow:
        agreementParties.at(fieldPosition.column())->setHouseNumber(value);
        break;
    case StreetRow:
        agreementParties.at(fieldPosition.column())->setStreet(value);
        break;
    case PostalCodeRow:
        agreementParties.at(fieldPosition.column())->setPostalCode(value);
        break;
    case CityRow:
        agreementParties.at(fieldPosition.column())->setCity(value);
        break;
    case StateRow:
        agreementParties.at(fieldPosition.column())->setState(value);
        break;
    case CountryRow:
        agreementParties.at(fieldPosition.column())->setCountry(value);
        break;
    case VatNumberRow:
        agreementParties.at(fieldPosition.column())->setVatNumber(value);
        break;
    }
}

Qt::ItemFlags AgreementPartiesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}


