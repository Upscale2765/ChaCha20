#include <cstdint>

class ChaCha20 {
	private:
		uint32_t *chacha_state;

	public:
		ChaCha20(uint32_t *key, uint32_t *nonce);
};
