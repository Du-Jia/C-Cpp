    #include<iostream>

    using namespace std;

    const int MAXSIZE =101;

    int main(){
        int a[MAXSIZE];
        int n = 0;
        int m = 0;

        cin >> n ;
        cin >> m ;

        int i = 0;

        for(i = 0; i < n; i++){
            cin >> a[i];
        }

        m = m % n;

        for(i = n - m ; i < n; i++){
            if(i == n - m){
                cout << a[i];
            }
            else{
                cout << " " << a[i];
            }
        }

        for(i = 0; i < n - m; i++){
            if(i == 0 && m == 0)
                cout << a[i];
            else{
                cout << " " << a[i];
            }
        }
        cout << endl;


        return 0;
    }
