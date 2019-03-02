//
//  main.cpp
//  text_pr
//
//  Created by Simon Chen on 2019/1/22.
//  Copyright © 2019 Simon Chen. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num;
    cin >> num;
    int increase[num], decrease[num], dp[num], arr[num], ans = 0;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    for (int i = num - 1; i >= 0; i--) {
        increase[i] = 1;
        decrease[i] = 1;
        for (int j = num - 1; j > i; j--) {
            if (arr[j] < arr [i]) {
                increase[i] = max(increase[i], increase[j] + 1);
            } else if (arr[j] > arr[i]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
        dp[i] = increase[i] + decrease[i] - 1;
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}

