/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   NESNEYE DAYALI PROGRAMLAMA DERSİ
**					2018-2019 BAHAR DÖNEMİ
**	
**				ÖDEV NUMARASI..........:3.ODEV
**				ÖĞRENCİ ADI............:CEYDA ÖNEMLİ
**				ÖĞRENCİ NUMARASI.......:g181210107
**              DERSİN ALINDIĞI GRUP...:2A
****************************************************************************/


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NDP_Odev3
{
    public partial class Form1 : Form
    {
        double temp, temp1; // aradaki  sayilari tutmak için serbest değişken
        double[] sayilar = new double[1000]; //sayilar icin dizi oluşturdum
        double sonucVal=0;
        string s,s2; // aradaki sayilarin string halini tutan rastgele değişkenler
        char topla = '+';// isaretleri tanımladım
        char eksilt = '-';
        char carp = '*';
        char bol = '/';
        string isaretler; // isaretleri tutan string
        Islemler islem = new Islemler(); 
        private void txtIslem_KeyPress(object sender, KeyPressEventArgs e) // sadece rakam ve belirili işaretlerin girilmesini sağlayan kod parçası
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar) && e.KeyChar != '+' && e.KeyChar != '-' && e.KeyChar != '*' && e.KeyChar != '/';
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void btnHesapla_Click(object sender, EventArgs e)
        {
            int i = 0;
            s = txtIslem.Text;
            foreach(char a in s) // sayilari ve işaretleri ayıran foreach döngüsü
            {
                if (a == topla)
                {
                    sayilar[i] = Convert.ToDouble(s2);
                    s2 = ""; 
                    i++;
                    isaretler += a;
                }
                else if(a == eksilt)
                {
                    sayilar[i] = Convert.ToDouble(s2);
                    s2 = "";
                    i++;
                    isaretler += a;
                }
                else if (a == carp)
                {
                    sayilar[i] = Convert.ToDouble(s2);
                    s2 = "";
                    i++;
                    isaretler += a;
                }
                else if (a == bol)
                {
                    sayilar[i] = Convert.ToDouble(s2);
                    s2 = "";
                    i++;
                    isaretler += a;
                }
                else
                {
                    s2 += a.ToString();
                }
            }
            sayilar[i] = Convert.ToDouble(s2);
            s2 = "";
            int x = 0;
            foreach (char b in isaretler) // isaretlere göre islem yapan foreach döngüsü
            {

                if (b == carp)
                {
                    sayilar[x + 1] = sayilar[x] * sayilar[x + 1];

                }
                else  if (b == bol)
                {
                        sayilar[x + 1] = sayilar[x] / sayilar[x + 1];
                }
                else if (b == topla)
                {
                    if(x+1<isaretler.Length)
                    {
                        if (isaretler[x + 1] == bol || isaretler[x + 1] == carp || isaretler[x + 1] == null)
                        {
                            temp1+=sayilar[x];
                        }
                        else
                        {
                            sayilar[x + 1] = sayilar[x] + sayilar[x + 1];
                        }
                    }
                    else
                    {
                        sayilar[x + 1] = sayilar[x] + sayilar[x + 1];
                    }
                }
                else if (b == eksilt)
                {
                    if ((x+1)<isaretler.Length)
                    {
                        if (isaretler[x + 1] == bol || isaretler[x + 1] == carp)
                        {
                        }
                        else
                        {
                            sayilar[x + 1] = sayilar[x] - sayilar[x + 1];
                        }
                    }
                    else
                    {
                        sayilar[x + 1] = sayilar[x] - sayilar[x + 1];
                    }
                    
                }
                temp = sayilar[x + 1];
                x =x+1;

            }
            sonucVal = temp + temp1;
            txtSonuc.Text = sonucVal.ToString(); // sonucu ekrana yazdıran kod
            for(int c = 0; c == sayilar.Length; c++) //dizileri ve değişkenleri temizliyoruz...
            {
                sayilar[c] = 0;
            }
            sonucVal = 0;
            temp1 = 0;
            temp = 0;
            isaretler = "";
            s = "";
            s2 = "";
        }
    }
}
//10+5-20+10/2+5*5
