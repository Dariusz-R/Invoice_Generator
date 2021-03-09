#ifndef AGREEMENTPARTIESMODEL_H
#define AGREEMENTPARTIESMODEL_H

#include <QAbstractTableModel>

#include <company.h>

class AgreementPartiesModel : public QAbstractTableModel
{
public:
    AgreementPartiesModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    enum RowNames{
         vatNumberRow,
         fullNameRow,
         countryRow,
         streetRow,
         cityRow,
         houseNumberRow,
         stateRow,
         postalCodeRow
    };

    enum ColumnNames {
        supplierColumn,
        customerColumn
    };

private:
    const short numberOfColumns;
    const short numberOfRows;
    const QList <Company*> companies;



};

#endif // AGREEMENTPARTIESMODEL_H
