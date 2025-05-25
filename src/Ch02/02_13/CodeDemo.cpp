// Learning C++ 
// Challenge 02_13
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>

int main(){
    const int NUM_LENGTH = 5;
    int nums[NUM_LENGTH] = {1,23,32,24,337};
    float result; 

    // Write your code here
    result = (float)(nums[0] + nums[1] + nums[2] + nums[3] + nums[4]) / NUM_LENGTH;
    
    std::cout << "The average is " << result << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
