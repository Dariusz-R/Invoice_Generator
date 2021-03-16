#ifndef TABLEOFGOODSMODEL_H
#define TABLEOFGOODSMODEL_H

#include <QAbstractListModel>

#include "merchandise.h"

class TableOfGoodsModel : public QAbstractTableModel
{

public:

    TableOfGoodsModel(QObject* parent = nullptr);
    ~TableOfGoodsModel();

public slots:

    void addItem();
    void updateOrdinalNumberColumn();
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    void clearListOfGoods();

public :

    short getNumberOfColumns() const;
    void setNumberOfColumns(short value);
    short listOfGoodsSize() const;
    QString chooseAndExecuteGetter(const QModelIndex &itemIndex);
    void chooseAndExecuteSetter(const QModelIndex &itemIndex, const QString &value);

private:

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

public:

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
