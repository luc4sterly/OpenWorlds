// 0042cc60 FUN_0042cc60 [Global]
// programa: sfmain.exe

uint __fastcall FUN_0042cc60(undefined4 param_1,uint *param_2)

{
  byte bVar1;
  uint *in_EAX;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  uint uVar2;
  
  if (in_EAX != param_2) {
    do {
      uVar2 = *in_EAX;
      uVar4 = *param_2;
      if (uVar4 != uVar2) {
LAB_0042ccd9:
        bVar1 = (byte)uVar2;
        bVar5 = bVar1 < (byte)uVar4;
        if (bVar1 == (byte)uVar4) {
          if (bVar1 == 0) {
            return 0;
          }
          bVar1 = (byte)(uVar2 >> 8);
          bVar3 = (byte)(uVar4 >> 8);
          bVar5 = bVar1 < bVar3;
          if (bVar1 == bVar3) {
            if (bVar1 == 0) {
              return 0;
            }
            bVar1 = (byte)(uVar2 >> 0x10);
            bVar3 = (byte)(uVar4 >> 0x10);
            bVar5 = bVar1 < bVar3;
            if (bVar1 == bVar3) {
              if (bVar1 == 0) {
                return 0;
              }
              bVar5 = (byte)(uVar2 >> 0x18) < (byte)(uVar4 >> 0x18);
            }
          }
        }
        return -(uint)bVar5 | 1;
      }
      if ((uVar2 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
        return 0;
      }
      uVar2 = in_EAX[1];
      uVar4 = param_2[1];
      if (uVar4 != uVar2) goto LAB_0042ccd9;
      if ((uVar2 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
        return 0;
      }
      uVar2 = in_EAX[2];
      uVar4 = param_2[2];
      if (uVar4 != uVar2) goto LAB_0042ccd9;
      if ((uVar2 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
        return 0;
      }
      uVar2 = in_EAX[3];
      uVar4 = param_2[3];
      if (uVar4 != uVar2) goto LAB_0042ccd9;
      in_EAX = in_EAX + 4;
      param_2 = param_2 + 4;
    } while ((uVar2 + 0xfefefeff & ~uVar4 & 0x80808080) == 0);
  }
  return 0;
}


