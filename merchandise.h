#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <QString>

class Merchandise
{
public:
    Merchandise();
    ~Merchandise();

    QString getQuantity() const;
    void setQuantity(QString value);

    QString getServiceOrDescription() const;
    void setServiceOrDescription(const QString &value);

    QString getExchangeRate() const;
    void setExchangeRate(QString value);

    QString getUnitNetPrice() const;
    void setUnitNetPrice(QString value);

    QString getNetAmount() const;
    void setNetAmount(QString value);

    QString getVatRate() const;
    void setVatRate(QString value);

    QString getVatAmount() const;
    void setVatAmount(QString value);

    QString getGrossAmount() const;
    void setGrossAmount(QString value);

    QString getOrdinalNumber();
    void setOrdinalNumber(QString value);

    static int getNumberOfGoods();
    static void setNumberOfGoods(int value);

private:
    static int numberOfGoods;
    QString ordinalNumber;
    QString quantity;
    QString serviceOrDescription;
    QString exchangeRate;
    QString unitNetPrice;
    QString netAmount;
    QString vatRate;
    QString vatAmount;
    QString grossAmount;
};

#endif // MERCHANDISE_H
