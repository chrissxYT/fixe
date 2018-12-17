package de.chrissx.fixe4j.tests;

import de.chrissx.fixe4j.Fixe;

public class Test {

	public static void main(String[] args) {
		byte[] i = "this is a secret text i want to encrypt".getBytes();
		byte[] o = new byte[i.length];
		byte[] k = Fixe.keyFromStr("THIS IS SECRET!");
		Fixe.fixe(i, o, k);
	}

}
