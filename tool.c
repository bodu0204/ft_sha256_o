#include"sha256.h"

unit32_t	rbit(unit32_t x, unit32_t n)
{
	n %= 32;
	return ((x >> n) | (x << (32 - n)));
}

void	b32tob8(unit32_t *src, unit8_t *dst)
{
	dest[0] = (*src >> 24);
	dest[1] = (*src >> 16) & 0xff;
	dest[2] = (*src >> 8) & 0xff;
	dest[3] = *src & 0xff;
	return ;
}

void	b8tob32(unit8_t *src, unit32_t *dst)
{
	*dest = (((unit32_t)src[0]) << 24) | (((unit32_t)src[1]) << 16) \
	 | (((unit32_t)src[2]) << 8) | ((unit32_t)src[3]);
	return ;
}
