

#ifndef OPENSSLTOOL_H

#define OPENSSLTOOL_H

#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/rand.h>
#include <QDebug>


class OpenSSLTool
{
public:

    RSA* readRSAKeyFromContext(const QString& keyContext);

    RSA* readRSAKeyFromFile(const char* filename);

    int encryptRSA(RSA* r , const unsigned char *data, int data_size , unsigned char * out);
    int decryptRSA(RSA* r , const unsigned char *data, int data_size , unsigned char * out);

    QByteArray getDecryptStrByRSA(RSA *rsa, const QByteArray &encryptedData);
    QByteArray getEncryptStrByRSA(RSA *rsa, const QByteArray &data);

    OpenSSLTool();
};


#endif // OPENSSLTOOL_H



