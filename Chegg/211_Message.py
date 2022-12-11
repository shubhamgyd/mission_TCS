# Utility function which return the plain text after decrypting the given message
def decrypt(message):
    # Get final updated string after removing non alphabetic chars
    updatedMessage = ""
    # Iterate entered message
    for ch in message:
        # If char is alpbabetic then append into the updatedMessage
        if ch.isalpha():
            updatedMessage += ch
        # else ignore

    # Get plain Text
    plainText = ""
    # Iterate updated Message
    for i in range(0, len(updatedMessage)):
        # Get every 4th character from the updatedMessage
        if (i+1) % 4 == 0:
            plainText += updatedMessage[i]
    # Return plainText
    return plainText


# print(decrypt('zerhvuli'))
# print(decrypt('llbsdryeobfcsisthvvieuiozxdnsyltdtjwliho'))
# print(decrypt('Glybkisa xuibrakyyyds huohmeiani erz cjk'))
# print(decrypt('Xatr, pyko te kmh. Oietfko'))
# print(decrypt('Mox, jiwg uwh xlfhqi. Qgweaklt!'))
print(decrypt('Jo yr en oo vj es fi ga hp il mm wi mg vn vt qd.'))
