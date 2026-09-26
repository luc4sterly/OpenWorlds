// 10068c40 __strcmpi [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __strcmpi
   
   Library: Visual Studio 1998 Release */

int __cdecl __strcmpi(char *_Str1,char *_Str2)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar8;
  uint uVar9;
  uint uVar7;
  
  if (DAT_10088740 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_10068c8e;
        bVar5 = *_Str2;
        _Str2 = _Str2 + 1;
        bVar4 = *_Str1;
        _Str1 = _Str1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_10068c8e:
    uVar7 = (uint)cVar6;
  }
  else {
    bVar2 = 0 < DAT_1008b344;
    if (bVar2) {
      __lock(0x13);
    }
    else {
      _DAT_1008b348 = _DAT_1008b348 + 1;
    }
    uVar9 = (uint)bVar2;
    uVar7 = 0xff;
    uVar8 = 0;
    do {
      do {
        if ((char)uVar7 == '\0') goto LAB_10068ce7;
        cVar6 = *_Str2;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),cVar6);
        _Str2 = _Str2 + 1;
        cVar1 = *_Str1;
        uVar8 = CONCAT31((int3)(uVar8 >> 8),cVar1);
        _Str1 = _Str1 + 1;
      } while (cVar6 == cVar1);
      uVar8 = __tolower_lk(uVar8);
      uVar7 = __tolower_lk(uVar7);
    } while ((byte)uVar8 == (byte)uVar7);
    uVar8 = (uint)((byte)uVar8 < (byte)uVar7);
    uVar7 = (1 - uVar8) - (uint)(uVar8 != 0);
LAB_10068ce7:
    if (uVar9 == 0) {
      _DAT_1008b348 = _DAT_1008b348 + -1;
    }
    else {
      FUN_10064870(0x13);
    }
  }
  return uVar7;
}


