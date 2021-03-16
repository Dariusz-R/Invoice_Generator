#ifndef INVOICEINFOMODEL_H
#define INVOICEINFOMODEL_H

#include <QAbstractTableModel>

class InvoiceInfoModel : public QAbstractTableModel
{

public:
    InvoiceInfoModel(QObject* parent = nullptr);

private:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

public:
    enum ColumnNames{
        InvoiceNumberColumn,
        DateOfIssueColumn,
        DateOfPaymentColumn
    };

//MEMBERS

private:
   QString invoiceNumber;
   QString dateOfIssue;
   QString dateOfPayment;


};
#endif // INVOICEINFOMODEL_H
