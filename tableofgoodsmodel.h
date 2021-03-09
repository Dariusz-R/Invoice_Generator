#ifndef TABLEOFGOODSMODEL_H
#define TABLEOFGOODSMODEL_H

#include <QAbstractListModel>

#include "merchandise.h"

class TableOfGoodsModel : public QAbstractTableModel
{
public:
    TableOfGoodsModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    enum ColumnNames{
        OrdinalNumberColumn,
        ServiceOrDescriptionColumn,
        QuantityColumn,
        ExchangeRateColumn,
        UnitNetPriceColumn,
        NetAmountColumn,
        VatRateColumn,
        VatAmountColumn,
        GrossAmountColumn
    };

private:

    QList <Merchandise*> listOfGoods;
    short numberOfColumns;
};
#endif // TABLEOFGOODSMODEL_H
