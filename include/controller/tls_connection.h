#ifndef TLS_CONNECTION_H
#define TLS_CONNECTION_H

#include "net/connection.h"
#include <openssl/ssl.h>

class TLSConnection : public Connection {
private:
    SSL *ssl;
    bool tls_enabled;

public:
    TLSConnection(socket_t fd, SSL *ssl_ctx);

    ~TLSConnection() override;

    void start() override;

    void stop() override;

protected:
    SSL* get_ssl() { return ssl; }  // getter protegido
    int read_data(std::vector<uint8_t> &buffer) override;

    int write_data(const std::vector<uint8_t> &buffer) override;
};

#endif // TLS_CONNECTION_H
