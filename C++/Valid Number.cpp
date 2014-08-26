bool isNumber(const char *s) {
    char *endptr;
    strtod(s,&endptr);
    if(endptr==s) return false;
    for(;*endptr;++endptr)
        if(!ispace(*endptr)) return false;
    return true;
}