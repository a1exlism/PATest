int getPartition(vector<int> &nums, int low, int height)
{
    int keyVal = nums[low];
    while (low<height)
    {
        while (low < height&&nums[height] >= keyVal)
            height--;
        nums[low] = nums[height];
        while (low < height&&nums[low] <= keyVal)
            low++;
        nums[height] = nums[low];
    }
    nums[low] = keyVal;
    return low;
}
void quickSortNonRecursive(vector<int> &nums, int low, int height)
{
    stack<int> s;
    if (low<height)
    {
        int mid = getPartition(nums, low, height);
        if (mid-1>low)
        {
            s.push(low);
            s.push(mid - 1);
        }
        if (mid+1<height)
        {
            s.push(mid + 1);
            s.push(height);
        }

        while (!s.empty())
        {
            int qHeight = s.top();
            s.pop();
            int pLow = s.top();
            s.pop();
            int pqMid = getPartition(nums, pLow, qHeight);
            if (pqMid - 1 > pLow)
            {
                s.push(pLow);
                s.push(pqMid - 1);
            }
            if (pqMid + 1 < qHeight)
            {
                s.push(pqMid + 1);
                s.push(qHeight);
            }
        }

    }
}