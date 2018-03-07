#include <iostream>
#include<ctime>
#include "PCA.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    srand((unsigned) time(NULL));
    PCA pca(5);
    for(int i=0;i<20;i++){
        int tmp = rand() % 100;
        bool flag = pca.push(tmp);
        if(flag){
            int k = 0;
            vector<float> result = pca.get_points();
            cout << "width : " << pca.get_width() << endl;
            for(auto it = result.begin();it != result.end();it++)
                cout << "data " << ++k << " : " << *it << endl;
            cout << "sum : " << pca.get_sum() << endl;
            cout << "avg : " << pca.get_avg() << endl;
            pca.reset();
        }
    }

    return 0;
}