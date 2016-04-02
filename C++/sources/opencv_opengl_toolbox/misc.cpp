#include <QString>

QString getRandomString() {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgjijklmnopqstruvwzyz0123456789");;
    const int randomStringLength = 12;

    QString randomString;
    for(int i = 0; i < randomStringLength; ++i){
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}
