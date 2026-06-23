// If you are to enroll a user with one finger – two fingerprint
// templates - to a BioEntry Plus device
BEUserHdr userHdr;
// fill other fields of userHdr
// ..
userHdr.numOfFinger = 1;
unsigned char* templateBuf = (unsigned char*)malloc( 384 * userHdr.numOfFinger * 2 );
int bufPos = 0;
for( int i = 0; i < userHdr.numOfFinger * 2; i++ )
{
BS_RET_CODE result = BS_ScanTemplate( handle, templateBuf + bufPos );
bufPos += 384;
}
```

