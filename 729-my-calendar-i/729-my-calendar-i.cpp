class MyCalendar {
    int st[1001], en[1001], sz;
    bool checker(int start, int end){
        for (int i=0;i<sz;++i){
            int old_st = st[i], old_en = en[i];
            if ((start<old_en && start>=old_st) ||
                (end<old_en && end>old_st) ||
                (end>=old_en && start<=old_st)){
                return false;
            }
        }
        return true;
    }
public:
    MyCalendar() {
        sz = 0;
    }
    
    bool book(int start, int end) {
        if (sz!=0 && !checker(start,end))
            return false;
        st[sz] = start;
        en[sz++] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */