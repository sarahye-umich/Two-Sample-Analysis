/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Statistics Project
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_count();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  // Call your test functions here

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6); //change

  cout << "PASS!" << endl;
}

vector<double> testVector(){
  vector<double> data;
  for(int i = 1; i< 101; i++){
    data.push_back(i);
  }
  return data;
}

vector<double> empty_vector(){
  vector<double> data;
  return data;
}

vector<double> single_zero(){
  vector<double> data;
  data.push_back(0);
  return data;
}

vector<double> single_element(){
  vector<double> data;
  data.push_back(1);
  return data;
}

vector<double> all_same(){
  vector<double> data;
  for(int i = 1; i<= 20; i++){
    data.push_back(1);
  }
  return data;
}

vector<double> sum_zero(){
  vector<double> data;
  data.push_back(-1);
  data.push_back(1);
  return data;
}

vector<double> all_negative(){
  vector<double> data;
  for(int i = 1; i< 21; i++){
    data.push_back(-1);
  }
  return data;
}

//
//
//prolly needs to be almost equal instead of ==
//
//

void test_count(){
  assert(count(testVector()) == 100);
  assert(count(empty_vector()) == 0);
  assert(count(single_zero()) == 1);
  assert(count(single_element()) == 1);
  assert(count(all_same()) == 20);
  assert(count(sum_zero()) == 2);
  assert(count(all_negative()) == 20);
}

void test_sum(){
  assert(sum(testVector()) == 5050);
  assert(sum(empty_vector()) == 0);
  assert(sum(single_zero()) == 0);
  assert(sum(single_element()) == 1);
  assert(sum(all_same()) == 20);
  assert(sum(sum_zero()) == 0);
  assert(sum(all_negative()) == -20);
}

const double epsilon = 0.00001;

void test_mean(){
  assert(abs(mean(testVector())-50.5)<epsilon);
  assert(mean(empty_vector()) == 0);
  assert(mean(single_zero()) == 0);
  assert(mean(single_element()) == 1);
  assert(mean(all_same()) == 1);
  assert(mean(sum_zero()) == 0);
  assert(mean(all_negative()) == -1);
}

void test_median(){
  assert(abs(median(testVector()) - 50.5)<epsilon);
  assert(median(empty_vector()) == 0);
  assert(median(single_zero()) == 0);
  assert(median(single_element()) == 1);
  assert(median(all_same()) == 1);
  assert(median(sum_zero()) == 0);
  assert(median(all_negative()) == -1);
}

void test_min(){
  assert(min(testVector()) == 1);
  assert(min(empty_vector()) == 0);
  assert(min(single_zero()) == 0);
  assert(min(single_element()) == 1);
  assert(min(all_same()) == 1);
  assert(min(sum_zero()) == -1);
  assert(min(all_negative()) == -1);
}

void test_max(){
  assert(max(testVector()) == 100);
  assert(max(empty_vector()) == 0);
  assert(max(single_zero()) == 0);
  assert(max(single_element()) == 1);
  assert(max(all_same()) == 1);
  assert(max(sum_zero()) == 1);
  assert(max(all_negative()) == -1);
}

void test_stdev(){
  assert(round(stdev(testVector()))== 29);
  assert(stdev(empty_vector()) == 0);
  assert(stdev(single_zero()) == 0);
  assert(stdev(single_element()) == 0);
  assert(stdev(all_same()) == 0);
  assert(stdev(sum_zero()) == 1);
  assert(stdev(all_negative()) == 0);
}

void test_percentile(){
  vector<double> test_one;
  test_one.push_back(15);
  test_one.push_back(20);
  test_one.push_back(35);
  test_one.push_back(40);
  test_one.push_back(50);

  vector<double> test_two {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};

  assert(percentile(test_one, 0.4) == 29);
  assert(percentile(empty_vector(), 0.2) == 0);
  assert(percentile(single_zero(), 0.5) == 0);
  assert(percentile(single_element(), 0.5) == 1);
  assert(percentile(test_two, 0) == 1);
  assert(percentile(test_two, 1) == 10);
}

void test_filter(){
  vector<double> locations = {0, 1, 0, 1, 1, 2, 2, 0, 1};
vector<double> temps = {15.5, 23.1, 7.8, 19.2, 22.6, 4.6, 1.9, 14.3, 18.0};

  assert(filter(empty_vector(), empty_vector(), 1) == single_zero());
  assert(filter(single_element(), single_element(), 1) == single_element());
  assert(filter(single_element(), all_same(), 1) == single_zero());
  assert(filter(all_same(), all_same(), 1) == all_same());

  for(double i = 0; i<temps.size(); i++){
    assert(abs(temps[i]-locations[i])<epsilon);
  }
}
// Add the test function implementations here.
