// 1004fdc0 __setmode_lk [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __setmode_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __setmode_lk(uint param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  byte bVar4;
  
  pbVar1 = (byte *)(*(int *)((int)&DAT_1005f6d0 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 +
                   (param_1 & 0x1f) * 0x24);
  bVar2 = *pbVar1;
  if (param_2 == 0x8000) {
    bVar4 = bVar2 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      piVar3 = FUN_100490e0();
      *piVar3 = 0x16;
      return -1;
    }
    bVar4 = bVar2 | 0x80;
  }
  *pbVar1 = bVar4;
  return (-(uint)((bVar2 & 0x80) == 0) & 0x4000) + 0x4000;
}


