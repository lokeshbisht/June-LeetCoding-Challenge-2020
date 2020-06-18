 	class Solution {
public:
    string validIPAddress(string ip) {
        
		int n = ip.size();
        int findex;
		int lindex;
		int count = 0;
        
		string temp;
        
		if(ip.find(".") != string::npos) {
            findex = 0;
            lindex =- 1;
            temp = "";
            
            for(int i = 0; i < n; i++) {
                if(ip[i] == '.'|| i == n-1) {
                    if(i == n - 1) {
                        if(isdigit(ip[i]) == 0) {
                    	   return "Neither";
                   		}
                        temp += ip[i];
                       
                        i = n;
                    }
                    count++;
                    findex = lindex + 1;
                    lindex = i;
                    
					if(lindex - findex > 3 || lindex - findex <= 0 || (lindex - findex != 1 && temp[0] == '0')) {
						return "Neither";
					}
                    if(stoi(temp) > 255) {
                       	return "Neither";
					}
                                   
                    temp="";
                    
                }
                else {
                    temp += ip[i];
                    
					if(isdigit(ip[i]) == 0) {
						return "Neither";	
					}
                       
                }
            }
            if(count != 4) {
            	return "Neither";
			}
                
            return "IPv4";
        }
        else {
            count = 0;
            findex  =0;
            lindex =- 1;
            for(int i = 0; i < n; i++) {
                if(ip[i] == ':' || i == n-1) {
                    if(i == n - 1) {
                       i = n;
                    }
                    
					count++;
                    findex = lindex + 1;
                    lindex = i;
                    
					if(lindex - findex > 4 || lindex - findex <= 0) {
                        cout<<count<<" "<<lindex<<" "<<findex<<endl;
                        return "Neither";
                    }
                }
                else {
                    if(isxdigit(ip[i]) == 0) {
                        return "Neither";
                	}
                }
            }
            if(count != 8) {
            	return "Neither";
			}
            
            return "IPv6";
        }
    }
};
