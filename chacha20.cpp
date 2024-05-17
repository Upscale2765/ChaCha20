/*
A ChaCha20 implementation
Copyright (C) 2024 Upscale2765

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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

void ChaCha20::get_stream(uint32_t *out, uint32_t ctr) {
    for (int i = 0; i < 16; i++) {
        out[i] = chacha_state[i];
    }

    out[12] = ctr;

    for (int i = 0; i < 10; i++) {
        quarter_round(out, 0, 4, 8, 12);
        quarter_round(out, 1, 5, 9, 13);
        quarter_round(out, 2, 6, 10, 14);
        quarter_round(out, 3, 7, 11, 15);

        quarter_round(out, 0, 5, 10, 15);
        quarter_round(out, 1, 6, 11, 12);
        quarter_round(out, 2, 7, 8, 13);
        quarter_round(out, 3, 4, 9, 14);
    }

    for (int i = 0; i < 16; i++) {
        out[i] += chacha_state[i];
    }
}