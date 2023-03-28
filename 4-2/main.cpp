#include <AES.h>
#include <DES.h>

int main () {
    unsigned op, alg;
    string file_in, file_out, key;
    do {
        cout << "Шифратор запущен. Выберите алгоритм шифрования (0-выход, 1-AES, 2-DES): ";
        cin >> alg;
        if (alg != 0) {
            cout<<"Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать): ";
            cin >> op;
        }
        if (alg > 2) {
            cerr << "Неверный выбор алгоритма" << endl;
        }
        else if (alg > 0) {
            cout << "Введите путь к входному файлу: ";
            cin >> file_in;
            cout << "Введите путь к выходному файлу: ";
            cin >> file_out;
            cout << "Введите ключ: ";
            cin >> key;
            if (alg == 1) {
                mod_AES aes(file_in, file_out, key);
                if (op == 1) {
                    if (aes.encrypt())
                        cout << "Шифрование завершено" << endl;
                    else
                        cout << "Сбой шифрования" << endl;
                } else {
                    if (aes.decrypt())
                        cout << "Расшифровка завершена" << endl;
                    else
                        cout << "Расшифровка не удалась" << endl;
                }
            }
            else if (alg == 2) {
                mod_DES des(file_in, file_out, key);
                if (op == 1) {
                    if (des.encrypt())
                        cout << "Шифрование завершено" << endl;
                    else
                        cout << "Сбой шифрования" << endl;
                } else {
                    if (des.decrypt())
                        cout << "Шифрование завершено" << endl;
                    else
                        cout << "Сбой шифрования" << endl;
                }
            }
            else {
                cerr << "Алгоритм прерван: неверный текст!" << endl;
            }
        }
    } while (alg != 0);
    return 0;
}