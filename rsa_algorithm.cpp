#include <bits/stdc++.h>
using namespace std;

// power(a, b, m) = (a^b) mod m
long long power(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return res;
}

// gcd বের করার ফাংশন
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// modular inverse বের করার ফাংশন (d বের করার জন্য)
long long modInverse(long long e, long long phi) {
    for (long long d = 2; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    // ধাপ ১: ছোট দুইটি prime সংখ্যা
    long long p = 7, q = 11;

    // ধাপ ২: n এবং phi(n) বের করা
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    // ধাপ ৩: e নির্বাচন করা যেন gcd(e, phi) = 1
    long long e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }

    // ধাপ ৪: d বের করা যেন (e*d) mod phi = 1
    long long d = modInverse(e, phi);

    cout << "p = " << p << ", q = " << q << endl;
    cout << "n = " << n << ", phi(n) = " << phi << endl;
    cout << "Public key (e, n) = (" << e << ", " << n << ")" << endl;
    cout << "Private key (d, n) = (" << d << ", " << n << ")" << endl;

    // মূল মেসেজ
    long long M;
    cout << "\nEnter message (number, less than " << n << "): ";
    cin >> M;

    // Encryption: C = M^e mod n
    long long C = power(M, e, n);
    cout << "Encrypted (C) = " << C << endl;

    // Decryption: M = C^d mod n
    long long decrypted = power(C, d, n);
    cout << "Decrypted (M) = " << decrypted << endl;

    return 0;
}