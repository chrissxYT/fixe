using System;
using System.Text;
using System.Diagnostics;

namespace ManagedFixe
{
    public static class Fixe
    {
        public static byte[] keyFromStr(String str)
	    {
	    	return Encoding.ASCII.GetBytes(str);
	    }

	    public static byte[] keyFromInt(int i)
	    {
	    	return BitConverter.GetBytes(i);
	    }

	    public static byte[] keyFromLong(long i)
	    {
	    	return BitConverter.GetBytes(i);
	    }

	    public static void fixe(byte[] key, byte[] i, byte[] o)
	    {
	    	Debug.Assert(i.LongLength <= o.LongLength);
	    	for(long j = 0; j < i.LongLength; j++)
	    	{
	    		o[j] = (byte) (i[j] ^ key[j % key.LongLength]);
	    	}
	    }
    }
}
