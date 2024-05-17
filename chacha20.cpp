#include <cstdint>
#include "chacha20.h"

uint32_t ChaCha20::l_roll(uint32_t w, unsigned int b) {
    return (w << b) | (w >> (32 - b));
}

void ChaCha20::quarter_round(uint32_t *s, uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
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
        key[0], key[1], key[2], key[3], key[4], key[5], key[6], key[7],
        0x00000000, nonce[0], nonce[1], nonce[2], 
    };
}