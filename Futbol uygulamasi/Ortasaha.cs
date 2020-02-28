using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Odev2_g181210107_2A
{
    class Ortasaha : Futbolcu //Futbolcudan OrtaSaha sınıfını kalıtıyoruz
    {
        Random random1 = new Random(); // rastgele nesnemiz
        private double UzunTop, IlkDokunus, Uretkenlik, TopSurme, OzelYetenek; // Orta sahaya özgü değişkenlerimiz

        public Ortasaha(string adsoyad, int formano)
        {
            //Kurucu da gerekli değerler rastgele atanıyor
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
            this.UzunTop = random1.Next(60, 100);
            this.IlkDokunus = random1.Next(60, 100);
            this.Uretkenlik = random1.Next(60, 100);
            this.TopSurme = random1.Next(60, 100);
            this.OzelYetenek = random1.Next(60, 100);
        }
        public override double PasVer()
        {
            this.PasSkor = this.Pas * 0.3 + this.Yetenek * 0.2 + this.OzelYetenek * 0.2 + this.Dayaniklilik * 0.1 + this.DogalForm * 0.1 + this.UzunTop * 0.1 + this.TopSurme * 0.1 + this.Sans * 0.1;
            return this.PasSkor;
        }

        public override double GolVurusu()
        {
            this.GolSkor = this.Yetenek * 0.3 + this.OzelYetenek * 0.2 + this.Sut * 0.2 + this.IlkDokunus * 0.1 + this.Kararlilik * 0.1 + this.DogalForm * 0.1 + this.Sans * 0.1;
            return this.GolSkor;
        }
    }
}


