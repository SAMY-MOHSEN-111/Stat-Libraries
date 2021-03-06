/// this is a stat library that calculates Data measures ///
/// Github link: https://github.com/SAMY-MOHSEN-111/Stat-Libraries.git
/// check if you are using the latest version ///
/// this is version 0.0.1 ///
/// Cairo university FCAI ///
/// Made by Samy Mohsen ///
/// Email: engsamymohsen33@gmail.com
/// Stay safe stay healthy xD ///
/// To learn how to use it watch:

#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>

using namespace std;
class Data_Measures{
private:
    double *arr1;
    int observations;
    double sum1=0;
///******************************///
public:
    int max_val = -1;
    double matching_max_val=0;
    set<double>st;
    map<double,int>mp;
///******************************///
    double * arr1_copy;
    Data_Measures(){}
    void set_Data(){
        cout<<"Enter the number of observations\n"; cin>>observations;
        arr1 = new double [observations];
        arr1_copy = new double [observations];
        cout<<"Enter the observations sequentially\n";
        for (int i = 0; i < observations; ++i) {
            cout<<"X"<<i+1<<":";  cin >> arr1[i]; arr1_copy[i]=arr1[i]; sum1+=arr1[i];
            mp[arr1[i]]++;
        }
    }
    void restore_order(){
        for (int i = 0; i < observations; ++i) {
            arr1_copy[i] = arr1[i];
        }
    }
    ~Data_Measures(){
        delete [] arr1;
    }
    void print_data(){
        for (int i = 0; i < observations; ++i) {
            cout<<arr1[i]<<" ";
        }
        cout<<"\n";
    }
    double Summation();
    double Mean();
    double Mean_Weighted();
    double Median();
    void   Mode();
    double Max_element();
    double Min_element();
    double Range();
    double Variance_pop();
    double Variance_sample();
    double StandaradDeviation_pop();
    double StandaradDeviation_sample();
    double Difference_Summation();
    double CV_pop();
    double CV_sample();
    double Percentile(double val);
    double Q1();
    double Q3();
    double IQR();
    double UpperLimit();
    double LowerLimit();

};
double Data_Measures :: Summation(){
    double sum=0;
    for (int i = 0; i < observations; ++i) {
        sum+=arr1[i];
    }
    return sum;
}
double Data_Measures :: Mean(){
    return Summation()/observations;
}
double Data_Measures:: Mean_Weighted(){
    double *ar ;
    ar = new double[observations];
    double SUM1=0;
    double SUM2=0;
    cout<<"Enter the weights sequentially: ";
    for (int i = 0; i < observations; ++i) {
        cout<<"Enter weight #"<<i+1;
        cin>>ar[i]; SUM1+=ar[i]*arr1[i]; SUM2+=ar[i];
    }
    return SUM1/SUM2;
}
double Data_Measures:: Median(){

    sort(arr1_copy, arr1_copy + observations);
    ///cout<<"Median:";
    if(observations%2==1){ double tmp =  arr1_copy[observations / 2]; restore_order(); return tmp;}
    else {double tmp = (arr1_copy[observations / 2] + arr1_copy[(observations / 2) - 1]) / 2.0; restore_order(); return tmp;}

}
void Data_Measures:: Mode(){

    map<double,int>::iterator  it;
    //it=mp.begin();
    for(auto it : mp){
        if(it.second>max_val){max_val=it.second; matching_max_val=it.first;}
    }

    st.insert(matching_max_val);

    for(auto it : mp){
        if(it.second==max_val){st.insert(it.first);}
    }
    int tmp = 0;
    for(auto it : mp){
        if(it.second==1){tmp++;}
    }

    ///perhaps there is a bug here ?
    if(tmp>=1&&max_val==1)
        cout<<"Mode: no mode\n";
    else{
        cout<<"Mode: ";
        for(auto x : st){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}
double Data_Measures::Max_element() {
    sort(arr1_copy,arr1_copy+observations);
    ///cout<<"Max element: "<<arr1_copy[observations-1]<<"\n";
    double tmp = arr1_copy[observations-1];
    restore_order();
    return tmp;
}
double Data_Measures::Min_element() {
    sort(arr1_copy,arr1_copy+observations);
    double tmp = arr1_copy[0];
    restore_order();
    return tmp;
}

double Data_Measures::Range(){

    sort(arr1_copy,arr1_copy+observations);
    ///cout<<"The Range is: "<<arr1_copy[observations-1]-arr1_copy[0]<<"\n";
    double tmp1,tmp2;
    tmp1=arr1_copy[observations-1];
    tmp2=arr1_copy[0];
    restore_order();
    return tmp1-tmp2;

}
double Data_Measures:: Difference_Summation(){
    double SUM3 = 0;
    double tmp1,tmp2;
    tmp2 = Mean();
    for (int i = 0; i < observations; ++i) {
        tmp1 = arr1[i] - tmp2;
        SUM3+=pow(tmp1,2);
    }
    return  SUM3;
}
double Data_Measures:: Variance_pop(){
    return Difference_Summation()/observations;
}
double Data_Measures:: Variance_sample(){
    return Difference_Summation()/(observations-1);
}
double Data_Measures:: StandaradDeviation_pop(){
    return sqrt(Difference_Summation()/observations);
}
double Data_Measures:: StandaradDeviation_sample(){
    return sqrt(Difference_Summation()/(observations-1));
}
double Data_Measures::CV_pop() {
    return StandaradDeviation_pop()/Mean()*100;
}
double Data_Measures::CV_sample() {
    return StandaradDeviation_sample()/Mean()*100;
}
double Data_Measures::Percentile(double val){
    double tmp = ceil(val/100*observations)-1;
    sort(arr1_copy,arr1_copy+observations);
    double tmp2 = arr1_copy[(int)tmp];
    restore_order();
    return tmp2;
}
double Data_Measures::Q1(){
    return Percentile(25);
}
double Data_Measures::Q3(){
    return Percentile(75);
}
double Data_Measures::IQR(){
    return Q3()-Q1();
}
double Data_Measures::UpperLimit(){
    return Q3()+1.50*IQR();
}
double Data_Measures::LowerLimit(){
    return Q1()-1.50*IQR();
}
int main(){
    ///these are the methods you can use after declaring and object
    /// from class Data_Measures
    /*
    -)set_Data();
    -)print_data();
    1)Summation();
    2)Mean();
    3)Mean_Weighted();
    4)Median();
    5)Mode();
    6)Max_element();
    7)Min_element();
    8)Range();
    9)Variance_pop();
    10)Variance_sample();
    11)StandaradDeviation_pop();
    12)StandaradDeviation_sample();
    13)Difference_Summation();
    14)CV_pop();
    15)CV_sample();
    16)Percentile(double val);
    17)Q1();
    18)Q3();
    19)IQR();
    20)UpperLimit();
    21)LowerLimit();
     */

    Data_Measures s;
    s.set_Data();
    s.print_data();
    return 0;
}
