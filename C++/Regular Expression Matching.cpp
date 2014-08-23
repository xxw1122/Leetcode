#include <cstring>

bool match(const char *s,const char *p,int pos1,int pos2){
    if(pos1==strlen(s)&&pos2==strlen(p)) return true;
    if(pos2+1<strlen(p)&&p[pos2+1]=='*'){
        if(p[pos2]!='.'){
            int tag=0;
            for(int i=pos1;i<strlen(s);i++){
                if(s[i]==p[pos2]){
                    if(match(s, p, i+1, pos2+2)) tag=1;
                }
                else{
                    return false;
                }
                if(tag==1) return true;
            }
            if(match(s, p, pos1, pos2+2)) return true;
        }
        else if(p[pos2]=='.'){
            int tag=0;
            if(match(s,p,pos1,pos2+2)) return true;
            for(int i=pos1;i<strlen(s);i++){
                if(match(s,p,i+1,pos2+2)){
                    tag=1;
                    return true;
                }
            }
        }
        return false;
    }
    else if(p[pos2]!='.'){
        if(s[pos1]==p[pos2]) return match(s, p, pos1+1, pos2+1);
        else return false;
    }
    else if(p[pos2]=='.'){
        return match(s,p,pos1+1,pos2+1);
    }
    return false;
}

bool isMatch(const char *s, const char *p) {
    return match(s, p, 0, 0);
}