#include "invoiceinfomodel.h"

//======================================================================
//CONSTRUCTORS==========================================================
//======================================================================

InvoiceInfoModel::InvoiceInfoModel(QObject* parent)
    : QAbstractTableModel(parent),
      numberOfRows(1),
      numberOfColumns(3)
{
     invoiceNumber = "";
     dateOfIssue = "";
     dateOfPayment = "";
}

//======================================================================
//PUBLIC SLOTS==========================================================
//======================================================================

void InvoiceInfoModel::resetInvoiceInformation()
{
    invoiceNumber = "";
    dateOfIssue = "";
    dateOfPayment = "";

    const short invoiceNumberRow = 0;
    const short dateOfPaymentRow = 0;

    emit dataChanged(QModelIndex(index(InvoiceNumberColumn,invoiceNumberRow)), QModelIndex(index(DateOfPaymentColumn,dateOfPaymentRow)));
}

//======================================================================
//PRIVATE METHODS=======================================================
//======================================================================

int InvoiceInfoModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return numberOfRows;
}

int InvoiceInfoModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return numberOfColumns;
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

bool InvoiceInfoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    if(role == Qt::EditRole)
    {
        if(data(index, Qt::DisplayRole) == value)
            return false;

        switch (index.column()) {
        case InvoiceNumberColumn:
            invoiceNumber = value.toString();
            break;
        case DateOfIssueColumn:
            dateOfIssue = value.toString();
            break;
        case DateOfPaymentColumn:
            dateOfPayment = value.toString();
        };

        emit dataChanged(index, index);
        return true;

    }
    return false;
}

Qt::ItemFlags InvoiceInfoModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}


