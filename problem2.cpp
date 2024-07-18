#include <iostream>
using namespace std;

class US;

class NEP {
private:
    double NRs;

public:
    NEP(double rs) : NRs(rs) {}

    friend bool operator>(const NEP &, const US &);
    friend bool operator==(const NEP &, const US &);
    friend bool operator<(const NEP &, const US &);
};

class US {
private:
    double USD;

public:
    US(double dollar) : USD(dollar) {}

    friend bool operator>(const NEP &, const US &);
    friend bool operator==(const NEP &, const US &);
    friend bool operator<(const NEP &, const US &);
};

bool operator>(const NEP &N, const US &U) {
    return N.NRs > U.USD * 101.36;
}

bool operator<(const NEP &N, const US &U) {
    return N.NRs < U.USD * 101.36;
}

bool operator==(const NEP &N, const US &U) {
    return N.NRs == U.USD * 101.36;
}

int main() {
    double a, b;

    cout << "Enter the Nepali currency: ";
    cin >> a;
    NEP RS(a);

    cout << "Enter the US currency: ";
    cin >> b;
    US USD(b);

    if (RS == USD) {
        cout << "Both currencies are equal" << endl;
    } else if (RS > USD) {
        cout << "Nepali currency is greater" << endl;
    } else if (RS < USD) {
        cout << "US currency is greater" << endl;
    }
    else
    {}

    return 0;
}
