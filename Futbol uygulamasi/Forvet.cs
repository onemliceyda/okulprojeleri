using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Odev2_g181210107_2A
{
    class Forvet : Futbolcu // Futbolcudan Forvet sınıfı kalıtıyoruz
    {
        
        
            Random random1 = new Random(); // random atamalar için
            private double Bitiricilik, IlkDokunus, Kafa, OzelYetenek, SogukKanlilik; // forvete özel özellikler



            public Forvet(string adsoyad, int formano)
            {
                //Kurucu fonksoyonda Durumuna göre rastgele atama yapıyoruz...
                this.AdSoyad = adsoyad;
                this.FormaNo = formano;
                this.Hiz = random1.Next(50, 100);
                this.Dayaniklilik = random1.Next(50, 100);
                this.Pas = random1.Next(50, 100);
                this.Sut = random1.Next(50, 100);
                this.Yetenek = random1.Next(50, 100);
                this.Kararlilik = random1.Next(50, 100);
                this.DogalForm = random1.Next(50, 100);
                this.Sans = random1.Next(50, 100);
                this.Bitiricilik = random1.Next(70, 100);
                this.IlkDokunus = random1.Next(70, 100);
                this.Kafa = random1.Next(70, 100);
                this.OzelYetenek = random1.Next(50, 100);
                this.SogukKanlilik = random1.Next(70, 100);
            }
            public override double PasVer() // override PasVer methodu
            {
                this.PasSkor = this.Pas * 0.3 + this.Yetenek * 0.2 + OzelYetenek * 0.2 + this.Dayaniklilik * 0.1 + this.DogalForm * 0.1 + this.Sans * 0.1;
                return this.PasSkor;
            }

            public override double GolVurusu() // override GolVurusu Methodu
            {
                this.GolSkor = this.Yetenek * 0.2 + this.OzelYetenek * 0.2 + this.Sut * 0.1 + this.Kafa * 0.1 + this.IlkDokunus * 0.1 + this.Bitiricilik * 0.1 + this.SogukKanlilik * 0.1 + this.Kararlilik * 0.1 + this.DogalForm * 0.1 + this.Sans * 0.1;
                return this.GolSkor;
            }

        }
    }

