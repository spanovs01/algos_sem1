#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

std::vector<float> separate(std::string &l) {
    std::stringstream ss(l);  
    std::string word;
    std::vector<float> numbers;
    while (ss >> word) { // Extract word from the stream.
        numbers.push_back(std::stof(word));
    }
    return numbers;
}

std::vector<std::vector<float>> reading(std::string &path) {
    std::vector<std::string> lines;
    std::string line;
    std::vector<float> a;
    std::vector<std::vector<float>> whole; 
    std::ifstream in("input.txt");

    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            a = separate(line);
            whole.push_back(a);
            // std::cout << "look:" <<std::endl;
            // for (auto element : a) {
                // std::cout << element << " ";
            // }     
            // std::cout << std::endl;      
            a.clear();
        }
    }
    in.close();

    return whole;
}

double geometric_mean(std::vector<float> &data, std::pair<float, float> & segm) {
    float product = 1;
    double power = 1 / (segm.second - segm.first + 1);
    double result;
    for (float i = segm.first; i <= segm.second; ++i) {
        product *= data[i];
    }
    result = std::pow(product, power);
    return result;
}

int main(){
    float n;
    float q;
    double res;
    std::vector<std::pair<float, float>> segment;

    std::string path = "input.txt";
    std::vector<std::vector<float>> input = reading(path);
    


    n = input[0][0];
    std::cout << "N = " << n << std::endl;

    q = input[2][0];
    std::cout << "Q = " << q << std::endl;

    std::vector<float> &data = input[1];
    std::cout << "data = ";
    for (float & elem : data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    for (int i = 3; i < input.size(); ++i) {
        std::pair<float, float> p = std::make_pair(input[i][0], input[i][1]);
        segment.push_back(p);
    }
    std::cout << "segments:" << std::endl;
    for (std::pair<float, float> & segm : segment) {
        std::cout << "(" << segm.first << ", " << segm.second << "); ";
    }
    std::cout << std::endl;

    for (std::pair<float, float> & segm : segment) {
        res =  geometric_mean(data, segm);
        std::cout << "(" << res << "); ";
    }
        
}