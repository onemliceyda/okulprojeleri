using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Odev2_g181210107_2A
{
    class Defans : Futbolcu
    {
        Random random1 = new Random();
        private double PozisyonAlma, Kafa, Sicrama; // Defansa özel değişkenleri kalıtıyoruz..

        public Defans(string adsoyad, int formano)
        {
            //Kurucu da gerekli özellikler rastgele atanıyor..
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
            this.PozisyonAlma = random1.Next(50, 90);
            this.Kafa = random1.Next(50, 90);
            this.Sicrama = random1.Next(50, 90);
        }

        public override double PasVer()
        {
            this.PasSkor = this.Pas * 0.3 + this.Yetenek * 0.3 + this.Dayaniklilik * 0.1 + this.DogalForm * 0.1 + this.PozisyonAlma * 0.1 + this.Sans * 0.2;
            return this.PasSkor;
        }
        public override double GolVurusu()
        {
            this.GolSkor = this.Yetenek * 0.3 + this.Sut * 0.2 + this.Kararlilik * 0.1 + this.DogalForm * 0.1 + this.Kafa * 0.1 + this.Sicrama * 0.1 + this.Sans * 0.1;
            return this.GolSkor;
        }
    }
}

