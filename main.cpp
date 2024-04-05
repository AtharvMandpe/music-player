#include <bits/stdc++.h>
using namespace std;
#define f(i, m, n) for (ll i = m; i < n; i++)
#define ll long long

struct song {
    string name = "";
    ll genre;
    ll p = 0;
    ll l = 0;
    ll p1 = 0;
    string path = "";
};

vector<vector<song>> v(6);
vector<string> all;
map<ll, string> m;

priority_queue<pair<ll, ll>> pq;

// map for genre updating
map<string, ll> gen;

map<pair<ll, ll>, ll> views;

stack<pair<ll, ll>> prevv, nextt;

ll volume = 100;

void playSong() {
    cout << "enter coordinates of song to be played : ";
    ll i, j;
    cin >> i >> j;
    gen[m[i]]++;
    views[{i, j}]++;

    prevv.push({i, j});

    pq.push({gen[m[i]], views[{i, j}]});
    while(true){
        char cc;
        cout << "\ncurrent song : " << i << " " << j << " : " << m[i] << endl;
        cin>>cc;
        ll k = 0;
        if(cc=='p' && k==0){

            cout<<"paused\n";
            k==1;
        }
        else if(cc=='r' && k==1){
            cout<<"resumed\n";
        }
        else if(cc=='e'){
            return;
        }
    }
}

void prevSong() {
    if (prevv.empty()) {
        cout << "NO PREV SONG\n";
    } else {
        pair<ll, ll> c = prevv.top();
        ll i = c.first, j = c.second;

        gen[m[i]]++;
        views[{i, j}]++;
       // cout << "\ncurrent song : " << i << " " << j << " : " << m[i] << endl;

        pq.push({gen[m[i]], views[{i, j}]});

        prevv.pop();
        nextt.push(c);
         while(true){
        char cc;
        cout << "\ncurrent song : " << i << " " << j << " : " << m[i] << endl;
        cin>>cc;
        ll k = 0;
        if(cc=='p' && k==0){

            cout<<"paused\n";
            k==1;
        }
        else if(cc=='r' && k==1){
            cout<<"resumed\n";
        }
        else if(cc=='e'){
            return;
        }
    }
    }
}

void nextSong() {
    if (nextt.empty()) {
        cout << "\nnext list over\n";
    } else {
        pair<ll, ll> c = nextt.top();
        ll i = c.first, j = c.second;

        gen[m[i]]++;
        views[{i, j}]++;
       // cout << "\ncurrent song : " << i << " " << j << " : " << m[i] << endl;

        pq.push({gen[m[i]], views[{i, j}]});

        nextt.pop();
        prevv.push(c);
         while(true){
        char cc;
        cout << "\ncurrent song : " << i << " " << j << " : " << m[i] << endl;
        cin>>cc;
        ll k = 0;
        if(cc=='p' && k==0){

            cout<<"paused\n";
            k==1;
        }
        else if(cc=='r' && k==1){
            cout<<"resumed\n";
        }
        else if(cc=='e'){
            return;
        }
    }
    }
}

void volumeControl() {
    cout << "A. increase\nB. decrease : ";
    ll aa;
    cin >> aa;

    if (aa == 1) {
        cout << "\nby how much : ";
        ll val;
        cin >> val;
        volume = min(volume + val, 100LL);
    } else {
        cout << "\nby how much : ";
        ll val;
        cin >> val;
        volume = max(volume - val, 0LL);
    }

    cout << "\nCURRENT VOLUME : " << volume << endl;
}

void playRandomSong() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    map<int, bool> mp;
    f(i, 0, 20) mp[arr[i]] = false;

    vector<int> selected;

    srand(time(0));
    while (selected.size() < 10) {
        int randomIndex = rand() % 20;
        int num = arr[randomIndex];
        if (!mp[num]) {
            mp[num] = true;
            selected.push_back(num);
        }
    }

    cout << "Selected 10 elements: ";
    for (int num : selected) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> selected2;

    srand(time(0));
    while (selected2.size() < 10) {
        int randomIndex = rand() % 20;
        int num = arr[randomIndex];
        if (!mp[num]) {
            mp[num] = true;
            selected2.push_back(num);
        }
    }

    cout << "Selected2 10 elements: ";
    for (int num : selected2) {
        cout << num << " ";
    }
}

void topGenre(){
    cout<<"\nTOP GENRE TILL NOW: ";
    cout << pq.top().first<<endl;
}


int main() {
    m[1] = "love";
    m[2] = "romantic";
    m[3] = "motivational";
    m[4] = "birthday";
    m[5] = "new year";
    ll n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            struct song h;
            char t = char(97 + i - 1);
            all.push_back("" + t);
            v[i].push_back(h);

            views[{i,j}] = 0;
        }
    }



    // songs being played now
    while (true) {
        cout << "select option \n";
        cout << "1. play song\n2. Play random songs\n3. Previous Song\n4. Next Song\n5. Volume Control\n6. Top Genre\n7.Exit";

        ll i;
        cin >> i;
        if (i == 1) {
            playSong();
            continue;
        }
        if (i == 2) {
            playRandomSong();
            continue;
        }
        if (i == 3) {
            prevSong();
            continue;
        }
        if (i == 4) {
            nextSong();
            continue;
        }
        if (i == 5) {
            volumeControl();
            continue;
        }
        if(i==6){
            topGenre();
            continue;
        }
        if (i == 7) {
            cout << "thank you";
            break;
        }
    }
    return 0;
}
