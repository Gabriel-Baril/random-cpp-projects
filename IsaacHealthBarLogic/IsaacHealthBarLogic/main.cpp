#include <iostream>

enum HeartModifier : uint64_t {
	GOLDEN = 1,
	BONED = 2
};

enum class HeartType {
	EMPTY_HEART,
	RED_HEART,
	SOUL_HEART,
	DEMON_HEART,
	ROTTEN_HEART,
	BROKEN_HEART
};

struct HeartContainer {
	HeartType heartType = HeartType::EMPTY_HEART;
	uint64_t heartModifiers = 0;
	int fillCount = 0;
};

template<unsigned N>
struct PlayerHealthBar {
	HeartContainer containers[N];

	const HeartContainer& getHeart(unsigned index) const {
		return containers[index];
	}
};

void print_heart(const HeartContainer& heart) {
	std::cout << "[" << static_cast<int>(heart.heartType) << ", " << heart.heartModifiers << ", " << heart.fillCount << "]" << std::endl;
}

template<unsigned N>
void print_health_bar(const PlayerHealthBar<N>& healthBar) {
	for (int i = 0; i < N; i++) {
		print_heart(healthBar.getHeart(i));
	}
}

int main() {
	PlayerHealthBar<12> healthBar;
	print_health_bar(healthBar);

	return 0;
}