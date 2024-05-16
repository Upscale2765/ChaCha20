#include <cstdint>
#include "chacha20.h"

void ChaCha20::quarter_round(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d) {

}

ChaCha20::ChaCha20(uint32_t *key, uint32_t *nonce) {
	this -> chacha_state = new uint32_t[16] {
        0x61707865, 0x3320646e, 0x79622d32, 0x6b206574,
        key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7],
        0x00000000, nonce[0], nonce[1], nonce[2], 
    };
}