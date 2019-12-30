class FreqStack {
public:
    unordered_map<int, stack<int> > freqToStack;
    unordered_map<int, int> valToFreq;
    priority_queue<int> pq;
    
    FreqStack() {
        
    }
    
    void push(int x) {
        valToFreq[x]++;
        freqToStack[valToFreq[x]].push(x);
        pq.push(valToFreq[x]);
    }
    
    int pop() {
        int maxFreq = pq.top();
        pq.pop();
        int ans = freqToStack[maxFreq].top();
        freqToStack[maxFreq].pop();
        valToFreq[ans]--;
        return ans;
    }
};
