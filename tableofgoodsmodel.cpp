#include "tableofgoodsmodel.h"

#include <QDebug>

TableOfGoodsModel::TableOfGoodsModel(QObject* parent)
    : QAbstractTableModel(parent),
      numberOfColumns(8)
{
    listOfGoods.append(new Merchandise());
    listOfGoods.append(new Merchandise());
    listOfGoods.append(new Merchandise());
}

TableOfGoodsModel::~TableOfGoodsModel()
{
    qDeleteAll(listOfGoods);
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

    if(role == Qt::EditRole)
        return QString("");

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

QString TableOfGoodsModel::chooseAndExecuteGetter(const QModelIndex &itemIndex)
{
    switch (itemIndex.column()) {

    case OrdinalNumberColumn:
        return listOfGoods.at(itemIndex.row())->getOrdinalNumber();
    case ServiceOrDescriptionColumn:
        return listOfGoods.at(itemIndex.row())->getServiceOrDescription();
    case QuantityColumn:
        return listOfGoods.at(itemIndex.row())->getQuantity();
    case ExchangeRateColumn:
        return listOfGoods.at(itemIndex.row())->getExchangeRate();
    case UnitNetPriceColumn:
        return listOfGoods.at(itemIndex.row())->getUnitNetPrice();
    case NetAmountColumn:
        return listOfGoods.at(itemIndex.row())->getNetAmount();
    case VatRateColumn:
        return listOfGoods.at(itemIndex.row())->getVatRate();
    case VatAmountColumn:
        return listOfGoods.at(itemIndex.row())->getVatAmount();
    case GrossAmountColumn:
        return listOfGoods.at(itemIndex.row())->getGrossAmount();
    default:
        return "Error";
    }
}

Qt::ItemFlags TableOfGoodsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void TableOfGoodsModel::chooseAndExecuteSetter(const QModelIndex &itemIndex, const QString &value)
{
    switch (itemIndex.column()) {

    case OrdinalNumberColumn:
        //listOfGoods.at(itemIndex.row())->setOrdinalNumber(value);
        break;
    case ServiceOrDescriptionColumn:
        listOfGoods.at(itemIndex.row())->setServiceOrDescription(value);
        break;
    case QuantityColumn:
        listOfGoods.at(itemIndex.row())->setQuantity(value);
        break;
    case ExchangeRateColumn:
        listOfGoods.at(itemIndex.row())->setExchangeRate(value);
        break;
    case UnitNetPriceColumn:
        listOfGoods.at(itemIndex.row())->setUnitNetPrice(value);
        break;
    case NetAmountColumn:
        listOfGoods.at(itemIndex.row())->setNetAmount(value);
        break;
    case VatRateColumn:
        listOfGoods.at(itemIndex.row())->setVatRate(value);
        break;
    case VatAmountColumn:
        listOfGoods.at(itemIndex.row())->setVatAmount(value);
        break;
    case GrossAmountColumn:
        listOfGoods.at(itemIndex.row())->setGrossAmount(value);
        break;
    }
}

void TableOfGoodsModel::updateOrdinalNumberColumn()
{
    for(short i = 0 ; i < listOfGoods.size(); ++i){
        listOfGoods.at(i)->setOrdinalNumber(QString::number(i));
        emit dataChanged(index(i, OrdinalNumberColumn), index(i, OrdinalNumberColumn));
    }
}

bool TableOfGoodsModel::setData(const QModelIndex &index, const QVariant &value, int role){

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

short TableOfGoodsModel::listOfGoodsSize() const
{
    return listOfGoods.size();
}

void TableOfGoodsModel::clearListOfGoods()
{

    beginRemoveRows(QModelIndex(), 0, listOfGoods.size()-1);
    qDeleteAll(listOfGoods.begin(), listOfGoods.end());
    listOfGoods.clear();
    endRemoveRows();
    addItem();
}

void TableOfGoodsModel::addItem()
{

    beginInsertRows(QModelIndex(), listOfGoods.size() - 1, listOfGoods.size() - 1);
    listOfGoods.append( new Merchandise);
    endInsertRows();
}

bool TableOfGoodsModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(listOfGoods.size()>0){
        beginRemoveRows(parent, row, row + count - 1);
        for( short i = row + count - 1; i == row ; --i){
            delete listOfGoods.at(i);
            listOfGoods.removeAt(i);
            qDebug() << "Test removal i = " << i;
        }
        endRemoveRows();

        updateOrdinalNumberColumn();

        return true;
    }
    else
        return false;
}

