#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define p(x,y) pair<x,y>
// #define oset(x) tree<x, null_type, less<x>, rb_tree_tag, tree_order_statistics_node_update>
// #define all(x) (x).begin(),(x).end()
// #define ll long long
// #define scan(a) for(auto &it:a)cin>>it;
#define print(a) {for(auto it:a)cout<<it<<" ";cout<<endl;}
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//#define int ll

class Solution {
  private:
    vector<string> words;
    unordered_map<int,unordered_set<int>> adjlst;
    vector<bool> vis;
    vector<vector<string>> soln={};
    vector<string> temp;
    int ct,n,min,end=-1;
  
  private:
    bool adj(string &a,string &b){
      bool f=0;
      for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
          if(!f)
            f=1;
          else
            return 0;
      return f;
    }
  
    void dfs(int i){

      if(ct>min)
        return;

      ct++;
      // cout<<i<<" -> ";
      temp.push_back(words[i]);
      vis[i]=1;

      //base case
      if( i==end){
        // cout<<" solution! ";
        if(ct==min){
          soln.push_back(temp);
        }
        else if(ct<min){
          min=ct;
          soln.clear();
          soln.push_back(temp);
        }
      }else
        //recursive calls
        for(int j:adjlst[i])
          if(!vis[j])
            dfs(j);
      
      temp.pop_back();
      vis[i]=0;
      // cout<<" <- "<<i<<" ";
      ct--;
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        words=ref(wordList);
         n=wordList.size();
        for(int i=0;i<n;i++)
          if(wordList[i]==endWord){
            end=i;
            break;
          }
        if(end==-1)
          return {};
        unordered_set<int> st;
        
        string s=beginWord;
        for(int i=0;i<n;i++)
            if(adj(s,wordList[i]))
                st.insert(i);
        adjlst[-1]=st;
        
        for(int i=0;i<n;i++){
            
            s=wordList[i];
            st.clear();
            for(int j=0;j<n;j++)
                if(i!=j && adj(s,wordList[j]))
                    st.insert(j);
            adjlst[i]=st;
        }
        
        // memset(dp,0,(5001)*(5001)*sizeof(bool));
        
        // string s=beginWord;
        // for(int j=0;j<n;j++)
        //     if(adj(s,wordList[j]))
        //         dp[0][j+1]=1;
        
        // for(int i=0;i<n;i++){
            
        //     s=wordList[i];
        //     for(int j=i+1;j<n;j++)
        //         if(adj(s,wordList[j]))
        //             dp[i+1][j+1]=dp[j+1][i+1]=1;
            
        // }
        // memset(vis,0,5000);
        
        // for(auto i:adjlst){
        //   cout<<i.first<<" : ";
        //   print(i.second);
        // }
        temp={beginWord};
        ct=0;
        min=n;
        vis=vector<bool>(n,0);
        for(auto i:adjlst[-1])
          dfs(i);
        return soln;
    }
};

void solve(){
    vector<string> l={"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
    auto soln=Solution().findLadders("cet","ism",l);
    for(auto v:soln)
      print(v);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t=1;
  //init();
  // cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}