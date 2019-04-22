#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    int c;

    enum State {
        SPACE,
        PATTERN_0,
        PATTERN_1,
        CHECK_0,
        CHECK_1,
        SKIP_END
    };

    enum State st = SPACE;
    int k = 0, m = 0;
    int mm = 0, kk = 0;

    while ((c = cin.get()) != EOF) {
        if (isspace(c)) {
            switch (st) {
            case SPACE:
                break;
            case PATTERN_0:
                cout << 0 << endl;
                st = SPACE;
                break;
            case PATTERN_1:
                cout << 1 << endl;
                st = SPACE;
                break;
            case CHECK_0:
                cout << 0 << endl;
                k = m = kk = mm = 0;
                st = SPACE;
                break;
            case CHECK_1:
                if (k == kk && m == mm) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
                k = m = kk = mm = 0;
                st = SPACE;
                break;
            case SKIP_END:
                st = SPACE;
                break;
            }
        } else if (c == '0') {
            switch (st) {
            case SPACE:
                k = 1;
                m = 0;
                st = PATTERN_0;
                break;
            case PATTERN_0:
                ++k;
                break;
            case PATTERN_1:
                kk = 1;
                st = CHECK_0;
                break;
            case CHECK_0:
                ++kk;
                break;
            case CHECK_1:
                if (kk != k || mm != m) {
                    cout << 0 << endl;
                    st = SKIP_END;
                } else {
                    mm = 0;
                    kk = 1;
                    st = CHECK_0;
                }
                break;
            case SKIP_END:
                break;
            }
        } else if (c == '1') {
            switch (st) {
            case SPACE:
                cout << 0 << endl;
                st = SKIP_END;
                break;
            case PATTERN_0:
                m = 1;
                st = PATTERN_1;
                break;
            case PATTERN_1:
                ++m;
                break;
            case CHECK_0:
                if (k != kk) {
                    cout << 0 << endl;
                    st = SKIP_END;
                } else {
                    st = CHECK_1;
                    mm = 1;
                }
                break;
            case CHECK_1:
                ++mm;
                break;
            case SKIP_END:
                break;
            }
        } else {
            switch (st) {
            case SPACE:
                cout << 0 << endl;
                st = SKIP_END;
                break;
            case PATTERN_0:
                k = m = kk = mm = 0;
                cout << 0 << endl;
                st = SKIP_END;
                break;
            case PATTERN_1:
                k = m = kk = mm = 0;
                cout << 0 << endl;
                st = SKIP_END;
                break;
            case CHECK_0:
                k = m = kk = mm = 0;
                cout << 0 << endl;
                st = SKIP_END;
                break;
            case CHECK_1:
                k = m = kk = mm = 0;
                cout << 0 << endl;
                st = SKIP_END;
                break;
            case SKIP_END:
                break;
            }
        }
    }

    switch (st) {
    case PATTERN_0:
        cout << 0 << endl;
        break;
    case PATTERN_1:
        cout << 1 << endl;
        break;
    case CHECK_0:
        cout << 0 << endl;
        break;
    case CHECK_1:
        if (kk != k || mm != m) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    default:
        break;
    }

    return 0;
}