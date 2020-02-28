using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Odev2_g181210107_2A
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random1 = new Random(); // Random nesnesi oluşturduk
            List<Futbolcu> takim = new List<Futbolcu>(); // Liste yöntemiyle oyuncuları oluşturduk
            takim.Add(new Defans("Aysun Karabacak", 1));
            takim.Add(new Defans("Hilal Sevinç", 2));
            takim.Add(new Defans("Nehir Yayla", 3));
            takim.Add(new Defans("Beyzanur Gülapoğlu", 4));
            takim.Add(new Ortasaha("Eda Nur Tavmaşat", 5));
            takim.Add(new Ortasaha("Beyza Nadaroğlu", 6));
            takim.Add(new Ortasaha("Zeynep Melike", 7));
            takim.Add(new Ortasaha("Elif Sezer", 8));
            takim.Add(new Forvet("Serap Özgür", 9));
            takim.Add(new Forvet("Berra Yakar", 10));

            while (true)
            {
                int FormaNum; // Oyuncular için forma numarası tanımlıyoruz
                int kontrol;//secimlerin kontrolu için değişken.
                Console.WriteLine("Rastgele bir oyuncu secildi ");
                FormaNum = random1.Next(0, 9); // Oyuncuların rastegele seçilmesi için random değerler atıyoruz
                Console.WriteLine(takim[FormaNum].EkranaYaz() + "\n");
                Console.WriteLine("Pas Vermek için herhangi bir tuşa basın");
                Console.ReadLine();
                Console.Clear(); // konsolun temizlenmesi için 
                for (int i = 1; i <= 3; i++) // Pas sayısına göre döngü başşlattık
                {

                    if (takim[FormaNum].PasVer() > 60) // pas değerini
                    {
                        Console.Write("Pas Başarılı  : " + takim[FormaNum].EkranaYaz() + " = ");
                        kontrol = random1.Next(0, 9); // pası atacağımız oyuncu belirleniyor
                                                      //Oyuncunun kendine pas atmaması için yazdığımız döngü
                        while (true)
                        {
                            if (FormaNum != kontrol)
                            {
                                FormaNum = kontrol;
                                break;
                            }
                            else
                            {
                                kontrol = random1.Next(1, 10);
                            }
                        }
                        Console.Write(takim[FormaNum].EkranaYaz() + "\n"); //Ekrana yazdırma
                        if (i == 3) // gol için pas sayısı sogusu
                        {
                            if (takim[FormaNum].GolVurusu() > 70) //Gol sorgusu
                            {
                                Console.ReadLine();
                                Console.Clear();
                                Console.WriteLine("GOOOOOOOL!!!! ");
                                Console.WriteLine("Harika pasları ile takımına golü atan oyuncuuuu  " + takim[FormaNum].EkranaYaz() + " oldu" + "\n Devam etmek için tıklayınız.");
                                Console.ReadLine();
                                Console.Clear();
                                //Ekrana yazdırıyoruz
                                Console.WriteLine("Tekrardan oynamak için 1'e tıklayın \n Oyundan çıkmak için 2'ye tıklayınız");
                                takim[FormaNum]._Secim = Convert.ToInt32(Console.ReadLine());
                                if (takim[FormaNum]._Secim == 1) // Çıkma veya yeniden oynamak için tercih yapılıyor
                                {
                                    Console.Clear();
                                    break;
                                }
                                else if (takim[FormaNum]._Secim == 2)
                                {
                                    System.Environment.Exit(0);
                                }
                                else
                                {
                                    Console.WriteLine("Seçiminiz Geçersiz");
                                }
                            }
                            else //gol başarılı olmazsa
                            {
                                Console.ReadLine();
                                Console.Clear();
                                Console.WriteLine(" Golü Kaçırdınııız --> " + takim[FormaNum].EkranaYaz() + " Kaçırdı \n");
                                Console.WriteLine("Tekrar Oynamak için 1 e tıklayınız.. \n Çıkmak için 2 ye tıklayınız.. ");
                                takim[FormaNum]._Secim = Convert.ToInt32(Console.ReadLine());
                                if (takim[FormaNum]._Secim == 1)
                                {
                                    Console.Clear();
                                    break;
                                }
                                else if (takim[FormaNum]._Secim == 2)
                                {
                                    System.Environment.Exit(0);
                                }
                                else
                                {
                                    Console.WriteLine("Geçersiz Secim");
                                }

                            }
                        }
                    }
                    else // pasın gerçekleşmediği durumlar.
                    {
                        Console.WriteLine("Pas başarısız oldu ");
                        Console.WriteLine("Hata Yapan Oyuncu : " + takim[FormaNum].EkranaYaz());
                        Console.ReadLine();
                        Console.Clear();
                        break;
                    }
                }
            }
        }
    }
}

   
