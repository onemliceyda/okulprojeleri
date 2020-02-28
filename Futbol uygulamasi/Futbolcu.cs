using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Odev2_g181210107_2A
{
    abstract class Futbolcu //abstract olarak ana sınıfımız
    
    {
        protected string AdSoyad; // kalıtılacak değişkenler tanımlanıyor
        protected int FormaNo;
        protected double Hiz;
        protected double Dayaniklilik, Pas, Sut, Yetenek, Kararlilik, DogalForm, Sans;
        protected double PasSkor, GolSkor;
        public abstract double PasVer(); // abstract Methodlar
        public abstract double GolVurusu();
        public int secim; // secim değişkeni

        public string EkranaYaz() // Ekrana yazdırma methodu
        {
            return AdSoyad + " (" + FormaNo + ")";
        }

        public int _Secim // secim özelliği yanlış secimi önlemek için
        {
            get
            {
                return secim;
            }
            set
            {
                while (true)
                {
                    if (value == 1)
                    {
                        secim = value;
                        break;
                    }
                    else if (value == 2)
                    {
                        secim = value;
                        break;
                    }
                    else if (value == null)
                    {
                        Console.Write("\n Tekrar Deneyin : ");
                        value = Convert.ToInt32(Console.ReadLine());
                    }
                    else
                    {
                        Console.Write("\n Tekrar Deneyin : ");
                        value = Convert.ToInt32(Console.ReadLine());
                    }
                }
            }
        }
    }

}

