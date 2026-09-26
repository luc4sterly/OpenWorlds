// 00407714 FUN_00407714 [Global]
// programa: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00407714(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 < DAT_0040cf80) {
    bVar1 = *(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8);
    if ((bVar1 & 1) != 0) {
      if (param_2 == 0x8000) {
        bVar2 = bVar1 & 0x7f;
      }
      else {
        if (param_2 != 0x4000) {
          _DAT_0040ba38 = 0x16;
          return -1;
        }
        bVar2 = bVar1 | 0x80;
      }
      *(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) = bVar2;
      return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  _DAT_0040ba38 = 9;
  return -1;
}


