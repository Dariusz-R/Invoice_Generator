#include "tableofgoodsmodel.h"

TableOfGoodsModel::TableOfGoodsModel(QObject* parent)
    : QAbstractTableModel(parent),
      numberOfColumns(8)
{
    listOfGoods.append(new Merchandise());
}

int TableOfGoodsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfGoods.size();
}

int TableOfGoodsModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return numberOfColumns;
}

QVariant TableOfGoodsModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        switch (index.column()) {

        case OrdinalNumberColumn:
            return listOfGoods.at(index.row())->getOrdinalNumber();
        case ServiceOrDescriptionColumn:
            return listOfGoods.at(index.row())->getServiceOrDescription();
        case QuantityColumn:
            return listOfGoods.at(index.row())->getQuantity();
        case ExchangeRateColumn:
            return listOfGoods.at(index.row())->getExchangeRate();
        case UnitNetPriceColumn:
            return listOfGoods.at(index.row())->getUnitNetPrice();
        case NetAmountColumn:
            return listOfGoods.at(index.row())->getNetAmount();
        case VatRateColumn:
            return listOfGoods.at(index.row())->getVatRate();
        case VatAmountColumn:
            return listOfGoods.at(index.row())->getVatAmount();
        case GrossAmountColumn:
            return listOfGoods.at(index.row())->getGrossAmount();
        default:
            return QString("Error - no valid data");
        }
    }


    return QVariant();
}

QVariant TableOfGoodsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){

        switch (section) {

        case OrdinalNumberColumn:
            return "No";
        case ServiceOrDescriptionColumn:
            return "Service\nDescription";
        case QuantityColumn:
            return "Quantity";
        case ExchangeRateColumn:
            return "Exchange\nRate";
        case UnitNetPriceColumn:
            return "Unit Net\nPrice";
        case NetAmountColumn:
            return "Net\nAmount";
        case VatRateColumn:
            return "Vat\nRate";
        case VatAmountColumn:
            return "Vat\nAmount";
        case GrossAmountColumn:
            return "Gross\nAmount";
        default:
            return QString("Error - no valid data");
        }
    }
    return QVariant();
}
