#ifndef AGREEMENTPARTIESMODEL_H
#define AGREEMENTPARTIESMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include <company.h>

class AgreementPartiesModel : public QAbstractTableModel
{
public:
    AgreementPartiesModel(QObject* parent = nullptr);
    ~AgreementPartiesModel();

public slots:

    void resetAgreementParty(short columnName);
private:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QString chooseAndExecuteGetter(const QModelIndex &fieldPosition);
    void chooseAndExecuteSetter(const QModelIndex &fieldPosition, const QString &value);
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    //MEMBERS
public:
    enum RowNames{
        FullNameRow,
        HouseNumberRow,
        StreetRow,
        PostalCodeRow,
        CityRow,
        StateRow,
        CountryRow,
        VatNumberRow
    };

    enum ColumnNames {
        SupplierColumn,
        CustomerColumn
    };

private:
    const short numberOfColumns;
    const short numberOfRows;
    const QList <Company*> agreementParties;
};

#endif // AGREEMENTPARTIESMODEL_H
