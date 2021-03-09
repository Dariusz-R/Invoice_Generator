#include "invoiceinfomodel.h"

InvoiceInfoModel::InvoiceInfoModel(QObject* parent) : QAbstractTableModel(parent)
{
     invoiceNumber = "";
     dateOfIssue = "";
     dateOfPayment = "";
}

int InvoiceInfoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;
}

int InvoiceInfoModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant InvoiceInfoModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        switch (index.column()) {
        case InvoiceNumberColumn:
            return invoiceNumber;
        case DateOfIssueColumn:
            return dateOfIssue;
        case DateOfPaymentColumn:
            return dateOfPayment;
        }
    }
    return QVariant();
}

QVariant InvoiceInfoModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
        switch (section) {
        case InvoiceNumberColumn:
            return "Invoice Number";
        case DateOfIssueColumn:
            return "Date of Issue";
        case DateOfPaymentColumn:
            return "Date of Payment";
        }
    }
    return QVariant();
}


