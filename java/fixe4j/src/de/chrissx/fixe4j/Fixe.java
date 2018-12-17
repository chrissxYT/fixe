package de.chrissx.fixe4j;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class Fixe {

	public static byte[] keyFromStr(String str)
	{
		return str.getBytes(StandardCharsets.US_ASCII);
	}

	public static byte[] keyFromInt(int i)
	{
		return ByteBuffer.allocate(4).putInt(i).array();
	}

	public static byte[] keyFromLong(long i)
	{
		return ByteBuffer.allocate(8).putLong(i).array();
	}

	public static void fixe(byte[] key, byte[] in, byte[] out)
	{
		assert in.length <= out.length;
		for(int i = 0; i < in.length; i++)
		{
			out[i] = (byte) (in[i] ^ key[i % key.length]);
		}
	}
}
