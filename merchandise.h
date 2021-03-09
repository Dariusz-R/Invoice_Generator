#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <QString>

class Merchandise
{
public:
    Merchandise();

    int getQuantity() const;
    void setQuantity(int value);

    QString getServiceOrDescription() const;
    void setServiceOrDescription(const QString &value);

    int getExchangeRate() const;
    void setExchangeRate(int value);

    int getUnitNetPrice() const;
    void setUnitNetPrice(int value);

    int getNetAmount() const;
    void setNetAmount(int value);

    int getVatRate() const;
    void setVatRate(int value);

    int getVatAmount() const;
    void setVatAmount(int value);

    int getGrossAmount() const;
    void setGrossAmount(int value);

    int getOrdinalNumber();
    void setOrdinalNumber(int value);

    static int getNumberOfGoods();
    static void setNumberOfGoods(int value);

private:
    static int numberOfGoods;
    int ordinalNumber;
    int quantity;
    QString serviceOrDescription;
    int exchangeRate;
    int unitNetPrice;
    int netAmount;
    int vatRate;
    int vatAmount;
    int grossAmount;
};

#endif // MERCHANDISE_H
