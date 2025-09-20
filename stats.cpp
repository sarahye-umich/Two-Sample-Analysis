// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf
#include <iostream>

using namespace std;

int count(vector<double> v) {
    if(v.empty()){
        return 0;
    }
    return v.size();
  //assert(false);
}

double sum(vector<double> v) {
    if(v.empty()){
        return 0;
    }
    double ans = 0;
    for(double num: v){
        ans += num;
    }

    return ans;
  //assert(false);
}

double mean(vector<double> v) {
    if(v.empty()){
        return 0;
    }
    double sumMean, countMean;
    sumMean = sum(v);
    countMean = count(v);

    return sumMean/countMean;
  //assert(false);
}

double median(vector<double> v) {
    if(v.empty()){
        return 0;
    }
    int mid;
    double ans;

    sort(v.begin(), v.end());
    //1 2 3 4 5 6 7
    if(v.size()%2 == 0){
        mid = v.size()/2;
        ans = (v[mid-1] + v[mid])/2;
    }
    else{
        mid = (v.size()/2);
        ans = v[mid];
    }
    return ans;
  //assert(false);
}

double min(vector<double> v) {
    if(v.empty()){
        return 0;
    }
    double minimum = v[0];
    for(double num: v){
        if(num<minimum){
            minimum = num;
        }
    }
    return minimum;
  //assert(false);
}

double max(vector<double> v) {
    if(v.empty()){
        return 0;
    }
    double maximum = v[0];
    for(double num: v){
        if(num>maximum){
            maximum = num;
        }
    }
    return maximum;
  //assert(false);
}

double stdev(vector<double> v) {
    if(v.size()<2){
        return 0;
    }
    double ans = 0;
    double meanSt = mean(v);

    for(double num: v){
        ans += (num-meanSt)*(num-meanSt);
    }
    //cout<<ans;

    double a = v.size();
    double b = a-1.0;
    double c = 1.0/b;
    //double inbetween = 1.0/(v.size()-1.0);
    //cout<<a<<b<<c;

    ans = ans*(c);
    
    ans = sqrt(ans);

    return ans;
  //assert(false);
}

double percentile(vector<double> v, double p) {
    //check for when p=1; it will crash sometimes
    if(v.empty()||p<0||p>1){
        return 0;
    }


    sort(v.begin(), v.end());


    if(p == 1){
        return v[v.size()-1];
    }

    double ans;
    double rank = p*(v.size()-1)+1;

    double k;
    double d;

    d = modf(rank, &k);

    ans = v[k-1] + d*(v[k]-v[k-1]);
 
  //  cout<<"rank:"<<rank<<"k:"<<k<<"d:"<<d<<"ans:"<<ans<< endl;
  //  cout<<"v[k-1]"<<v[k-1]<<"(v[k]"<<v[k]<<"d*(v[k]-v[k-1])"<<d*(v[k]-v[k-1])<<endl;

    return ans;
  //assert(false);
}

vector<double> filter(vector<double> v, vector<double> criteria, double target) {
    if(v.empty()||criteria.empty()||(v.size()!=criteria.size())){
        vector<double> no_ans;
        no_ans.push_back(0);
        return no_ans;
    }
    vector<double> ans ={};

    for(int i = 0; i<criteria.size(); i++){
        if(criteria[i] == target){
            ans.push_back(v[i]);
        }
    }

    return ans;
    //assert(false);
}
