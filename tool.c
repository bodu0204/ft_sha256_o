#include"sha256.h"

uint32_t	rbit(uint32_t x, uint32_t n)
{
	n %= 32;
	return ((x >> n) | (x << (32 - n)));
}

void	b32tob8(uint32_t *src, uint8_t *dst)
{
	dest[0] = (*src >> 24);
	dest[1] = (*src >> 16) & 0xff;
	dest[2] = (*src >> 8) & 0xff;
	dest[3] = *src & 0xff;
	return ;
}

void	b8tob32(uint8_t *src, uint32_t *dst)
{
	*dest = (((uint32_t)src[0]) << 24) | (((uint32_t)src[1]) << 16) \
	 | (((uint32_t)src[2]) << 8) | ((uint32_t)src[3]);
	return ;
}
