#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include<stdlib.h>
#include<iomanip>
#include<string>
using namespace std;
struct sheetpdb
{
    string shetname;
    string inires;
    int sheetid;
    string chainid1;
    string terres;
    string chainid2;
    int terseqid;
};
struct atompdb
{
    string atmname;
    string calpha;
    string chainid;
    int code;
    double x;
    double y;
    double z;

};
std::vector<sheetpdb> sheetdata;
std::vector<atompdb> atomdata;
void Outputdata()
{
    ofstream outputdata;
    outputdata.open("Dataextract.txt");
     for(int i=0;i<sheetdata.size();i++)
    {
        for(int j=0;j<atomdata.size();j++)
        {
            if((sheetdata[i].sheetid==atomdata[j].code || sheetdata[i].terseqid==atomdata[j].code)&&(sheetdata[i].chainid1==atomdata[j].chainid || sheetdata[i].chainid2==atomdata[j].chainid))
            {
				outputdata<<endl<<sheetdata[i].shetname<<"  "<<sheetdata[i].inires<<"  "<<sheetdata[i].chainid1<<" "<<sheetdata[i].sheetid<<"  "<<sheetdata[i].terres<<" "<<sheetdata[i].chainid2<<"  "<<sheetdata[i].terseqid;
                outputdata<<endl<<atomdata[j].atmname<<"  "<<atomdata[j].calpha<<"  "<<atomdata[j].chainid<<"  "<<atomdata[j].code<<"  x="<<atomdata[j].x<<"  y="<<atomdata[j].y<<"  z="<<atomdata[j].z<<endl;
            }
        }
    }
}
void extractData(string value, ofstream & opdata)
{
    string Recordtype;
    sheetpdb shet;
    atompdb atm;
    Recordtype=value.substr(0,5);
         if(Recordtype=="SHEET")
        {
            shet.shetname=Recordtype;
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(17,3);
			opdata<<Recordtype<<" ";
			shet.inires=Recordtype;
			Recordtype=value.substr(21,1);
			opdata<<Recordtype<<" ";
			shet.chainid1=Recordtype;
            Recordtype=value.substr(22,4);
            opdata<<Recordtype<<" ";
            shet.sheetid=atoi(Recordtype.c_str());
            Recordtype=value.substr(28,3);
            opdata<<Recordtype<<" ";
            shet.terres=Recordtype;
            Recordtype=value.substr(32,1);
			opdata<<Recordtype<<" ";
			shet.chainid2=Recordtype;
            Recordtype=value.substr(33,4);
            opdata<<Recordtype<<" ";
            shet.terseqid=atoi(Recordtype.c_str());
            sheetdata.push_back(shet);
        }
        Recordtype=value.substr(0,4);
        string word1="";
        if(Recordtype=="ATOM")
        {
            word1=value.substr(13,2);
        }
        if(Recordtype=="ATOM" && word1=="CA")
        {
            atm.atmname=Recordtype;
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(13,2);
            atm.calpha=Recordtype.c_str();
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(21,1);
            atm.chainid=Recordtype.c_str();
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(22,4);
            atm.code=atoi(Recordtype.c_str());
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(30,8);
            atm.x=stod(Recordtype.c_str());
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(38,8);
            atm.y=stod(Recordtype.c_str());
            opdata<<Recordtype<<" ";
            Recordtype=value.substr(46,8);
            atm.z=stod(Recordtype.c_str());
            atomdata.push_back(atm);
        }
}
int main()
{
    string name,filein;
    ifstream input;
    ofstream output;
    cout<<endl<<"Please enter the PDB file name:";
    cin>>filein;
    input.open(filein.c_str());
   if(input.fail())
   {
       cout<<endl<<" Error while opening the file"<<endl;
       exit(0);
   }
   else
    {
        while(!input.eof())
    {
        getline(input,name);
        extractData(name, output);
    }
    }
   Outputdata();
    return 0;
}