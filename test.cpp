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
#include <iostream>
#include <cstdint>
#include "chacha20.h"

using namespace std;

int main() {
	uint32_t key[8] = {
		0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f,
		0x10111213, 0x14151617, 0x18191a1b, 0x1c1d1e1f
	};

	uint32_t nonce[3] = {
		0x00000009, 0x0000004a, 0x00000000
	};

	ChaCha20 chacha(key, nonce);

	uint32_t stream[16];

	chacha.get_stream(stream, 1);

	cout << hex;

	for (int i = 0; i < 16; i++) {
		cout << stream[i] << endl;
	}

	return 0;
}
