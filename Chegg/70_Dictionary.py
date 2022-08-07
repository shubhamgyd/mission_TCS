# Dictionary of user emails
users_email={
    "gmail":"Camilla.Bent",
    "yahoo":"Diana.Spencer",
    "outlook":"Kate.Middleton",
    "iCloud":"Meghan.Markle"}

# Itarate the dictionary 
for key,value in users_email.items():
    # converting the value/subdomain into lower string
    subdomain=value.lower()
    # appending @ sign
    subdomain=subdomain+'@'
    # storing domainName
    domainName=key
    # appending .com at last
    domainName=domainName+".com"
    # finalUserEmail
    finalEmail=subdomain+domainName
    #printing Email
    print(finalEmail)