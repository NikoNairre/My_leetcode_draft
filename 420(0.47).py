password=input()
class Solution: 
    def appears(self,password:str):
        apper_res=[]
        i=0
        cur_num=1
        while i<len(password):
            if i+1>len(password)-1:
                if password[i]!=password[i-1]:
                    apper_res.append([password[i],1])
                else:
                    apper_res.append([password[i],cur_num])
                i+=1
                break         
            if password[i]!=password[i+1]:
                apper_res.append([password[i],cur_num])
                i+=1
                cur_num=1
                continue
            else:
                cur_num+=1
                i+=1
        return apper_res
    def strongPasswordChecker(self, password: str) -> int:
        if len(password)==1:
            return 5
        if len(password)==2:
            return 4
        if len(password)==3:
            if password[0]==password[1] and password[1]==password[2]:
                return 4
            else:
                return 3
        if len(password)==4:
            if (password[0]==password[1] and password[1]==password[2]) or(password[1]==password[2] and password[2]==password[3]):
                return 3
            else:
                return 2
        if len(password)==5:
            arr=Solution.appears(self,password)
            for character in arr:
                if character[1]==5 and (character[0]=="!" or character[0]=="."):
                    return 3
                elif character[1]==5 and(character[0]!="!" and character[0]!="."):
                    return 2
                elif character[1]==4 and (password=="!!!!." or password==".!!!!" or password=="....!" or password=="!...."):
                    return 3
                elif character[1]==4 and(character[0]!="!" and character[0]!="."):
                    return 2
                elif character[1]==3:
                    if password=="!!!.." or password==".!!!." or password=="..!!!" or password=="...!!" or password=="!...!" or password=="!!...":
                        return 3
                    elif ("!!!." in password) or("!!.!" in password)or("!.!!" in password)or(".!!!" in password) or ("...!" in password) or("..!." in password)or(".!.." in password)or("!..." in password):
                        return 3
                    else:
                        return 2
                elif password=="!!.!!" or password=="..!..":
                    return 3
                elif ("!!.!" in password) or("!.!!" in password) or("..!." in password)or(".!.." in password)or("..!." in password):
                    return 2
            return 1
        if len(password)>=6 and len(password)<=20:
            num_lower=0
            num_upper=0
            num_num=0
            biggest_appear=0
            alter=0
            for letter in Solution.appears(self,password):
                if ord(letter[0])>=97 and ord(letter[0])<=112:
                    num_lower+=1
                if ord(letter[0])>=65 and ord(letter[0])<=90:
                    num_upper+=1
                if ord(letter[0])>=48 and ord(letter[0])<=90:
                    num_num+=1
                alter+=letter[1]//3
                if letter[1]>biggest_appear:
                    biggest_appear=max(letter[1],biggest_appear)
            if num_lower!=0 and num_upper!=0 and num_num!=0 and alter==0:
                return 0
            else:
                return alter
        if len(password)>20:
            return len(password)-20
s=Solution()
print(s.appears(password))