#include <cstdint>

class ChaCha20 {
	private:
		uint32_t *chacha_state;

	public:
		ChaCha20(uint32_t *key, uint32_t *nonce);
		uint32_t l_roll(uint32_t w, unsigned int b);
		void quarter_round(uint32_t *state, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};
