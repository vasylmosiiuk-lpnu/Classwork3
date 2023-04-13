#include "CRandomNumberGenerator.h"
#include <climits>
#include <ctime>

CRandomNumberGenerator::CRandomNumberGenerator() : CRandomNumberGenerator(time(nullptr))
{
}

CRandomNumberGenerator::CRandomNumberGenerator(unsigned seed) : seed(new unsigned(seed))
{
	++objCounter;
}

CRandomNumberGenerator::CRandomNumberGenerator(const CRandomNumberGenerator& other) : CRandomNumberGenerator(*other.seed)
{
}

CRandomNumberGenerator::CRandomNumberGenerator(CRandomNumberGenerator&& other) noexcept : seed(nullptr)
{
	std::swap(seed, other.seed);

	++objCounter;
}

CRandomNumberGenerator& CRandomNumberGenerator::operator=(const CRandomNumberGenerator& other)
{
	if(this != &other)
	{
		*seed = *other.seed;
	}

	return *this;
}

CRandomNumberGenerator& CRandomNumberGenerator::operator=(CRandomNumberGenerator&& other) noexcept
{
	if (this != &other)
	{
		seed = nullptr;
		std::swap(seed, other.seed);
	}

	return *this;
}

CRandomNumberGenerator::~CRandomNumberGenerator()
{
	delete seed;

	seed = nullptr;
}

unsigned CRandomNumberGenerator::getNext()
{
	constexpr int a = 75;
	constexpr int c = 74;
	constexpr int m = (2 << 16) - 1;

	*seed = (a * *seed + c) % m;

	++rndNumbersGenCount;

	return *seed;
}

unsigned CRandomNumberGenerator::getNext(unsigned min, unsigned max)
{
	return static_cast<unsigned>(getNextDouble() * static_cast<double>(max - min) + min);
}

double CRandomNumberGenerator::getNextDouble()
{
	return getNext() / static_cast<double>(UINT32_MAX);
}

void CRandomNumberGenerator::getNextNumbers(unsigned * numbers, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		numbers[i] = getNext();
	}
}

double CRandomNumberGenerator::operator()()
{
	return getNextDouble();
}

std::ostream& operator<<(std::ostream& out, CRandomNumberGenerator& rnd)
{
	out << rnd.getNext();

	return out;
}
