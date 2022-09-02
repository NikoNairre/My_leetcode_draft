from typing import Set


class Solution:
    def numUniqueEmails(self, emails: list[str]) -> int:
        real_emails=set()
        for email in emails:
            op=email.split("@")
            real_email=""
            for i in range(0,len(op[0])):
                if op[0][i]==".":
                    continue
                if op[0][i]=="+":
                    break
                real_email+=op[0][i]
            real_email+="@"+op[1]
            real_emails.add(real_email)
        return len(real_emails)
e=["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
a=Solution()
print(a.numUniqueEmails(e))
