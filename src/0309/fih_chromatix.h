/*============================================================================

FIHTDC

versions define : VAB.XXXX.YY
A:Main cam module number
B:Front cam module number
XXXX:firmware major version
YY:firmware test version

============================================================================*/

#define FIH_version_len 20

typedef struct
{
    char versions[FIH_version_len];
}fih_chromatix;
