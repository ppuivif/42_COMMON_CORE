unsigned char reverse_bits(unsigned char octet)
{
	(octet >> 4 | octet << 4);
}