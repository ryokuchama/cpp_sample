#ifndef CRYPTO_H_
#define CRYPTO_H_
#include <aes.h>
#include <cryptlib.h>
#include <files.h>
#include <hex.h>
#include <interface_crypto.h>
#include <modes.h>
#include <osrng.h>
#include <rijndael.h>

#include <string>

class Crypto : public InterfaceCrypto {
 private:
  /* data */
 public:
  Crypto(/* args */) {}
  ~Crypto() {}
  int generateKey() override;
};

#endif  // CRYPTO_H_