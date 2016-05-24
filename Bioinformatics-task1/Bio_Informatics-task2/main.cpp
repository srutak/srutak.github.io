#include <iostream>
#include<fstream>
#include<sstream>
#include <vector>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

struct atompdb
{
    string atomName;
    int num;
    string calpha;
     string residueName;
    string chainid;
    int atomdataerialNumber;
    double xCoordinate;
    double yCoordinate;
    double zCoordinate;
    string sym;
};
struct sheetpdb
{
    string shetname;
    string residueName;
    int sheetid;
    string chainid1;
    string terres;
    string chainid2;
    int terseqid;
};
struct seqNumR
{
    int start;
    int end;
};
std::vector<sheetpdb> sheetdata;
std::vector<atompdb> atomdata;
std::vector<string> data;
std::vector<atompdb> atomdiff;
std::vector<atompdb> CAdiff;
std::vector<seqNumR> range;
std::vector<seqNumR> CAlpharan;

void rotation()
{
    double x1 = (atomdata[0].xCoordinate);
    double y1 = (atomdata[0].yCoordinate);
    double z1 = (atomdata[0].zCoordinate);
    double x2 = (atomdata[1].xCoordinate);
    double y2 = (atomdata[1].yCoordinate);
    double z2 = (atomdata[1].zCoordinate);
    double r = sqrt((pow((x2-x1),2)) + (pow((y2-y1),2)) + (pow((z2-z1),2)));
    double theta = atan((y2-y1)/(x2-x1));
    double si = acos((z2-z1)/r);
        for(int i=3;i<atomdata.size();i=i+2){
        atompdb aData1;
        double x3 = (atomdata[i-1].xCoordinate);
        double y3 = (atomdata[i-1].yCoordinate);
        double z3 = (atomdata[i-1].zCoordinate);
        aData1.atomName=atomdata[i].atomName;
        aData1.atomdataerialNumber=atomdata[i].atomdataerialNumber;
        double x4 = (atomdata[i].xCoordinate);
        double y4 = (atomdata[i].yCoordinate);
        double z4 = (atomdata[i].zCoordinate);
        double R = sqrt((pow((x4-x3),2)) + (pow((y4-y3),2)) + (pow((z4-z3),2)));
        double x5 = R * cos(theta) * sin(si);
        double y5 = R * sin(theta) * sin(si);
        double z5 = R * cos(si);
        x5 += x1;
        y5 += y1;
        z5 += z1;
        atomdata[i].xCoordinate = x5;
        atomdata[i].yCoordinate = y5;
        atomdata[i].zCoordinate = z5;
        aData1.xCoordinate=x5-x4;
        aData1.yCoordinate=y5-y4;
        aData1.zCoordinate=z5-z4;
        CAdiff.push_back(aData1);
    }
}
void CAlphadata()
{
    ifstream inFile;
    ofstream outFile;
    string line;
    inFile.open("difference.pdb");
    outFile.open("CAlpha.pdb");
    int i=0;
        while(!inFile.eof()&&getline(inFile,line))
        {
       if(line.substr(0,1)=="-" || line.substr(0,1)=="#")
          {
          }
          else
          {
           string sheetid=line.substr(22,4);
           string cAlpha=line.substr(12,4);
           string xCoordinate=line.substr(30,8);
           string yCoordinate=line.substr(38,8);
           string zCoordinate=line.substr(46,8);
           string chainIdentifier=line.substr(21,1);
          int num=stoi(sheetid.c_str());

              if(num>=CAlpharan[i+1].start && num<=CAlpharan[i+1].end )
              {
               string x1=to_string(CAdiff[i].xCoordinate);
               string dec=x1.substr(x1.find(".")+1);
                if(dec.length()>3)
                    for(int i=3;i<dec.length();i++)
                    x1.erase(x1.size()-1);
                double x=stod(x1)+stod(xCoordinate);
               string y1=to_string(CAdiff[i].yCoordinate);
                dec=y1.substr(y1.find(".")+1);
                if(dec.length()>3)
                    for(int i=3;i<dec.length();i++)
                    y1.erase(y1.size()-1);
                double y=stod(y1)+stod(yCoordinate);
               string z1=to_string(CAdiff[i].zCoordinate);
               dec=z1.substr(z1.find(".")+1);
                if(dec.length()>3)
                    for(int i=3;i<dec.length();i++)
                    z1.erase(z1.size()-1);
                double z=stod(z1)+stod(zCoordinate);
                  string str = to_string (x);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                   dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                  for(int i=0;i<=(xCoordinate.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);


                   string str1 = to_string (y);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                    dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                   for(int i=0;i<=(yCoordinate.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (z);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                  for(int i=0;i<=(zCoordinate.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);
                  line.replace(line.find(xCoordinate), xCoordinate.length(),str );
                  line.replace(line.find(yCoordinate), yCoordinate.length(),str1);
                  line.replace(line.find(zCoordinate), zCoordinate.length(),str2);
                if(num==(CAlpharan[i+1].end))
                {
                    i++;
                }
              }
        }
        outFile<<line<<endl;
        }
}
void rplcatomdata()
{

    ifstream inFile;
    ofstream outFile;
    string line;
    inFile.open("Aligneddata.pdb");
    outFile.open("difference.pdb");
    int i=0;
        while(!inFile.eof()&&getline(inFile,line))
        {
       if(line.substr(0,1)=="-" || line.substr(0,1)=="#")
          {
          }
          else
          {
           string sheetid=line.substr(22,4);
           string cAlpha=line.substr(12,4);
           string xCoordinate=line.substr(30,8);
           string yCoordinate=line.substr(38,8);
           string zCoordinate=line.substr(46,8);
           string chainIdentifier=line.substr(21,1);
          int num=stoi(sheetid.c_str());
              if(num>=range[i+1].start && num<=range[i+1].end )
              {
              double x=atomdiff[i].xCoordinate+stod(xCoordinate);
              double y=atomdiff[i].yCoordinate+stod(yCoordinate);
              double z=atomdiff[i].zCoordinate+stod(zCoordinate);
                  string str = to_string (x);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                  string dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                  for(int i=0;i<=(xCoordinate.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);
                   string str1 = to_string (y);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                    dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                   for(int i=0;i<=(yCoordinate.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (z);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                  for(int i=0;i<=(zCoordinate.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);
                  line.replace(line.find(xCoordinate), xCoordinate.length(),str );
                  line.replace(line.find(yCoordinate), yCoordinate.length(),str1);
                  line.replace(line.find(zCoordinate), zCoordinate.length(),str2);

                if(num==(range[i+1].end-1))
                {
                    i++;
                }
              }
        }
        outFile<<line<<endl;
        }
}
void replaceCoordinates()
{
    ifstream inFile;
    ofstream outFile;
    string line;
    inFile.open("CAlpha.pdb");
    outFile.open("Final_atomdata.pdb");
    while(!inFile.eof() && getline(inFile,line))
      {
          if(line.substr(0,5)=="-ATOM")
          {
          string sheetid=line.substr(23,4);
          string cAlpha=line.substr(13,4);
          string xCoordinate=line.substr(31,8);
          string yCoordinate=line.substr(39,8);
          string zCoordinate=line.substr(47,8);
          string chainIdentifier=line.substr(22,1);
          string markerAtom="-ATOM";
          string atomdatatring="ATOM";
           line.replace(line.find(markerAtom), markerAtom.length(),atomdatatring);
          for(int i=2;i<atomdata.size();i=i+2 )
          {
              if(atomdata[i].atomdataerialNumber==atoi(sheetid.c_str()) && cAlpha==" CA ")
              {


                  string str = to_string (atomdata[0].xCoordinate);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                  string dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                  for(int i=0;i<=(xCoordinate.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);


                   string str1 = to_string (atomdata[0].yCoordinate);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                    dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                   for(int i=0;i<=(yCoordinate.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (atomdata[0].zCoordinate);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                  for(int i=0;i<=(zCoordinate.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);
                  line.replace(line.find(xCoordinate), xCoordinate.length(),str );
                  line.replace(line.find(yCoordinate), yCoordinate.length(),str1);
                  line.replace(line.find(zCoordinate), zCoordinate.length(),str2);
                  break;
              }
          }
          }
           if(line.substr(0,5)=="#ATOM")
          {
          string sheetid=line.substr(23,4);
          string cAlpha=line.substr(13,4);
          string xCoordinate=line.substr(31,8);
          string yCoordinate=line.substr(39,8);
          string zCoordinate=line.substr(47,8);
          string chainIdentifier=line.substr(22,1);
          string markerAtom="#ATOM";
          string atomdatatring="ATOM";
          line.replace(line.find(markerAtom), markerAtom.length(),atomdatatring);
          for(int i=3;i<atomdata.size();i=i+2 )
          {
              if(atomdata[i].atomdataerialNumber==atoi(sheetid.c_str()) && cAlpha==" CA ")
              {
                  string str = to_string (atomdata[i].xCoordinate);
                  str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
                  string dec=str.substr(str.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str=str+"0";
                     str = (str.substr(0,str.find(".")) + str.substr(str.find("."),4));
                  for(int i=0;i<=(xCoordinate.length()-str.length()+1);i++)
                  str=" "+str;
                  if( str.length()>8)
                    str.erase(0,1);
                   string str1 = to_string (atomdata[i].yCoordinate);
                  str1.erase ( str1.find_last_not_of('0') + 1, std::string::npos );
                  dec=str1.substr(str1.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str1=str1+"0";
                    str1 = (str1.substr(0,str1.find(".")) + str1.substr(str1.find("."),4));
                   for(int i=0;i<=(yCoordinate.length()-str1.length()+1);i++)
                    str1=" "+str1;
                    if( str1.length()>8)
                    str1.erase(0,1);

                 string str2 = to_string (atomdata[i].zCoordinate);
                  str2.erase ( str2.find_last_not_of('0') + 1, std::string::npos );
                  dec=str2.substr(str2.find(".")+1);
                  for(int i=dec.length();i<3;i++)
                    str2=str2+"0";
                    str2 = (str2.substr(0,str2.find(".")) + str2.substr(str2.find("."),4));
                  for(int i=0;i<=(zCoordinate.length()-str2.length()+1);i++)
                  str2=" "+str2;
                  if( str2.length()>8)
                    str2.erase(0,1);

                  line.replace(line.find(xCoordinate), xCoordinate.length(),str );
                  line.replace(line.find(yCoordinate), yCoordinate.length(),str1);
                  line.replace(line.find(zCoordinate), zCoordinate.length(),str2);
                  break;
              }
          }
          }
	   outFile<<line<<endl;
      }
}
void difatm()
{
     atompdb aData1;
    for(int i=2;i<atomdata.size();i=i+2)
    {
        aData1.atomName=atomdata[i].atomName;
        aData1.atomdataerialNumber=atomdata[i].atomdataerialNumber;
        aData1.xCoordinate=atomdata[0].xCoordinate-atomdata[i].xCoordinate;
        aData1.yCoordinate=atomdata[0].yCoordinate-atomdata[i].yCoordinate;
        aData1.zCoordinate=atomdata[0].zCoordinate-atomdata[i].zCoordinate;
        atomdata[i].xCoordinate=atomdata[i].xCoordinate+ aData1.xCoordinate;
        atomdata[i].yCoordinate=atomdata[i].yCoordinate+ aData1.yCoordinate;
        atomdata[i].zCoordinate=atomdata[i].zCoordinate+ aData1.zCoordinate;
        atomdata[i+1].xCoordinate=atomdata[i+1].xCoordinate+ aData1.xCoordinate;
        atomdata[i+1].yCoordinate=atomdata[i+1].yCoordinate+ aData1.yCoordinate;
        atomdata[i+1].zCoordinate=atomdata[i+1].zCoordinate+ aData1.zCoordinate;

       cout<<endl;
       atomdiff.push_back(aData1);
    }
}

void Avect(int aStart,int aEnd)
{
         ifstream inFile;
         string temp,marker,word,word1,s;
         int num;
         inFile.open("Aligneddata.pdb");
         while(!inFile.eof())
         {
             atompdb aData1;
             atompdb aData2;
             getline(inFile,s);
             marker=s.substr(0,1);
              if(marker=="-" || marker=="#")
              {
                temp=s.substr(23,4);
                marker=s.substr(0,1);
                num=atoi(temp.c_str());
                  if(num==aStart && marker=="-" )
                   {
                     word=s.substr(1,4);
                     aData1.atomName=word;
                     word=s.substr(23,4);
                     aData1.atomdataerialNumber=atoi(word.c_str());
                     word=s.substr(31,8);
                     aData1.xCoordinate=stod(word.c_str());
                     word=s.substr(39,8);
                     aData1.yCoordinate=stod(word.c_str());
                     word=s.substr(47,8);
                     aData1.zCoordinate=stod(word.c_str());
                   }

               if(num==aEnd&& marker=="#" )
                {
                  word=s.substr(1,4);
                  aData2.atomName=word;
                  word=s.substr(23,4);
                  aData2.atomdataerialNumber=atoi(word.c_str());
                  word=s.substr(31,8);
                  aData2.xCoordinate=stod(word.c_str());
                  word=s.substr(39,8);
                  aData2.yCoordinate=stod(word.c_str());
                  word=s.substr(47,8);
                  aData2.zCoordinate=stod(word.c_str());
                 atomdata.push_back(aData1);
                 atomdata.push_back(aData2);
               }
             }
        }
}


void Outputdata()
{
    ofstream outFile;
   outFile.open("Aligneddata.pdb");
   int counter=0;
     for(int i=0;i<sheetdata.size();i++)
    {
        for(int j=0;j<atomdata.size();j++)
        {
			int index=j;

            if((sheetdata[i].sheetid==atomdata[j].atomdataerialNumber ) )
            {
				for(int k=sheetdata[i].sheetid;k<=sheetdata[i].terseqid;k++)
				{
				    int atomDifference= sheetdata[i].terseqid-sheetdata[i].sheetid;
				    if(atomDifference>=2 )
                    {
                        if(counter!=0)
                        {
                            outFile<<endl;
				    if(k==sheetdata[i].sheetid)
                        outFile<<"#";
                    if(k==sheetdata[i].sheetid+2)
                        outFile<<"-";
                        }
					outFile<<data[index];
					index++;
					counter++;
                    }
				}
            }
        }
int aStart=sheetdata[i].sheetid;
int aEnd=sheetdata[i].sheetid+2;
Avect(aStart,aEnd);
    }
}

void Dataout(string s, ofstream & outfile)
{
    string word;
    sheetpdb sData;
    atompdb aData;
    int value;
     word=s.substr(0,5);
     string temp="";
        if(word=="SHEET")
        {
            temp=s.substr(21,1);

        }
         if(word=="SHEET")
        {
           outfile<<endl;
            sData.shetname=word;
            outfile<<word<<" ";
            word=s.substr(17,3);
           outfile<<word<<" ";
           sData.residueName=word;
           word=s.substr(21,1);
           outfile<<word<<" ";
           sData.chainid1=word;
            word=s.substr(22,4);
            outfile<<word<<" ";
            sData.sheetid=atoi(word.c_str());
             word=s.substr(28,3);
             outfile<<word<<" ";
             sData.terres=word;
             word=s.substr(32,1);
           outfile<<word<<" ";
           sData.chainid2=word;
             word=s.substr(33,4);
             outfile<<word<<" ";
             sData.terseqid=atoi(word.c_str());

             sheetdata.push_back(sData);
        }
        word=s.substr(0,4);
        string word1="";
         string word2="";
        if(word=="ATOM")
        {
            word1=s.substr(13,2);
            word2=s.substr(21,1);
        }
        if(word=="ATOM" && word1=="CA"&& word2=="A")
        {
             outfile<<endl;
            aData.atomName=word;
            outfile<<word<<" ";
             word=s.substr(6,4);
             aData.num=atoi(word.c_str());
            outfile<<word<<" ";
             word=s.substr(13,2);
             aData.calpha=word.c_str();
            outfile<<word<<" ";
            word=s.substr(17,3);
             aData.residueName=word.c_str();
            outfile<<word<<" ";
             word=s.substr(21,1);
             aData.chainid=word.c_str();
            outfile<<word<<" ";
             word=s.substr(22,4);
             aData.atomdataerialNumber=atoi(word.c_str());
            outfile<<word<<" ";
            word=s.substr(30,8);
             aData.xCoordinate=stod(word.c_str());
            outfile<<word<<" ";
            word=s.substr(38,8);
             aData.yCoordinate=stod(word.c_str());
            outfile<<word<<" ";
            word=s.substr(46,8);
             aData.zCoordinate=stod(word.c_str());
            outfile<<word<<" ";
            word=s.substr(76,2);
             aData.sym=(word.c_str());
            outfile<<word<<" ";
            data.push_back(s);
            atomdata.push_back(aData);
        }
}
int main()
{
    string s,filename;
    ifstream inFile;
    ofstream outFile;
    cout<<endl<<"Enter the file name:";
    cin>>filename;
    inFile.open(filename.c_str());
    outFile.open("output.txt");
   if(inFile.fail())
   {
       cout<<endl<<" Cannot open the file please check for the file"<<endl;
       exit(0);

   }

   else
    {
        while(!inFile.eof())
    {
        getline(inFile,s);
        Dataout(s, outFile);
    }
    }
   Outputdata();

    return 0;
}
