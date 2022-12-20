#ifndef INTERFACE_CRYPTO_H_
#define INTERFACE_CRYPTO_H_

#include <cassert>
#include <cstddef>
#include <cstdint>

class InterfaceCrypto {
 public:
  virtual ~InterfaceCrypto() {}
  virtual int generateKey() = 0;
};

#endif  // INTERFACE_CRYPTO_H_