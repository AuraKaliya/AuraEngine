#pragma once
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/rand.h>

#include <QDebug>
#include <QVector>
#include "../AuraGlobal.h"
namespace AuraTool{
class AuraLibrary_DECL OpenSSLTool
{
public:
    OpenSSLTool();

    //==================================RSA==================================
public:
    RSA* readRSAKeyFromContext(const QString& keyContext);
    RSA* readRSAKeyFromFile(const char* filename);

    QByteArray getEncryptStrByRSA(RSA *rsa, const QByteArray &data);
    QByteArray getDecryptStrByRSA(RSA *rsa, const QByteArray &encryptedData);
protected:
    int encryptRSA(RSA* r , const unsigned char *data, int data_size , unsigned char * out);
    int decryptRSA(RSA* r , const unsigned char *data, int data_size , unsigned char * out);
    //==================================RSA==================================
    //==================================SHA256==================================
public:
    QString solveBySHA256(const QVector<QString>& infoList);
    //==================================SHA256==================================
};


}
