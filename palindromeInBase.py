# Program to check if the number in some base results in palindrom or not
# LOGIC : num = a4*b^4 + a3*b^3 + a2*b^2 + a1*b^1 + a0*b^0
# then reverse = a0*b^4 + a1*b*3 + a2*b^2 + a1*b^1 + a0*b^4
# where b is the base

def isPalindrome(num, base):
    temp = num 
    reverse = 0 
    
    while(temp != 0):
        reverse = reverse*base + temp%base 
        temp = temp/base 

    print "Reverse", reverse
    print "Number ", num
    print "YES" if reverse == num  else "NO"

if __name__ == "__main__":
    ch = 'y'
    while(ch == 'y' or  ch == 'Y'):
        # Base must be greater than or equals to 2
        num, base = map(int, raw_input("Enter the number and base ").split())
        isPalindrome(num , base)
        ch = raw_input("Want to continue (Y- yes ; Other - No) ")
