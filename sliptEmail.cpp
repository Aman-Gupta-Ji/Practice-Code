int cv = 0;
int cch = 0;

for(int i = 0; i < s.length(); i++) {
	if(s[i] == '@') {
		if(cch < 2) {
			if(cch == 1 && i == 1) {
				cch = 0;
				continue;
			}
			return -1;
		}
		cch = 0;
		continue;
	}
	cch++;
}


// at the end
if(cch == 0)
	return -1;