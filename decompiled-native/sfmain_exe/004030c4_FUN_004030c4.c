// 004030c4 FUN_004030c4 [Global]
// programa: sfmain.exe

void __fastcall FUN_004030c4(ushort *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  int in_EAX;
  short *psVar3;
  short *psVar4;
  int unaff_EBX;
  uint uVar5;
  ushort *local_28;
  uint local_10;
  
  local_28 = param_1;
  while (unaff_EBX = unaff_EBX + -1, unaff_EBX != -1) {
    uVar5 = (uint)*local_28;
    psVar3 = (short *)(in_EAX + 0x23c);
    psVar4 = param_2;
    local_10 = uVar5;
    do {
      sVar1 = *psVar3;
      sVar2 = *psVar4;
      *psVar3 = (short)local_10;
      local_10 = (int)(short)((int)(short)uVar5 * (int)sVar2 + 0x4000 >> 0xf) + (int)sVar1;
      if (0xffff < local_10 + 0x8000) {
        if ((int)local_10 < 1) {
          local_10 = 0xffff8000;
        }
        else {
          local_10 = 0x7fff;
        }
      }
      uVar5 = (int)(short)((int)sVar1 * (int)sVar2 + 0x4000 >> 0xf) + (int)(short)uVar5;
      if (0xffff < uVar5 + 0x8000) {
        if ((int)uVar5 < 1) {
          uVar5 = 0xffff8000;
        }
        else {
          uVar5 = 0x7fff;
        }
      }
      psVar3 = psVar3 + 1;
      psVar4 = psVar4 + 1;
    } while (psVar3 != (short *)(in_EAX + 0x24c));
    *local_28 = (ushort)uVar5;
    local_28 = local_28 + 1;
  }
  return;
}


