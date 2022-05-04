#include"sha256.h"

void	sha256_hash(t_sha *ctx, const void *data, size_t len)
{
	const uint8_t	*bytes;
	size_t			i;

	ctx->bits[0] = len / 0x100000000;
	ctx->bits[1] = len % 0x100000000;
	bytes = (const uint8_t *)data;
	i = 0;
	while (i < len)
	{
		ctx->buf[ctx->len] = bytes[i];
		ctx->len++;
		i++;
		if (ctx->len == sizeof(ctx->buf)) {
			hash(ctx);
			ctx->len = 0;
		}
	}
}

void	hash(t_sha *ctx)
{
	uint32_t hs[8];
	uint32_t t[2];
	size_t	i;

	//a = ctx->hash[0];
	//b = ctx->hash[1];
	//c = ctx->hash[2];
	//d = ctx->hash[3];
	//e = ctx->hash[4];
	//f = ctx->hash[5];
	//g = ctx->hash[6];
	//h = ctx->hash[7];
	memcpy(ctx->hash, hs, sizeof(uint32_t) * 8);

	i = 0;
	while (i < 64)
	{
		memmove(ctx->W + 1, ctx->W, sizeof(uint32_t) * 16);
		if (i < 16) {
			/* ctx->W[16] = _word(&ctx->buf[_shw(i, 2)]); */ b8tob32(ctx->buf + (i * 4), ctx->W + 16);
		} else {
			ctx->W[16] = G1(ctx->W[14])  + ctx->W[9] +
						G0(ctx->W[1]) + ctx->W[0];
		}

		t[0] = h + S1(hs[4]) + Ch(hs[4], hs[5], hs[6]) + ctx->K[i] + ctx->W[16];
		t[1] = S0(hs[0]) + Ma(hs[0], hs[1], hs[2]);
		memmove(hs + 1, hs, sizeof(uint32_t) * 7);
		hs[4] += t[0];
		hs[0] = t[0] + t[1];
		//h = g;
		//g = f;
		//f = e;
		//e = d + t[0];
		//d = c;
		//c = b;
		//b = a;
		//a = t[0] + t[1];
		i++;
	}

	//ctx->hash[0] += a;
	//ctx->hash[1] += b;
	//ctx->hash[2] += c;
	//ctx->hash[3] += d;
	//ctx->hash[4] += e;
	//ctx->hash[5] += f;
	//ctx->hash[6] += g;
	//ctx->hash[7] += h;
	i = 0;
	while (i < 8)
	{
		ctx->hash[i] += sh[i];
		i++;
	}
}
