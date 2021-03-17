#ifndef INVOICEINFOMODEL_H
#define INVOICEINFOMODEL_H

#include <QAbstractTableModel>

class InvoiceInfoModel : public QAbstractTableModel
{

public:
    InvoiceInfoModel(QObject* parent = nullptr);

public slots:
    void resetInvoiceInformation();

private:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

public:
    enum ColumnNames{
        InvoiceNumberColumn,
        DateOfIssueColumn,
        DateOfPaymentColumn
    };

//MEMBERS

private:
   const short numberOfRows;
   const short numberOfColumns;

   QString invoiceNumber;
   QString dateOfIssue;
   QString dateOfPayment;

};
#endif // INVOICEINFOMODEL_H
