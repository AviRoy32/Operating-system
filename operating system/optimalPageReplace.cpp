#include<bits/stdc++.h>
using namespace std;
int predict(vector<int>& page, vector<int>& fr, int pn, int fn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fn; i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == page[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}

bool search(int key, vector<int>& fr, int fn)
{
    for (int i = 0; i < fn; i++)
        if (fr[i] == key)
            return true;
    return false;
}

void opr(vector<int>& page, int pn, int fn)
{
    float rh, rf;
    vector<int> fr(fn, -1);
    int hit = 0;
    int filled = 0;
    for (int i = 0; i < pn; i++)
    {
        if (search(page[i], fr, fn))
        {
            hit++;
            continue;
        }
        if (filled < fn)
        {
            fr[filled] = page[i];
            filled++;
        }
        else
        {
            int j = predict(page, fr, pn, fn, i + 1);
            fr[j] = page[i];
        }
    }
    rh = ((float)hit / pn) * 100.0;
    rf = ((float)(pn - hit) / pn) * 100.0;
    cout << "Hits = " << hit << endl;
    cout << "Misses = " << pn - hit << endl;
    cout << "Hits = " << rh << "%" << endl;
    cout << "Misses = " << rf << "%" << endl;
}

int main()
{
    int pn;
    cout << "Enter the number of pages: ";
    cin >> pn;
    vector<int> page(pn);
    cout << "Enter the pages: ";
    for (int i = 0; i < pn; i++)
    {
        cin >> page[i];
    }
    int fn;
    cout << "Enter the number of frames: ";
    cin >> fn;
    opr(page, pn, fn);
    return 0;
}