#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]) {
	cout << "야구게임!" << endl;
    
    int nums[9];
    for(int i = 0; i < 9; ++i) {
        nums[i] = i + 1;
    }
    
    int i1, i2, temp;
    srand((unsigned int) time(0));
    
    //SUFFLE
    for(int i = 0; i < 100; ++i) {
        i1 = rand() % 9;
        i2 = rand() % 9;
        temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
    
    for(int i = 0; i < sizeof(nums)/sizeof(int); ++i){
            cout << nums[i] << endl;
    }
    
    cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
    
    int ins[3];
    
    cin >> ins[0] >> ins[1] >> ins[2];
    
    int strikes = 0; 
    int balls = 0;
    
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == j && nums[i] == ins[i])
                ++strikes;
            else if(ins[i] == nums[j])
                ++balls;
        }
        
    }
    
    cout << strikes << balls;
    
	return 0;
}