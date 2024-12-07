
#ifdef LOAD_OPENSSL_BY_PROJECT


#include "openssltool.h"

extern "C"
{
#include <openssl/applink.c>
};

RSA *OpenSSLTool::readRSAKeyFromContext(const QString &keyContext)
{
    // 将 QString 转换为标准字符串
    std::string keyContextStd = keyContext.toStdString();

    // 使用 BIO 对象读取密钥字符串
    BIO* bio = BIO_new_mem_buf((void*)keyContextStd.c_str(), -1);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

    // 从 BIO 中读取私钥
    RSA* rsaKey = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);

    if(rsaKey == nullptr) {
        // 打印错误信息
        ERR_print_errors_fp(stderr);
        // 可以在这里处理错误，例如抛出异常或返回错误代码
    }


    // 清理 BIO 对象
    BIO_free_all(bio);

    // 返回 RSA 密钥
    return rsaKey;
}

RSA *OpenSSLTool::readRSAKeyFromFile(const char *filename)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("无法打开密钥文件");
        return nullptr;
    }

    RSA* rsaKey  = PEM_read_RSAPrivateKey(fp, nullptr, nullptr, nullptr);
    fclose(fp);

    if (!rsaKey) {
        perror("无法读取密钥");
        return nullptr;
    }

    return rsaKey;
}

int OpenSSLTool::encryptRSA(RSA *r, const unsigned char *data, int data_size, unsigned char *out)
{
    int key_size = RSA_size(r);
    int block_size = RSA_size(r) - RSA_PKCS1_PADDING_SIZE;
    int out_size = 0;
    for (int i = 0; i < data_size; i += block_size)
    {
        int en_size = ((data_size - i < block_size) ? data_size - i : block_size);
        int out_off = i + RSA_PKCS1_PADDING_SIZE * (i / block_size);
        int re = RSA_public_encrypt(en_size, data, out + out_off, r, RSA_PKCS1_PADDING);
        out_size = out_off + key_size;
    }
    return out_size;
}

int OpenSSLTool::decryptRSA(RSA *r, const unsigned char *data, int data_size, unsigned char *out)
{
    int key_size = RSA_size(r);
    int out_off = 0;
    for (int i = 0; i < data_size; i += key_size) {
        int re = RSA_private_decrypt(key_size, data + i, out + out_off, r, RSA_PKCS1_PADDING);
        if (re < 0) {
            // 解密失败，处理错误
            qDebug()<<"OpenSSLTool::decryptRSA | error : re<0.";
            return -1;
        }
        out_off += re;
    }
    return out_off;
}

QByteArray OpenSSLTool::getDecryptStrByRSA(RSA *rsa, const QByteArray &encryptedData)
{
    int dataSize = encryptedData.size();
    int byteSize = ((dataSize % RSA_size(rsa)) == 0) ? dataSize : ((dataSize / RSA_size(rsa)) + 1) * RSA_size(rsa);
    QByteArray decryptOut(byteSize, 0);
    qDebug()<<"D=================================OpenSSLTest::getDecryptStrByRSA | ********check:";
    qDebug()<<"dataSize "<<dataSize;
    int strSize = decryptRSA(rsa, reinterpret_cast<const unsigned char*>(encryptedData.constData()), dataSize, reinterpret_cast<unsigned char*>(decryptOut.data()));
    qDebug()<<"strSize "<<strSize;
    qDebug()<<"D=================================OpenSSLTest::getDecryptStrByRSA | ********end.";

    QString decryptedString = QString::fromUtf8(decryptOut.data(), strSize);
    return decryptOut;
}

QByteArray OpenSSLTool::getEncryptStrByRSA(RSA *rsa, const QByteArray &data)
{
    int dataSize = data.size();
    int byteSize = ((dataSize % RSA_size(rsa)) == 0) ? dataSize : ((dataSize / RSA_size(rsa)) + 1) * RSA_size(rsa);
    QByteArray encryptOut(byteSize, 0);

    qDebug()<<"E=================================OpenSSLTest::getEncryptStrByRSA | ********check:";
    qDebug()<<"dataSize "<<dataSize;
    int strSize = encryptRSA(rsa,reinterpret_cast<const unsigned char*>(data.constData()),dataSize, reinterpret_cast<unsigned char*>(encryptOut.data()));
    qDebug()<<"strSize "<<strSize;
    qDebug()<<"E=================================OpenSSLTest::getEncryptStrByRSA | ********end.";

    QString encryptedString = QString::fromUtf8(encryptOut,strSize);
    return encryptOut;
}

OpenSSLTool::OpenSSLTool()
{
    //openssl link
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    OPENSSL_Applink();
}

#endif


