#include "agreementpartiesmodel.h"

AgreementPartiesModel::AgreementPartiesModel(QObject* parent)
    : QAbstractTableModel(parent),
      numberOfColumns(2),
      numberOfRows(8),
      companies({new Company, new Company})
{

}

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

        case vatNumberRow:
            return companies.at(index.column())->getVatNumber();
        case fullNameRow:
            return companies.at(index.column())->getFullName();
        case countryRow:
            return companies.at(index.column())->getCountry();
        case streetRow:
            return companies.at(index.column())->getStreet();
        case cityRow:
            return companies.at(index.column())->getCity();
        case houseNumberRow:
            return companies.at(index.column())->getHouseNumber();
        case stateRow:
            return companies.at(index.column())->getState();
        case postalCodeRow:
            return companies.at(index.column())->getPostalCode();
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

        case vatNumberRow:
            return "VAT Number";
        case fullNameRow:
            return "Full Name";
        case countryRow:
            return "Country";
        case streetRow:
            return "Street";
        case cityRow:
            return "City";
        case houseNumberRow:
            return "House Number";
        case stateRow:
            return "State";
        case postalCodeRow:
            return "Postal Code";
        default:
            return QString("Error - no valid data.");
        }
    }
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section) {

        case supplierColumn:
            return "Supplier";
        case customerColumn:
            return "Customer";
        default:
            return QString("Error - no valid data");
        }
    }
    return QVariant();
}
