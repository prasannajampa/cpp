#include<bits\stdc++.h>
using namespace std;

class SegmentTree{
    private:
            vector<int>segtree;
    public:
            SegmentTree(int n){
                segtree.resize(4*n);
            }

            //Add Data
            void buildsegtree(int index,int start, int end, vector<int>&a){
                if(start == end){
                    segtree[index] = a[start];
                }
                int mid = (start + end) / 2;
                buildsegtree(2*index + 1, start, mid, a);
                buildsegtree(2*index + 2, mid + 1, end, a);
                segtree[index] = segtree[2*index + 1] + segtree[2*index + 2];
            }

            //find range sum (L to R)
            int rangesum(int l, int r, int start, int end, int index){
                // No Overlap
                if(l > end || r < start){
                    return 0;
                }

                // Complete Overlap
                if(l <= start && r >= end){
                    return segtree[index];
                }

                // Partial Overlap
                int mid = (start + end) / 2;
                int left = rangesum(l, r, start, mid, 2*index+1);
                int right = rangesum(l, r, mid+1, end, 2*index+2);
                return left + right;
            }

            //Update the number in kth index
            //void update()
}

int main(){
       int n;
       cin >> n;
       vector <int> a(n);
       for(int i = 0; i < n; i++){
        cin >> a[i];
       }
       SegmentTree segtree(n);
       segtree.buildsegtree(0, 0, n - 1, a);
       int l = 2, r = 5;
       segtree.rangesum(l , r, 0, n - 1, 0);
       cout << segtree.rangesum(l, r, 0, n - 1, 0);
}
