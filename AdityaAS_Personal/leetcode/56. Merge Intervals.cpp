class Solution {
public:
    
    static bool compareByStart(Interval& a,Interval& b)
    {
        if(a.start < b.start)   return true;
        else if(a.start == b.start) return a.end < b.end;
        else return false;
    }
    
    static bool intersect(Interval& a, Interval& b)
    {
        return max(a.start, b.start) <= min(a.end, b.end);
    }
    
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        if(intervals.size() == 0) return intervals;
        
        sort(intervals.begin(), intervals.end(), compareByStart);
        
        vector<Interval> result;
        
        int last = -1;
        bool flag = false;
        //iterate for all elements except last element
        for(int i=0; i<intervals.size()-1; i++)
        {
            last = -1;
            if(intersect(intervals[i], intervals[i+1]))
            {
                if(i+1 == intervals.size()-1)last = 1;

                Interval newInterval(min(intervals[i].start, intervals[i+1].start), max(intervals[i].end, intervals[i+1].end) );
                
                while(i < intervals.size())
                {
                    
                    if( intersect(newInterval, intervals[i]) )
                    {
                        if(i == intervals.size()-1) last = 1;
                        newInterval.start = min(intervals[i].start, newInterval.start);
                        newInterval.end = max(intervals[i].end, newInterval.end);
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                i--;
                result.push_back(newInterval);
                
            }
            else
            {
                result.push_back(intervals[i]);
                continue;
            }
        }
        
        //Check if last element is merged or not explicitly
        if( last == -1 && intervals.size()!=0 )  result.push_back(intervals[intervals.size()-1]);
        
        return result;
    
    }
};