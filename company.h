#ifndef COMPANY_H
#define COMPANY_H

#include <QString>

class Company
{
public:
    Company();

    QString getVatNumber() const;
    void setVatNumber(const QString &value);

    QString getFullName() const;
    void setFullName(const QString &value);

    QString getCountry() const;
    void setCountry(const QString &value);

    QString getStreet() const;
    void setStreet(const QString &value);

    QString getCity() const;
    void setCity(const QString &value);

    QString getHouseNumber() const;
    void setHouseNumber(const QString &value);

    QString getState() const;
    void setState(const QString &value);

    QString getPostalCode() const;
    void setPostalCode(const QString &value);

private:
    QString vatNumber;
    QString fullName;
    QString country;
    QString street;
    QString city;
    QString houseNumber;
    QString state;
    QString postalCode;
};

#endif // COMPANY_H
