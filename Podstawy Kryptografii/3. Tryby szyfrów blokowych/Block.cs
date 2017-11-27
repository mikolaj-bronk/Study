//Mikolaj Bronk 234998
using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;


namespace Enc
{
    class Block
    {       
        public static void ECB(string filename, string outfilename)
        {
            TripleDESCryptoServiceProvider ECB_crypt = new TripleDESCryptoServiceProvider();

            ECB_crypt.GenerateIV();
            ECB_crypt.GenerateKey();

            ECB_crypt.Mode = CipherMode.ECB;
            FileStream plik = new FileStream(filename, FileMode.Open, FileAccess.Read);
            MemoryStream ms = new MemoryStream();
            plik.CopyTo(ms);           
            var header = ms.ToArray().Take(54).ToArray();           
            var imageArray = ms.ToArray().Skip(54).ToArray();           
            var enc = ECB_crypt.CreateEncryptor();           
            var encimg = enc.TransformFinalBlock(imageArray, 0, imageArray.Length);          
            var image = Combine(header, encimg);           
            File.WriteAllBytes(outfilename, image);

        }

        public static void CBC(string filename, string outfilename)
        {
            TripleDESCryptoServiceProvider CCB_crypt = new TripleDESCryptoServiceProvider();

            CCB_crypt.GenerateIV();
            CCB_crypt.GenerateKey();

            CCB_crypt.Mode = CipherMode.CBC;
            FileStream plik = new FileStream(filename, FileMode.Open, FileAccess.Read);
            MemoryStream ms = new MemoryStream();
            plik.CopyTo(ms);      
            var header = ms.ToArray().Take(54).ToArray();          
            var imageArray = ms.ToArray().Skip(54).ToArray();           
            var enc = CCB_crypt.CreateEncryptor();           
            var encimg = enc.TransformFinalBlock(imageArray, 0, imageArray.Length);
            var image = Combine(header, encimg);
            File.WriteAllBytes(outfilename, image);

        }

        static void Main(string[] args)
        {

            ECB(@"plain.bmp", @"ecb_crypto.bmp");
            CBC(@"plain.bmp", @"cbc_crypto.bmp");


        }
        public static byte[] Combine(byte[] first, byte[] second)
        {
            byte[] ret = new byte[first.Length + second.Length];
            Buffer.BlockCopy(first, 0, ret, 0, first.Length);
            Buffer.BlockCopy(second, 0, ret, first.Length, second.Length);
            return ret;
        }
    }
}
