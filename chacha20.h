#include <cstdint>

class ChaCha20 {
	private:
		uint32_t *chacha_state;
		uint32_t l_roll(uint32_t w, unsigned int b);
		uint32_t e_flip(uint32_t w);
		void quarter_round(uint32_t *state, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

	public:
		ChaCha20(uint32_t *key, uint32_t *nonce);
		void get_stream(uint32_t *out, unsigned int ctr);
};
