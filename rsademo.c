// rsademo.c
//ref. http://amitmason.blogspot.com/2016/05/linux-mint-openssl-library.html
#include <stdio.h>
#include <openssl/rsa.h>
#include <string.h>
main(){
    int keylen, enclen, declen,i;
    char enc[256],dec[256];
    char *b="1234";
    RSA *key=NULL;
    key=RSA_generate_key(2048,RSA_F4,NULL,NULL);

    enclen=RSA_public_encrypt(strlen(b),b,enc,key,RSA_PKCS1_PADDING);
    declen=RSA_private_decrypt(enclen,enc,dec,key,RSA_PKCS1_PADDING);
    keylen=RSA_size(key);

    printf("keylen=%d\n",keylen);
    printf("enclen=%d\n",enclen);
    printf("declen=%d\n",declen);

    for(i=0;i<declen;i++) printf("%c",dec[i]);
        printf("\n");

    RSA_free(key);
}
