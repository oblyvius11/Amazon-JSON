
#include "proj4-ItemInfo.hpp"
#include <cmath>
#include <iomanip>
#include <vector>

void ItemInfo::setItemId(const char *num) {
    int count = 0;
    int temp, pos;

    while (num[count] != '\0') {
        count++;
    }

    pos = count - 1;

    for (int i = 0; i < count; i++) {
        temp = num[i] - 48;
        itemId += temp * pow(10, pos);
        pos --;
    }
}

void ItemInfo::setDescription(const char *cstr) {
    int i = 0;
    while (cstr[i] != '\0') {
        description[i] = cstr[i];
        i++;
    }
    description[i] = '\0';
}

void ItemInfo::setManCost(const char *num) {
    manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num) {
    sellPrice = stuCstrToDbl(num);
}

int ItemInfo::getItemId() {
    return itemId;
}

const char * ItemInfo::getDescription() {
    return description;
}

double ItemInfo::getManCost() {
    return manCost;
}

double ItemInfo::getSellPrice() {
    return sellPrice;
}

void ItemInfo::toAmazonJSON(ostream &out) {
    out << "\t\t\t \"itemId\": " << getItemId() << "\n";
    out << "\t\t\t \"description\": " << getDescription() << "\n";
    out << "\t\t\t \"manPrice\": " << getManCost() << "\n";
    out << "\t\t\t \"sellPrice\": " << getSellPrice() << "\n";
}

void ItemInfo::displayItemInfo(ostream &out) {
    out << "\n";
    out << "itemID: " << itemId << "\n";
    out << "description: " << description << "\n";
    out << fixed << setprecision(2) << "manCost: " << manCost << "\n";
    out << "sellPrice: " << sellPrice << "\n";
    out << "calculatedProfit: " << calcProfit() << "\n";
    out << "\n";
}

double ItemInfo::calcProfit() {
    return sellPrice - manCost;
}

double stuCstrToDbl(const char *num) {
    int count = 0;
    int temp, pos, point;
    double val, result;
    bool negative = false;

    if (num[0] == '-') {
        negative = true;
        count = 1;
    }

    while (num[count] != '\0') {
        if (num[count] == '.') {
            point = count;
        }
        count++;
    }

    int i = 0;

    pos = count;

    if (negative) {
        i++;
        pos--;
    }

    for (i; i < count; i++) {
        temp = num[i] - 48;
        if (i == point) {
            pos = 0;
            temp = 0;
            result /= pow(10, count - point + 1);
        }
        val = static_cast<double>(temp);
        result += val * pow(10, pos);
        pos --;
    }

    if (negative) {
        result = -result;
    }
    return result;
}

void stuDblToCstr(char *cstr, double num) {
    bool negative = false;
    int count = 1, tmp, countA, countB;
    vector<int> digitB, digitA;

    digitB.clear();
    digitA.clear();

    if (num < 0) {
        negative = true;
        num = -num;
        count--;
    }

    int a = static_cast<int>(num);
    int b = num * 100;

    b %= a * 100;

    if (negative) {
        count ++;
    }

    tmp = a;
    while (tmp / 10 != 0) {
        count++;
        tmp /= 10;
    }
    countA = count;

    tmp = b;
    count ++;
    while (tmp / 10 != 0) {
        count ++;
        tmp /= 10;
    }
    countB = count - countA;

    for (int i = 0; i < count; i++) {
        cstr[i] = '0';
    }

    count++;

    while (b != 0) {
        tmp = b % 10;
        digitB.push_back(tmp);
        b -= tmp;
        b /= 10;
    }

    while (a != 0) {
        tmp = a % 10;
        digitA.push_back(tmp);
        a -= tmp;
        a /= 10;
    }


    for (int i = 0; i < countB; i++) {
        cstr[count - 1 - i] = digitB.at(i) + 48;
        if (i == countB - 1) {
            cstr[count - 1 - countB] = '.';
        }
    }

    tmp = countA - 1;
    for (int i = 0; i < countA; i++) {
        cstr[i] = digitA.at(tmp) + 48;
        tmp--;
    }

    cstr[count] = '\0';

    if (negative) {
        for (int i = count - 1; i >= 0; i--) {
            cstr[i+1] = cstr[i];
        }
        cstr[0] = '-';
    }

}

void stuCstrCpy(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int stuCstrLen(const char *src) {
    int count = 0;
    while (src[count] != '\0') {
        count ++;
    }

    return count;
}

ostream& printCString(ostream &out, const char *src){
    int len = stuCstrLen(src);
    for (int i = 0; i < len; i++) {
        out << src[i];
    }
}





