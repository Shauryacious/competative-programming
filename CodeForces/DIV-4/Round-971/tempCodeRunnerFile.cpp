void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> points;
    vector<pair<ll, ll>> points0;
    vector<pair<ll, ll>> points1;
    ll y0 = 0, y1 = 0;
    for(int i = 0; i < n; i++) {
        ll x, y; 
        cin >> x >> y;
        points.push_back({x, y});
        if(y == 0){
            y0++;
            points0.push_back({x, y});
        }
        else{
            y1++;
            points1.push_back({x, y});
        }
    }
    debug(y0);
    debug(y1);

    ll total_triangle = 0;

    sort(points.begin(), points.end());
    sort(points0.begin(), points0.end());
    sort(points1.begin(), points1.end());
    set<pair<ll, ll>> set_points0(points0.begin(), points0.end());
    set<pair<ll, ll>> set_points1(points1.begin(), points1.end());
    debug(points);
    for(int i = 0; i < n-1; i++) {
        if(points[i].first == points[i+1].first) {
            total_triangle += y0-1;
            total_triangle += y1-1;
        }
        debug(total_triangle);
    }
    debug(points0);
    debug(points1);

    for(int i=0; i<points0.size(); i++){
        pair<ll, ll> ppp = points0[i];
        if(set_points1.find({ppp.first-1, 1}) != set_points1.end()){ //
            if(set_points1.find({ppp.first+1, 1}) != set_points1.end()){
                total_triangle++;
            }
        }
    }

    for(int i=0; i<points1; i++){
        pair<ll, ll> ppp = points1[i];
        if(set_points0.find({ppp.first-1, 1}) != set_points0.end()){ //
            if(set_points0.find({ppp.first+1, 1}) != set_points0.end()){
                total_triangle++;
            }
        }
    }

    cout << total_triangle << nline;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    
    fastio();
    ll t; 
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}