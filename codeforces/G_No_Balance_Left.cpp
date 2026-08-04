#include<bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile ".inp","r")){freopen(tenfile ".inp","r",stdin);freopen(tenfile ".out","w",stdout);}
#define int long long
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define ii pair<int,int>
#define iii pair<int,ii>
#define On(mask,pos) (mask|(1LL<<pos))
#define Off(mask,pos) (mask^(1LL<<pos))
#define endl "\n"
using namespace std;
const int N=1e6+69;
const int BASE=256;
const int MOD=1e9+7;
int add(int a,int b){return(a+b)%MOD;}
int sub(int a,int b){return((a-b)%MOD+MOD)%MOD;}
int mul(int a,int b){return((a%MOD)*(b%MOD))%MOD;}
void solve(){
int so_hang,so_cot,so_luong;
cin>>so_hang>>so_cot>>so_luong;
vector<vector<int>>ma_tran(so_hang+1,vector<int>(so_cot+1));
vector<int>tong_hang(so_hang+1,0),tong_cot(so_cot+1,0);
for(int i=1;i<=so_hang;i++){
for(int j=1;j<=so_cot;j++){
cin>>ma_tran[i][j];
tong_hang[i]+=ma_tran[i][j];
tong_cot[j]+=ma_tran[i][j];}}
if(so_hang==1&&so_cot==1){
if(so_luong==1){
if(ma_tran[1][1]>=0)cout<<0<<endl;
else cout<<-1<<endl;
}else cout<<-1<<endl;
return;}
if(so_hang==1||so_cot==1){
int do_dai=max(so_hang,so_cot);
vector<int>mang_danh_gia(do_dai+1);
for(int i=1;i<=do_dai;i++){
int gia_tri;
if(so_hang==1)gia_tri=ma_tran[1][i];
else gia_tri=ma_tran[i][1];
int tong_cong;
if(so_hang==1)tong_cong=tong_hang[1];
else tong_cong=tong_cot[1];
mang_danh_gia[i]=2*gia_tri-tong_cong;}
if(do_dai==2){
if(so_luong==1)cout<<0<<endl;
else{
int gia_tri_ke;
if(so_hang==1)gia_tri_ke=ma_tran[1][2];
else gia_tri_ke=ma_tran[2][1];
cout<<abs(ma_tran[1][1]-gia_tri_ke)<<endl;}
return;}
if(so_luong>=2){
vector<int>mang_tam(mang_danh_gia.begin()+1,mang_danh_gia.end());
sort(all(mang_tam),greater<int>());
int muc_tieu=mang_tam[so_luong-1];
if(muc_tieu>=0)cout<<0<<endl;
else cout<<(-muc_tieu+do_dai-3)/(do_dai-2)<<endl;
}else{
int ket_qua=-1;
for(int i=1;i<=do_dai;i++){
int max_tam;
if((int)i-1>(int)do_dai-i)max_tam=(int)i-1;
else max_tam=(int)do_dai-i;
int max_buoc;
if((int)do_dai-2>max_tam)max_buoc=(int)do_dai-2;
else max_buoc=max_tam;
int can_thiet;
if(mang_danh_gia[i]>=0)can_thiet=0;
else can_thiet=(-mang_danh_gia[i]+max_buoc-1)/max_buoc;
if(ket_qua==-1)ket_qua=can_thiet;
else{
if(can_thiet<ket_qua)ket_qua=can_thiet;}}
cout<<ket_qua<<endl;}
return;}
vector<int>mang_ket_qua;
mang_ket_qua.reserve(so_hang*so_cot);
for(int i=1;i<=so_hang;i++){
for(int j=1;j<=so_cot;j++){
mang_ket_qua.push_back(3*ma_tran[i][j]-tong_hang[i]-tong_cot[j]);}}
sort(all(mang_ket_qua),greater<int>());
if(mang_ket_qua[so_luong-1]>=0)cout<<0<<endl;
else cout<<(-mang_ket_qua[so_luong-1]+so_hang+so_cot-4)/(so_hang+so_cot-3)<<endl;
}
main(){
skibidi;
int so_test;
if(cin>>so_test){
while(so_test--)solve();}
}