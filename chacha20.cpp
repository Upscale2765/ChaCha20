#include <cstdint>
#include "chacha20.h"

uint32_t ChaCha20::e_flip(uint32_t w) {
    return (w << 24) |
          ((w <<  8) & 0x00ff0000) |
          ((w >>  8) & 0x0000ff00) |
          ((w >> 24) & 0x000000ff);
}

uint32_t ChaCha20::l_roll(uint32_t w, unsigned int b) {
    return (w << b) | (w >> (32 - b));
}

void ChaCha20::quarter_round(uint32_t *s, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    s[a] += s[b];
    s[d] ^= s[a];
    s[d] = l_roll(s[d], 16);

    s[c] += s[d];
    s[b] ^= s[c];
    s[b] = l_roll(s[b], 12);

    s[a] += s[b];
    s[d] ^= s[a];
    s[d] = l_roll(s[d], 8);

    s[c] += s[d];
    s[b] ^= s[c];
    s[b] = l_roll(s[b], 7);
}

ChaCha20::ChaCha20(uint32_t *key, uint32_t *nonce) {
	chacha_state = new uint32_t[16] {
        0x61707865, 0x3320646e, 0x79622d32, 0x6b206574,
        e_flip(key[0]), e_flip(key[1]), e_flip(key[2]), e_flip(key[3]),
        e_flip(key[4]), e_flip(key[5]), e_flip(key[6]), e_flip(key[7]),
        0x00000000, e_flip(nonce[0]), e_flip(nonce[1]), e_flip(nonce[2]), 
    };
}