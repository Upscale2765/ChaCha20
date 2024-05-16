#include <cstdint>

class ChaCha20 {
	private:
		uint32_t *chacha_state;

	public:
		ChaCha20(uint32_t *key, uint32_t *nonce);
		void quarter_round(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d);
};
