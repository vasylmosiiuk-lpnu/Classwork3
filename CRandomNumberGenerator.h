#pragma once
#include <ostream>

class CRandomNumberGenerator
{
private:
	unsigned int* seed;

	inline static size_t objCounter = 0;
	inline static size_t rndNumbersGenCount = 0;

public:
	CRandomNumberGenerator();
	explicit CRandomNumberGenerator(unsigned int seed);

	CRandomNumberGenerator(const CRandomNumberGenerator& other);
	CRandomNumberGenerator(CRandomNumberGenerator&& other) noexcept;

	CRandomNumberGenerator& operator=(const CRandomNumberGenerator& other);
	CRandomNumberGenerator& operator=(CRandomNumberGenerator&& other) noexcept;

	~CRandomNumberGenerator();

	unsigned int getNext();
	unsigned int getNext(unsigned int min, unsigned int max);
	double getNextDouble();
	void getNextNumbers(unsigned int * numbers, size_t count);

	double operator()();

	friend std::ostream& operator<<(std::ostream& out, CRandomNumberGenerator& rnd);
};

std::ostream& operator<<(std::ostream& out, CRandomNumberGenerator& rnd);