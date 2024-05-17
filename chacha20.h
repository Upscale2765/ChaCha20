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

class ChaCha20 {
	private:
		uint32_t *chacha_state;
		uint32_t l_roll(uint32_t w, unsigned int b);
		uint32_t e_flip(uint32_t w);
		void quarter_round(uint32_t *state, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

	public:
		ChaCha20(uint32_t *key, uint32_t *nonce);
		void get_stream(uint32_t *out, uint32_t ctr);
};
