// TLSContext.h
#ifndef TLS_CONTEXT_H
#define TLS_CONTEXT_H

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <string>

class TLSContext {
private:
    SSL_CTX *ctx;

public:
    TLSContext(const std::string &cert_file, const std::string &key_file);

    ~TLSContext();

    SSL_CTX *get() const {
        return ctx;
    }

    // Inicializa OpenSSL (llamar al inicio del programa)
    static void initialize();

    static void cleanup();
};

#endif //TLS_CONTEXT_H
