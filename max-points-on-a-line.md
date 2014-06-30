[https://oj.leetcode.com/problems/max-points-on-a-line/](https://oj.leetcode.com/problems/max-points-on-a-line/)

``` cpp
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
			unordered_map<float,int> mp;
			int maxNum = 0;
			for(int i = 0; i < points.size(); i++)
			{
				mp.clear();
				mp[INT_MIN] = 0;
				int duplicate = 1;
				for(int j = 0; j < points.size(); j++)
				{
					if(j == i) continue;
					if(points[i].x == points[j].x && points[i].y == points[j].y)
					{
						duplicate++;
						continue;
					}
					float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
					mp[k]++;
				}
				unordered_map<float, int>::iterator it = mp.begin();
				for(; it != mp.end(); it++)
					if(it->second + duplicate > maxNum)
						maxNum = it->second + duplicate;
			}
			return maxNum;
    }
};
```

MaskRay大神不明觉厉的[做法](https://github.com/MaskRay/LeetCode/blob/master/max-points-on-a-line.cc)

``` cpp
#define FOR(i, a, b) for (__typeof(b) i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

bool operator<(const Point &a, const Point &b)
{
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

class Solution {
public:
    int maxPoints(vector<Point> &a) {
      int i, j, k, r = 0, c;
      sort(a.begin(), a.end());
      vector<int> pi(a.size());
      auto f = [&](int p, int q) {
        return (long long)(a[p].x-a[i].x)*(a[q].y-a[i].y) - (long long)(a[q].x-a[i].x)*(a[p].y-a[i].y);
      };
      for (i = 0; i < a.size(); i++) {
        pi.pop_back();
        for (j = i; j < a.size() && a[i].x == a[j].x && a[i].y == a[j].y; j++);
        c = j-i;
        iota(pi.begin(), pi.end()-(c-1), j);
        sort(pi.begin(), pi.end()-(c-1), [&](int p, int q) { return f(p, q) < 0; });
        r = max(r, c);
        for (j = 0, k = 0; j < pi.size()-(c-1); j = k) {
          for (; k < pi.size()-(c-1) && f(pi[j], pi[k]) == 0; k++);
          r = max(r, c+k-j);
        }
      }
      return r;
    }
};
```
 速度差不多。
