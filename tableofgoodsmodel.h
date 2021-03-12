#ifndef TABLEOFGOODSMODEL_H
#define TABLEOFGOODSMODEL_H

#include <QAbstractListModel>

#include "merchandise.h"

class TableOfGoodsModel : public QAbstractTableModel
{

public slots:
    void addItem();
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

public:
    TableOfGoodsModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

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

    short listOfGoodsSize() const;

private:

    QList <Merchandise*> listOfGoods;
    short numberOfColumns;

public:

    QString chooseAndExecuteGetter(const QModelIndex &itemIndex);

    // QAbstractItemModel interface
public:
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void chooseAndExecuteSetter(const QModelIndex &itemIndex, const QString &value);
};
#endif // TABLEOFGOODSMODEL_H
