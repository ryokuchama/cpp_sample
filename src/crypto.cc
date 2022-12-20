#include <crypto.h>

#include <iostream>

int Crypto::generateKey() {
  // generate ramdom seed class
  CryptoPP::AutoSeededRandomPool pool;
  // convert data to 16
  CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
  // Store Keys
  CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
  CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

  // generate key
  pool.GenerateBlock(key, key.size());
  // generate initialize vector
  pool.GenerateBlock(iv, iv.size());

  std::string plain = "CBC Mode Test";
  std::string cipher, recovered;

  std::cout << "plain text: " << plain << std::endl;

  try {
    CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    CryptoPP::StringSource s(
        plain, true,
        new CryptoPP::StreamTransformationFilter(
            e,
            new CryptoPP::StringSink(cipher))  // StreamTransformationFilter
    );                                         // StringSource
  } catch (const CryptoPP::Exception& e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
}